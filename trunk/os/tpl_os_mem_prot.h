/**
 * @file tpl_os_mem_prot.h
 *
 * @section descr File description
 *
 * Trampoline datatypes for memory protection descriptors.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
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
#include "tpl_memory_protection.h"

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
#ifdef WITH_AUTOSAR
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

/* TPL_OS_MEM_PROT_H */
#endif
/* End of file tpl_os_mem_prot.h */
