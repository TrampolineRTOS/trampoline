/*==============================================================================
** Trampoline OS
**
** Trampoline is copyright (c) IRCCyN 2005+
** Copyright ESEO for function and data structures documentation
** Trampoline is protected by the French intellectual property law.
**
** This software is distributed under the Lesser GNU Public Licence
**-----------------------------------------------------------------------------
** Supported MCUs       : NEC V850E
** Supported Compilers  : GHS Multi
**-----------------------------------------------------------------------------
** File name         : Compiler_Cfg.h
**
** Module name       : All AUTOSAR Modules
**
** Requirement specification : AUTOSAR_SWS_CompilerAbstraction.pdf
**
** Summary: Compiler abstraction for all AUTOSAR Modules
**
**= History ====================================================================
** 01.00  J.Monsimier 19/12/2007
** - Creation
==============================================================================*/

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/******************************************************************************/
/* DEFINITION OF MACROS                                                       */
/******************************************************************************/
/******************************************************************************/
/* STUB                                                                       */
/******************************************************************************/
#define MCU_CODE                AUTOMATIC
#define ECUM_CODE               AUTOMATIC
/******************************************************************************/
/* GPT                                                                        */
/******************************************************************************/
#define GPT_PRIVATE_CODE        AUTOMATIC
#define GPT_PRIVATE_CONST       AUTOMATIC
#define GPT_FAST_DATA           AUTOMATIC
#define GPT_PRIVATE_DATA        AUTOMATIC

#define GPT_PUBLIC_CODE         AUTOMATIC
#define GPT_PUBLIC_CONST        AUTOMATIC

#define GPT_APPL_CODE           AUTOMATIC
#define GPT_APPL_CONST          AUTOMATIC

#define GPT_VAR                 AUTOMATIC
#define GPT_CONST               AUTOMATIC

#define GPT_VAR_NOINIT          AUTOMATIC

#define GPT_VAR_POWER_ON_INIT   AUTOMATIC

#define GPT_APPL_DATA           AUTOMATIC
#define GPT_CONFIG_CONST        AUTOMATIC
#define GPT_CONFIG_DATA         AUTOMATIC

/******************************************************************************/
/* OS                                                                         */
/******************************************************************************/
#define OS_CODE                 AUTOMATIC
#define OS_VAR_NOINIT           AUTOMATIC
#define OS_VAR_POWER_ON_INIT    AUTOMATIC
#define OS_VAR_FAST             AUTOMATIC
#define OS_VAR                  AUTOMATIC
#define OS_CONST                AUTOMATIC
#define OS_APPL_DATA            AUTOMATIC
#define OS_APPL_CONST           AUTOMATIC
#define OS_APPL_CODE            AUTOMATIC

#endif /* COMPILER_CFG_H */

