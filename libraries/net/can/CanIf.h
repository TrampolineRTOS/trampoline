/**
 * @file CanIf.h
 *
 * @section desc File description
 *
 * This implementation is based on AUTOSAR CAN Driver R22-11, see
 * https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_CANInterface.pdf
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
#ifndef CAN_IF_H
#define CAN_IF_H

#include <ComStack_Types.h>
#include <tpl_os_types.h>

/**
 * This service initializes internal and external interfaces of the CAN
 * interfaces for the further processing.
 * @note This function takes a parameter in the AUTOSAR specs, but there
 * is currently no parameter here because the function does nothing.
 */
void CanIf_Init(void);

/**
 * This service shall set the baud rate configuration of the CAN controller.
 * Depending on necessary baud rate modifications the controller might have to
 * reset.
 *
 * @param ControllerId Abstract CanIf ControllerId which is assigned to a CAN
 * controller, whose baud rate shall be set.
 * Here it is the index of the controller in the controllers list provided to
 * Can_Init().
 * @param BaudRateConfigID References a baud rate configuration by ID.
 *
 * @retval E_OK Service request accepted, setting of (new) baud rate started.
 * @retval E_NOT_OK Service request not accepted.
 */
Std_ReturnType CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID);

/**
 * Requests transmission of a PDU.
 *
 * @param TxPduId Identifier of the PDU to be transmitted.
 * Here it is the index of the controller in the controllers list provided to
 * Can_Init().
 * @param PduInfoPtr Length of and pointer to the PDU data and pointer to
 * MetaData.
 *
 * @retval E_OK Transmit request has been accepted.
 * @retval E_NOT_OK Transmit request has not been accepted.
 */
Std_ReturnType CanIf_Transmit(PduIdType TxPduId, const PduInfoType *PduInfoPtr);

/**
 * This service provides the Data Length and the received data of the requested
 * CanIfRxSduId to the calling upper layer.
 *
 * @param CanIfRxSduId Receive L-SDU handle specifying the corresponding CAN
 * L-SDU ID and implicitly the CAN Driver instance as well as the corresponding
 * CAN controller device.
 * @param CanIfRxInfoPtr Contains the length (SduLength) of the received PDU,
 * a pointer to a buffer (SduDataPtr) containing the PDU, and the MetaData
 * related to this PDU.
 *
 * @retval E_OK Request for L-SDU data has been accepted.
 * @retval E_NOT_OK No valid data has been received.
 */
Std_ReturnType CanIf_ReadRxPduData(PduIdType CanIfRxSduId, PduInfoType *CanIfRxInfoPtr);

/**
 * Ease the filling of a PduInfoType struct from the content of a Can_PduType
 * struct, and also prepares the Can_PduType content.
 * This way, it is faster to prepare a CAN frame to be sent with the
 * CanIf_Transmit() function.
 *
 * @param can_pdu A non-initialized CAN PDU structure, it will be filled by this
 * function.
 * @param pdu_info A non-initialized generic PDU info structure, it will also
 * be filled by this function.
 * @param id_and_flags The CAN ID (standard or extended) ORed with the frame
 * type flag (use a constant from TPL_CAN_ID_TYPE_xx).
 * @param payload A pointer to the buffer already containing the frame payload.
 * @param payload_length The payload length in bytes. The length will be
 * automatically rounded by the CAN stack if it is of CAN-FD format and should
 * be adjusted to an available Data Length Code (@see
 * tpl_can_get_dlc_from_length).
 */
void tpl_can_fill_pdu_info(Can_PduType *can_pdu, PduInfoType *pdu_info, Can_IdType id_and_flags, void *payload, uint32 payload_length);

#endif
