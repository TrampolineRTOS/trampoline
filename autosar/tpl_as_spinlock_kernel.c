/**
 * @file tpl_as_counter_kernel.c
 *
 * @internal
 *
 * @section desc File description
 *
 * Trampoline autosar extension software counters functions
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

#include "tpl_as_spinlock_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_errorhook.h"
#include "tpl_machine_interface.h"
#include "tpl_as_error.h"
#include "tpl_os_error.h"
#include "tpl_os_definitions.h"
#include "tpl_as_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * FIXME : Ugly but we need this until the SPINLOCK_RESUME and SPINLOCK_SUSPEND
 *         macros are corrected.
 */
tpl_bool tpl_spinlock_resscheduler_taken[NUMBER_OF_CORES] = {FALSE};

/*
 *
 */
FUNC(tpl_status, OS_CODE) tpl_get_spinlock_service(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC)  result = E_OK;

  P2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock = NULL_PTR;

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetSpinlock)
  STORE_SPINLOCK_ID(spinlock_id)

  /*  check a spinlock_id error                   */
  CHECK_SPINLOCK_ID_ERROR(spinlock_id, result)

  /*  check access rights */
  CHECK_ACCESS_RIGHTS_SPINLOCK_ID(core_id, spinlock_id, result)

  /*  check spinlock interference deadlock error  */
  CHECK_SPINLOCK_INTERFERENCE_DEADLOCK_ERROR(core_id, spinlock_id, result)

  /*  check spinlock nesting order error          */
  CHECK_SPINLOCK_NESTING_ORDER_ERROR(core_id, spinlock_id, result)

  IF_NO_EXTENDED_ERROR(result)
  {
    /* increase the tolerance level of interrupts following the spinlock's
     * lock method */
    SPINLOCK_SUSPEND_INTERRUPTS(core_id, spinlock_id)

    /*  get the lock descriptor                   */
    lock = &(tpl_spinlock_table[spinlock_id]->state);

    /* get the lock, this call is blocking        */
    tpl_get_lock(lock);

    /* get the resscheduler if the spinlock has the associated method */
    SPINLOCK_GET_RESSCHEDULER(core_id, spinlock_id)

    /* store id of last taken spinlock, so we can check later the nesting order */
    SET_LAST_TAKEN_SPINLOCK(core_id, spinlock_id)
  }


  PROCESS_ERROR(result)

  return result;
}




/*
 *
 */
FUNC(tpl_status, OS_CODE) tpl_release_spinlock_service(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC)  result = E_OK;

  P2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock = NULL_PTR;

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_ReleaseSpinlock)
  STORE_SPINLOCK_ID(spinlock_id)

  /*  check a spinlock_id error                   */
  CHECK_SPINLOCK_ID_ERROR(spinlock_id, result)

  /*  check access rights */
  CHECK_ACCESS_RIGHTS_SPINLOCK_ID(core_id, spinlock_id, result)

  /*  check spinlock not taken error              */
  CHECK_SPINLOCK_NOT_TAKEN_ERROR(core_id, spinlock_id, result)

  /*  check spinlock nesting order error          */
  CHECK_SPINLOCK_UNNESTING_ORDER_ERROR(core_id, spinlock_id, result)

  IF_NO_EXTENDED_ERROR(result)
  {
    /*  get the lock descriptor                   */
    lock = &(tpl_spinlock_table[spinlock_id]->state);

    /* get the lock, this call is blocking        */
    tpl_release_lock(lock);

    /* store id of last released spinlock, so we can check later the nesting order */
    REMOVE_LAST_TAKEN_SPINLOCK(core_id)

    /* lower the tolerance level of interrupts. Release res_scheduler */
    SPINLOCK_RESUME_INTERRUPTS(core_id)
  }

  PROCESS_ERROR(result)

  return result;
}



/*
 *
 */
FUNC(tpl_status, OS_CODE) tpl_try_to_get_spinlock_service(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id,
    P2VAR(tpl_try_to_get_spinlock_type, AUTOMATIC, OS_VAR) success)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC)  result = E_OK;

  P2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock = NULL_PTR;

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_TryToGetSpinlock)
  STORE_SPINLOCK_ID(spinlock_id)

  /*  check a spinlock_id error                   */
  CHECK_SPINLOCK_ID_ERROR(spinlock_id, result)

  /*  check access rights */
  CHECK_ACCESS_RIGHTS_SPINLOCK_ID(core_id, spinlock_id, result)

  /*  check spinlock interference deadlock error  */
  CHECK_SPINLOCK_INTERFERENCE_DEADLOCK_ERROR(core_id, spinlock_id, result)

  /*  check spinlock nesting order error          */
  CHECK_SPINLOCK_NESTING_ORDER_ERROR(core_id, spinlock_id, result)

  IF_NO_EXTENDED_ERROR(result)
  {
    /* increase the tolerance level of interrupts following the spinlock's
     * lock method */
    SPINLOCK_SUSPEND_INTERRUPTS(core_id, spinlock_id)

    /*  get the lock descriptor                   */
    lock = &(tpl_spinlock_table[spinlock_id]->state);

    /* get the lock, this call is not blocking        */
    tpl_try_to_get_lock(lock, success);

    if (*success == TRYTOGETSPINLOCK_SUCCESS) {
      /* get the resscheduler if the spinlock has the associated method */
      SPINLOCK_GET_RESSCHEDULER(core_id, spinlock_id)
      /* store id of last taken spinlock */
      SET_LAST_TAKEN_SPINLOCK(core_id, spinlock_id)
    }
    else {
     /* restore the tolerance level of interrupts if the lock has not been
      * taken
      */
      SPINLOCK_RESUME_INTERRUPTS(core_id)
    }
  }

  PROCESS_ERROR(result)

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#include "Os.h"

#define API_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Trampoline extra
 * GetSpinlock_IE : GetSpinlock with Interrupts Enabled
 */
FUNC(tpl_status, OS_CODE) GetSpinlock_IE(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id)
{
  VAR(tpl_status, AUTOMATIC)  result = E_OK;
  VAR(TryToGetSpinlockType, AUTOMATIC) success = TRYTOGETSPINLOCK_NOSUCCESS;

  do {
    result = TryToGetSpinlock(spinlock_id, &success);
  } while((result == E_OK) && (success == TRYTOGETSPINLOCK_NOSUCCESS));

  return result;
}

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_counter_kernel.c */
