/**
 * @file tpl_os_std_types.h
 *
 * @section descr File description
 *
 * Trampoline standard types. Here for MISRA rule 13 compliance
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

#include "tpl_app_objects.h"
#include "tpl_compiler.h"

#ifdef WITH_AUTOSAR

#include "Std_Types.h"

/**
 * @typedef u8
 *
 * 8 bits unsigned number
 */
typedef uint8   u8;

/**
 * @typedef s8
 *
 * 8 bits signed number
 */
typedef sint8   s8;

/**
 * @typedef u16
 *
 * 16 bits unsigned number
 */
typedef uint16  u16;

/**
 * @typedef s16
 *
 * 16 bits signed number
 */
typedef sint16  s16;

/**
 * @typedef u32
 *
 * 32 bits unsigned number
 */
typedef uint32  u32;

/**
 * @typedef s32
 *
 * 32 bits signed number
 */
typedef sint32  s32;

#else

/**
 * @typedef u8
 *
 * 8 bits unsigned number
 */
typedef unsigned char   u8;

/**
 * @typedef s8
 *
 * 8 bits signed number
 */
typedef signed char     s8;

/**
 * @typedef u16
 *
 * 16 bits unsigned number
 */
typedef unsigned short  u16;

/**
 * @typedef s16
 *
 * 16 bits signed number
 */
typedef signed short    s16;

/**
 * @typedef u32
 *
 * 32 bits unsigned number
 */
typedef unsigned long   u32;

/**
 * @typedef s32
 *
 * 32 bits signed number
 */
typedef signed long     s32;

#endif /* WITH_AUTOSAR */

#endif /* TPL_OS_STD_TYPES_H */

/* End of file tpl_os_std_types.h */
