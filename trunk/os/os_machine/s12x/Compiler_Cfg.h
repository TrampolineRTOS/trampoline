/*==============================================================================
**                             AYRTON TECHNOLOGY
**                      Proprietary - Copyright (C) 2007
**------------------------------------------------------------------------------
** Customer          : Internal
** Project           : O4A (06-01-BEE-055)
**------------------------------------------------------------------------------
** Supported MCUs    : Codewarrior compiler for S12X
**------------------------------------------------------------------------------
** File name         : Compiler_Cfg.h
**
** Module name       : All AUTOSAR Modules
**
** Summary: Compiler abstraction for all AUTOSAR Modules
**
**= History ====================================================================
** 00.01  N. Cornet	04/19/07
** - Creation
==============================================================================*/

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/******************************************************************************/
/* DEFINITION OF MACROS                                                       */
/******************************************************************************/

/******************************************************************************/
/* OS                                                                       */
/******************************************************************************/
#define OS_CODE              AUTOMATIC
#define OS_CBK_CODE          __near
#define OS_VAR_NOINIT        AUTOMATIC
#define OS_VAR_POWER_ON_INIT AUTOMATIC
#define OS_VAR_FAST          AUTOMATIC
#define OS_VAR               AUTOMATIC
#define OS_CONST             AUTOMATIC
#define OS_APPL_DATA         AUTOMATIC
#define OS_APPL_CONST        AUTOMATIC
#define OS_APPL_CODE         AUTOMATIC

#endif /* COMPILER_CFG_H */

