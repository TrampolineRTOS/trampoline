/**
 * @file Can_GeneralTypes.h
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
#ifndef CAN_GENERAL_TYPES_H
#define CAN_GENERAL_TYPES_H

#include <ComStack_Types.h>
#include <tpl_os.h>

#define TPL_CAN_ID_TYPE_STANDARD (0x00U << 30)
#define TPL_CAN_ID_TYPE_FD_STANDARD (0x01U << 30)
#define TPL_CAN_ID_TYPE_EXTENDED (0x02U << 30)
#define TPL_CAN_ID_TYPE_FD_EXTENDED (0x03U << 30)
#define TPL_CAN_ID_TYPE_MASK (0x03U << 30)
#define TPL_CAN_ID_TYPE_GET(id) ((id & TPL_CAN_ID_TYPE_MASK) >> 30)
#define TPL_CAN_ID_STANDARD_MASK (0x3FFU)
#define TPL_CAN_ID_EXTENDED_MASK (0x3FFFFFFFU)

#define TPL_CAN_CLASSIC_FRAME_MAXIMUM_PAYLOAD_SIZE (8)
#define TPL_CAN_FD_FRAME_MAXIMUM_PAYLOAD_SIZE (64)

/**
 * @typedef Can_IdType
 *
 * Represents the identifier of an L-PDU. The two most significant bits specify
 * the frame type:
 * 00: CAN message with standard CAN ID,
 * 01: CAN FD frame with standard CAN ID,
 * 10: CAN message with extended CAN ID,
 * 11: CAN FD frame with extended CAN ID.
 *
 * @see TPL_CAN_ID_TYPE_STANDARD and related constants to use for the frame
 * type.
 */
typedef uint32 Can_IdType;

/**
 * @typedef Can_PduType
 *
 * This type unites PduId (swPduHandle), SduLength (length), SduData (sdu)
 * and CanId (id) for any CAN L-SDU.
 */
typedef struct
{
	PduIdType swPduHandle;
	uint8 length;
	Can_IdType id;
	uint8 *sdu;
} Can_PduType;

/**
 * @typedef CanControllerFdBaudrateConfig
 *
 * This optional container contains bit timing related configuration parameters of the
 * CAN controller(s) for payload and CRC of a CAN FD frame. If this container exists
 * the controller supports CAN FD frames.
 */
typedef struct
{
	uint32 CanControllerFdBaudRate; // Should be of type EcucFloatParamDef, but we avoid floating numbers
	uint32 CanControllerPropSeg;
	uint32 CanControllerSeg1;
	uint32 CanControllerSeg2;
	uint32 CanControllerSspOffset;
	uint32 CanControllerSyncJumpWidth;
	tpl_bool CanControllerTxBitRateSwitch;
} CanControllerFdBaudrateConfig;

/**
 * @typedef CanControllerBaudrateConfig
 *
 * This container contains bit timing related configuration parameters of
 * the CAN controller(s).
 *
 * @note Base types have been used here instead of the ECUxxx types to avoid
 * duplication.
 */
typedef struct
{
	uint32 CanControllerBaudRate; // Should be of type EcucFloatParamDef, but we avoid floating numbers
	uint32 CanControllerBaudRateConfigID;
	uint32 CanControllerPropSeg;
	uint32 CanControllerSeg1;
	uint32 CanControllerSeg2;
	uint32 CanControllerSyncJumpWidth;
	tpl_bool use_fd_configuration; // If this value is true, the can_fd_config must be taken into account
	CanControllerFdBaudrateConfig can_fd_config;
} CanControllerBaudrateConfig;

struct tpl_can_controller_config_t;
/**
 * @struct tpl_can_controller_t
 *
 * Contains all details and callback functions to directly interact with a
 * CAN controller hardware.
 */
struct tpl_can_controller_t
{
	uint32 base_address;
	int (*init)(struct tpl_can_controller_config_t *config);
	int (*set_baudrate)(struct tpl_can_controller_t *ctrl, CanControllerBaudrateConfig *baud_rate_config);
	Std_ReturnType (*transmit)(struct tpl_can_controller_t *ctrl, const Can_PduType *pdu_info);
	Std_ReturnType (*receive)(struct tpl_can_controller_t *ctrl, Can_PduType *pdu_info);
	int (*is_data_available)(struct tpl_can_controller_t *ctrl);
	void *priv; // Store a custom structure for the driver internal use
};
typedef struct tpl_can_controller_t tpl_can_controller_t;

/**
 * @struct tpl_can_controller_config_t
 *
 * Associate a CAN controller and its configuration for the current application.
 */
struct tpl_can_controller_config_t
{
	tpl_can_controller_t *controller;
	CanControllerBaudrateConfig baud_rate_config;
};
typedef struct tpl_can_controller_config_t tpl_can_controller_config_t;

/**
 * @typedef Can_HwHandleType
 *
 * Represents the hardware object handles of a CAN hardware unit.
 */
typedef tpl_can_controller_t *Can_HwHandleType;

#endif
