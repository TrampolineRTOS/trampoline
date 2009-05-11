/**
 * @file Std_Types.h
 *
 * @section desc File description
 *
 * Standard Types for all AUTOSAR Modules
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
#ifndef STD_TYPES_H
#define STD_TYPES_H

/*****************************************************************************/
/* INCLUSIONS                                                                */
/*****************************************************************************/
#include "Platform_Types.h"
#include "Compiler.h"

/*****************************************************************************/
/* TYPE DEFINITIONS                                                          */
/*****************************************************************************/
typedef uint8 Std_ReturnType;
typedef struct
{
  VAR(uint16, TYPEDEF)  vendorID;
  VAR(uint16, TYPEDEF)  moduleID;
  VAR(uint8, TYPEDEF)   instanceID;
  VAR(uint8, TYPEDEF)   sw_major_version;
  VAR(uint8, TYPEDEF)   sw_minor_version;
  VAR(uint8, TYPEDEF)   sw_patch_version;
} Std_VersionInfoType;

/*****************************************************************************/
/* SYMBOL DEFINITIONS                                                        */
/*****************************************************************************/
#ifndef STATUSTYPE_DEFINED
#define STATUSTYPE_DEFINED
typedef unsigned char StatusType; /* OSEK compliance */
#endif

#ifndef E_OK_DEFINED
#define E_OK_DEFINED
#define E_OK 0x00
#endif

#define E_NOT_OK    0x01

#define STD_HIGH    0x01 /* Physical state 5V or 3.3V */
#define STD_LOW     0x00 /* Physical state 0V */

#define STD_ACTIVE  0x01 /* Logical state active */
#define STD_IDLE    0x00 /* Logical state idle */

#define STD_ON      0x01
#define STD_OFF     0x00

/*****************************************************************************/
/* PUBLISHED INFORMATION                                                     */
/*****************************************************************************/
#define STD_TYPES_VENDOR_ID         48
#define STD_TYPES_AR_MAJOR_VERSION  3
#define STD_TYPES_AR_MINOR_VERSION  0
#define STD_TYPES_AR_PATCH_VERSION  0
#define STD_TYPES_SW_MAJOR_VERSION  1
#define STD_TYPES_SW_MINOR_VERSION  1
#define STD_TYPES_SW_PATCH_VERSION  0

#endif /* STD_TYPES_H */

