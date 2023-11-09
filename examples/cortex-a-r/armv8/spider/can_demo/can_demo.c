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
			// CAN 2.0 at 250Kbps
			#if 0
			{
				.CanControllerBaudRate = 250,
				.CanControllerBaudRateConfigID = 0,
				.CanControllerPropSeg = 1, // Fine tune the bus speed, it is measured at 245KHz
				.CanControllerSeg1 = 11,
				.CanControllerSeg2 = 4,
				.CanControllerSyncJumpWidth = 4,
				.use_fd_configuration = FALSE
			}
			#endif
			// CAN-FD at 1Mbps without BRS
			#if 1
			{
				.CanControllerBaudRate = 1000,
				.CanControllerBaudRateConfigID = 0,
				.CanControllerPropSeg = 1, // Fine tune the bus speed, it is measured at 1MHz
				.CanControllerSeg1 = 5,
				.CanControllerSeg2 = 2,
				.CanControllerSyncJumpWidth = 2,
				.use_fd_configuration = TRUE,
				{
					.CanControllerFdBaudRate = 5000,
					.CanControllerPropSeg = 2,
					.CanControllerSeg1 = 10,
					.CanControllerSeg2 = 5,
					.CanControllerSspOffset = 15,
					.CanControllerSyncJumpWidth = 5,
					.CanControllerTxBitRateSwitch = FALSE
				}
			}
			#endif
		}
	};
	static Can_ConfigType can_config_type =
	{
		can_controllers_config,
		sizeof(can_controllers_config) / sizeof(can_controllers_config[0])
	};
	int ret;

	// Initialize the CAN module 0 channel 0 with the enabled configuration
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
	uint8 payload[TPL_CAN_FD_FRAME_MAXIMUM_PAYLOAD_SIZE];
	int i;
	Can_IdType id_without_flags, id_flags;

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
			// Make sure the payload size is compatible with CAN-FD
			pointer_can_pdu = (Can_PduType *) pdu_info.SduDataPtr;
			if (pointer_can_pdu->length > TPL_CAN_FD_FRAME_MAXIMUM_PAYLOAD_SIZE)
				continue;

			// Increment the CAN ID and wrap to 0 if the highest ID was received
			id_flags = pointer_can_pdu->id & TPL_CAN_ID_TYPE_MASK;
			if ((id_flags == TPL_CAN_ID_TYPE_STANDARD) || (id_flags == TPL_CAN_ID_TYPE_FD_STANDARD))
			{
				id_without_flags = pointer_can_pdu->id & TPL_CAN_ID_STANDARD_MASK;
				if (id_without_flags >= 1023) // 11-bit standard ID
					id_without_flags = 0;
				else
					id_without_flags++;
			}
			else
			{
				id_without_flags = pointer_can_pdu->id & TPL_CAN_ID_EXTENDED_MASK;
				if (id_without_flags >= 536870911) // 29-bit extended ID
					id_without_flags = 0;
				else
					id_without_flags++;
			}
			pointer_can_pdu->id = id_flags | id_without_flags;

			// Increment the payload bytes
			for (i = 0; i < pointer_can_pdu->length; i++)
				pointer_can_pdu->sdu[i]++;

			// Send the incremented frame back
			CanIf_Transmit(0, &pdu_info);
		}
	}
}
