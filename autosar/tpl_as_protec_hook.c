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
#include "tpl_os_os_kernel.h"
#include "tpl_os_resource_kernel.h"
#include "tpl_os_interrupt_kernel.h"
#include "tpl_as_app_kernel.h"
#if SPINLOCK_COUNT > 0
  #include "tpl_as_spinlock_kernel.h"
#endif

#include "tpl_machine_interface.h"
#include "tpl_trace.h"

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
  GET_CURRENT_CORE_ID(core_id)
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(ProtectionReturnType, AUTOMATIC) result;
  VAR(tpl_proc_id, AUTOMATIC) proc_id;

#if WITH_MEMORY_PROTECTION == YES
  TPL_KERN_REF(kern).running_trusted = 1;
#endif /* WITH_MEMORY_PROTECTION == YES */
  result = ProtectionHook(error);
#if WITH_MEMORY_PROTECTION == YES
  TPL_KERN_REF(kern).running_trusted = 0;
#endif /* WITH_MEMORY_PROTECTION == YES */

  /* OS506: If the ProtectionHook() is called with E_OS_PROTECTION_ARRIVAL 
   * the only valid return values are PRO_IGNORE or PRO_SHUTDOWN. 
   * Returning other values will result in a call to ShutdownOS().
   */
  if ((E_OS_PROTECTION_ARRIVAL == error)  && !((PRO_IGNORE == result) || (PRO_SHUTDOWN == result)))
  {
    tpl_call_shutdown_os(error);
  }
  
  switch (result)
  {
    case PRO_TERMINATETASKISR:
      /*
       * OS243: If the reaction is to forcibly terminate the Task/Category 2
       * OsIsr and no Task or OsIsr can be associated with the error,
       * the running OS-Application is forcibly terminated by the Operating
       * System.
       */
      proc_id = (tpl_proc_id)TPL_KERN_REF(kern).running_id;
      if (proc_id != INVALID_PROC)
      {
        tpl_release_all_resources(proc_id);
#if SPINLOCK_COUNT > 0
        RELEASE_ALL_SPINLOCKS(core_id);
#endif
        tpl_reset_interrupt_lock_status();
        TPL_KERN_REF(kern).running->activate_count--;

        /* terminate the running task */
        tpl_terminate();
        /* task switching should occur */
        TPL_KERN_REF(kern).need_switch = NEED_SWITCH;
        /* start the highest priority task */
        tpl_start(CORE_ID_OR_NOTHING(core_id));
        
        LOCAL_SWITCH_CONTEXT(core_id)
        
      }
      else
      {
        /*
         * if no Task or OsIsr is running then no OS Application is running
         * so the os is shutdown
         */
        tpl_call_shutdown_os(error);
      }
      break;
    case PRO_TERMINATEAPPL:
#if WITH_OSAPPLICATION == YES
      tpl_terminate_application_service(TPL_KERN_REF(kern).s_running->app_id,NO_RESTART);
#else
      /*
       * According to requirement OS244, if no OS Application
       * is configured, the os is shutdown
       */
      tpl_call_shutdown_os(error);
#endif
      break;
    case PRO_TERMINATEAPPL_RESTART:
#if WITH_OSAPPLICATION == YES
      tpl_terminate_application_service(TPL_KERN_REF(kern).s_running->app_id,RESTART);
#else
      /*
       * According to requirement OS244, if no OS Application
       * is configured, the os is shutdown
       */
      tpl_call_shutdown_os(error);
#endif
      break;
    case PRO_SHUTDOWN:
      tpl_call_shutdown_os(error);
      break;
    case PRO_IGNORE:
      /*
       * OS475: If the reaction is to do nothing and the ProtectionHook()
       * was not called with E_OS_PROTECTION_ARRIVAL then the Operating System
       * shall call ShutdownOS()
       */
      if (E_OS_PROTECTION_ARRIVAL != error)
      {
        tpl_call_shutdown_os(error);
      }
      break;
    default:
      /*
       * if the ProtectionHook does return a wrong result,
       * we shut down the os ! well done !
       */
      tpl_call_shutdown_os(error);
      break;
  }
#else /* WITH_PROTECTION_HOOK */
  /*
   * OS107: If no ProtectionHook() is configured and a protection error occurs,
   * the Operating System shall call ShutdownOS().
   */
  tpl_call_shutdown_os(error);
#endif /* WITH_PROTECTION_HOOK */
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

