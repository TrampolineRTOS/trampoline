/**
 * @file tpl_os_mem_prot.h
 *
 * @section descr File description
 *
 * Trampoline datatypes for memory protection descriptors.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_MEM_PROT_H
#define TPL_OS_MEM_PROT_H

#include "tpl_compiler.h"

/**
 * @struct TPL_MEM_REGION
 *
 * Memory region descriptor. This descriptor is used for
 * memory protection.
 */
struct TPL_MEM_REGION {
  P2VAR(void, TYPEDEF, OS_APPL_DATA) start; /**< start address of the region  */
  P2VAR(void, TYPEDEF, OS_APPL_DATA) end;   /**< end address of the region    */
};

/**
 * @typedef tpl_mem_region
 *
 * This is an alias for the #TPL_MEM_REGION structure
 *
 * @see #TPL_MEM_REGION
 */
typedef struct TPL_MEM_REGION tpl_mem_region;

/**
 * @struct TPL_MEM_PROT_DESC
 *
 * Memory protection descriptor. A set of memory regions
 * This descriptor is used for memory protection.
 */
struct TPL_MEM_PROT_DESC {
    VAR(tpl_mem_region, TYPEDEF) proc_var;    /* region of private data */
    VAR(tpl_mem_region, TYPEDEF) proc_stack;  /* region of stack        */
#if WITH_AUTOSAR == YES
    VAR(tpl_mem_region, TYPEDEF) osap_var;    /* region of OS App data  */
#endif
};

/**
 * @typedef tpl_mem_prot_desc
 *
 * This is an alias for the #TPL_MEM_PROT_DESC structure
 *
 * @see #TPL_MEM_PROT_DESC
 */
typedef struct TPL_MEM_PROT_DESC tpl_mem_prot_desc;


extern CONSTP2CONST(tpl_mem_prot_desc, AUTOMATIC, OS_CONST) tpl_mp_table[];

/* TPL_OS_MEM_PROT_H */
#endif
/* End of file tpl_os_mem_prot.h */
