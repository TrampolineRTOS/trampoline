/**
 * @file tpl_os_alarm_kernel.c
 *
 * @section desc File description
 *
 * Trampoline Alarm Kernel implementation file
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c)
 * CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
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
 */

#include "tpl_os_alarm_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"
#include "tpl_os_error.h"
#include "tpl_os_errorhook.h"
#include "tpl_machine_interface.h"
#include "tpl_trace.h"

#include "tpl_debug.h"

#if WITH_AUTOSAR == YES
#include "tpl_as_protec_hook.h"
#endif

#if WITH_MEMORY_PROTECTION == YES
#include "tpl_os_mem_prot.h"
#endif

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/**
 * @def INVALID_ALARM
 *
 * This value is used to specify an invalid alarm ID
 */
CONST(tpl_alarm_id, AUTOMATIC) INVALID_ALARM = (-1);
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * @internal
 *
 * tpl_raise_alarm is called by tpl_counter_tick
 * when an alarm time object is raised.
 *
 * @param time_obj  The alarm to raise.
 */
FUNC(void, OS_CODE) tpl_raise_alarm(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) _time_obj)
{
  /*
   * A tpl_time_obj_static * is cast to a tpl_alarm_static *
   * This violate MISRA rule 45. However, since the
   * first member of tpl_alarm_static is a tpl_time_obj_static
   * This cast behaves correctly.
   */
  /*  Get the alarm descriptor                            */
  #ifdef VOLATILE_ARGS_AND_LOCALS
    static volatile P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) time_obj ;
	time_obj = _time_obj;
    static volatile P2VAR(tpl_alarm_static, AUTOMATIC, OS_APPL_DATA) stat_alarm ;
	stat_alarm = (tpl_alarm_static *)time_obj->stat_part;
    /*  Get the action to perform from the alarm descriptor */
    static volatile P2VAR(tpl_action, AUTOMATIC, OS_APPL_CONST) action_desc ;
    action_desc = stat_alarm->action;
  #else
   #define time_obj _time_obj
    P2VAR(tpl_alarm_static, AUTOMATIC, OS_APPL_DATA) stat_alarm =
      (tpl_alarm_static *)time_obj->stat_part;
    /*  Get the action to perform from the alarm descriptor */
    CONSTP2VAR(tpl_action, AUTOMATIC, OS_APPL_CONST) action_desc =
      stat_alarm->action;
  #endif

  TRACE_ALARM_EXPIRE(time_obj)
  /*  Call the action                                     */
  (action_desc->action)(action_desc) ;
  #ifndef VOLATILE_ARGS_AND_LOCALS
    #undef time_obj
  #endif
}


FUNC(tpl_status, OS_CODE) tpl_get_alarm_base_service(
    CONST(tpl_alarm_id, AUTOMATIC)                  _alarm_id,
    P2VAR(tpl_alarm_base, AUTOMATIC, OS_APPL_DATA)  _info)
{
  GET_CURRENT_CORE_ID(core_id)
  #ifdef VOLATILE_ARGS_AND_LOCALS
    static volatile VAR(tpl_alarm_id, AUTOMATIC) alarm_id ;
    alarm_id = _alarm_id;
    static volatile P2VAR(tpl_alarm_base, AUTOMATIC, OS_APPL_DATA)  info ;
    info = _info;
    static volatile VAR(tpl_status, AUTOMATIC) result ;
    result = E_OK;
  #else
    #define alarm_id _alarm_id
    #define info _info
    VAR(tpl_status, AUTOMATIC) result = E_OK;
  #endif

#if ALARM_COUNT > 0
#ifdef VOLATILE_ARGS_AND_LOCALS
  static volatile P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
#else
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
#endif
#endif

  LOCK_KERNEL()

/* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_GetAlarmBase)
  STORE_ALARM_ID(alarm_id)
  STORE_ALARM_BASE_REF(info)

  CHECK_ALARM_ID_ERROR(alarm_id, result)

	/* check access right */
	CHECK_ACCESS_RIGHTS_ALARM_ID(core_id, alarm_id, result)

  /* check info is in an authorized memory region */
  CHECK_DATA_LOCATION(core_id, info, result);

#if ALARM_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    alarm = tpl_alarm_table[alarm_id];

    info->ticksperbase = alarm->stat_part->counter->ticks_per_base;
    info->maxallowedvalue = alarm->stat_part->counter->max_allowed_value;
    info->mincycle = alarm->stat_part->counter->min_cycle;
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()
  #ifndef VOLATILE_ARGS_AND_LOCALS
    #undef alarm_id
    #undef info
  #endif

  return result;
}

FUNC(tpl_status, OS_CODE) tpl_get_alarm_service(
  CONST(tpl_alarm_id, AUTOMATIC)              _alarm_id,
  P2VAR(tpl_tick, AUTOMATIC, OS_APPL_DATA)    _tick)
{
  GET_CURRENT_CORE_ID(core_id)
  #ifdef VOLATILE_ARGS_AND_LOCALS
    static volatile VAR(tpl_alarm_id, AUTOMATIC)              alarm_id ;
    alarm_id = _alarm_id;
    static volatile P2VAR(tpl_tick, AUTOMATIC, OS_APPL_DATA)    tick ;
    tick = _tick;
    static volatile VAR(tpl_status, AUTOMATIC) result ;
    result = E_OK;
  #else
    #define alarm_id _alarm_id
    #define tick _tick
    VAR(tpl_status, AUTOMATIC) result = E_OK;
  #endif

#if ALARM_COUNT > 0
#ifdef VOLATILE_ARGS_AND_LOCALS
  static volatile P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
#else
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
#endif
#endif

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_GetAlarm)
  STORE_ALARM_ID(alarm_id)
  STORE_TICK_REF_1(tick)

  CHECK_ALARM_ID_ERROR(alarm_id,result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_ALARM_ID(core_id, alarm_id,result)

  /* check tick is in an authorized memory region */
  CHECK_DATA_LOCATION(core_id, tick, result);

#if ALARM_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    alarm = tpl_alarm_table[alarm_id];
    /* Tick optimization :
     * A syscall must update counters before using a timeobj's structures
     */
    TPL_UPDATE_COUNTERS(alarm);

    /*  verify the alarm is active  */
    if (alarm->state == (tpl_time_obj_state)ALARM_ACTIVE)
    {
      VAR(tpl_tick, AUTOMATIC) alarm_date = alarm->date;
      VAR(tpl_tick, AUTOMATIC) current_date =
        alarm->stat_part->counter->current_date;
      if (alarm_date < current_date)
      {
        alarm_date += alarm->stat_part->counter->max_allowed_value;
      }
      *tick = alarm_date - current_date;
    }
    else
    {
      result = E_OS_NOFUNC;
    }

    /* Tick optimization :
     * A syscall must enable the mastersource after finishing using the timeobj
     * structure.
     */
    TPL_ENABLE_SHAREDSOURCE(alarm);
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()
  #ifndef VOLATILE_ARGS_AND_LOCALS
    #undef alarm_id
    #undef tick
  #endif

  return result;
}

FUNC(tpl_status, OS_CODE) tpl_set_rel_alarm_service(
  CONST(tpl_alarm_id, AUTOMATIC)  _alarm_id,
  CONST(tpl_tick, AUTOMATIC)      _increment,
  CONST(tpl_tick, AUTOMATIC)      _cycle)
{
  GET_CURRENT_CORE_ID(core_id)
  #ifdef VOLATILE_ARGS_AND_LOCALS
    static volatile VAR(tpl_alarm_id, AUTOMATIC)  alarm_id ;
    alarm_id = _alarm_id;
    static volatile VAR(tpl_tick, AUTOMATIC)      increment ;
    increment = _increment;
    static volatile VAR(tpl_tick, AUTOMATIC)      cycle ;
    cycle = _cycle;
    static volatile VAR(tpl_status, AUTOMATIC) result ;
    result = E_OK;
  #else
    #define alarm_id _alarm_id
    #define increment _increment
    #define cycle _cycle
    VAR(tpl_status, AUTOMATIC) result = E_OK;
  #endif

#if ALARM_COUNT > 0
#ifdef VOLATILE_ARGS_AND_LOCALS
  static volatile P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
  static volatile P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) cnt;
  static volatile VAR(tpl_tick, AUTOMATIC) date;
#else
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
  P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) cnt;
  VAR(tpl_tick, AUTOMATIC) date;
#endif
#endif

  LOCK_KERNEL()

/* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_SetRelAlarm)
  STORE_ALARM_ID(alarm_id)
  STORE_TICK_1(increment)
  STORE_TICK_2(cycle)

  CHECK_ALARM_ID_ERROR(alarm_id,result)

	/* check access right */
  CHECK_ACCESS_RIGHTS_ALARM_ID(core_id, alarm_id,result)

  CHECK_ALARM_INCREMENT_ERROR(alarm_id,increment,result)
  CHECK_ALARM_MIN_CYCLE_ERROR(alarm_id,cycle,result)

#if ALARM_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    alarm = tpl_alarm_table[alarm_id];
    /* Tick optimization :
     * A syscall must update counters before using a timeobj's structures
     */
    TPL_UPDATE_COUNTERS(alarm);

    if (alarm->state == (tpl_time_obj_state)ALARM_SLEEP)
    {
      cnt = alarm->stat_part->counter;
      /*  the alarm is not in use, proceed    */
      date = cnt->current_date + increment;
      if (date > cnt->max_allowed_value)
      {
          date -= (cnt->max_allowed_value + 1);
      }
      alarm->date = date;
      alarm->cycle = cycle;
      alarm->state = ALARM_ACTIVE;
      tpl_insert_time_obj(alarm);
      TRACE_ALARM_SCHEDULED(alarm)
    }
    else
    {
      /*  the alarm is in use, return the proper error code   */
      result = E_OS_STATE;
    }

    /* Tick optimization :
     * A syscall must enable the mastersource after finishing using the timeobj
     * structure.
     */
    TPL_ENABLE_SHAREDSOURCE(alarm);
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()
  #ifndef VOLATILE_ARGS_AND_LOCALS
    #undef alarm_id
    #undef increment
    #undef cycle
  #endif

  return result;
}

/*
 * SetAbsAlarm
 *
 * See page 64 of the OSEK spec
 */
FUNC(tpl_status, OS_CODE) tpl_set_abs_alarm_service(
  CONST(tpl_alarm_id, AUTOMATIC)  _alarm_id,
  CONST(tpl_tick, AUTOMATIC)      _start,
  CONST(tpl_tick, AUTOMATIC)      _cycle)
{
  GET_CURRENT_CORE_ID(core_id)
  #ifdef VOLATILE_ARGS_AND_LOCALS
    static volatile VAR(tpl_alarm_id, AUTOMATIC)  alarm_id ;
    alarm_id = _alarm_id;
    static volatile VAR(tpl_tick, AUTOMATIC)      start ;
    start = _start;
    static volatile VAR(tpl_tick, AUTOMATIC)      cycle ;
    cycle = _cycle;
    static volatile VAR(tpl_status, AUTOMATIC) result ;
    result = E_OK;
  #else
    #define alarm_id _alarm_id
    #define start _start
    #define cycle _cycle
    VAR(tpl_status, AUTOMATIC) result = E_OK;
  #endif

#if ALARM_COUNT > 0
#ifdef VOLATILE_ARGS_AND_LOCALS
  static volatile P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
#else
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
#endif
#endif

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_SetAbsAlarm)
  STORE_ALARM_ID(alarm_id)
  STORE_TICK_1(start)
  STORE_TICK_2(cycle)

  CHECK_ALARM_ID_ERROR(alarm_id,result)

	/* check access right */
  CHECK_ACCESS_RIGHTS_ALARM_ID(core_id, alarm_id,result)

  CHECK_ALARM_INCREMENT_ERROR(alarm_id,start,result)
  CHECK_ALARM_MIN_CYCLE_ERROR(alarm_id,cycle,result)

#if ALARM_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    alarm = tpl_alarm_table[alarm_id];
    /* Tick optimization :
     * A syscall must update counters before using a timeobj's structures
     */
    TPL_UPDATE_COUNTERS(alarm);

    if (alarm->state == (tpl_time_obj_state)ALARM_SLEEP)
    {
      /*  the alarm is not in use, proceed    */
      alarm->date = start;
      alarm->cycle = cycle;
      alarm->state = ALARM_ACTIVE;
      tpl_insert_time_obj(alarm);
      TRACE_ALARM_SCHEDULED(alarm)
    }
    else
    {
      /*  the alarm is in use, return the proper error code   */
      result = E_OS_STATE;
    }

    /* Tick optimization :
     * A syscall must enable the mastersource after finishing using the timeobj
     * structure.
     */
    TPL_ENABLE_SHAREDSOURCE(alarm);
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()
  #ifndef VOLATILE_ARGS_AND_LOCALS
    #undef alarm_id
    #undef start
    #undef cycle
  #endif

  return result;
}

/*
 * CancelAlarm
 *
 * See page 65 of the OSEK spec
 */
FUNC(tpl_status, OS_CODE) tpl_cancel_alarm_service(
  CONST(tpl_alarm_id, AUTOMATIC) _alarm_id)
{
  GET_CURRENT_CORE_ID(core_id)
  #ifdef VOLATILE_ARGS_AND_LOCALS
    static volatile VAR(tpl_alarm_id, AUTOMATIC) alarm_id ;
    alarm_id = _alarm_id;
    static volatile VAR(tpl_status, AUTOMATIC) result ;
    result = E_OK;
  #else
    #define alarm_id _alarm_id
    VAR(tpl_status, AUTOMATIC) result = E_OK;
  #endif

#if ALARM_COUNT > 0
#ifdef VOLATILE_ARGS_AND_LOCALS
  static volatile P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
#else
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
#endif
#endif

  LOCK_KERNEL()

	/* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_CancelAlarm)
  STORE_ALARM_ID(alarm_id)

  CHECK_ALARM_ID_ERROR(alarm_id,result)

	/* check access right */
	CHECK_ACCESS_RIGHTS_ALARM_ID(core_id, alarm_id,result)

#if ALARM_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    alarm = tpl_alarm_table[alarm_id];
    /* Tick optimization :
     * A syscall must update counters before using a timeobj's structures
     */
    TPL_UPDATE_COUNTERS(alarm);

    if (alarm->state == (tpl_time_obj_state)ALARM_ACTIVE)
    {
      tpl_remove_time_obj(alarm);
      TRACE_ALARM_CANCEL(alarm_id)
      alarm->state = ALARM_SLEEP;
    }
    else
    {
      result = E_OS_NOFUNC;
    }

    /* Tick optimization :
     * A syscall must enable the mastersource after finishing using the timeobj
     * structure.
     */
    TPL_ENABLE_SHAREDSOURCE(alarm);
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()
  #ifndef VOLATILE_ARGS_AND_LOCALS
    #undef alarm_id
  #endif

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_alarm_kernel.c */
