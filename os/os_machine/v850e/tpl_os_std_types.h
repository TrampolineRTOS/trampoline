/*==============================================================================
** Trampoline OS
**
** Trampoline is copyright (c) IRCCyN 2005+
** Copyright ESEO for function and data structures documentation
** Trampoline is protected by the French intellectual property law.
**
** This software is distributed under the Lesser GNU Public Licence
**------------------------------------------------------------------------------
** Supported MCUs       : NEC V850E
** Supported Compilers  : GHS Multi
**------------------------------------------------------------------------------
** File name         : tpl_os_std_types.h
**
** Module name       : OS
**
** Summary: standard types
**              .
**= History ===================================================================
** 01.04  J.Monsimier 03/12/07
**  - creation
=============================================================================*/

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
