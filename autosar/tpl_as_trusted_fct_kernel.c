/**
 * @file tpl_as_trusted_fct_kernel.c
 *
 * @section desc File description
 *
 * Trampoline AUTOSAR's trusted fonction implementation
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

#include "tpl_as_trusted_fct_kernel.h"
#include "tpl_as_definitions.h"
#include "tpl_os_kernel.h"

#if TRUSTED_FCT_COUNT > 0
extern CONST(tpl_trusted_fct, OS_APPL_CODE)
  tpl_trusted_fct_table[TRUSTED_FCT_COUNT];
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_status, OS_CODE) tpl_call_trusted_function_service(
  CONST(tpl_tf_id, AUTOMATIC)               fct_idx,
  CONSTP2VAR(void, AUTOMATIC, OS_APPL_DATA) fct_param)
{
  GET_CURRENT_CORE_ID(core_id)
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(tpl_status, AUTOMATIC) result = E_OK;

#if (TRUSTED_FCT_COUNT > 0)
  if (fct_idx < TRUSTED_FCT_COUNT)
  {
    CONST(tpl_trusted_fct, AUTOMATIC) tf = tpl_trusted_fct_table[fct_idx];
#   if WITH_OSAPPLICATION == YES
    TPL_KERN_REF(kern).running->trusted_counter++;
#   endif
    tf(fct_idx, fct_param);
#   if WITH_OSAPPLICATION == YES
    TPL_KERN_REF(kern).running->trusted_counter--;
#   endif
  }
  else
#endif
  {
    result = E_OS_SERVICEID;
  }
  return result;
}

FUNC(void, OS_CODE) tpl_exit_trusted_function_service(void)
{
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_trusted_fct_kernel.c */
