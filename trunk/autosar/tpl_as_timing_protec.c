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
#include "tpl_os_kernel.h"
#include "tpl_machine_interface.h"
#include "tpl_as_protec_hook.h"

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "tpl_memmap.h"

#ifndef NO_TASK
STATIC VAR(tpl_watchdog, OS_VAR_NOINIT) tpl_watchdog_task_timeframe[TASK_COUNT];
STATIC VAR(tpl_watchdog, OS_VAR_NOINIT) tpl_watchdog_task_budget_monitor[TASK_COUNT];
#endif
#ifndef NO_ISR
STATIC VAR(tpl_watchdog, OS_VAR_NOINIT) tpl_watchdog_isr_timeframe[ISR_COUNT];
STATIC VAR(tpl_watchdog, OS_VAR_NOINIT) tpl_watchdog_isr_budget_monitor[ISR_COUNT];
#endif
STATIC VAR(tpl_watchdog, OS_VAR_NOINIT) tpl_watchdog_all_isr_lock_monitor;
STATIC VAR(tpl_watchdog, OS_VAR_NOINIT) tpl_watchdog_os_isr_lock_monitor;
#ifndef NO_RESOURCE
STATIC VAR(tpl_watchdog, OS_VAR_NOINIT) tpl_watchdog_resource_monitor[RESOURCE_COUNT];
#endif
STATIC P2VAR(tpl_watchdog, OS_VAR_NOINIT, OS_VAR_NOINIT) tpl_earliest_watchdog;

#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

STATIC FUNC(void, OS_CODE) tpl_schedule_watchdog(
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog);

STATIC FUNC(void, OS_CODE) tpl_unschedule_watchdog(
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"



#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * This function is called when a watchdog expires. It computes
 * the action for all watchdog which have the same scheduled_date
 *
 */
FUNC(void, OS_CODE) tpl_watchdog_expiration(void)
{
  VAR(tpl_status, AUTOMATIC)  need_resched = NO_SPECIAL_CODE;
  VAR(tpl_time, AUTOMATIC) current_date;
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;

  /* get the local current date */
  current_date = tpl_get_local_current_date();

  /* the watchdog which has just expired is the first in the list */
  watchdog = tpl_earliest_watchdog;

  /* while the next watchdog has the same scheduled_date,
     it means that it is also expiring now */
  while( (watchdog != NULL) && (watchdog->scheduled_date <= current_date) )
  {

      /* the action to perform is dependent on the type of the watchdog */
      switch(watchdog->type)
      {
        /* inter-arrival rate measurement */
        case TIME_FRAME:
          /* the inter-arrival time has finished,
           * so the object can be activated again
           */
          tpl_dyn_proc_table[watchdog->proc_id]->activation_allowed = TRUE;
          need_resched = NO_SPECIAL_CODE;
          break;

        case EXEC_BUDGET:
          /* the corresponding object has exceeds its execution budget */
          tpl_call_protection_hook(E_OS_PROTECTION_TIME);
          need_resched = NEED_RESCHEDULING;
          break;

        case REZ_LOCK:
          /* the correspondong object has blocked a resource for to long */
          tpl_call_protection_hook(E_OS_PROTECTION_LOCKED);
          need_resched = NO_SPECIAL_CODE;
          break;

        case ALL_INT_LOCK:
          /* the correspondong object has blocked interrupts for to long */
          tpl_call_protection_hook(E_OS_PROTECTION_LOCKED);
          need_resched = NO_SPECIAL_CODE;
          break;

        case OS_INT_LOCK:
          /* the correspondong object has blocked OS interrupts for to long */
          tpl_call_protection_hook(E_OS_PROTECTION_LOCKED);
          need_resched = NO_SPECIAL_CODE;
          break;
        default:
          need_resched = NO_SPECIAL_CODE;
          break;
      }

      /* remove the expired watchdog from the list and loop
         if there are pending watchdogs on the same date */
      tpl_unschedule_watchdog(watchdog);
      watchdog = tpl_earliest_watchdog;
  }

  if(NEED_RESCHEDULING == need_resched)
  {
    tpl_schedule_from_dying();
  }
}


/**
 * Function used to start the measure of a time frame for a task/isr2
 *
 * @param proc_id: object owner of the time frame to start
 *
 */
FUNC(void, OS_CODE) tpl_start_timeframe (
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];
  VAR(tpl_time, AUTOMATIC) date;
  VAR(tpl_time, AUTOMATIC) timeframe;

#if !defined(NO_TASK) || !defined(NO_ISR)
  /* check if timing protection os configured for this object */
  if (proc->timing_protection != NULL)
  {
    /* get a free watchdog from the watchdog table,
     * as there can be only one time frame per task or isr,
     * the watchdog is always free
     */
    if (proc->type != IS_ROUTINE)
    {
#ifndef NO_TASK
      watchdog = &tpl_watchdog_task_timeframe[proc_id];
#endif
    }
    else
    {
#ifndef NO_ISR
      watchdog = &tpl_watchdog_isr_timeframe[proc_id - TASK_COUNT];
#endif
    }

    /* set the type of the watchdog */
    watchdog->type = TIME_FRAME;

    /* set the object which sets the watchdog */
    watchdog->proc_id = proc_id;

    /* set the start date of the watchdog */
    date = tpl_get_local_current_date();
    watchdog->start_date = date;

    /* calculate the expiration date of the watchdog */
    timeframe = proc->timing_protection->timeframe;
    watchdog->scheduled_date = date + timeframe;

    watchdog->time_left = timeframe;

    tpl_dyn_proc_table[proc_id]->activation_allowed = FALSE;

    /* insert new watchdog in the list */
    tpl_schedule_watchdog(watchdog);
  }
#endif
}


/**
 * Function used to stop the measure of a time frame for a task/isr2
 *
 * @param proc_id: object owner of the time frame to stop
 *
 */
FUNC(void, OS_CODE) tpl_stop_timeframe(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];

#if !defined(NO_TASK) || !defined(NO_ISR)
  /* check if timing protection os configured for this object */
  if (proc->timing_protection != NULL)
  {
    /* select the corresponding watchdog */
    if (proc->type != IS_ROUTINE)
    {
#ifndef NO_TASK
      watchdog = &tpl_watchdog_task_timeframe[proc_id];
#endif
    }
    else
    {
#ifndef NO_ISR
      watchdog = &tpl_watchdog_isr_timeframe[proc_id - TASK_COUNT];
#endif
    }
    /* remove the watchdog from the queue */
    tpl_unschedule_watchdog(watchdog);
  }
#endif
}


/**
 * Function used to initialized the timing protection kernel
 *
 */
FUNC(void, OS_CODE) tpl_init_timing_protection(void)
{
  tpl_earliest_watchdog = NULL;

}


/**
 * Function used to monitor execution budget of a task/isr2
 *
 * @param proc_id: object owner of the execution budget to start
 *
 */
FUNC(void, OS_CODE) tpl_start_budget_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];
  VAR(tpl_time, AUTOMATIC) date;
  VAR(tpl_time, AUTOMATIC) executionbudget;

#if !defined(NO_TASK) || !defined(NO_ISR)
  if (proc->timing_protection != NULL)
  {
    /* select the corresponding watchdog */
    if (proc->type != IS_ROUTINE)
    {
#ifndef NO_TASK
      watchdog = &tpl_watchdog_task_budget_monitor[proc_id];
#endif
    }
    else
    {
#ifndef NO_ISR
      watchdog = &tpl_watchdog_isr_budget_monitor[proc_id - TASK_COUNT];
#endif
    }

    /* set the watchdog parameters */
    watchdog->type = EXEC_BUDGET;

    watchdog->proc_id = proc_id;

    /* calculate the watchdog expiration date */
    date = tpl_get_local_current_date();
    executionbudget = proc->timing_protection->execution_budget;
    watchdog->scheduled_date = date + executionbudget;

    /* insert the watchdog in the queue */
    tpl_schedule_watchdog(watchdog);
  }
#endif
}


/**
 * Function used to stop a budget monitor watchdog
 *
 * @param proc_id: object owner of the execution budget to stop
 *
 */
FUNC(void, OS_CODE) tpl_stop_budget_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
  tpl_stat_proc_table[proc_id];

#if !defined(NO_TASK) || !defined(NO_ISR)
  if(proc->timing_protection!=NULL)
  {
    /* select the corresponding watchdog */
    if(proc->type != IS_ROUTINE)
    {
#ifndef NO_TASK
      watchdog = &tpl_watchdog_task_budget_monitor[proc_id];
#endif
    }
    else
    {
#ifndef NO_ISR
      watchdog = &tpl_watchdog_isr_budget_monitor[proc_id - TASK_COUNT];
#endif
    }

    /* remove the watchdog from the queue */
    tpl_unschedule_watchdog(watchdog);
  }
#endif
}


/**
 * Function used to pause a budget monitor watchdog
 *
 * @param proc_id: object owner of the execution budget to pause
 *
 */
FUNC(void, OS_CODE) tpl_pause_budget_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];

#if !defined(NO_TASK) || !defined(NO_ISR)
  if(proc->timing_protection != NULL)
  {
      /* select the corresponding watchdog */
      if(proc->type != IS_ROUTINE)
      {
#ifndef NO_TASK
          watchdog = &tpl_watchdog_task_budget_monitor[proc_id];
#endif
      }
      else
      {
#ifndef NO_ISR
          watchdog = &tpl_watchdog_isr_budget_monitor[proc_id - TASK_COUNT];
#endif
      }

      /* calculate the remaining time */
      watchdog->time_left = (watchdog->scheduled_date) - (watchdog->start_date);

      /* remove the watchdog from the queue */
      tpl_unschedule_watchdog(watchdog);
  }
#endif
}


/**
 * Function used to continue a budget monitor watchdog previously paused
 *
 * @param proc_id: object owner of the execution budget to continue
 *
 */
FUNC(void, OS_CODE) tpl_continue_budget_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];
  VAR(tpl_time, AUTOMATIC) date;

#if !defined(NO_TASK) || !defined(NO_ISR)
  if(proc->timing_protection != NULL)
  {
    /* select the corresponding watchdog */
    if(proc->type != IS_ROUTINE)
    {
#ifndef NO_TASK
      watchdog = &tpl_watchdog_task_budget_monitor[proc_id];
#endif
    }
    else
    {
#ifndef NO_ISR
      watchdog = &tpl_watchdog_isr_budget_monitor[proc_id - TASK_COUNT];
#endif
    }

    /* set the watchodg parameters */
    watchdog->type=EXEC_BUDGET;
    watchdog->proc_id = proc_id;

    /* calculate the scheduled date */
    date = tpl_get_local_current_date();
    watchdog->start_date = date;
    watchdog->scheduled_date = date + watchdog->time_left;

    /* insert the watchdog */
    tpl_schedule_watchdog(watchdog);
  }
#endif
}


/**
 * Function used to start a resource locking monitor for a task/isr2
 *
 * @param proc_id: owner of the watchdog to start
 *
 * @param rez_id: resource the owner os blocking
 *
 */
FUNC(void, OS_CODE) tpl_start_resource_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id,
  CONST(tpl_resource_id, AUTOMATIC) rez_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];
  VAR(tpl_time, AUTOMATIC)  resource_lock_time;
  VAR(tpl_time, AUTOMATIC)  date;

#ifndef NO_RESOURCE
  if ((proc->timing_protection != NULL) &&
      (proc->timing_protection->resource_lock_time!= NULL))
  {
    resource_lock_time = proc->timing_protection->resource_lock_time[rez_id];

    /*  if resource lock time is null, it means there is no
        timing protection for this resource                   */
    if (resource_lock_time > 0)
    {
      /* select the corresponding watchdog */
      watchdog = &tpl_watchdog_resource_monitor[rez_id];

      /* set the watchdog parameters */
      watchdog->type = REZ_LOCK;
      watchdog->proc_id = proc_id;

      watchdog->resource = rez_id;

      /* calculate the scheduled date */
      date = tpl_get_local_current_date();
      watchdog->start_date = date;
      watchdog->scheduled_date = date + resource_lock_time;

      /* insert the watchdog */
      tpl_schedule_watchdog(watchdog);
    }
  }
#endif
}


/**
 * Function used to stop a resource locking monitor for a task/isr2
 *
 * @param proc_id: owner of the watchdog to stop
 *
 * @param rez_id: resource the owner os blocking
 *
 */
FUNC(void, OS_CODE) tpl_stop_resource_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id,
  CONST(tpl_resource_id, AUTOMATIC) rez_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];
  VAR(tpl_time, AUTOMATIC) resource_lock_time;

#ifndef NO_RESOURCE
  if ((proc->timing_protection != NULL) &&
      (proc->timing_protection->resource_lock_time != NULL))
  {
    resource_lock_time = proc->timing_protection->resource_lock_time[rez_id];

    /* if reousrce lock time is null, it means there is no timing protection for this resource */
    if(resource_lock_time >0)
    {
      /* select the corresponding watchdog */
      watchdog = &tpl_watchdog_resource_monitor[rez_id];

      /* remove the watchdog */
      tpl_unschedule_watchdog(watchdog);
    }
  }
#endif
}


#ifdef WITH_OSAPPLICATION
/**
 * Function used to stop all resource locking monitor for a task/isr2
 *
 * @param proc_id: owner of the watchdog to stop
 *
 */
FUNC(void, OS_CODE) tpl_stop_all_resource_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];
  
#ifndef NO_RESOURCE
  if ((proc->timing_protection != NULL) &&
      (proc->timing_protection->resource_lock_time != NULL))
  {
    VAR(tpl_resource_id, AUTOMATIC) rez_id;
    
    for (rez_id = 0; rez_id < RESOURCE_COUNT; rez_id++)
    {
      VAR(tpl_time, AUTOMATIC) resource_lock_time =
        proc->timing_protection->resource_lock_time[rez_id];
      
      /*  if resource lock time is null, it means there is
          no timing protection for this resource            */
      if (resource_lock_time >0)
      {
        P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
        /* select the corresponding watchdog */
        watchdog = &tpl_watchdog_resource_monitor[rez_id];
        
        /* remove the watchdog */
        tpl_unschedule_watchdog(watchdog);
      }
    }
  }
#endif
}
#endif

/**
 * Function used to start an isr locking monitor for a task/isr2
 *
 * @param proc_id: owner of the watchdog to start
 *
 */
FUNC(void, OS_CODE) tpl_start_all_isr_lock_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];
  VAR(tpl_time, AUTOMATIC) int_lock_time;
  VAR(tpl_time, AUTOMATIC) date;

  if ((proc->timing_protection != NULL) &&
      (proc->timing_protection->all_interrupt_lock_time > 0) )
  {
    /* select the corresponding watchdog */
    watchdog = &tpl_watchdog_all_isr_lock_monitor;

    /* set the watchdog parameters */
    watchdog->type = ALL_INT_LOCK;
    watchdog->proc_id = proc_id;

    /* calculate the scheduled date */
    date = tpl_get_local_current_date();
    watchdog->start_date = date;
    int_lock_time = proc->timing_protection->all_interrupt_lock_time;
    watchdog->scheduled_date = date + int_lock_time;

    /* insert the watchdog */
    tpl_schedule_watchdog(watchdog);
  }
}


/**
 * Function used to stop an isr locking monitor for a task/isr2
 *
 * @param this_exec_obj: owner of the watchdog to stop
 *
 */
FUNC(void, OS_CODE) tpl_stop_all_isr_lock_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];

  if ((proc->timing_protection != NULL) &&
      (proc->timing_protection->all_interrupt_lock_time > 0) )
  {
    /* select the corresponding watchdog */
    watchdog = &tpl_watchdog_all_isr_lock_monitor;

    /* remove the watchdog */
    tpl_unschedule_watchdog(watchdog);
  }
}


/**
 * Function used to start an isr2 locking monitor for a task/isr2
 *
 * @param this_exec_obj: owner of the watchdog to start
 *
 */
FUNC(void, OS_CODE) tpl_start_os_isr_lock_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];
  VAR(tpl_time, AUTOMATIC) int_lock_time;
  VAR(tpl_time, AUTOMATIC) date;


  if ((proc->timing_protection != NULL) &&
      (proc->timing_protection->os_interrupt_lock_time > 0) )
  {
    /* select the corresponding watchdog */
    watchdog = &tpl_watchdog_os_isr_lock_monitor;

    /* set the watchdog parameters */
    watchdog->type = OS_INT_LOCK;
    watchdog->proc_id = proc_id;

    /* calculate the scheduled date */
    date = tpl_get_local_current_date();
    watchdog->start_date = date;
    int_lock_time = proc->timing_protection->os_interrupt_lock_time;
    watchdog->scheduled_date = date + int_lock_time;

    /* insert the watchdog */
    tpl_schedule_watchdog(watchdog);
  }
}


/**
 * Function used to stop an isr2 locking monitor for a task/isr2
 *
 * @param this_exec_obj: owner of the watchdog to stop
 *
 */
FUNC(void, OS_CODE) tpl_stop_os_isr_lock_monitor (
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];

  if ((proc->timing_protection != NULL) &&
      (proc->timing_protection->os_interrupt_lock_time > 0) )
  {
    /* select the corresponding watchdog */
    watchdog = &tpl_watchdog_os_isr_lock_monitor;

    /* remove the watcdhog */
    tpl_unschedule_watchdog(watchdog);
  }
}


/**
 * Function used to insert a watchdog in the watchdog chained list
 *
 * @param watchdog: watchdog to be inserted
 *
 */
STATIC FUNC(void, OS_CODE) tpl_schedule_watchdog(
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog)
{
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) next_watchdog;
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) previous_watchdog;
  VAR(tpl_time, AUTOMATIC) current_date;
  VAR(tpl_time, AUTOMATIC) date;

  /* initializes the previous and next watchdog,
     beginning from the first watchdog in the queue */
  next_watchdog = tpl_earliest_watchdog;
  previous_watchdog = NULL;

  /* if the watchdog has to be the first */
  if ((tpl_earliest_watchdog == NULL) ||
      ((watchdog->scheduled_date) < (tpl_earliest_watchdog->scheduled_date)))
  {
    /* insert the watchdog before the earliest */
    watchdog->next = tpl_earliest_watchdog;
    watchdog->previous = NULL;
    tpl_earliest_watchdog = watchdog;
    if (watchdog->next != NULL)
    {
      watchdog->next->previous = watchdog;
    }

    current_date = tpl_get_local_current_date();
    date = (watchdog->scheduled_date) - current_date;

    tpl_cancel_watchdog();
    tpl_set_watchdog(date);
  }
  /* else the watchdog has to be inserted in the middle
     or at the end of the queue */
  else
  {
    /* continue until the watchdog scheduled date is lower than the current */
    while ((next_watchdog!=NULL) && 
           ((watchdog->scheduled_date) >= (next_watchdog->scheduled_date)))
    {
      previous_watchdog = next_watchdog;
      next_watchdog=next_watchdog->next;
    }

    /* then insert the wqtchdog between the next and the previous */
    watchdog->next = next_watchdog;
    watchdog->previous = previous_watchdog;

    previous_watchdog->next = watchdog;
    if (next_watchdog != NULL )
    {
      next_watchdog->previous = watchdog;
    }
  }
}


/**
 * Function used to remove a watchdog from the watchdog chained list
 *
 * @param watchdog: watchdog to be removed
 *
 */
STATIC FUNC(void, OS_CODE) tpl_unschedule_watchdog(
  P2VAR(tpl_watchdog, AUTOMATIC, OS_VAR_NOINIT) watchdog)
{
  VAR(tpl_time, AUTOMATIC) current_date;
  VAR(tpl_time, AUTOMATIC) date;

  /* if the watchdog to remove is the first one */
  if (watchdog == tpl_earliest_watchdog)
  {
    if (watchdog->next != NULL)
    {
      watchdog->next->previous = NULL;

      /*  if the new first watchdog has a different expiration date,
          we have to start it                                           */
      tpl_earliest_watchdog = watchdog->next;

      if ((tpl_earliest_watchdog->scheduled_date) > (watchdog->scheduled_date))
      {
        /* calculate time until the next watchdog expiration */
        current_date = tpl_get_local_current_date();
        date = (tpl_earliest_watchdog->scheduled_date) - current_date;

        /* start the next watchdog timer */
        tpl_cancel_watchdog();
        tpl_set_watchdog(date);
      }
    }
    else
    {
      /*  if the next watchdog is null, the queue is now empty,
          we do not have to start another watchdog                    */
      tpl_earliest_watchdog = NULL;

      tpl_cancel_watchdog();
    }
  }
  else
  {
    /* if the watchdog is not the first, we just remove it from the queue */
    if (watchdog->next != NULL)
    {
      watchdog->next->previous = watchdog->previous;
    }
    watchdog->previous->next = watchdog->next;
  }
}


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#else /* defined WITH_AUTOSAR_TIMING_PROTECTION */
volatile static u8 nothing;
#endif /* !defined WITH_AUTOSAR_TIMING_PROTECTION */
