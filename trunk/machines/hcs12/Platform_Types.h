/**
 * @file Platform_Types.h
 *
 * @section desc File description
 *
 * Platform specific types for all AUTOSAR modules
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
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
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/*****************************************************************************/
/* DEFINITION OF CONSTANTS                                                   */
/*****************************************************************************/
#ifndef TRUE
#define TRUE ((boolean) 1)
#endif
#ifndef FALSE
#define FALSE ((boolean) 0)
#endif

#define CPU_TYPE_8      8
#define CPU_TYPE_16     16
#define CPU_TYPE_32     32
#define MSB_FIRST       0
#define LSB_FIRST       1
#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST  1

/*************************************
**
** TARGET : S12X
**
** Compiler : Codewarrior
**
*************************************/
#define CPU_TYPE        CPU_TYPE_16
#define CPU_BIT_ORDER   LSB_FIRST
#define CPU_BYTE_ORDER  HIGH_BYTE_FIRST

/*****************************************************************************/
/* DEFINITION OF TYPES                                                       */
/*****************************************************************************/
/*************************************
**
** TARGET : S12X
**
** Compiler : Codewarrior
**
*************************************/
typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed long sint32;
typedef unsigned long uint32;
typedef signed char sint8_least;
typedef unsigned char uint8_least;
typedef signed short sint16_least;
typedef unsigned short uint16_least;
typedef signed long sint32_least;
typedef unsigned long uint32_least;
typedef float float32;
typedef double float64;

/*****************************************************************************/
/* PUBLISHED INFORMATION                                                     */
/*****************************************************************************/
#define PLATFORM_VENDOR_ID        48
#define PLATFORM_AR_MAJOR_VERSION 3
#define PLATFORM_AR_MINOR_VERSION 0
#define PLATFORM_AR_PATCH_VERSION 0
#define PLATFORM_SW_MAJOR_VERSION 1
#define PLATFORM_SW_MINOR_VERSION 0
#define PLATFORM_SW_PATCH_VERSION 0

#endif /* PLATFORM_TYPES_H */

