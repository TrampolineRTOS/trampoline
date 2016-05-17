/**
 * @file Platform_Types.h
 *
 * @section descr File description
 *
 * Trampoline AUTOSAR platform dependant types.
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

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#include "tpl_os_std_types.h"

/******************************************************************************/
/* DEFINITION OF CONSTANTS                                                    */
/******************************************************************************/
#ifndef TRUE
#define TRUE    ((boolean) 1)
#endif
#ifndef FALSE
#define FALSE   ((boolean) 0)
#endif

#define CPU_TYPE_8      8
#define CPU_TYPE_16     16
#define CPU_TYPE_32     32
#define MSB_FIRST       0
#define LSB_FIRST       1
#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST  1

/*
 * target : posix
 * compiler : gcc 4
 */
#define CPU_TYPE        CPU_TYPE_32
#define CPU_BIT_ORDER   LSB_FIRST
#ifdef i386
#define CPU_BYTE_ORDER  LOW_BYTE_FIRST
#else
#define CPU_BYTE_ORDER  HIGH_BYTE_FIRST
#endif

typedef unsigned char   boolean;
typedef s8              sint8;
typedef u8              uint8;
typedef s16             sint16;
typedef u16             uint16;
typedef s32             sint32;
typedef u32             uint32;
typedef s8              sint8_least;
typedef u8              uint8_least;
typedef s16             sint16_least;
typedef u16             uint16_least;
typedef s32             sint32_least;
typedef u32             uint32_least;
typedef float           float32;
typedef double          float64;

/*#define PLATFORM_VENDOR_ID ?? (Vendor ID of the dedicated implementation of
                            this module according to the AUTOSAR vendor list) */
#define PLATFORM_AR_MAJOR_VERSION 1
#define PLATFORM_AR_MINOR_VERSION 0
#define PLATFORM_AR_PATCH_VERSION 0
#define PLATFORM_SW_MAJOR_VERSION 1
#define PLATFORM_SW_MINOR_VERSION 0
#define PLATFORM_SW_PATCH_VERSION 0

#endif /* PLATFORM_TYPES_H */
