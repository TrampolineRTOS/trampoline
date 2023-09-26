/**
 * @file tpl_can_demo_driver.c
 *
 * @section desc File description
 *
 * See tpl_can_demo_driver.h for description.
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
#include <stdio.h>
#include <string.h>
#include <tpl_can_demo_driver.h>
#include <tpl_os.h>

static int can_demo_driver_init(struct tpl_can_controller_config_t *config);
static int can_demo_driver_set_baudrate(struct tpl_can_controller_t *ctrl, tpl_can_baud_rate_t baud_rate);
static Std_ReturnType can_demo_driver_transmit(struct tpl_can_controller_t *ctrl, const Can_PduType *pdu_info);
static Std_ReturnType can_demo_driver_receive(struct tpl_can_controller_t *ctrl, Can_PduType *pdu_info);
static int can_demo_driver_is_data_available(struct tpl_can_controller_t *ctrl);

static uint32 baud_rate_lut[CAN_BAUD_RATE_COUNT] =
{
	// CAN_BAUD_RATE_50_KBPS
	50000,
	// CAN_BAUD_RATE_100_KBPS
	100000,
	// CAN_BAUD_RATE_125_KBPS
	125000,
	// CAN_BAUD_RATE_250_KBPS
	250000,
	// CAN_BAUD_RATE_500_KBPS
	500000,
	// CAN_BAUD_RATE_1_MBPS
	1000000,
	// CAN_BAUD_RATE_2_MBPS
	2000000,
	// CAN_BAUD_RATE_5_MBPS
	5000000
};

tpl_can_controller_t can_demo_driver_controller_1 =
{
	0x12341111,
	can_demo_driver_init,
	can_demo_driver_set_baudrate,
	can_demo_driver_transmit,
	can_demo_driver_receive,
	can_demo_driver_is_data_available
};

tpl_can_controller_t can_demo_driver_controller_2 =
{
	0x12342222,
	can_demo_driver_init,
	can_demo_driver_set_baudrate,
	can_demo_driver_transmit,
	can_demo_driver_receive,
	can_demo_driver_is_data_available
};

static int can_demo_driver_init(struct tpl_can_controller_config_t *config)
{
	printf("[%s:%d] Initializing controller 0x%08X...\r\n",
		__func__,
		__LINE__,
		config->controller->base_address);
	printf("Protocol version : %s\r\nNominal baud rate : %u\r\n",
		config->protocol_version == CAN_PROTOCOL_VERSION_CLASSIC ? "CAN classic 2.0" : "CAN-FD",
		baud_rate_lut[config->nominal_baud_rate]);
	if (config->protocol_version == CAN_PROTOCOL_VERSION_FD)
		printf("Data baud rate (only for CAN-FD) : %u\r\n", baud_rate_lut[config->fd_data_baud_rate]);
	return 0;
}

static int can_demo_driver_set_baudrate(struct tpl_can_controller_t *ctrl, tpl_can_baud_rate_t baud_rate)
{
	uint32 bits_per_second;

	if (baud_rate >= CAN_BAUD_RATE_COUNT)
	{
		printf("[%s:%d] Wrong baud rate code %d, aborting.\r\n", __func__, __LINE__, baud_rate);
		return -1;
	}
	bits_per_second = baud_rate_lut[baud_rate];

	printf("[%s:%d] Baud rate set to %u for controller 0x%08X.\r\n", __func__, __LINE__, bits_per_second, ctrl->base_address);
	return 0;
}

static Std_ReturnType can_demo_driver_transmit(struct tpl_can_controller_t *ctrl, const Can_PduType *pdu_info)
{
	uint32 i;

	printf("[%s:%d] Transmission request for controller 0x%08X, CAN ID = 0x%X, flags = 0x%02X, payload length = %u, payload = ",
		__func__,
		__LINE__,
		ctrl->base_address,
		pdu_info->id & TPL_CAN_ID_MASK,
		TPL_CAN_ID_TYPE_GET(pdu_info->id),
		pdu_info->length);
	for (i = 0; i < pdu_info->length; i++)
		printf("0x%02X ", pdu_info->sdu[i]);
	printf("\r\n");

	return 0;
}

static Std_ReturnType can_demo_driver_receive(struct tpl_can_controller_t *ctrl, Can_PduType *pdu_info)
{
	if (ctrl->base_address == can_demo_driver_controller_1.base_address)
	{
		pdu_info->id = 0x1ab | TPL_CAN_ID_TYPE_STANDARD; // Random value
		strcpy((char *) pdu_info->sdu, "Test");
		pdu_info->length = strlen((char *) pdu_info->sdu);
	}
	else if (ctrl->base_address == can_demo_driver_controller_2.base_address)
	{
		pdu_info->id = 0xcafeb0b | TPL_CAN_ID_TYPE_FD_EXTENDED; // Random value
		strcpy((char *) pdu_info->sdu, "The CAN-FD frame longer payload.");
		pdu_info->length = strlen((char *) pdu_info->sdu);
	}

	return E_OK;
}

static int can_demo_driver_is_data_available(struct tpl_can_controller_t *ctrl)
{
	(void) ctrl;

	return 1;
}
