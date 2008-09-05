/**
 * @file Compiler.h
 *
 * @section desc File description
 *
 * Compiler abstraction for all AUTOSAR Modules
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
#define TYPEDEF
#define STATIC static
#define NULL_PTR ((void *)0)
#define INLINE (#pragma INLINE)

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

/*****************************************************************************/
/* PUBLISHED INFORMATION                                                     */
/*****************************************************************************/
#define COMPILER_VENDOR_ID        48
#define COMPILER_AR_MAJOR_VERSION 3
#define COMPILER_AR_MINOR_VERSION 0
#define COMPILER_AR_PATCH_VERSION 0
#define COMPILER_SW_MAJOR_VERSION 1
#define COMPILER_SW_MINOR_VERSION 1
#define COMPILER_SW_PATCH_VERSION 0


#endif /* COMPILER_H */

