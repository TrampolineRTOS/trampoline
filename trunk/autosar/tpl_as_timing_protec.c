/**
 * @file tpl_as_timing_protec.c
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

typedef enum
{
  EXEC_BUDGET,
  TIME_LIMIT,
  ALL_INT_LOCK,
  OS_INT_LOCK,
  REZ_LOCK,
  TIMEFRAME_BOUNDARY
} tpl_watchdog_type;

typedef struct
{
  tpl_exec_common   *exec_obj;
  tpl_watchdog_type type;
  tpl_resource_id   resource;
} tpl_watchdog;

struct TPL_SCHEDULED_WATCHDOG
{
  tpl_watchdog                   watchdog;
  struct TPL_SCHEDULED_WATCHDOG  *next;
  tpl_time                       delay_from_previous;
  tpl_time                       scheduled_date;
  u8                             allocated;
};

typedef struct TPL_SCHEDULED_WATCHDOG tpl_scheduled_watchdog;

static tpl_scheduled_watchdog scheduled_watchdogs[MAXIMUM_SCHEDULED_WATCHDOGS];

static tpl_scheduled_watchdog *earliest_watchdog;

/*
 * forward prototypes
 */
static void schedule_watchdog (tpl_watchdog *this_watchdog, 
   tpl_time expire_delay);
static void unschedule_watchdog (tpl_watchdog *this_watchdog);

static tpl_time delay_to_next_timeframe (tpl_time timeframe)
{
  tpl_time result;

  result = timeframe;
  result -= tpl_get_local_current_date () % timeframe;

  return result;
}

static void watchdog_callback ()
{
  tpl_exec_common *exec_obj;
  
  do
  {
    switch (earliest_watchdog->watchdog.type)
    {
      case EXEC_BUDGET:
      case TIME_LIMIT:
        tpl_call_protection_hook (E_OS_PROTECTION_TIME);
        break;
      case REZ_LOCK:
      case ALL_INT_LOCK:
      case OS_INT_LOCK:
        tpl_call_protection_hook (E_OS_PROTECTION_LOCKED);
        break;
      case TIMEFRAME_BOUNDARY:
        exec_obj = earliest_watchdog->watchdog.exec_obj;
        if (exec_obj->static_desc->type != IS_ROUTINE)
        {
          /* reset execution budget for the task */
          exec_obj->time_left =
             exec_obj->static_desc->timing_protection->execution_budget;
        }
        else
        {
          /* unlock this ISR2 if needed */
          if (exec_obj->static_desc->timing_protection->count_limit == 0)
            tpl_enable_isr2 ((tpl_isr*)exec_obj);
          
          /* reset the activation countdown for the isr */
          exec_obj->time_left = 
             exec_obj->static_desc->timing_protection->count_limit;
        }

        /* reschedule next timeframe end boundary */
        schedule_watchdog (&(earliest_watchdog->watchdog),
           exec_obj->static_desc->timing_protection->timeframe);
        break;
      default:
        DOW_ASSERT (0);
        break;
    }
    
    /* jump to next watchdog */
    earliest_watchdog = earliest_watchdog->next;
  } while ((earliest_watchdog != NULL) && 
     (earliest_watchdog->delay_from_previous == 0));
  
  /* schedule the next earliest watchdog */
  if (earliest_watchdog != NULL)
    set_watchdog (earliest_watchdog->delay_from_previous, watchdog_callback);   
}

/**
 * Schedule a watchdog at specified date
 * 
 * @param this_watchdog watchdog to schedule (data are copied)
 * @param expire_date date when the watchdog should expire
 */
static void schedule_watchdog (tpl_watchdog *this_watchdog, 
   tpl_time expire_delay)
{  
  tpl_scheduled_watchdog *new_watchdog;
  tpl_scheduled_watchdog *watchdog_cursor;
  tpl_scheduled_watchdog *previous_cursor;
  tpl_scheduled_watchdog_id watchdog_id;
  tpl_time expire_date;
  tpl_time current_date;
  
  /* find a free watchdog */
  watchdog_id = 0;
  while (scheduled_watchdogs[watchdog_id].allocated)
  {
    watchdog_id++;
    DOW_ASSERT (watchdog_id < MAXIMUM_SCHEDULED_WATCHDOGS);
  }
  new_watchdog = &scheduled_watchdogs[watchdog_id];
  
  /* prepare the watchdog scheduling */
  new_watchdog->watchdog.exec_obj = this_watchdog->exec_obj;
  new_watchdog->watchdog.type = this_watchdog->type;
  new_watchdog->watchdog.resource = this_watchdog->resource;
  new_watchdog->scheduled_date = expire_date;
  new_watchdog->allocated = TRUE;
  
  /* get the time reference */
  current_date = tpl_get_local_current_date ();
  expire_date = current_date + expire_delay;
  
  /* insert the watchdog in the list */
  if ((earliest_watchdog != 0) &&
     (expire_date >= earliest_watchdog->scheduled_date))
  {
    /* look for the position in the list, FIFO policy is used
     * if expire date matches an existing watchdog */
    watchdog_cursor = earliest_watchdog;
    while ((watchdog_cursor != NULL) &&
       (new_watchdog->scheduled_date <= watchdog_cursor->scheduled_date))
    {
      previous_cursor = watchdog_cursor; /* only used for queue insert */
      watchdog_cursor = watchdog_cursor->next;
    }
    
    /* insert at the end of the list ? */
    if ((watchdog_cursor == NULL) || (earliest_watchdog->next == NULL))
    {
      new_watchdog->next = NULL;
      new_watchdog->delay_from_previous =
         expire_date - previous_cursor->scheduled_date;
      previous_cursor->next = new_watchdog; 
    }
    else
    {
      new_watchdog->next = watchdog_cursor->next;
      new_watchdog->delay_from_previous =
         expire_date - watchdog_cursor->scheduled_date;
      watchdog_cursor->next = new_watchdog;
      new_watchdog->next->delay_from_previous -=
         new_watchdog->delay_from_previous;
    }
  }
  else
  {
    /* insert at the head of the list */
    new_watchdog->next = earliest_watchdog;
    new_watchdog->delay_from_previous = 0;
    if (new_watchdog->next != NULL)
    {
      new_watchdog->next->delay_from_previous -=
         new_watchdog->scheduled_date; 
    }
    earliest_watchdog = new_watchdog;
    
    /* we need to set the low level watchdog
     * as the earliest changed */
    set_watchdog (expire_delay, watchdog_callback);
  }
}

/**
 * Cancels a watchdog to avoid its expiration.
 */
static void unschedule_watchdog (tpl_watchdog *this_watchdog)
{
  tpl_scheduled_watchdog *watchdog_cursor;
  tpl_scheduled_watchdog *previous_cursor;
  u8 found;
  
  /* look for an similar watchdog */
  watchdog_cursor = earliest_watchdog;
  previous_cursor = watchdog_cursor;
  do
  {
    if (this_watchdog->exec_obj == watchdog_cursor->watchdog.exec_obj)
    {
      if (this_watchdog->type == watchdog_cursor->watchdog.type)
      {
        if (this_watchdog->type == REZ_LOCK)
        {
          if (this_watchdog->resource == watchdog_cursor->watchdog.resource)
            found = TRUE;
        }
        else
          found = TRUE;
      } 
    }
    if (!found)
    {
      previous_cursor = watchdog_cursor;
      watchdog_cursor = watchdog_cursor->next;
    }
  }
  while ((!found) && (watchdog_cursor != NULL));
  
  if (found)
  {
    /* do we delete the earliest cursor ? */
    if (watchdog_cursor == previous_cursor)
    {
      /* restart underlying watchdog */
      cancel_watchdog ();
      if (earliest_watchdog->next != NULL)
        set_watchdog (earliest_watchdog->next->delay_from_previous, 
           watchdog_callback);
      /* update the list */
      earliest_watchdog = earliest_watchdog->next;
      if (earliest_watchdog != NULL)
        earliest_watchdog->delay_from_previous = 0;
      watchdog_cursor->allocated = FALSE;
    }
    else
    {
      previous_cursor->next = watchdog_cursor->next;
      watchdog_cursor->allocated = 0; 
    }
  }
}

static void start_timeframe (tpl_exec_common *this_exec_obj)
{
  tpl_watchdog watchdog;
  tpl_time timeframe;
  tpl_time delay_to_timeframe;

  /* schedule the timeframe end boundary's watchdog 
  * (timeframe period is synchronized with the current date
  * modulo timeframe, see delay_to_next_timeframe function)
  */
  timeframe = this_exec_obj->static_desc->timing_protection->timeframe;
  delay_to_timeframe = delay_to_next_timeframe (timeframe);
  if (delay_to_timeframe == 0)
    delay_to_timeframe = timeframe;
  watchdog.exec_obj = this_exec_obj;
  watchdog.type = TIMEFRAME_BOUNDARY;
  schedule_watchdog (&watchdog, delay_to_timeframe);
}

static void stop_timeframe (tpl_exec_common *this_exec_obj)
{
  tpl_watchdog watchdog;

  watchdog.exec_obj = this_exec_obj; 
  watchdog.type = TIMEFRAME_BOUNDARY;
  unschedule_watchdog (&watchdog);
}

void tpl_init_timing_protection ()
{
  tpl_scheduled_watchdog_id watchdog_id;
   
  earliest_watchdog = NULL;
  for (watchdog_id = 0 ; 
     watchdog_id < MAXIMUM_SCHEDULED_WATCHDOGS ; 
     watchdog_id++)
  {
    scheduled_watchdogs[watchdog_id].allocated = 0;
  }
}

void tpl_start_budget_monitor (tpl_exec_common *this_exec_obj)
{
  tpl_watchdog watchdog;
  
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
    start_timeframe (this_exec_obj);
  }
}

void tpl_pause_budget_monitor (tpl_exec_common *this_exec_obj)
{
  tpl_watchdog watchdog; 
    
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

void tpl_continue_budget_monitor (tpl_exec_common *this_exec_obj)
{
  tpl_watchdog watchdog;
  tpl_time current_date;

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

void tpl_disable_budget_monitor (tpl_exec_common *this_exec_obj)
{
  tpl_watchdog watchdog; 
    
  if (this_exec_obj->static_desc->timing_protection != NULL)
  {
    /* unschedule the related watchdogs */
    watchdog.exec_obj = this_exec_obj;
    watchdog.type = EXEC_BUDGET;
    unschedule_watchdog (&watchdog);

    /* stops the timeframe watchdog */
    stop_timeframe (this_exec_obj);
  }
}

void tpl_reset_activation_count (tpl_exec_common *this_exec_obj)
{
  this_exec_obj->time_left =
     this_exec_obj->static_desc->timing_protection->count_limit + 1;
}

void tpl_add_activation_count (tpl_exec_common *this_exec_obj)
{
  if (this_exec_obj->time_left > 0)
    this_exec_obj->time_left -= 1;
    
  if (this_exec_obj->time_left == 0)
  {
    tpl_disable_isr2 ((tpl_isr*)this_exec_obj);
  }
}

void tpl_start_exectime_monitor (tpl_exec_common *this_exec_obj)
{
  this_exec_obj->monitor_start_date = tpl_get_local_current_date ();
}

void tpl_finish_exectime_monitor (tpl_exec_common *this_exec_obj)
{
  tpl_time execution_time;

  execution_time = tpl_get_local_current_date () -
     this_exec_obj->monitor_start_date;
  if (execution_time > 
     this_exec_obj->static_desc->timing_protection->execution_budget)
  {
    tpl_call_protection_hook (E_OS_PROTECTION_TIME);
  }
}

void tpl_start_resource_monitor (tpl_exec_common *this_exec_obj, 
   tpl_resource_id this_resource)
{
  tpl_watchdog watchdog;
  tpl_time resource_lock_time;

  /* nothing to do if no timing protection specified */
  if ((this_exec_obj->static_desc->timing_protection != NULL) &&
      (this_exec_obj->static_desc->timing_protection->resource_lock_time != 
      NULL))
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

void tpl_disable_resource_monitor (tpl_exec_common *this_exec_obj, 
   tpl_resource_id this_resource)
{
  tpl_watchdog watchdog;
  
  watchdog.exec_obj = this_exec_obj;
  watchdog.type = REZ_LOCK;
  watchdog.resource = this_resource;
  unschedule_watchdog (&watchdog);
}

void tpl_start_all_isr_lock_monitor (tpl_exec_common *this_exec_obj)
{
  tpl_watchdog watchdog;
  tpl_time int_lock_time;

  /* nothing to do if no timing protection specified */
  if ((this_exec_obj->static_desc->timing_protection != NULL) &&
      (this_exec_obj->static_desc->timing_protection-> all_interrupt_lock_time 
      > 0))
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

void tpl_disable_all_isr_lock_monitor (tpl_exec_common *this_exec_obj)
{
  tpl_watchdog watchdog;
  
  watchdog.exec_obj = this_exec_obj;
  watchdog.type = ALL_INT_LOCK;
  unschedule_watchdog (&watchdog);
}

void tpl_start_os_isr_lock_monitor (tpl_exec_common *this_exec_obj)
{
  tpl_watchdog watchdog;
  tpl_time int_lock_time;

  /* nothing to do if no timing protection specified */
  if ((this_exec_obj->static_desc->timing_protection != NULL) &&
      (this_exec_obj->static_desc->timing_protection-> all_interrupt_lock_time 
      > 0))
  {
    /* get the maximum time the interrupts can be locked */
    int_lock_time = 
       this_exec_obj->static_desc->timing_protection->all_interrupt_lock_time;
       
    /* schedule a watchdog */
    watchdog.exec_obj = this_exec_obj;  
    watchdog.type = OS_INT_LOCK;
    schedule_watchdog (&watchdog, int_lock_time);
  }
}

void tpl_disable_os_isr_lock_monitor (tpl_exec_common *this_exec_obj)
{
  tpl_watchdog watchdog;
  
  watchdog.exec_obj = this_exec_obj;
  watchdog.type = OS_INT_LOCK;
  unschedule_watchdog (&watchdog);
}
