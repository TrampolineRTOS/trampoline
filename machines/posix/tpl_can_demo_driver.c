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

static int can_demo_driver_init(struct tpl_can_controller_t *ctrl, void *data);
static int can_demo_driver_set_baudrate(struct tpl_can_controller_t *ctrl, tpl_can_baud_rate_t baud_rate);
static Std_ReturnType can_demo_driver_transmit(struct tpl_can_controller_t *ctrl, const Can_PduType *pdu_info);
static Std_ReturnType can_demo_driver_receive(struct tpl_can_controller_t *ctrl, Can_PduType *pdu_info);
static int can_demo_driver_is_data_available(struct tpl_can_controller_t *ctrl);

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

static int can_demo_driver_init(struct tpl_can_controller_t *ctrl, void *data)
{
	printf("[%s:%d] Initialized controller 0x%08X.\r\n", __func__, __LINE__, ctrl->base_address);
	return 0;
}

static int can_demo_driver_set_baudrate(struct tpl_can_controller_t *ctrl, tpl_can_baud_rate_t baud_rate)
{
	static uint32 baud_rate_lut[] =
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
		1000000
	};
	uint32 bits_per_second;

	if (baud_rate >= CAN_BAUD_RATE_COUNT)
	{
		printf("[%s:%d] Wrong baud rate code %d, aborting.\r\n", baud_rate);
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
		   __func__, __LINE__, ctrl->base_address, pdu_info->id & ~TPL_CAN_ID_TYPE_MASK, pdu_info->length, pdu_info->id >> 30);
	for (i = 0; i < pdu_info->length; i++)
		printf("0x%02X ", pdu_info->sdu[i]);
	printf("\r\n");

	return 0;
}

static Std_ReturnType can_demo_driver_receive(struct tpl_can_controller_t *ctrl, Can_PduType *pdu_info)
{
	pdu_info->id = 0x1ab; // Random value
	strcpy(pdu_info->sdu, "Test");
	pdu_info->length = strlen(pdu_info->sdu);
	return 0;
}

static int can_demo_driver_is_data_available(struct tpl_can_controller_t *ctrl)
{
	return 1;
}
