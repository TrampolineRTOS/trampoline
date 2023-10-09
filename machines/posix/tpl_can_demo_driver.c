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
static int can_demo_driver_set_baudrate(struct tpl_can_controller_t *ctrl, CanControllerBaudrateConfig *baud_rate_config);
static Std_ReturnType can_demo_driver_transmit(struct tpl_can_controller_t *ctrl, const Can_PduType *pdu_info);
static Std_ReturnType can_demo_driver_receive(struct tpl_can_controller_t *ctrl, Can_PduType *pdu_info);
static int can_demo_driver_is_data_available(struct tpl_can_controller_t *ctrl);

struct can_demo_driver_priv
{
	int is_can_fd_enabled;
};

static struct can_demo_driver_priv can_demo_driver_controller_priv[2];

tpl_can_controller_t can_demo_driver_controller_1 =
{
	0x12341111,
	can_demo_driver_init,
	can_demo_driver_set_baudrate,
	can_demo_driver_transmit,
	can_demo_driver_receive,
	can_demo_driver_is_data_available,
	&can_demo_driver_controller_priv[0]
};

tpl_can_controller_t can_demo_driver_controller_2 =
{
	0x12342222,
	can_demo_driver_init,
	can_demo_driver_set_baudrate,
	can_demo_driver_transmit,
	can_demo_driver_receive,
	can_demo_driver_is_data_available,
	&can_demo_driver_controller_priv[1]
};

static int can_demo_driver_init(struct tpl_can_controller_config_t *config)
{
	struct can_demo_driver_priv *priv = config->controller->priv;

	// Determine the CAN protocol version
	if (config->baud_rate_config.use_fd_configuration)
		priv->is_can_fd_enabled = 1;
	else
		priv->is_can_fd_enabled = 0;

	printf("[%s:%d] Initializing controller 0x%08X...\r\n",
		__func__,
		__LINE__,
		config->controller->base_address);
	printf("Protocol version : %s\r\nNominal baud rate : %u kbps\r\n",
		priv->is_can_fd_enabled ? "CAN-FD" : "CAN classic 2.0",
		config->baud_rate_config.CanControllerBaudRate);
	if (priv->is_can_fd_enabled)
		printf("Data baud rate (only for CAN-FD) : %u kbps\r\n", config->baud_rate_config.can_fd_config.CanControllerFdBaudRate);
	return 0;
}

static int can_demo_driver_set_baudrate(struct tpl_can_controller_t *ctrl, CanControllerBaudrateConfig *baud_rate_config)
{
	printf("[%s:%d] Setting a new baud rate for controller 0x%08X. Protocol version : %s, nominal baud rate : %u kbps",
		__func__,
		__LINE__,
		ctrl->base_address,
		baud_rate_config->use_fd_configuration ? "CAN-FD" : "CAN classic 2.0",
		baud_rate_config->CanControllerBaudRate);
	if (baud_rate_config->use_fd_configuration)
		printf(", CAN-FD data baud rate : %u kbps", baud_rate_config->can_fd_config.CanControllerFdBaudRate);
	printf(".\r\n");

	return 0;
}

static Std_ReturnType can_demo_driver_transmit(struct tpl_can_controller_t *ctrl, const Can_PduType *pdu_info)
{
	uint32 i;

	printf("[%s:%d] Transmission request for controller 0x%08X, CAN ID = 0x%X, flags = 0x%02X, payload length = %u, payload = ",
		__func__,
		__LINE__,
		ctrl->base_address,
		pdu_info->id & TPL_CAN_ID_EXTENDED_MASK,
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
