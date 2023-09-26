/**
 * @file can_demo.c
 *
 * @section desc File description
 *
 * Test most of the CAN and CAN-FD stack functions using the POSIX virtual
 * environment and a stub driver.
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
#include <stdio.h>
#include <string.h>
#include <tpl_can_demo_driver.h>
#include <tpl_os.h>

int main(void)
{
	// Statically list the configuration of each CAN controller used in the
	// application
	static tpl_can_controller_config_t can_controllers_config[] =
	{
		// First controller will use CAN 2.0
		{
			&can_demo_driver_controller_1,
			CAN_PROTOCOL_VERSION_CLASSIC,
			CAN_BAUD_RATE_250_KBPS,
			CAN_BAUD_RATE_250_KBPS // This value is ignored for classic CAN
		},
		// Second controller will use CAN FD with bit rate switch
		{
			&can_demo_driver_controller_2,
			CAN_PROTOCOL_VERSION_FD,
			CAN_BAUD_RATE_1_MBPS,
			CAN_BAUD_RATE_5_MBPS
		}
	};
	static Can_ConfigType can_config_type =
	{
		can_controllers_config,
		sizeof(can_controllers_config) / sizeof(can_controllers_config[0])
	};
	int ret;

	printf("Initializing all requested controllers...\r\n");
	ret = Can_Init(&can_config_type);
	if (ret)
	{
		printf("[%s:%d] Error : Can_Init() failed (%d).\r\n", __func__, __LINE__, ret);
		return -1;
	}

	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(can_task)
{
	Std_ReturnType ret;
	uint8 payload[64];
	Can_PduType can_pdu, *pointer_can_pdu;
	PduInfoType pdu_info;
	int i;

	printf("Transmitting a CAN 2.0 frame with standard ID...\r\n");
	can_pdu.id = 0x123 | TPL_CAN_ID_TYPE_STANDARD;
	strcpy((char *) payload, "Ciao !");
	can_pdu.length = strlen((char *) payload);
	can_pdu.sdu = payload;
	pdu_info.SduDataPtr = (uint8 *) &can_pdu;
	pdu_info.SduLength = sizeof(can_pdu);
	ret = CanIf_Transmit(0, &pdu_info);
	if (ret)
		printf("[%s:%d] Error : failed to transmit the frame (%d).\r\n", __func__, __LINE__, ret);
	printf("Transmission succeeded.\r\n");

	printf("Waiting for a CAN 2.0 frame with standard ID...\r\n");
	ret = CanIf_ReadRxPduData(0, &pdu_info);
	if (ret)
		printf("No frame is available.\r\n");
	else
	{
		printf("A frame has been received.\r\n");

		pointer_can_pdu = (Can_PduType *) pdu_info.SduDataPtr;
		printf("ID = 0x%X, flags = 0x%02X, length = %d, payload = ",
			pointer_can_pdu->id & TPL_CAN_ID_MASK,
			TPL_CAN_ID_TYPE_GET(pointer_can_pdu->id),
			pointer_can_pdu->length);
		for (i = 0; i < pointer_can_pdu->length; i++)
			printf("0x%02X ", pointer_can_pdu->sdu[i]);
		printf("\r\n");
	}

	printf("Transmitting a CAN-FD frame with extended ID...\r\n");
	can_pdu.id = 0xABCD123 | TPL_CAN_ID_TYPE_FD_EXTENDED;
	strcpy((char *) payload, "This is a longer string.");
	can_pdu.length = strlen((char *) payload); // The FD length will be automatically adapted by the driver
	can_pdu.sdu = payload;
	pdu_info.SduDataPtr = (uint8 *) &can_pdu;
	pdu_info.SduLength = sizeof(can_pdu);
	ret = CanIf_Transmit(1, &pdu_info);
	if (ret)
		printf("[%s:%d] Error : failed to transmit the frame (%d).\r\n", __func__, __LINE__, ret);
	printf("Transmission succeeded.\r\n");

	printf("Waiting for a CAN-FD frame with extended ID...\r\n");
	ret = CanIf_ReadRxPduData(1, &pdu_info);
	if (ret)
		printf("No frame is available.\r\n");
	else
	{
		printf("A frame has been received.\r\n");

		pointer_can_pdu = (Can_PduType *) pdu_info.SduDataPtr;
		printf("ID = 0x%X, flags = 0x%02X, length = %d, payload = ",
			pointer_can_pdu->id & TPL_CAN_ID_MASK,
			TPL_CAN_ID_TYPE_GET(pointer_can_pdu->id),
			pointer_can_pdu->length);
		for (i = 0; i < pointer_can_pdu->length; i++)
			printf("0x%02X ", pointer_can_pdu->sdu[i]);
		printf("\r\n");
	}

	printf("\r\nEnd of the CAN demo. Press 'q' to exit.\r\n");

	TerminateTask();
}
