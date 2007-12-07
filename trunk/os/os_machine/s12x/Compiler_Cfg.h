/*=============================================================================
** Trampoline OS
**
** Trampoline is copyright (c) IRCCyN 2005+
** Copyright ESEO for function and data structures documentation
** Trampoline is protected by the French intellectual property law.
**
** This software is distributed under the Lesser GNU Public Licence
**-----------------------------------------------------------------------------
** Supported MCUs      : Freescale MC9S12XEP100
** Supported Compilers : Code Warrior V4.6
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
** 01.00  N. Cornet 19/04/2007
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
#define MCU_CODE            AUTOMATIC
#define ECUM_CODE           AUTOMATIC
/******************************************************************************/
/* GPT                                                                        */
/******************************************************************************/
#define GPT_CODE              AUTOMATIC
#define GPT_VAR_NOINIT        AUTOMATIC
#define GPT_VAR_POWER_ON_INIT AUTOMATIC
#define GPT_VAR_FAST          AUTOMATIC
#define GPT_VAR               AUTOMATIC
#define GPT_CONST             AUTOMATIC
#define GPT_APPL_DATA         __near
#define GPT_APPL_CONST        __near
#define GPT_APPL_CODE         __near

/******************************************************************************/
/* OS                                                                         */
/******************************************************************************/
#define OS_CODE               AUTOMATIC
#define OS_VAR_NOINIT         AUTOMATIC
#define OS_VAR_POWER_ON_INIT  AUTOMATIC
#define OS_VAR_FAST           AUTOMATIC
#define OS_VAR                AUTOMATIC
#define OS_CONST              AUTOMATIC
#define OS_APPL_DATA          __near
#define OS_APPL_CONST         __near
#define OS_APPL_CODE          __near


/******************************************************************************/
/* CAN_00_S12X                                                                         */
/******************************************************************************/
#define CAN_00_S12X_CODE               AUTOMATIC
#define CAN_00_S12X_VAR_NOINIT         AUTOMATIC
#define CAN_00_S12X_VAR_POWER_ON_INIT  AUTOMATIC
#define CAN_00_S12X_VAR_FAST           AUTOMATIC
#define CAN_00_S12X_VAR                AUTOMATIC
#define CAN_00_S12X_CONST              AUTOMATIC
#define CAN_00_S12X_APPL_DATA          __near
#define CAN_00_S12X_APPL_CONST         __near
#define CAN_00_S12X_APPL_CODE          __near

#endif /* COMPILER_CFG_H */

