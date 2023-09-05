#include <Can.h>
#include <CanIf.h>
#include <stdio.h>
#include <string.h>
#include <tpl_can_demo_driver.h>
#include <tpl_os.h>

int main(void)
{
	// Statically list the CAN controllers to use in the application
	static tpl_can_controller_t *can_controllers[] =
	{
		&can_demo_driver_controller_1,
		&can_demo_driver_controller_2,
		NULL
	};
	static Can_ConfigType can_config_type =
	{
		can_controllers
	};
	int ret;

	printf("Initializing all requested controllers...\r\n");
	ret = Can_Init(&can_config_type);
	if (ret)
	{
		printf("[%s:%d] Error : Can_Init() failed (%d).\r\n", __func__, __LINE__, ret);
		return -1;
	}

	printf("Setting first controller baud rate...\r\n");
	ret = CanIf_SetBaudrate(0, CAN_BAUD_RATE_500_KBPS);
	if (ret)
	{
		printf("[%s:%d] Error : CanIf_SetBaudrate() failed (%d).\r\n", __func__, __LINE__, ret);
		return -1;
	}

	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(can_task)
{
	Std_ReturnType ret;
	uint8 payload[8];
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
		printf("ID = 0x%X, length = %d, payload = ", pointer_can_pdu->id, pointer_can_pdu->length);
		for (i = 0; i < pointer_can_pdu->length; i++)
			printf("0x%02X ", pointer_can_pdu->sdu[i]);
		printf("\r\n");
	}

	TerminateTask();
}
