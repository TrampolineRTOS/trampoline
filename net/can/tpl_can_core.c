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

static tpl_can_controller_t **controllers_list;
static int controllers_count;

int Can_Init(const Can_ConfigType *Config)
{
	int i, ret;
	tpl_can_controller_t **ctrl_list, *ctrl;

	controllers_list = Config->controllers_list;
	controllers_count = 0;
	ctrl_list = controllers_list;
	while ((ctrl = *ctrl_list) != NULL)
	{
		// Make sure all callback functions are provided (check only once here to avoid checking later at every function call)
		if (!ctrl->init)
			return -5;
		if (!ctrl->set_baudrate)
			return -5;
		if (!ctrl->transmit)
			return -5;
		if (!ctrl->receive)
			return -5;
		if (!ctrl->is_data_available)
			return -5;

		ret = ctrl->init(ctrl, NULL);
		if (ret)
			return ret;

		ctrl_list++;
		controllers_count++;
	}

	return 0;
}

Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudRateConfigID)
{
	tpl_can_controller_t *ctrl;

	// Make sure the controller has been registered and initialized
	if (Controller >= controllers_count)
		return E_NOT_OK;
	ctrl = controllers_list[Controller];

	if (ctrl->set_baudrate(ctrl, BaudRateConfigID))
		return E_NOT_OK;
	return E_OK;
}

Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo)
{
	tpl_can_controller_t *ctrl = Hth;
	Std_ReturnType ret = E_NOT_OK;

	if (ctrl == NULL)
		return E_NOT_OK;

	if (ctrl->transmit)
		ret = ctrl->transmit(ctrl, PduInfo);

	return ret;
}

void CanIf_Init(void)
{
	// TODO, maybe flags to enable CAN FD
}

Std_ReturnType CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID)
{
	// The ControllerId checking will be done by Can_SetBaudrate(), so call
	// this function directly
	return Can_SetBaudrate(ControllerId, BaudRateConfigID);
}

Std_ReturnType CanIf_Transmit(PduIdType TxPduId, const PduInfoType *PduInfoPtr)
{
	tpl_can_controller_t *ctrl;
	Can_PduType *can_pdu;

	// Make sure the controller has been registered and initialized
	if (TxPduId >= controllers_count)
		return E_NOT_OK;
	ctrl = controllers_list[TxPduId];

	can_pdu = (Can_PduType *) PduInfoPtr->SduDataPtr;
	return Can_Write(ctrl, can_pdu);
}

Std_ReturnType CanIf_ReadRxPduData(PduIdType CanIfRxSduId, PduInfoType *CanIfRxInfoPtr)
{
	tpl_can_controller_t *ctrl;
	Can_PduType *can_pdu;

	// Make sure the controller has been registered and initialized
	if (CanIfRxSduId >= controllers_count)
		return E_NOT_OK;
	ctrl = controllers_list[CanIfRxSduId];

	if (!ctrl->is_data_available(ctrl))
		return E_NOT_OK;

	can_pdu = (Can_PduType *) CanIfRxInfoPtr->SduDataPtr;
	return ctrl->receive(ctrl, can_pdu);
}
