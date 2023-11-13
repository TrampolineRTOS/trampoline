/**
 * @file tpl_can_core.c
 *
 * @section desc File description
 *
 * Implements the AUTOSAR CAN Driver and CAN Interface layers.
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
#include <tpl_os_definitions.h>

static tpl_can_controller_config_t *controller_configs;
static unsigned int controllers_count;

int Can_Init(const Can_ConfigType *Config)
{
	int ret;
	unsigned int i;
	tpl_can_controller_config_t *config;
	tpl_can_controller_t *controller;

	controller_configs = Config->configs;
	controllers_count = Config->configs_count;

	for (i = 0; i < controllers_count; i++)
	{
		config = &controller_configs[i];
		controller = config->controller;

		// Make sure all callback functions are provided (check only once here to avoid checking later at every function call)
		if (!controller->init)
			return -5;
		if (!controller->set_baudrate)
			return -5;
		if (!controller->transmit)
			return -5;
		if (!controller->receive)
			return -5;
		if (!controller->is_data_available)
			return -5;

		ret = controller->init(config);
		if (ret)
			return ret;
	}

	return 0;
}

Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudRateConfigID)
{
	tpl_can_controller_t *controller;
	CanControllerBaudrateConfig *baud_rate_config;
	unsigned int i;

	// Make sure the controller has been registered and initialized
	if (Controller >= controllers_count)
		return E_NOT_OK;
	controller = controller_configs[Controller].controller;

	// Look for the baud rate configuration matching the requested ID
	for (i = 0; i < controllers_count; i++)
	{
		baud_rate_config = &controller_configs[i].baud_rate_config;
		if (baud_rate_config->CanControllerBaudRateConfigID == BaudRateConfigID)
			break;
	}
	// Was a matching baud rate configuration found ?
	if (i == controllers_count)
		return E_NOT_OK;

	if (controller->set_baudrate(controller, baud_rate_config))
		return E_NOT_OK;
	return E_OK;
}

Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo)
{
	tpl_can_controller_t *controller = Hth;
	Std_ReturnType ret = E_NOT_OK;

	if (controller == NULL)
		return E_NOT_OK;
	if (PduInfo == NULL)
		return E_NOT_OK;

	// TODO check if CAN FD enabled for CAN FD frame, otherwise send as CAN classic if SDU < 8 (see parag 7.12 "CAN FD Support" in AUTOSAR_SWS_CANDriver R22-11)

	// No need to check for the transmit callback presence, this has already been done by Can_Init()
	ret = controller->transmit(controller, PduInfo);

	return ret;
}

void CanIf_Init(void) {}

Std_ReturnType CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID)
{
	// The ControllerId checking will be done by Can_SetBaudrate(), so call
	// this function directly
	return Can_SetBaudrate(ControllerId, BaudRateConfigID);
}

Std_ReturnType CanIf_Transmit(PduIdType TxPduId, const PduInfoType *PduInfoPtr)
{
	tpl_can_controller_t *controller;
	Can_PduType *can_pdu;

	// Make sure the controller has been registered and initialized
	if (TxPduId >= controllers_count)
		return E_NOT_OK;
	controller = controller_configs[TxPduId].controller;

	can_pdu = (Can_PduType *) PduInfoPtr->SduDataPtr;
	return Can_Write(controller, can_pdu);
}

Std_ReturnType CanIf_ReadRxPduData(PduIdType CanIfRxSduId, PduInfoType *CanIfRxInfoPtr)
{
	tpl_can_controller_t *controller;
	Can_PduType *can_pdu;

	// Make sure the controller has been registered and initialized
	if (CanIfRxSduId >= controllers_count)
		return E_NOT_OK;
	controller = controller_configs[CanIfRxSduId].controller;

	if (!controller->is_data_available(controller))
		return E_NOT_OK;

	can_pdu = (Can_PduType *) CanIfRxInfoPtr->SduDataPtr;
	return controller->receive(controller, can_pdu);
}

uint32 tpl_can_get_dlc_from_length(uint32 length, uint32 *adjusted_length)
{
	struct length_code_t
	{
		uint32 dlc;
		uint32 adjusted_length;
	};
	static struct length_code_t length_code_table[TPL_CAN_FD_FRAME_MAXIMUM_PAYLOAD_SIZE + 1] =
	{
		{ 0x0,  0 }, { 0x1,  1 }, { 0x2,  2 }, { 0x3,  3 }, { 0x4,  4 }, { 0x5,  5 }, { 0x6,  6 }, { 0x7,  7 },
		{ 0x8,  8 }, { 0x9, 12 }, { 0x9, 12 }, { 0x9, 12 }, { 0x9, 12 }, { 0xA, 16 }, { 0xA, 16 }, { 0xA, 16 },
		{ 0xA, 16 }, { 0xB, 20 }, { 0xB, 20 }, { 0xB, 20 }, { 0xB, 20 }, { 0xC, 24 }, { 0xC, 24 }, { 0xC, 24 },
		{ 0xC, 24 }, { 0xD, 32 }, { 0xD, 32 }, { 0xD, 32 }, { 0xD, 32 }, { 0xD, 32 }, { 0xD, 32 }, { 0xD, 32 },
		{ 0xD, 32 }, { 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 },
		{ 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 }, { 0xE, 48 },
		{ 0xE, 48 }, { 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 },
		{ 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 }, { 0xF, 64 },
		{ 0xF, 64 }
	};

	if (length > TPL_CAN_FD_FRAME_MAXIMUM_PAYLOAD_SIZE)
		return 0;

	if (adjusted_length != NULL)
		*adjusted_length = length_code_table[length].adjusted_length;

	return length_code_table[length].dlc;
}

uint32 tpl_can_get_length_from_dlc(uint32 dlc)
{
	static uint32 length[16] =
	{
		 0,  1,  2,  3,  4,  5,  6,  7,
		 8, 12, 16, 20, 24, 32, 48, 64
	};

	if (dlc > 0x0F)
		return 0;

	return length[dlc];
}

void tpl_can_fill_pdu_info(Can_PduType *can_pdu, PduInfoType *pdu_info, Can_IdType id_and_flags, void *payload, uint32 payload_length)
{
	can_pdu->id = id_and_flags;
	can_pdu->sdu = payload;
	can_pdu->length = (uint8) payload_length;

	pdu_info->SduDataPtr = (uint8 *) can_pdu;
	pdu_info->SduLength = sizeof(Can_PduType) + payload_length;
}
