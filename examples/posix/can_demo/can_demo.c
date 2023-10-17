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
	// Statically list the configuration of each CAN controller used in the application
	static tpl_can_controller_config_t can_controllers_config[] =
	{
		// First controller will use CAN 2.0 (values are fake)
		{
			&can_demo_driver_controller_1,
			{
				.CanControllerBaudRate = 250,
				.CanControllerBaudRateConfigID = 0,
				.CanControllerPropSeg = 0,
				.CanControllerSeg1 = 11,
				.CanControllerSeg2 = 4,
				.CanControllerSyncJumpWidth = 4,
				.use_fd_configuration = FALSE
			},
		},
		// Second controller will use CAN FD with bit rate switch (values are fake)
		{
			&can_demo_driver_controller_2,
			{
				.CanControllerBaudRate = 1000,
				.CanControllerBaudRateConfigID = 1,
				.CanControllerPropSeg = 0,
				.CanControllerSeg1 = 31,
				.CanControllerSeg2 = 8,
				.CanControllerSyncJumpWidth = 8,
				.use_fd_configuration = TRUE,
				{
					.CanControllerFdBaudRate = 5000,
					.CanControllerPropSeg = 0,
					.CanControllerSeg1 = 10,
					.CanControllerSeg2 = 5,
					.CanControllerSspOffset = 15,
					.CanControllerSyncJumpWidth = 5,
					.CanControllerTxBitRateSwitch = TRUE
				},
			},
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
	strcpy((char *) payload, "Ciao !");
	tpl_can_fill_pdu_info(&can_pdu, &pdu_info, 0x123 | TPL_CAN_ID_TYPE_STANDARD, payload, strlen((char *) payload));
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
			pointer_can_pdu->id & TPL_CAN_ID_STANDARD_MASK,
			TPL_CAN_ID_TYPE_GET(pointer_can_pdu->id),
			pointer_can_pdu->length);
		for (i = 0; i < pointer_can_pdu->length; i++)
			printf("0x%02X ", pointer_can_pdu->sdu[i]);
		printf("\r\n");
	}

	printf("Transmitting a CAN-FD frame with extended ID...\r\n");
	strcpy((char *) payload, "This is a longer string.");
	tpl_can_fill_pdu_info(&can_pdu, &pdu_info, 0xABCD123 | TPL_CAN_ID_TYPE_FD_EXTENDED, payload, strlen((char *) payload)); // The FD length will be automatically adapted by the driver
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
			pointer_can_pdu->id & TPL_CAN_ID_EXTENDED_MASK,
			TPL_CAN_ID_TYPE_GET(pointer_can_pdu->id),
			pointer_can_pdu->length);
		for (i = 0; i < pointer_can_pdu->length; i++)
			printf("0x%02X ", pointer_can_pdu->sdu[i]);
		printf("\r\n");
	}

	printf("Setting the controller 0 baud rate with configuration 1...\r\n");
	ret = CanIf_SetBaudrate(0, 1);
	if (ret)
		printf("[%s:%d] Error : CanIf_SetBaudrate() failed (%d).\r\n", __func__, __LINE__, ret);

	printf("Setting the controller 1 baud rate with configuration 0...\r\n");
	ret = CanIf_SetBaudrate(1, 0);
	if (ret)
		printf("[%s:%d] Error : CanIf_SetBaudrate() failed (%d).\r\n", __func__, __LINE__, ret);

	printf("Setting an invalid baud rate configuration for controller 1...\r\n");
	ret = CanIf_SetBaudrate(1, 100);
	if (ret)
		printf("[%s:%d] The baud rate configuration setting failed as expected.\r\n", __func__, __LINE__);
	else
		printf("[%s:%d] Error : CanIf_SetBaudrate() succeeded while it should have not (%d).\r\n", __func__, __LINE__, ret);

	printf("\r\nEnd of the CAN demo. Press 'q' to exit.\r\n");

	TerminateTask();
}
