/**
 * @file tpl_os_os_kernel.c
 *
 * @section descr File description
 *
 * Trampoline os services implementation.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de
 * Nantes Trampoline is protected by the French intellectual property law.
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
 *
 */

#include "tpl_os_os_kernel.h"
#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_os_hooks.h"
#include "tpl_os_kernel.h"
#include "tpl_trace.h"

#if NUMBER_OF_CORES > 1
#include "tpl_os_multicore_kernel.h"
#if SPINLOCK_COUNT > 0
#include "tpl_as_spinlock_kernel.h"
#endif

#define START_OS_SYNC_LOCK_ID 0
#endif

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
#if NUMBER_OF_CORES > 1
STATIC VAR(tpl_application_mode, OS_VAR) application_mode[NUMBER_OF_CORES];
#else
STATIC VAR(tpl_application_mode, OS_VAR) application_mode = NOAPPMODE;
#endif

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

FUNC(tpl_application_mode, OS_CODE)
tpl_get_active_application_mode_service(void)
{
  VAR(tpl_application_mode, AUTOMATIC) app_mode;
  VAR(tpl_status, AUTOMATIC) result = E_OK;

  /*  lock the kernel    */
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetActiveApplicationMode)

#if NUMBER_OF_CORES > 1
  app_mode = application_mode[tpl_get_core_id()];
#else
  app_mode = application_mode;
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return app_mode;
}

FUNC(void, OS_CODE)
tpl_start_os_service(CONST(tpl_application_mode, AUTOMATIC) mode)
{
  GET_CURRENT_CORE_ID(core_id)

#if (WITH_ERROR_HOOK == YES) || (WITH_OS_EXTENDED == YES) | (WITH_ORTI == YES)
  /*  init the error to no error  */
  VAR(tpl_status, AUTOMATIC) result = E_OK;
#endif
  /*  lock the kernel    */
  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_StartOS)
  STORE_MODE(mode);

  CHECK_OS_NOT_STARTED(core_id, result)

  IF_NO_EXTENDED_ERROR(result)
  {
#if NUMBER_OF_CORES > 1
    /*
     * Sync barrier at start of tpl_start_os_service.
     */
    tpl_sync_barrier(&tpl_start_count_0, &tpl_startos_sync_lock);

    application_mode[core_id] = mode;
#else
    application_mode = mode;
#endif

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
    tpl_sync_barrier(&tpl_start_count_1, &tpl_startos_sync_lock);
#endif

    /*
     * Call tpl_start_scheduling to elect the highest priority task
     * if such a task exists.
     */
    tpl_start_scheduling(CORE_ID_OR_NOTHING(core_id));

    SWITCH_CONTEXT_NOSAVE(core_id)
  }

  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()
}

FUNC(void, OS_CODE)
tpl_call_shutdown_os(CONST(tpl_status, AUTOMATIC) error /*@unused@*/)
{
  GET_CURRENT_CORE_ID(core_id)
  /*
   * Call the OS Application shutdown hooks if needed
   */
  CALL_OSAPPLICATION_SHUTDOWN_HOOKS()

  CALL_SHUTDOWN_HOOK(error)
  TRACE_CLOSE()

#if SPINLOCK_COUNT > 0
  RELEASE_ALL_SPINLOCKS(core_id);
#endif

  /* architecture dependant shutdown. */
  tpl_shutdown();
}

FUNC(void, OS_CODE)
tpl_shutdown_os_service(CONST(tpl_status, AUTOMATIC) error /*@unused@*/)
{
  GET_CURRENT_CORE_ID(core_id)

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
  if (TPL_KERN(core_id).running->trusted_counter > 0)
#endif
  {
    /*  store information for error hook routine */
    STORE_SERVICE(OSServiceId_ShutdownOS)

    tpl_call_shutdown_os(error);
  }

  /*  unlock the kernel */
  UNLOCK_KERNEL()
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_os_kernel.c */
