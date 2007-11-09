/*=============================================================================
**                                 GEENSYS
**                      Proprietary - Copyright (C) 2007
**-----------------------------------------------------------------------------
** Supported MCUs      : MCU independent
** Supported Compilers : Compiler independent
**-----------------------------------------------------------------------------
** File name         : Compiler.h
**
** Module name       : All AUTOSAR Modules
**
** Requirement specification : AUTOSAR_SWS_CompilerAbstraction.pdf
**
** Summary: Compiler abstraction for all AUTOSAR Modules
**
**= History ===================================================================
** 01.00  N. Cornet 19/04/2007
** - Creation
=============================================================================*/

#ifndef COMPILER_H
#define COMPILER_H

/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "Compiler_Cfg.h"

/******************************************************************************/
/* DEFINITION OF MACROS                                                       */
/******************************************************************************/
#define _CODEWARRIOR_C_S12X_
#define AUTOMATIC
#define _STATIC_ static
#define NULL_PTR ((void *)0)
#define _INLINE_ (#pragma INLINE)

#define FUNC(rettype, memclass) rettype memclass
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype memclass * ptrclass
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype memclass * ptrclass
#define CONSTP2VAR(ptrtype, memclass, ptrclass) \
                     ptrtype memclass * const ptrclass
#define CONSTP2CONST(ptrtype, memclass, ptrclass) \
                     const ptrtype memclass * const ptrclass
#define P2FUNC(rettype, ptrclass, fctname) rettype (*ptrclass fctname)
#define CONST(consttype, memclass) const consttype memclass
#define VAR(vartype, memclass) vartype memclass

/******************************************************************************/
/* PUBLISHED INFORMATION                                                      */
/******************************************************************************/
#define COMPILER_VENDOR_ID 0
#define COMPILER_AR_MAJOR_VERSION 2
#define COMPILER_AR_MINOR_VERSION 1
#define COMPILER_AR_PATCH_VERSION 14
#define COMPILER_SW_MAJOR_VERSION 0
#define COMPILER_SW_MINOR_VERSION 0
#define COMPILER_SW_PATCH_VERSION 1


#endif /* COMPILER_H */

