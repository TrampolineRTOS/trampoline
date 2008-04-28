/**
 * @file tpl_as_timing_protec.c
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
#include "tpl_as_timing_protec.h"
#include "tpl_dow.h"
#include "tpl_as_isr_kernel.h"
#include "tpl_as_watchdog_kernel.h"

#ifdef WITH_AUTOSAR_TIMING_PROTECTION


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

_STATIC_ FUNC(tpl_time, OS_CODE) delay_to_next_timeframe (
    VAR(tpl_time, AUTOMATIC) timeframe);

_STATIC_ FUNC(u8, OS_CODE) watchdog_callback (
    P2CONST(tpl_watchdog, OS_VAR_NOINIT, AUTOMATIC) this_watchdog);

_STATIC_ FUNC(void, OS_CODE) start_timeframe (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

_STATIC_ FUNC(void, OS_CODE) stop_timeframe (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"



#define OS_START_SEC_CODE
#include "tpl_memmap.h"

_STATIC_ FUNC(tpl_time, OS_CODE) delay_to_next_timeframe (
    VAR(tpl_time, AUTOMATIC) timeframe)
{
  VAR(tpl_time, AUTOMATIC) result;

  result = timeframe;
  /*result -= tpl_get_local_current_date () % timeframe;*/

  return result;
}

_STATIC_ FUNC(u8, OS_CODE) watchdog_callback (
    P2CONST(tpl_watchdog, OS_VAR_NOINIT, AUTOMATIC) this_watchdog)
{
  P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) exec_obj;
  VAR(tpl_watchdog, AUTOMATIC) watchdog;
  VAR(u8, AUTOMATIC) need_resched = FALSE;
  P2VAR(tpl_scheduled_watchdog, OS_VAR_NOINIT, AUTOMATIC) found_watchdog;
  P2VAR(tpl_scheduled_watchdog, OS_VAR_NOINIT, AUTOMATIC) previous_watchdog;
  P2VAR(tpl_scheduled_watchdog, OS_VAR_NOINIT, AUTOMATIC) new_watchdog;
  VAR(tpl_time, AUTOMATIC) current_date;
  VAR(u8, AUTOMATIC) result;

  /* get the date one time to avoid offset while
   * we make assumption everything is done atomically
   * here
   */
  current_date = tpl_get_local_current_date ();

  switch (this_watchdog->type)
  {
    case EXEC_BUDGET:
    case TIME_LIMIT:
      /* remove timeframe watchdog for the task before killing it */
      watchdog.exec_obj = this_watchdog->exec_obj;
      watchdog.type = TIMEFRAME_BOUNDARY;
      if (find_scheduled_watchdog(&watchdog, &found_watchdog,
          &previous_watchdog))
      {
        result = remove_scheduled_watchdog(found_watchdog, previous_watchdog);
      }
      else
      {
        DOW_ASSERT (0) /* the timeframe must exist) */
      }
      /* as the task will be killed in any case of ProtectionHook return,
       * we have to remove any scheduled timing protection about
       * locks/resources the ISR2 can get */
      unschedule_exec_obj_watchdogs (this_watchdog->exec_obj);

      tpl_call_protection_hook (E_OS_PROTECTION_TIME);
      need_resched = TRUE;
      break;
    case REZ_LOCK:
    case ALL_INT_LOCK:
    case OS_INT_LOCK:
      /* as the task will be killed in any case of ProtectionHook return,
       * we have to remove any scheduled timing protection about
       * locks/resources the ISR2 can get */
      unschedule_exec_obj_watchdogs (this_watchdog->exec_obj);

      tpl_call_protection_hook (E_OS_PROTECTION_LOCKED);
      need_resched = TRUE;
      break;
    case TIMEFRAME_BOUNDARY:
      exec_obj = this_watchdog->exec_obj;
      if (exec_obj->static_desc->type != IS_ROUTINE)
      {
        /* remove budget monitor watchdog if any */
        watchdog.exec_obj = exec_obj;
        watchdog.type = EXEC_BUDGET;
        if (find_scheduled_watchdog(&watchdog, &found_watchdog,
            &previous_watchdog))
        {
          result = remove_scheduled_watchdog(found_watchdog, previous_watchdog);
        }
        /* reset the budget of the task */
        exec_obj->time_left =
             exec_obj->static_desc->timing_protection->execution_budget;
        exec_obj->monitor_start_date = tpl_get_local_current_date ();
        /* if the task is running, we need to schedule a
         * budget monitor watchdog immediatly
         */
        if (exec_obj->state == RUNNING)
        {
          new_watchdog = new_scheduled_watchdog();
          new_watchdog->scheduled_date = exec_obj->time_left +
             current_date;
          new_watchdog->watchdog.exec_obj = exec_obj;
          new_watchdog->watchdog.type = EXEC_BUDGET;
          result = insert_scheduled_watchdog(new_watchdog);
        }
      }
      else
      {
        /* unlock this ISR2 if needed */
        if (exec_obj->static_desc->timing_protection->count_limit == 0)
        {
          /* MISRA RULE 45 VIOLATION: a tpl_exec_common* is cast to a
             tpl_isr*. This cast behaves correctly because the first memeber
             of tpl_isr is a tpl_exec_common */
          tpl_enable_isr2_by_timing_protection ((tpl_isr*)exec_obj);
        }

        /* reset the activation countdown for the isr */
        exec_obj->time_left =
           exec_obj->static_desc->timing_protection->count_limit;
      }

      /* reschedule next timeframe end boundary */
      new_watchdog = new_scheduled_watchdog();
      new_watchdog->scheduled_date = current_date +
        exec_obj->static_desc->timing_protection->timeframe;
      new_watchdog->watchdog.exec_obj = exec_obj;
      new_watchdog->watchdog.type = TIMEFRAME_BOUNDARY;
      result = insert_scheduled_watchdog(new_watchdog);
      break;
    default:
      DOW_ASSERT (0)
      break;
  }

  return need_resched;
}

_STATIC_ FUNC(void, OS_CODE) start_timeframe (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(tpl_watchdog, AUTOMATIC) watchdog;
  VAR(tpl_time, AUTOMATIC) timeframe;
  VAR(tpl_time, AUTOMATIC) delay_to_timeframe;

  DOW_ASSERT (this_exec_obj != NULL)

  /* schedule the timeframe end boundary's watchdog
  * (timeframe period is synchronized with the current date
  * modulo timeframe, see delay_to_next_timeframe function)
  */
  timeframe = this_exec_obj->static_desc->timing_protection->timeframe;
  delay_to_timeframe = delay_to_next_timeframe (timeframe);
  if (delay_to_timeframe == 0)
  {
    delay_to_timeframe = timeframe;
  }
  watchdog.exec_obj = this_exec_obj;
  watchdog.type = TIMEFRAME_BOUNDARY;
  schedule_watchdog (&watchdog, delay_to_timeframe);
}

_STATIC_ FUNC(void, OS_CODE) stop_timeframe (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(tpl_watchdog, AUTOMATIC) watchdog;

  DOW_ASSERT (this_exec_obj != NULL)

  watchdog.exec_obj = this_exec_obj;
  watchdog.type = TIMEFRAME_BOUNDARY;
  unschedule_watchdog (&watchdog);
}

FUNC(void, OS_CODE) tpl_init_timing_protection(void)
{
  init_watchdog_kernel (watchdog_callback);
}

FUNC(void, OS_CODE) tpl_start_budget_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(tpl_watchdog, AUTOMATIC) watchdog;

  DOW_ASSERT (this_exec_obj != NULL)

  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    /* schedule the watchdog */
    watchdog.exec_obj = this_exec_obj;
    watchdog.type = EXEC_BUDGET;
    schedule_watchdog (&watchdog,
       this_exec_obj->static_desc->timing_protection->execution_budget);

    /* initialize the budget monitor counter */
    this_exec_obj->monitor_start_date = tpl_get_local_current_date ();
    this_exec_obj->time_left =
       this_exec_obj->static_desc->timing_protection->execution_budget;

    /* start the timeframe */
    stop_timeframe (this_exec_obj);
    start_timeframe (this_exec_obj);
  }
}

FUNC(void, OS_CODE) tpl_pause_budget_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(tpl_watchdog, AUTOMATIC) watchdog;

  DOW_ASSERT (this_exec_obj != NULL)

  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    /* unschedule the related watchdog */
    watchdog.exec_obj = this_exec_obj;
    watchdog.type = EXEC_BUDGET;
    unschedule_watchdog (&watchdog);

    /* update the budget monitor counter */
    this_exec_obj->time_left -=
       tpl_get_local_current_date () - this_exec_obj->monitor_start_date;
  }
}

FUNC(void, OS_CODE) tpl_continue_budget_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(tpl_watchdog, AUTOMATIC) watchdog;
  VAR(tpl_time, AUTOMATIC) current_date;

  DOW_ASSERT (this_exec_obj != NULL)

  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    /* request date only one time */
    current_date = tpl_get_local_current_date ();

    /* reschedule a related watchdog */
    watchdog.exec_obj = this_exec_obj;
    watchdog.type = EXEC_BUDGET;
    schedule_watchdog (&watchdog, this_exec_obj->time_left);

    /* restart the budget monitor base date */
    this_exec_obj->monitor_start_date = current_date;
  }
}

FUNC(void, OS_CODE) tpl_reset_activation_count (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  DOW_ASSERT (this_exec_obj != NULL)

  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    this_exec_obj->time_left =
       (tpl_time)(this_exec_obj->static_desc->timing_protection->count_limit) + 1;
  }
}

FUNC(void, OS_CODE) tpl_add_activation_count (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  DOW_ASSERT (this_exec_obj != NULL)

  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    if (this_exec_obj->time_left > 0)
    {
      this_exec_obj->time_left -= 1;
    }

    if (this_exec_obj->time_left == 0)
    {
      /* MISRA RULE 45 VIOLATION: a tpl_exec_common* is cast to a
         tpl_isr*. This cast behaves correctly because the first memeber
         of tpl_isr is a tpl_exec_common */
      tpl_disable_isr2_by_timing_protection ((tpl_isr*)this_exec_obj);
    }
  }
}

FUNC(void, OS_CODE) tpl_start_exectime_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  DOW_ASSERT (this_exec_obj != NULL)

  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    this_exec_obj->monitor_start_date = tpl_get_local_current_date ();
  }
}

FUNC(void, OS_CODE) tpl_finish_exectime_monitor (
    P2CONST(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(tpl_time, AUTOMATIC) execution_time;

  DOW_ASSERT (this_exec_obj != NULL)

  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    execution_time = tpl_get_local_current_date () -
       this_exec_obj->monitor_start_date;
    if (execution_time >
       this_exec_obj->static_desc->timing_protection->execution_budget)
    {
      /* as the task will be killed in any case of ProtectionHook return,
       * we have to remove any scheduled timing protection about
       * locks/resources the ISR2 can get */
      unschedule_exec_obj_watchdogs (this_exec_obj);

      tpl_call_protection_hook (E_OS_PROTECTION_TIME);
    }
  }
}

FUNC(void, OS_CODE) tpl_start_resource_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj,
    VAR(tpl_resource_id, AUTOMATIC) this_resource)
{
  VAR(tpl_watchdog, AUTOMATIC)  watchdog;
  VAR(tpl_time, AUTOMATIC)      resource_lock_time;

  DOW_ASSERT (this_exec_obj != NULL)
  DOW_ASSERT (this_resource < RESOURCE_COUNT)

  /* nothing to do if no timing protection specified */
  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    if (this_exec_obj->static_desc->timing_protection->resource_lock_time !=
        NULL)
    {
      /* get the maximum time the resource can be taken */
      resource_lock_time = this_exec_obj->static_desc->timing_protection->
         resource_lock_time[this_resource];

      /* if a related timing protection is found, schedule a watchdog */
      if (resource_lock_time > 0)
      {
        watchdog.exec_obj = this_exec_obj;
        watchdog.type = REZ_LOCK;
        watchdog.resource = this_resource;
        schedule_watchdog (&watchdog, resource_lock_time);
      }
    }
  }
}

FUNC(void, OS_CODE) tpl_disable_resource_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj,
    VAR(tpl_resource_id, AUTOMATIC) this_resource)
{
  VAR(tpl_watchdog, AUTOMATIC) watchdog;

  DOW_ASSERT (this_exec_obj != NULL)
  DOW_ASSERT (this_resource < RESOURCE_COUNT)

  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    watchdog.exec_obj = this_exec_obj;
    watchdog.type = REZ_LOCK;
    watchdog.resource = this_resource;
    unschedule_watchdog (&watchdog);
  }
}

FUNC(void, OS_CODE) tpl_start_all_isr_lock_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(tpl_watchdog, AUTOMATIC)  watchdog;
  VAR(tpl_time, AUTOMATIC)      int_lock_time;

  DOW_ASSERT (this_exec_obj != NULL)

  /* nothing to do if no timing protection specified */
  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    if (this_exec_obj->static_desc->timing_protection-> all_interrupt_lock_time
        > 0)
    {
      /* get the maximum time the interrupts can be locked */
      int_lock_time =
         this_exec_obj->static_desc->timing_protection->all_interrupt_lock_time;

      /* schedule a watchdog */
      watchdog.exec_obj = this_exec_obj;
      watchdog.type = ALL_INT_LOCK;
      schedule_watchdog (&watchdog, int_lock_time);
    }
  }
}

FUNC(void, OS_CODE) tpl_disable_all_isr_lock_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(tpl_watchdog, AUTOMATIC) watchdog;

  DOW_ASSERT (this_exec_obj != NULL)

  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    watchdog.exec_obj = this_exec_obj;
    watchdog.type = ALL_INT_LOCK;
    unschedule_watchdog (&watchdog);
  }
}

FUNC(void, OS_CODE) tpl_start_os_isr_lock_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(tpl_watchdog, AUTOMATIC)  watchdog;
  VAR(tpl_time, AUTOMATIC)      int_lock_time;

  DOW_ASSERT (this_exec_obj != NULL)

  /* nothing to do if no timing protection specified */
  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    if (this_exec_obj->static_desc->timing_protection-> all_interrupt_lock_time
        > 0)
    {
      /* get the maximum time the interrupts can be locked */
      int_lock_time =
         this_exec_obj->static_desc->timing_protection->os_interrupt_lock_time;

      /* schedule a watchdog */
      watchdog.exec_obj = this_exec_obj;
      watchdog.type = OS_INT_LOCK;
      schedule_watchdog (&watchdog, int_lock_time);
    }
  }
}

FUNC(void, OS_CODE) tpl_disable_os_isr_lock_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(tpl_watchdog, AUTOMATIC) watchdog;

  DOW_ASSERT (this_exec_obj != NULL)

  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    watchdog.exec_obj = this_exec_obj;
    watchdog.type = OS_INT_LOCK;
    unschedule_watchdog (&watchdog);
  }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#else /* defined WITH_AUTOSAR_TIMING_PROTECTION */
static u8 nothing;
#endif /* !defined WITH_AUTOSAR_TIMING_PROTECTION */
