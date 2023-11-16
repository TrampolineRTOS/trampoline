/**
 * @file spider_can.c
 *
 * @section desc File description
 *
 * Renesas R-Car S4 CAN 2.0 driver.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * (C) BayLibre 2023
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 *  @section infos File informations
 *
 *  $Date$
 *  $Rev$
 *  $Author$
 *  $URL$
 */
#include <Can.h>
#include <iodefine.h>
#include <string.h>
#include "spider_can.h"

// TODO make this value accessible globally
#define PROTECTION_DISABLE_KEY 0xA5A5A501
// TODO make this value accessible globally
#define PROTECTION_ENABLE_KEY 0xA5A5A500

#define SPIDER_CAN_RECEIVED_DATA_FLAG(ctrl) (!(((volatile struct __tag5579 *) ctrl->base_address)->CFDFESTS.UINT32 & 0x00000001))

/**
 * The CAN clock that feeds the prescalers (in Hertz).
 */
#define SPIDER_CAN_CLOCK (80000000)
#define SPIDER_CAN_COMPUTE_PRESCALER(baud_rate, prop_seg, tseg1, tseg2) ((SPIDER_CAN_CLOCK / (baud_rate * (1 + prop_seg + tseg1 + tseg2))) - 1)

static int spider_can_init(struct tpl_can_controller_config_t *config);
static int spider_set_baudrate(struct tpl_can_controller_t *ctrl, CanControllerBaudrateConfig *baud_rate_config);
static Std_ReturnType spider_transmit(struct tpl_can_controller_t *ctrl, const Can_PduType *pdu_info);
static Std_ReturnType spider_receive(struct tpl_can_controller_t *ctrl, Can_PduType *pdu_info);
static int spider_is_data_available(struct tpl_can_controller_t *ctrl);

struct spider_can_priv
{
	int is_can_fd_enabled;
	int is_can_fd_bit_rate_switch_enabled;
};

static struct spider_can_priv spider_can_controller_0_priv, spider_can_controller_1_priv;

tpl_can_controller_t spider_can_controller_0 =
{
	RSCFD0_BASE_ADDR,
	spider_can_init,
	spider_set_baudrate,
	spider_transmit,
	spider_receive,
	spider_is_data_available,
	&spider_can_controller_0_priv
};

tpl_can_controller_t spider_can_controller_1 =
{
	RSCFD1_BASE_ADDR,
	spider_can_init,
	spider_set_baudrate,
	spider_transmit,
	spider_receive,
	spider_is_data_available,
	&spider_can_controller_1_priv
};

/**
 * Refer to the figure 6.2 of the datasheet "158_23_uciaprcn0140kai_IPSpec_v010401.pdf" to find the TSEG1 and TSEG2 for each desired baud rate.
 * Then, compute the number of time quanta per bit : Total_TQ_Per_Bit = TSEG1 + TSEG2 + 1 (see datasheet section 6.1.1 for more information).
 * It is now possible to compute the prescaler value : Prescaler = (DLL / (Baud_Rate * Total_TQ_Per_Bit)) - 1.
 * DLL is the CAN module clock in MHz, Baud_Rate is the desired baud rate in bit/s and Total_TQ_Per_Bit has been computed previously.
 * On the R-Car S4 Spider board, the DLL clock is 80MHz.
 * The computed prescaler does not correspond to the measured baud rate, so adding 1 or 2 to Total_TQ_Per_Bit allows to get a correct value.
 * For this, use the CanControllerPropSeg value from the baud rate configuration.
 */
static int spider_can_configure_baud_rate_registers(struct tpl_can_controller_t *ctrl, CanControllerBaudrateConfig *baud_rate_config)
{
	struct __tag743 nominal_bitrate_conf_reg = { 0 };
	struct __tag900 data_bitrate_config_reg = { 0 };
	struct __tag901 can_fd_config_reg = { 0 };
	volatile struct __tag5579 *ctrl_base_address = (volatile struct __tag5579 *) ctrl->base_address;
	struct spider_can_priv *priv = ctrl->priv;

	// Make sure the CAN baud rates are in the allowed range
	if (baud_rate_config->CanControllerBaudRate > 1000)
		return -1;
	if (baud_rate_config->use_fd_configuration && baud_rate_config->can_fd_config.CanControllerFdBaudRate > 8000)
		return -1;

	// Set the CAN 2.0 baud rate registers
	nominal_bitrate_conf_reg.NBRP = SPIDER_CAN_COMPUTE_PRESCALER(
		baud_rate_config->CanControllerBaudRate * 1000,
		baud_rate_config->CanControllerPropSeg,
		baud_rate_config->CanControllerSeg1,
		baud_rate_config->CanControllerSeg2);
	nominal_bitrate_conf_reg.NSJW = baud_rate_config->CanControllerSyncJumpWidth;
	nominal_bitrate_conf_reg.NTSEG1 = baud_rate_config->CanControllerSeg1;
	nominal_bitrate_conf_reg.NTSEG2 = baud_rate_config->CanControllerSeg2;
	ctrl_base_address->CFDC0NCFG.BIT = nominal_bitrate_conf_reg;

	if (baud_rate_config->use_fd_configuration)
	{
		// Set the CAN-FD baud rate registers
		data_bitrate_config_reg.DBRP = SPIDER_CAN_COMPUTE_PRESCALER(
			baud_rate_config->can_fd_config.CanControllerFdBaudRate * 1000,
			baud_rate_config->can_fd_config.CanControllerPropSeg,
			baud_rate_config->can_fd_config.CanControllerSeg1,
			baud_rate_config->can_fd_config.CanControllerSeg2);
		data_bitrate_config_reg.DSJW = baud_rate_config->can_fd_config.CanControllerSyncJumpWidth;
		data_bitrate_config_reg.DTSEG1 = baud_rate_config->can_fd_config.CanControllerSeg1;
		data_bitrate_config_reg.DTSEG2 = baud_rate_config->can_fd_config.CanControllerSeg2;
		ctrl_base_address->CFDC0DCFG.BIT = data_bitrate_config_reg;

		// Configure the CAN-FD to work alongside the CAN 2.0
		can_fd_config_reg.EOCCFG = 0; // The error counter counts all transmitted or received frames
		can_fd_config_reg.TDCOC = 0; // Use the programmed offset and the measured one for the transceiver delay compensation
		can_fd_config_reg.TDCE = 0; // TODO enable the transceiver delay compensation
		can_fd_config_reg.ESIC = 0; // The Error State Indication bit represents the node itself
		can_fd_config_reg.RPNMD = 0; // Unused, set default value
		can_fd_config_reg.TDCO = baud_rate_config->can_fd_config.CanControllerSspOffset; // Set the transceiver delay compensation offset
		can_fd_config_reg.GWEN = 0; // Disable the multi gateway feature
		can_fd_config_reg.GWFDF = 0; // Unused, set default value
		can_fd_config_reg.GWBRS = 0; // Unused, set default value
		can_fd_config_reg.FDOE = 0; // Disable FD-only mode to allow both modes
		can_fd_config_reg.REFE = 0; // Disable RX edge filter for now
		can_fd_config_reg.CLOE = 0; // Disable classical-only mode to allow both modes
		ctrl_base_address->CFDC0FDCFG.BIT = can_fd_config_reg;
	}
	else
	{
		// Disable CAN-FD
		ctrl_base_address->CFDC0DCFG.UINT32 = 0;
		ctrl_base_address->CFDC0FDCFG.UINT32 = 0;
	}

	// Cache some configuration parameters to quickly access to these information in the transmit() function
	priv->is_can_fd_enabled = 0;
	priv->is_can_fd_bit_rate_switch_enabled = 0;
	if (baud_rate_config->use_fd_configuration)
	{
		priv->is_can_fd_enabled = 1;
		if (baud_rate_config->can_fd_config.CanControllerTxBitRateSwitch)
			priv->is_can_fd_bit_rate_switch_enabled = 1;
	}

	return 0;
}

/**
 * TODO improve, this is quick and dirty for now
 */
static void spider_can_configure_gpios(struct tpl_can_controller_t *ctrl)
{
	uint32 val;

	// Assign the CAN pins to the correct CAN module (the PMMR register value needs to be written before writing another register with the inverse of the register value)
	if (ctrl->base_address == RSCFD0_BASE_ADDR)
	{
		// Enable multiplexing register usage
		PFC1.PMMER7_B0A0 = 0x00000001;

		// Select the peripheral function for the CAN pins
		val = PFC1.GPSR7_B0A0 | 0x00000003;
		PFC1.PMMR7_B0A0 = ~val;
		PFC1.GPSR7_B0A0 = val;

		// Select the CAN function for the CAN GPIOs
		val = PFC1.IP0SR7_B0A0 & ~0x00000003;
		PFC1.PMMR7_B0A0 = ~val;
		PFC1.IP0SR7_B0A0 = val;

		// Set the drive strength of the CAN TX pin to 7/8
		val = PFC1.DRV0CTRL7_B0A0 & ~0x0000000F;
		val |= 0x00000003;
		PFC1.PMMR7_B0A0 = ~val;
		PFC1.DRV0CTRL7_B0A0 = val;
	}
	else
	{
		// Enable multiplexing register usage
		PFC1.PMMER7_B0A0 = 0x00000001;

		// Select the peripheral function for the CAN pins
		val = PFC1.GPSR7_B0A0 | 0x00030000;
		PFC1.PMMR7_B0A0 = ~val;
		PFC1.GPSR7_B0A0 = val;

		// Select the CAN function for the CAN GPIOs
		val = PFC1.IP2SR7_B0A0 & ~0x00000003;
		PFC1.PMMR7_B0A0 = ~val;
		PFC1.IP2SR7_B0A0 = val;

		// Set the drive strength of the CAN TX pin to 7/8
		val = PFC1.DRV2CTRL7_B0A0 & ~0x0000000F;
		val |= 0x00000003;
		PFC1.PMMR7_B0A0 = ~val;
		PFC1.DRV2CTRL7_B0A0 = val;
	}
}

static int spider_can_init(struct tpl_can_controller_config_t *config)
{
	uint32 val;
	volatile uint32 temp;
	struct tpl_can_controller_t *ctrl = config->controller;
	volatile struct __tag5579 *ctrl_base_address = (volatile struct __tag5579 *) ctrl->base_address;

	// Make sure the clocks are stable (this is needed only on the G4MH core)
	// Main oscillator
	while ((SYSCTRL.MOSCS.BIT.MOSCEN == 0) || (SYSCTRL.MOSCS.BIT.MOSCSTAB == 0));
	// The datasheet tells to wait 1.4us after the clock is stable, or to read the MOSCSTAB bit at least 4 times (take some margin here)
	for (val = 0; val < 100; val++)
		temp = SYSCTRL.MOSCS.UINT32;
	// PLL
	while ((SYSCTRL.PLLS.BIT.PLLCLKEN == 0) || (SYSCTRL.PLLS.BIT.PLLCLKSTAB == 0));
	// The datasheet tells to wait 1.4us after the clock is stable, or to read the PLLCLKSTAB bit at least 4 times (take some margin here)
	for (val = 0; val < 100; val++)
		temp = SYSCTRL.PLLS.UINT32;

	// Clock the CAN module with a 80MHz clock to be able to reach 8Mbit/s bus speed in CAN-FD mode (see datasheet table 13.6)
	SYSCTRL.CLKKCPROT1.UINT32 = PROTECTION_DISABLE_KEY; // Allow access to the clock controller registers
	SYSCTRL.CLKD_PLLC.UINT32 = 0x00000001; // Make sure the PLL output clock is not divided
	while (!SYSCTRL.CLKD_PLLS.BIT.PLLCLKDSYNC);
	SYSCTRL.CKSC_CPUC.UINT32 = 0; // Select the PLL output as the source for the system clock
	while (SYSCTRL.CKSC_CPUS.BIT.CPUCLKSACT);
	SYSCTRL.CKSC_RCANC.UINT32 = 0x00000001; // Make sure the clock is not divided
	SYSCTRL.CLKKCPROT1.UINT32 = PROTECTION_ENABLE_KEY; // Re-enable the clock controller registers protection

	// Allow access to the standby controller registers
	SYSCTRL.STBCKCPROT.UINT32 = PROTECTION_DISABLE_KEY;
	SYSCTRL.MSRKCPROT.UINT32 = PROTECTION_DISABLE_KEY;

	// Enable the CAN controller clock
	val = SYSCTRL.MSR_RSCFD.UINT32;
	if (ctrl->base_address == RSCFD0_BASE_ADDR)
		val &= ~0x00000001;
	else if (ctrl->base_address == RSCFD1_BASE_ADDR)
		val &= ~0x00000002;
	else
		return -1;
	SYSCTRL.MSR_RSCFD.UINT32 = val;

	// Re-enable the standby controller registers protection
	SYSCTRL.STBCKCPROT.UINT32 = PROTECTION_ENABLE_KEY;
	SYSCTRL.MSRKCPROT.UINT32 = PROTECTION_ENABLE_KEY;

	// Wait for the CAN RAM initialization to terminate
	while (ctrl_base_address->CFDGSTS.BIT.GRAMINIT);

	// Make sure the module is in reset mode
	ctrl_base_address->CFDGCTR.UINT32 = 0x00000001;
	while (!ctrl_base_address->CFDGSTS.BIT.GRSTSTS);

	// Release the channel 0 from sleep mode (TODO add support for a bitmask of enabled channels)
	ctrl_base_address->CFDC0CTR.UINT32 = 0x00000001;
	while (ctrl_base_address->CFDC0STS.BIT.CSLPSTS);

	// Configure bus speed
	if (spider_can_configure_baud_rate_registers(ctrl, &config->baud_rate_config) != 0)
		return E_NOT_OK;

	// Configure rule table (create 1 rule that match all possible frames in reception and transmission)
	ctrl_base_address->CFDGAFLECTR.UINT32 = 1 << 8; // Enable write access for page 0
	ctrl_base_address->CFDGAFLCFG0.UINT32 = 1 << 16; // Configure one rule for channel 0
	ctrl_base_address->CFDGAFLID1.UINT32 = 0; // Do not set IDs as they won't be taken into account with the mask register
	ctrl_base_address->CFDGAFLM1.UINT32 = 0; // Accept all received CAN frames
	ctrl_base_address->CFDGAFLP01.UINT32 = 0; // Disable DLC check
	ctrl_base_address->CFDGAFLP11.UINT32 = 0x00000001; // Use RX FIFO 0 as target for reception
	ctrl_base_address->CFDGAFLECTR.UINT32 = 0; // Disable write access for page 0

	// Disable the reception message buffers as FIFO is used instead
	ctrl_base_address->CFDRMNB.UINT32 = 0;

	// Configure the reception FIFO
	val = 0x06 << 8; // Disable all interrupts, set a FIFO depth of 64 messages, do not enable the FIFO yet
	// The default maximum allowed payload size is 8 bytes, set a 64-byte payload if CAN-FD is enabled
	if (config->baud_rate_config.use_fd_configuration)
		val |= 0x07 << 4;
	ctrl_base_address->CFDRFCC0.UINT32 = val;

	// Configure the transmission FIFO
	val = (0x06 << 21) | (0x01 << 8); // Set the FIFO depth to 64 messages, select transmission mode, do not enable the FIFO yet
	// The default maximum allowed payload size is 8 bytes, set a 64-byte payload if CAN-FD is enabled
	if (config->baud_rate_config.use_fd_configuration)
		val |= 0x07 << 4;
	ctrl_base_address->CFDCFCC0.UINT32 = val;
	ctrl_base_address->CFDCFCCE0.UINT32 = 0; // Enable transmission

	// Switch the module to global operation mode
	ctrl_base_address->CFDGCTR.UINT32 &= 0xFFFFFFFC;
	// On the Cortex-R52 clearing CFDGCTR bits 1..0 works immediately, on the G4MH some register hammering seems needed (TODO find why)
	val = 0;
	while ((ctrl_base_address->CFDGSTS.UINT32 & 0x00000003) != 0)
	{
		val++;
		if (val == 100000) // This random amount of cycles seems to be working
		{
			ctrl_base_address->CFDGCTR.UINT32 &= 0xFFFFFFFC;
			val = 0;
		}
	}

	// Switch the required CAN channels to operation mode, TODO handle multiple channels
	ctrl_base_address->CFDC0CTR.UINT32 = 0;
	while (ctrl_base_address->CFDC0STS.BIT.CRSTSTS);

	spider_can_configure_gpios(ctrl);

	// Enable reception FIFO (the write must be done separately, after all other bits of the register have been configured, and when the module is in global operation mode)
	val = ctrl_base_address->CFDRFCC0.UINT32;
	val |= 0x00000001;
	ctrl_base_address->CFDRFCC0.UINT32 = val;

	// Enable transmission FIFO, the requirements are the same than the reception FIFO
	val = ctrl_base_address->CFDCFCC0.UINT32;
	val |= 0x00000001;
	ctrl_base_address->CFDCFCC0.UINT32 = val;

	return E_OK;
}

static int spider_set_baudrate(struct tpl_can_controller_t *ctrl, CanControllerBaudrateConfig *baud_rate_config)
{
	// Does nothing for now
	(void) ctrl;
	(void) baud_rate_config;

	return E_OK;
}

static Std_ReturnType spider_transmit(struct tpl_can_controller_t *ctrl, const Can_PduType *pdu_info)
{
	volatile struct __tag5579 *ctrl_base_address = (volatile struct __tag5579 *) ctrl->base_address;
	int is_can_fd;
	volatile uint8 *src, *dest;
	uint32 i, val, adjusted_payload_length;
	struct spider_can_priv *priv = ctrl->priv;

	// If the FIFO is full, wait for a transmission to finish to get a free FIFO slot
	while (ctrl_base_address->CFDFFSTS.BIT.CF0FLL);

	// Cache the protocol type of the frame
	val = pdu_info->id & TPL_CAN_ID_TYPE_MASK;
	if ((val == TPL_CAN_ID_TYPE_FD_STANDARD) || (val == TPL_CAN_ID_TYPE_FD_EXTENDED))
		is_can_fd = 1;
	else
		is_can_fd = 0;

	// Set the CAN ID
	if ((val == TPL_CAN_ID_TYPE_EXTENDED) || (val == TPL_CAN_ID_TYPE_FD_EXTENDED))
		val = (pdu_info->id & TPL_CAN_ID_EXTENDED_MASK) | (1 << 31); // Tell this is an extended ID frame
	else
		val = pdu_info->id & TPL_CAN_ID_STANDARD_MASK;
	ctrl_base_address->CFDCFID0.UINT32 = val;

	// Set the payload size
	val = tpl_can_get_dlc_from_length(pdu_info->length, &adjusted_payload_length);
	ctrl_base_address->CFDCFPTR0.UINT32 = val << 28;

	// Set the frame payload
	if (!is_can_fd && pdu_info->length > TPL_CAN_CLASSIC_FRAME_MAXIMUM_PAYLOAD_SIZE)
		return E_NOT_OK;
	if (pdu_info->length > TPL_CAN_FD_FRAME_MAXIMUM_PAYLOAD_SIZE)
		return E_NOT_OK;
	src = pdu_info->sdu;
	dest = ctrl_base_address->CFDCFDF0_0.UINT8;
	// Use a for loop instead of memcpy() to make sure the buffer registers are accessed one byte at a time
	// Using memcpy() triggers a data abort exception for a 7-byte CAN payload
	for (i = 0; i < pdu_info->length; i++)
	{
		*dest = *src;
		src++;
		dest++;
	}
	// Pad the remaining data if needed if this is a CAN-FD frame
	for (; i < adjusted_payload_length; i++)
	{
		*dest = 0;
		dest++;
	}

	// Configure the frame format
	val = 0; // This corresponds to a classic CAN frame and also initializes the register bits not changed by the CAN-FD specific code
	if (is_can_fd)
	{
		val |= 1 << 2; // Tell to transmit a FD frame
		if (priv->is_can_fd_bit_rate_switch_enabled)
		{
			// TODO add BRS support
		}
	}
	ctrl_base_address->CFDCFFDCSTS0.UINT32 = val;

	// Start the frame transmission
	ctrl_base_address->CFDCFPCTR0.UINT32 = 0x000000FF;

	return E_OK;
}

static Std_ReturnType spider_receive(struct tpl_can_controller_t *ctrl, Can_PduType *pdu_info)
{
	volatile struct __tag5579 *ctrl_base_address = (volatile struct __tag5579 *) ctrl->base_address;
	int i, is_extended_id;
	volatile uint8 *src, *dest;
	Std_ReturnType ret = E_NOT_OK;
	struct spider_can_priv *priv = ctrl->priv;
	uint32 val;

	// Do not block if no data are available
	if (!SPIDER_CAN_RECEIVED_DATA_FLAG(ctrl))
		return E_NOT_OK;

	// Retrieve the CAN ID
	val = ctrl_base_address->CFDRFID0.UINT32;
	if (val & 0x80000000)
	{
		is_extended_id = 1;
		val &= TPL_CAN_ID_EXTENDED_MASK;
	}
	else
	{
		is_extended_id = 0;
		val &= TPL_CAN_ID_STANDARD_MASK;
	}
	pdu_info->id = val;

	// Retrieve the frame length
	val = ctrl_base_address->CFDRFPTR0.UINT32 >> 28;
	pdu_info->length = tpl_can_get_length_from_dlc(val);
	if (!priv->is_can_fd_enabled && pdu_info->length > TPL_CAN_CLASSIC_FRAME_MAXIMUM_PAYLOAD_SIZE)
		goto Exit;
	if (pdu_info->length > TPL_CAN_FD_FRAME_MAXIMUM_PAYLOAD_SIZE)
		goto Exit;

	// Retrieve the frame payload
	src = ctrl_base_address->CFDRFDF0_0.UINT8;
	dest = pdu_info->sdu;
	// Use a for loop instead of memcpy() to make sure the buffer registers are accessed one byte at a time
	// Using memcpy() triggers a data abort exception for a 7-byte CAN payload
	for (i = 0; i < pdu_info->length; i++)
	{
		*dest = *src;
		src++;
		dest++;
	}

	// Tell userspace about the type of the frame that has been received
	// Is this CAN-FD ?
	if (ctrl_base_address->CFDRFFDSTS0.BIT.RFFDF)
	{
		if (is_extended_id)
			pdu_info->id |= TPL_CAN_ID_TYPE_FD_EXTENDED;
		else
			pdu_info->id |= TPL_CAN_ID_TYPE_FD_STANDARD;
	}
	// So it is CAN classic
	else
	{
		if (is_extended_id)
			pdu_info->id |= TPL_CAN_ID_TYPE_EXTENDED;
		else
			pdu_info->id |= TPL_CAN_ID_TYPE_STANDARD;
	}

	ret = E_OK;

Exit:
	// Increment the FIFO read pointer to get access to the next received frame
	ctrl_base_address->CFDRFPCTR0.UINT32 = 0x000000FF;

	return ret;
}

static int spider_is_data_available(struct tpl_can_controller_t *ctrl)
{
	return SPIDER_CAN_RECEIVED_DATA_FLAG(ctrl);
}
