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
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 */

#ifndef TPL_OS_STD_TYPES_H
#define TPL_OS_STD_TYPES_H

/**
 * @typedef uint8
 *
 * 8 bits unsigned number
 */
typedef unsigned char   uint8;

/**
 * @typedef sint8
 *
 * 8 bits signed number
 */
typedef signed char     sint8;

/**
 * @typedef uint16
 *
 * 16 bits unsigned number
 */
typedef unsigned short  uint16;

/**
 * @typedef sint16
 *
 * 16 bits signed number
 */
typedef signed short    sint16;

/**
 * @typedef uint32
 *
 * 32 bits unsigned number
 */
typedef unsigned long   uint32;

/**
 * @typedef sint32
 *
 * 32 bits signed number
 */
typedef signed long     sint32;

/**
 * @typedef uint64
 *
 * 64 bits unsigned integer
 */
typedef unsigned long long uint64;

/**
 * @typedef sint64
 *
 * 64 bits signed integer
 */
typedef signed long long sint64;

#endif /* TPL_OS_STD_TYPES_GENERIC_H */

/* End of file tpl_os_std_types.h */
