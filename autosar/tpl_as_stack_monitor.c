/**
 * @file tpl_as_stack_monitor.c
 *
 * @section desc File description
 *
 * TODO
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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
#include "tpl_as_stack_monitor.h"
#include "tpl_os.h"
 
void tpl_check_stack (tpl_exec_common *this_exec_obj)
{  
  if ((!tpl_check_stack_pointer (this_exec_obj)) ||
     (!tpl_check_stack_footprint (this_exec_obj)))
  {
/*
 * see §7.4.2 of AUTOSAR SWS OS 2.1, related to requirements
 * OS068 and OS396
 */
#if (SCALABILITY_CLASS == 1) || (SCALABILITY_CLASS == 2)
    ShutdownOS (E_OS_STACKFAULT);
#else
    tpl_call_protection_hook (E_OS_STACKFAULT);
#endif
  }
}
 
