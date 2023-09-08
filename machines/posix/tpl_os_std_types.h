/**
 * @file tpl_os_std_types.h
 *
 * @section descr File description
 *
 * Trampoline standard types. Here for MISRA rule 13 compliance
 * and for platform specific type definition
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_STD_TYPES_H
#define TPL_OS_STD_TYPES_H

#include <stdint.h>

/**
 * @typedef uint8
 *
 * 8 bits unsigned number
 */
typedef uint8_t uint8;

/**
 * @typedef sint8
 *
 * 8 bits signed number
 */
typedef int8_t sint8;

/**
 * @typedef uint16
 *
 * 16 bits unsigned number
 */
typedef uint16_t uint16;

/**
 * @typedef sint16
 *
 * 16 bits signed number
 */
typedef int16_t sint16;

/**
 * @typedef uint32
 *
 * 32 bits unsigned number
 */
typedef uint32_t uint32;

/**
 * @typedef sint32
 *
 * 32 bits signed number
 */
typedef int32_t sint32;

#endif /* TPL_OS_STD_TYPES_H */

/* End of file tpl_os_std_types.h */
