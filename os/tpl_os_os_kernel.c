/**
 * @file tpl_os_os_kernel.c
 *
 * @section descr File description
 *
 * Trampoline os services implementation.
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
 *
 */

#include "tpl_os_os_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_machine_interface.h"
#include "tpl_trace.h"
#include "tpl_os_hooks.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*
 * @internal
 *
 * The Application Mode that was used to start the OS.
 *
 * @see #tpl_start_os_service
 * @see #tpl_shutdown_os_service
 */
STATIC VAR(tpl_application_mode, OS_VAR) application_mode = NOAPPMODE;

#if NUMBER_OF_CORES > 1
/**
 * @internal
 *
 * tpl_startos_sync_lock is the lock used in the critical section of
 * both synchronization barriers of tpl_start_os
 */
VAR(tpl_lock, OS_VAR) tpl_startos_sync_lock = UNLOCKED_LOCK;
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_application_mode, OS_CODE) tpl_get_active_application_mode_service(
  void)
{
  VAR(tpl_application_mode, AUTOMATIC) app_mode = application_mode;
  VAR(tpl_status, AUTOMATIC) result = E_OK;
	
  /*  lock the kernel    */
  LOCK_KERNEL()
	
  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)
	
  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetActiveApplicationMode)
	
  app_mode = application_mode;
	
  PROCESS_ERROR(result)
	
  UNLOCK_KERNEL()
	
  return app_mode;
}

FUNC(void, OS_CODE) tpl_start_os_service(
  CONST(tpl_application_mode, AUTOMATIC) mode)
{
#if (WITH_ERROR_HOOK == YES) || (WITH_OS_EXTENDED == YES)
  /*  init the error to no error  */
  VAR(tpl_status, AUTOMATIC) result = E_OK;
#endif
  /*  lock the kernel    */
  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_StartOS)
  STORE_MODE(mode);
	
  CHECK_OS_NOT_STARTED(result)
	
  IF_NO_EXTENDED_ERROR(result)
  /* { */
  
#if NUMBER_OF_CORES > 1
  /*
   * Sync barrier at start of tpl_start_os_service. 
   */
  tpl_sync_barrier(tpl_start_count, tpl_startos_sync_lock);
  /*
   * Restore the tpl_start_count to prepare the second sync barrier
   */
  tpl_start_count = tpl_number_of_activated_cores;
  application_mode[tpl_get_core_id()] = mode;
#else
  application_mode = mode;
#endif

  TRACE_TPL_INIT()

  tpl_init_os(mode);
  
  tpl_enable_counters();

  /*
   * Call the startup hook. According to the spec, it should be called
   * after the os is initialized and before the scheduler is running
   */
  CALL_STARTUP_HOOK()
  
  /*
   * Call the OS Application startup hooks if needed
   */
  CALL_OSAPPLICATION_STARTUP_HOOKS()

#if NUMBER_OF_CORES > 1
  /*
   * Sync barrier just before starting the scheduling. 
   */
  tpl_sync_barrier(tpl_start_count, tpl_startos_sync_lock);
#endif

  /* 
   * Call tpl_start_scheduling to elect the highest priority task
   * if such a task exists.
   */
  tpl_start_scheduling();

#if WITH_SYSTEM_CALL == NO
  if (tpl_kern.need_switch != NO_NEED_SWITCH)
  {
    tpl_kern.need_switch = NO_NEED_SWITCH;
    tpl_switch_context(
      &(tpl_kern.s_old->context),
      &(tpl_kern.s_running->context)
    );
  }
#endif
  
  /* } */
  IF_NO_EXTENDED_ERROR_END()
	
  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()
}

FUNC(void, OS_CODE) tpl_shutdown_os_service(
  CONST(tpl_status, AUTOMATIC) error  /*@unused@*/)
{
  /*  lock the kernel    */
  LOCK_KERNEL()
  
  /*
   * Requirement OS054, page 65 of AUTOSAR_SWS_OS.pdf document
   *
   * Check if the caller belongs to a Trusted OS Application
   * This is done only if the OS is compiled in AUTOSAR SC3 or SC4
   * (otherwise OS Applications do not exist)
   */
#if WITH_OSAPPLICATION == YES
  if (tpl_kern.running->trusted_counter > 0)
  {
#endif
	
  /*  store information for error hook routine */
  STORE_SERVICE(OSServiceId_ShutdownOS)

  /*
   * Call the OS Application shutdown hooks if needed
   */
  CALL_OSAPPLICATION_SHUTDOWN_HOOKS()
  
  CALL_SHUTDOWN_HOOK(error)

  TRACE_TPL_TERMINATE()
  /* architecture dependant shutdown. */
  tpl_shutdown();

#if WITH_OSAPPLICATION == YES
  }
#endif
            
  /*  unlock the kernel */
  UNLOCK_KERNEL()
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_os_kernel.c */