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


/******************************************************************************/
/*  MULTI for V850E                                                           */
/******************************************************************************/

#define AUTOMATIC

#define ROM_MEM   const
#define _STATIC_  static
#define _INTERRUPT_  __interrupt

#define NULL_PTR ((void *)0)
#define _INLINE_ (#pragma INLINE)

#define FUNC(type, memclass) memclass type

#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

#define P2CONST(ptrtype, memclass, ptrclass)  const ptrtype *

#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

#define CONST(type, memclass) const type

#define VAR(type, memclass) type

#define CONSTP2FUNC(rettype, ptrclass, fctname)  rettype (*const fctname)



/******************************************************************************/
/* PUBLISHED INFORMATION                                                      */
/******************************************************************************/
#define COMPILER_VENDOR_ID        48
#define COMPILER_AR_MAJOR_VERSION 2
#define COMPILER_AR_MINOR_VERSION 1
#define COMPILER_AR_PATCH_VERSION 14
#define COMPILER_SW_MAJOR_VERSION 0
#define COMPILER_SW_MINOR_VERSION 0
#define COMPILER_SW_PATCH_VERSION 1


#endif /* COMPILER_H */

