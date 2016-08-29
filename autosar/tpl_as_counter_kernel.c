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

#include "tpl_as_counter_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_errorhook.h"
#include "tpl_machine_interface.h"
#include "tpl_as_error.h"
#include "tpl_as_isr_kernel.h"
#include "tpl_as_protec_hook.h"
#if WITH_MEMORY_PROTECTION == YES
#include "tpl_os_mem_prot.h"
#endif /* WITH_MEMORY_PROTECTION == YES */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * @def INVALID_COUNTER
 *
 * This value is used to specify an invalid counter
 */
CONST(tpl_counter_id, AUTOMATIC) INVALID_COUNTER = (-1);

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Increment a counter.
 *
 * counter_id is the identifier of the counter to be incremented.
 * The function returns E_OK if everything was ok or E_OS_ID
 * (extended error only) if counter_id is invalid
 *
 * see paragraph 8.4.12, page 70 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_increment_counter_service(
  VAR(tpl_counter_id, AUTOMATIC) counter_id)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC)  result = E_OK;

#if COUNTER_COUNT > 0
  P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter = NULL;
#endif

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  lock the task structures                    */
  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_IncrementCounter)
  STORE_COUNTER_ID(counter_id)

  /*  check a counter_id error                    */
  CHECK_COUNTER_ID_ERROR(counter_id, result)
	
  /* check access right */
  CHECK_ACCESS_RIGHTS_COUNTER_ID(core_id, counter_id, result)
	
  CHECK_COUNTER_KIND_ERROR(counter_id, result)
	
#if COUNTER_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /*  get the counter descriptor              */
    counter = tpl_counter_table[counter_id];

    /*  increment the counter                   */
    tpl_counter_tick(counter);
	
#if NUMBER_OF_CORES > 1
    tpl_multi_schedule();
    tpl_dispatch_context_switch();
#endif
    if (TPL_KERN(core_id).need_schedule) {
      tpl_schedule_from_running(CORE_ID_OR_NOTHING(core_id));
      LOCAL_SWITCH_CONTEXT(core_id)
    }
  }
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures                  */
  UNLOCK_KERNEL()

  return result;
}


/**
 * Get the current value of a counter.
 *
 * counter_id is the identifier of the counter and value a reference (pointer)
 * to the variable where the value of the counter is stored.
 *
 * see paragraph 8.4.12, page 70 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_get_counter_value_service(
  VAR(tpl_counter_id, AUTOMATIC)              counter_id,
  P2VAR(tpl_tick, AUTOMATIC, OS_APPL_DATA)    value)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC)  result = E_OK;

#if COUNTER_COUNT > 0
  P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter = NULL;
#endif

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetCounterValue)
  STORE_COUNTER_ID(counter_id)
  STORE_TICK_REF_1(value)

  /*  check a counter_id error                    */
  CHECK_COUNTER_ID_ERROR(counter_id, result)
	
  /* check access right */
  CHECK_ACCESS_RIGHTS_COUNTER_ID(core_id, counter_id, result)

  /* check value is in an authorized memory region */
  CHECK_DATA_LOCATION(core_id, value, result);

#if COUNTER_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /*  get the counter descriptor              */
    counter = tpl_counter_table[counter_id];

    /*  copy its value in value ref             */
    *value = counter->current_date;
  }
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures                  */
  UNLOCK_KERNEL()

  return result;
}


/**
 * Get the elapsed value of a counter.
 *
 * counter_id is the identifier of the counter and value a reference (pointer)
 * to the variable where the value of the counter is stored.
 *
 * see paragraph 8.4.12, page 70 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_get_elapsed_counter_value_service(
  VAR(tpl_counter_id, AUTOMATIC)            counter_id,
  P2VAR(tpl_tick, AUTOMATIC, OS_APPL_DATA)  previous_value,
  P2VAR(tpl_tick, AUTOMATIC, OS_APPL_DATA)  value)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC)  result = E_OK;

#if COUNTER_COUNT > 0
  P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter = NULL;
  VAR(tpl_tick, AUTOMATIC)                    cpt_val;
#endif

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetElapsedCounterValue)
  STORE_COUNTER_ID(counter_id)
  STORE_TICK_REF_1(previous_value)
  STORE_TICK_REF_2(value)

  /*  check a counter_id error                    */
  CHECK_COUNTER_ID_ERROR(counter_id, result)
	
  /* check access right */
  CHECK_ACCESS_RIGHTS_COUNTER_ID(core_id, counter_id,result)
	
  /* check previous_value and value are in an authorized memory region */
  CHECK_DATA_LOCATION(core_id, previous_value, result);
  CHECK_DATA_LOCATION(core_id, value, result);

  /*  check the previous value does not exceed
      the maxallowedvalue of the counter          */
  CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR(counter_id, *previous_value, result)

#if COUNTER_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /*  get the counter descriptor              */
    counter = tpl_counter_table[counter_id];

    /*  get the current counter value           */
    cpt_val = counter->current_date;
    if (cpt_val < *previous_value) {
        cpt_val += tpl_counter_table[counter_id]->max_allowed_value + 1;
    }
    *value = cpt_val - *previous_value;
    *previous_value = counter->current_date;
  }
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures                  */
  UNLOCK_KERNEL()

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_counter_kernel.c */
