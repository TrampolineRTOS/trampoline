/**
 * @file can_demo.c
 *
 * @section desc File description
 *
 * Echo the received CAN frames after incrementing the CAN ID and the payload
 * bytes.
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
#include <CanIf.h>
#include <spider_can.h>
#include <stdio.h>
#include <string.h>
#include <tpl_os.h>

int main(void)
{
	// Statically list the configuration of each CAN controller used in the application
	static tpl_can_controller_config_t can_controllers_config[] =
	{
		// First controller will use CAN 2.0
		{
			&spider_can_controller_0,
			CAN_PROTOCOL_VERSION_CLASSIC,
			{
				.CanControllerBaudRate = 250,
				.CanControllerBaudRateConfigID = 0,
				.CanControllerPropSeg = 1, // Fine tune the bus speed, it is measured at 245KHz
				.CanControllerSeg1 = 11,
				.CanControllerSeg2 = 4,
				.CanControllerSyncJumpWidth = 4,
				.use_fd_configuration = FALSE
			},
		}
	};
	static Can_ConfigType can_config_type =
	{
		can_controllers_config,
		sizeof(can_controllers_config) / sizeof(can_controllers_config[0])
	};
	int ret;

	// Initialize the CAN module 0 channel 0 at 125 Kbit/s (the default baud rate)
	ret = Can_Init(&can_config_type);
	if (ret)
		return -1;

	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(can_task)
{
	Can_PduType can_pdu, *pointer_can_pdu;
	PduInfoType pdu_info;
	uint8 payload[64];
	int i;

	// Send a frame to tell that the program is ready
	can_pdu.id = 0x123 | TPL_CAN_ID_TYPE_STANDARD;
	can_pdu.sdu = payload;
	strcpy((char *) can_pdu.sdu, "Ready!");
	can_pdu.length = strlen((char *) can_pdu.sdu);
	pdu_info.SduDataPtr = (uint8 *) &can_pdu;
	pdu_info.SduLength = sizeof(can_pdu);// + can_pdu.length;
	CanIf_Transmit(0, &pdu_info);

	// Wait for a frame, then increment its ID and payload and send it back
	while (1)
	{
		if (CanIf_ReadRxPduData(0, &pdu_info) == E_OK)
		{
			// Make sure the payload size is compatible with CAN 2.0
			pointer_can_pdu = (Can_PduType *) pdu_info.SduDataPtr;
			if (pointer_can_pdu->length > 8)
				continue;

			// Increment the CAN ID and the payload bytes
			pointer_can_pdu->id++;
			for (i = 0; i < pointer_can_pdu->length; i++)
				pointer_can_pdu->sdu[i]++;

			// Send the incremented frame back
			CanIf_Transmit(0, &pdu_info);
		}
	}
}
