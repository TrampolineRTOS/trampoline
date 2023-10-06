/**
 * @file Can.h
 *
 * @section desc File description
 *
 * This implementation is based on AUTOSAR CAN Driver R22-11, see
 * https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_CANDriver.pdf
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
#ifndef CAN_H
#define CAN_H

#include <Can_GeneralTypes.h>
#include <ComStack_Types.h>

/**
 * @typedef Can_ConfigType
 *
 * Contain a static list of all controllers to configure.
 * The provided variable must be reachable during all the application lifetime.
 */
typedef struct
{
	tpl_can_controller_config_t *configs;
	unsigned int configs_count;
} Can_ConfigType;

/**
 * This function initializes the module.
 *
 * @param Config Pointer to driver configuration. All the pointed memory must
 * be reachable during all the application lifetime.
 *
 * @retval 0 if the function succeeded.
 * @retval -5 if a driver callback function is missing.
 *
 * @note Can_Init() return type is void in AUTOSAR standard. Returning void here
 * would involve to implement higher AUTOSAR CAN stack layers, which is too
 * complex for the current usage.
 */
int Can_Init(const Can_ConfigType *Config);

/**
 * This service shall set the baud rate configuration of the CAN controller.
 * Depending on necessary baud rate modifications the controller might have to
 * reset.
 *
 * @param Controller CAN controller, whose baud rate shall be set. Here it is
 * the index of the controller in the controllers list provided to Can_Init().
 * @param BaudRateConfigID References a baud rate configuration by ID.
 *
 * @retval E_OK Service request accepted, setting of (new) baud rate started.
 * @retval E_NOT_OK Service request not accepted.
 */
Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudRateConfigID);

/**
 * This function is called by CanIf to pass a CAN message to CanDrv for
 * transmission.
 *
 * @param Hth Information which HW-transmit handle shall be used for transmit.
 * Implicitly this is also the information about the controller to use because
 * the Hth numbers are unique inside one hardware unit.
 * Here it is the index of the controller in the controllers list provided to
 * Can_Init().
 * @param PduInfo Pointer to SDU user memory, Data Length and Identifier.
 *
 * @retval E_OK Write command has been accepted.
 * @retval E_NOT_OK Development error occurred.
 * @retval CAN_BUSY No TX hardware buffer available or pre-emptive call of
 * Can_Write that can't be implemented re-entrant (see Can_ReturnType).
 */
Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo);

/**
 * Convert a CAN-FD payload size in bytes to the corresponding CAN Data Length
 * Code.
 *
 * @param length The payload length in bytes.
 * @param adjusted_length If not NULL, contain on output the payload adjusted
 * length in bytes.
 *
 * @retval 0 if the provided payload length exceeds 64 bytes,
 * @return The DLC code if the provided payload length is valid.
 *
 * @note See https://www.can-cia.org/can-knowledge/can/can-fd for more details.
 */
uint32 tpl_can_get_dlc_from_length(uint32 length, uint32 *adjusted_length);

/**
 * Convert a CAN or CAN-FD DLC code to the corresponding payload length in
 * bytes.
 *
 * @param dlc The CAN or CAN-FD frame DLC field value.
 *
 * @retval 0 if the provided DLC value exceeds 0x0F,
 * @return The payload length in bytes if the provided DLC value is valid.
 */
uint32 tpl_can_get_length_from_dlc(uint32 dlc);

#endif
