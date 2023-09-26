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

#define TPL_CAN_ID_TYPE_STANDARD (0x00 << 30)
#define TPL_CAN_ID_TYPE_FD_STANDARD (0x01 << 30)
#define TPL_CAN_ID_TYPE_EXTENDED (0x02 << 30)
#define TPL_CAN_ID_TYPE_FD_EXTENDED (0x03 << 30)
#define TPL_CAN_ID_TYPE_MASK (0x03 << 30)
#define TPL_CAN_ID_TYPE_GET(id) ((id & TPL_CAN_ID_TYPE_MASK) >> 30)
#define TPL_CAN_ID_MASK (0x3FFFFFFF)

/**
 * @note This will be replaced by a table provided to Can_Init() with
 * several configurations mentionning both baud rates for CAN 2.0 and CAN FD.
 */
typedef enum
{
	CAN_BAUD_RATE_50_KBPS,
	CAN_BAUD_RATE_100_KBPS,
	CAN_BAUD_RATE_125_KBPS,
	CAN_BAUD_RATE_250_KBPS,
	CAN_BAUD_RATE_500_KBPS,
	CAN_BAUD_RATE_1_MBPS,
	CAN_BAUD_RATE_2_MBPS,
	CAN_BAUD_RATE_5_MBPS,
	CAN_BAUD_RATE_COUNT
} tpl_can_baud_rate_t;

/**
 * @typedef tpl_can_protocol_version_t
 *
 * Select the version of the CAN protocol to operate for a specific CAN
 * controller.
 */
typedef enum
{
	CAN_PROTOCOL_VERSION_CLASSIC,
	CAN_PROTOCOL_VERSION_FD,
	CAN_PROTOCOL_VERSION_XL
} tpl_can_protocol_version_t;

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
	int (*set_baudrate)(struct tpl_can_controller_t *ctrl, tpl_can_baud_rate_t baud_rate);
	Std_ReturnType (*transmit)(struct tpl_can_controller_t *ctrl, const Can_PduType *pdu_info);
	Std_ReturnType (*receive)(struct tpl_can_controller_t *ctrl, Can_PduType *pdu_info);
	int (*is_data_available)(struct tpl_can_controller_t *ctrl);
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
	tpl_can_protocol_version_t protocol_version;
	tpl_can_baud_rate_t nominal_baud_rate; // The classic CAN baud rate, or the arbitration baud rate when in CAN FD mode
	tpl_can_baud_rate_t fd_data_baud_rate; // The data baud rate for CAN-FD when bit rate switch is set, this value is ignored for classic CAN
};
typedef struct tpl_can_controller_config_t tpl_can_controller_config_t;

/**
 * @typedef Can_HwHandleType
 *
 * Represents the hardware object handles of a CAN hardware unit.
 */
typedef tpl_can_controller_t *Can_HwHandleType;

#endif
