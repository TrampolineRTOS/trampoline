/**
 * @file ComStack_Types.h
 *
 * @section desc File description
 *
 * This implementation is based on AUTOSAR CAN Driver R22-11, see
 * https://www.autosar.org/fileadmin/standards/R22-11/CP/AUTOSAR_SWS_CommunicationStackTypes.pdf
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
#ifndef COM_STACK_TYPES_H
#define COM_STACK_TYPES_H

#include <tpl_os_types.h>

/**
 * @typedef PduIdType
 *
 * Variables of this type serve as a unique identifier of a PDU within a
 * software module or a set thereof, and also for interaction of two software
 * modules where the PduId of the corresponding target module is being used for
 * referencing.
 */
typedef uint8 PduIdType;

/**
 * @typedef PduLengthType
 *
 * Variables of this type serve as length information of a PDU. The length
 * information is provided in number of bytes.
 */
typedef uint32 PduLengthType;

/**
 * @typedef PduInfoType
 *
 * Variables of this type shall be used to store the basic information about a
 * PDU of any type, namely a pointer variable pointing to its SDU (payload), a
 * pointer to Meta Data of the PDU, and the corresponding length of the SDU in
 * bytes.
 */
typedef struct
{
	uint8 *SduDataPtr;
	uint8 *MetaDataPtr;
	PduLengthType SduLength;
} PduInfoType;

#endif
