/**
 * @file tpl_debug.h
 *
 * @section descr File description
 *
 * Various functions for Debugging on Workstation (DoW) purpose.
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
 *
 */

#ifndef TPL_DEBUG_H
#define TPL_DEBUG_H

#include "tpl_os_timeobj_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE)
  print_counter(CONSTP2VAR(tpl_counter, AUTOMATIC, OS_CONST) c);

FUNC(void, OS_CODE)
  print_rez(CONST(tpl_resource_id, AUTOMATIC) rez_id);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* TPL_DEBUG_H */
#endif
/* End of file tpl_debug.h */
