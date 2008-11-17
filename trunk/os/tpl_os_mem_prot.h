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

#ifndef TPL_OS_MEM_PROT_H
#define TPL_OS_MEM_PROT_H

#include "tpl_memory_protection.h"

struct TPL_MEM_PROT_DESC {
    tpl_mp_region_start proc_var_start; /* region start of private data     */
    tpl_mp_region_start proc_cst_start; /* region start of private constant */
    tpl_mp_region_end   proc_var_end;   /* region end of private data       */
    tpl_mp_region_end   proc_cst_end;   /* region end of private constant   */
#ifdef WITH_AUTOSAR
    tpl_mp_region_start osap_var_start;
    tpl_mp_region_start osap_cst_start;
    tpl_mp_region_end   osap_var_end;
    tpl_mp_region_end   osap_cst_end;
#endif
};

typedef struct TPL_MEM_PROT_DESC tpl_mem_prot_desc;

/* TPL_OS_MEM_PROT_H */
#endif
/* End of file tpl_os_mem_prot.h */