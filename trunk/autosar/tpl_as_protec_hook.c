/**
 * @file tpl_as_protec_hook.c
 *
 * @section desc File description
 *
 * @todo document this
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
#include "tpl_as_protec_hook.h"
#include "tpl_dow.h"
#include "tpl_os_kernel.h"

static void killtaskisr ()
{
  tpl_running_obj->state = (tpl_exec_state)DYING;
}
 
void tpl_call_protection_hook (tpl_status error)
{
#ifdef WITH_PROTECTION_HOOK
  ProtectionReturnType result;
  
  result = ProtectionHook (error);
  
  switch (result)
  {
    case PRO_KILLTASKISR:
      killtaskisr ();
      break;
    case PRO_KILLAPPL:
      /* FIXME: check this behavior conformity with AUTOSAR */
      tpl_shutdown ();
      break;
    case PRO_KILLAPPL_RESTART:
      /* FIXME: check this behavior conformity with AUTOSAR */
      tpl_shutdown ();
      break;
    case PRO_SHUTDOWN:
      tpl_shutdown ();
      break;
    default:
      killtaskisr ();
      break;
  }
#else /* WITH_PROTECTION_HOOK */
  killtaskisr ();
#endif /* WITH_PROTECTION_HOOK */
}

