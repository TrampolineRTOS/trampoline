/**
 * @file tpl_as_protec_hook.c
 *
 * @internal
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
#include "tpl_os_kernel.h"
#include "tpl_os_rez_kernel.h"
#include "tpl_os_it_kernel.h"
#include "tpl_as_app_kernel.h"

#include "tpl_dow.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
extern CONST(tpl_proc_id, AUTOMATIC) INVALID_PROC;
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_call_protection_hook(VAR(tpl_status, AUTOMATIC) error)
{
#if WITH_PROTECTION_HOOK == YES
  VAR(ProtectionReturnType, AUTOMATIC) result;
  VAR(tpl_proc_id, AUTOMATIC) proc_id;

#if WITH_MEMORY_PROTECTION == YES
        tpl_kern.running_trusted = 1;
#endif /* WITH_MEMORY_PROTECTION == YES */
  result = ProtectionHook(error);
#if WITH_MEMORY_PROTECTION == YES
        tpl_kern.running_trusted = 0;
#endif /* WITH_MEMORY_PROTECTION == YES */

  switch (result)
  {
    case PRO_TERMINATETASKISR:
      /*
       * OS243: If the reaction is to forcibly terminate the Task/Category 2
       * OsIsr and no Task or OsIsr can be associated with the error,
       * the running OS-Application is forcibly terminated by the Operating
       * System.
       */
      proc_id = (tpl_proc_id)tpl_kern.running_id;
      if (proc_id != INVALID_PROC)
      {
        tpl_release_all_resources(proc_id);
        tpl_release_internal_resource(proc_id);
        tpl_reset_interrupt_lock_status();
        tpl_kern.running->activate_count--;

        /* terminate the running task */
        tpl_terminate();
        /* start the highest priority task */
        tpl_start(tpl_get_proc());
        /* task switching should occur */
        tpl_kern.need_switch = NEED_SWITCH;
      }
      else
      {
        /*
         * if no Task or OsIsr is running then no OS Application is running
         * so the os is shutdown
         */
        tpl_shutdown_os_service(error);
      }
      break;
    case PRO_TERMINATEAPPL:
#if WITH_OSAPPLICATION == YES
      tpl_terminate_application_service(NO_RESTART);
#else
      /*
       * According to requirement OS244, if no OS Application
       * is configured, the os is shutdown
       */
      tpl_shutdown_os_service(error);
#endif
      break;
    case PRO_TERMINATEAPPL_RESTART:
#if WITH_OSAPPLICATION == YES
      tpl_terminate_application_service(RESTART);
#else
      /*
       * According to requirement OS244, if no OS Application
       * is configured, the os is shutdown
       */
      tpl_shutdown_os_service(error);
#endif
      break;
    case PRO_SHUTDOWN:
      tpl_shutdown_os_service(error);
      break;
    case PRO_IGNORE:
      /*
       * OS475: If the reaction is to do nothing and the ProtectionHook()
       * was not called with E_OS_PROTECTION_ARRIVAL then the Operating System
       * shall call ShutdownOS()
       */
      if (E_OS_PROTECTION_ARRIVAL != error)
      {
        tpl_shutdown_os_service(error);
      }
      break;
    default:
      /*
       * if the ProtectionHook does return a wrong result,
       * we shut down the os ! well done !
       */
      tpl_shutdown_os_service(error);
      break;
  }
#else /* WITH_PROTECTION_HOOK */
  /*
   * OS107: If no ProtectionHook() is configured and a protection error occurs,
   * the Operating System shall call ShutdownOS().
   */
  tpl_shutdown_os_service(error);
#endif /* WITH_PROTECTION_HOOK */
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

