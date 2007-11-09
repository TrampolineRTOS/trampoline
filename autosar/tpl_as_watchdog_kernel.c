/**
 * @file tpl_as_watchdog_kernel.c
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
#include "tpl_as_watchdog_kernel.h"
#include "tpl_dow.h"

#if defined WITH_AUTOSAR_TIMING_PROTECTION

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

_STATIC_ VAR(tpl_scheduled_watchdog, OS_VAR) scheduled_watchdogs[MAXIMUM_SCHEDULED_WATCHDOGS];

_STATIC_ P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, OS_VAR) earliest_watchdog = NULL;

_STATIC_ VAR(watchdog_callback_function, AUTOMATIC) external_watchdog_callback = NULL;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

_STATIC_ FUNC(u8, OS_CODE) internal_watchdog_callback(void)
{
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) current_scheduled_watchdog;
  VAR(u8, AUTOMATIC) result;
  VAR(u8, AUTOMATIC) continue_loop;

  result = FALSE;

  /*
   * loop while there is watchdog to raise this time
   */
  do
  {
    current_scheduled_watchdog = earliest_watchdog;
    /* delete virtual watchdog and jump to next one */
    current_scheduled_watchdog->allocated = FALSE;
    earliest_watchdog = earliest_watchdog->next;

    /* as the list can be modified later by callback, we check now
     * if we need to exit the loop (this is really useful when
     * the list is emptied here and refilled by the callback
     */
    continue_loop = (earliest_watchdog != NULL) &&
       (earliest_watchdog->delay_from_previous == 0);

    DOW_ASSERT (external_watchdog_callback != NULL);
    if (external_watchdog_callback (&(current_scheduled_watchdog->watchdog)))
        result = TRUE;
  }
  while (continue_loop);

  /*
   * schedule the next earliest watchdog
   */
  if (earliest_watchdog != NULL)
  {
    tpl_set_watchdog (earliest_watchdog->delay_from_previous,
       internal_watchdog_callback);
    earliest_watchdog->delay_from_previous = 0;
  }

  return result;
}

FUNC(void, OS_CODE) init_watchdog_kernel(
  VAR(watchdog_callback_function, AUTOMATIC) callback)
{
  VAR(tpl_scheduled_watchdog_id, AUTOMATIC) watchdog_id;

  earliest_watchdog = NULL;
  for (watchdog_id = 0 ;
     watchdog_id < MAXIMUM_SCHEDULED_WATCHDOGS ;
     watchdog_id++)
  {
    scheduled_watchdogs[watchdog_id].allocated = 0;
  }

  external_watchdog_callback = callback;
}

FUNC(P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC), OS_CODE) new_scheduled_watchdog(void)
{
  VAR(tpl_scheduled_watchdog_id, AUTOMATIC) watchdog_id;

  watchdog_id = 0;
  while (scheduled_watchdogs[watchdog_id].allocated)
  {
    watchdog_id++;
    DOW_ASSERT (watchdog_id < MAXIMUM_SCHEDULED_WATCHDOGS);
  }

  scheduled_watchdogs[watchdog_id].allocated = TRUE;

  return &scheduled_watchdogs[watchdog_id];
}

FUNC(u8, OS_CODE) insert_scheduled_watchdog(
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) this_scheduled_watchdog)
{
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) watchdog_cursor;
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) previous_cursor;
  VAR(u8, AUTOMATIC) result;

  result = FALSE;

  if ((earliest_watchdog == NULL) ||
     (this_scheduled_watchdog->scheduled_date <
      earliest_watchdog->scheduled_date))
  {

    /* insert at the head of the list */
    this_scheduled_watchdog->next = earliest_watchdog;
    this_scheduled_watchdog->delay_from_previous = 0;
    if (this_scheduled_watchdog->next != NULL)
    {
      this_scheduled_watchdog->next->delay_from_previous =
         this_scheduled_watchdog->next->scheduled_date -
         this_scheduled_watchdog->scheduled_date;
    }
    earliest_watchdog = this_scheduled_watchdog;
    /* we need to set the low level watchdog
     * as the earliest changed */
    result = TRUE;
  }
  else
  {
    /* look for the position in the list, FIFO policy is used
     * if expire date matches an existing watchdog */
    watchdog_cursor = earliest_watchdog;
    DOW_ASSERT (watchdog_cursor != NULL);
/*    DOW_ASSERT (new_watchdog->scheduled_date >=
       watchdog_cursor->scheduled_date); */
    while ((watchdog_cursor != NULL) &&
       (this_scheduled_watchdog->scheduled_date >=
       watchdog_cursor->scheduled_date))
    {
      /* previous_cursor is used for queue insert, to chain the previous
       * watchdog to the current without rescanning the list
       */
      previous_cursor = watchdog_cursor;
      watchdog_cursor = watchdog_cursor->next;
    }

    /* insert at the end of the list ? */
    if (watchdog_cursor == NULL)
    {
      DOW_ASSERT (previous_cursor->next == NULL);
      this_scheduled_watchdog->next = NULL;
      this_scheduled_watchdog->delay_from_previous =
         this_scheduled_watchdog->scheduled_date -
         previous_cursor->scheduled_date;
      previous_cursor->next = this_scheduled_watchdog;
    }
    else
    {
      this_scheduled_watchdog->next = watchdog_cursor;
      this_scheduled_watchdog->delay_from_previous =
         this_scheduled_watchdog->scheduled_date -
         watchdog_cursor->scheduled_date;
      previous_cursor->next = this_scheduled_watchdog;
      this_scheduled_watchdog->next->delay_from_previous -=
         this_scheduled_watchdog->delay_from_previous;
    }
  }

  return result;
}

FUNC(u8, OS_CODE) find_scheduled_watchdog(
  P2VAR(tpl_watchdog, OS_APPL_DATA, AUTOMATIC) like_this_watchdog,
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) *watchdog_cursor,
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) *previous_cursor)
{
  VAR(u8, AUTOMATIC) result;

  *watchdog_cursor = earliest_watchdog;
  *previous_cursor = *watchdog_cursor;
  result = FALSE;
  while ((!result) && (*watchdog_cursor != NULL))
  {
    if (like_this_watchdog->exec_obj == (*watchdog_cursor)->watchdog.exec_obj)
    {
      if (like_this_watchdog->type == (*watchdog_cursor)->watchdog.type)
      {
        if (like_this_watchdog->type == REZ_LOCK)
        {
          if (like_this_watchdog->resource ==
              (*watchdog_cursor)->watchdog.resource)
            result = TRUE;
        }
        else
          result = TRUE;
      }
    }
    if (!result)
    {
      *previous_cursor = *watchdog_cursor;
      *watchdog_cursor = (*watchdog_cursor)->next;
    }
  }

  return result;
}

FUNC(u8, OS_CODE) remove_scheduled_watchdog(
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) watchdog_cursor,
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) previous_cursor)
{
  VAR(u8, AUTOMATIC) result;

  result = FALSE;

  if (watchdog_cursor == earliest_watchdog)
  {
    result = TRUE;

    earliest_watchdog = earliest_watchdog->next;
    if (earliest_watchdog != NULL)
    {
      earliest_watchdog->delay_from_previous = 0;
    }
  }
  else
  {
    previous_cursor->next = watchdog_cursor->next;
    if (previous_cursor->next != NULL)
    {
      previous_cursor->next->delay_from_previous +=
         watchdog_cursor->delay_from_previous;
    }
  }
  watchdog_cursor->allocated = FALSE;

  return result;
}

/**
 * @internal
 *
 * removes all scheduled watchdogs related to a task/isr from the list
 *
 * @note this function is intended to be called by the watchdog callback
 * (or internally in this module)
 *
 * @param this_exec_obj the task/isr which watchdog will be removed
 *
 * @retval FALSE the scheduled watchdog is not the earliest in the list
 * @retval TRUE the scheduled watchdog is the earliest in the list
 */
_STATIC_ FUNC(u8, OS_CODE) remove_all_exec_obj_watchdogs(
  P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(u8, AUTOMATIC) result;
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) watchdog_cursor;
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) previous_cursor;

  result = FALSE;

  watchdog_cursor = earliest_watchdog;
  previous_cursor = NULL;
  while (watchdog_cursor != NULL)
  {
    if (watchdog_cursor->watchdog.exec_obj == this_exec_obj)
    {
      if (remove_scheduled_watchdog (watchdog_cursor, previous_cursor) == TRUE)
        result = TRUE;
    }
    previous_cursor = watchdog_cursor;
    watchdog_cursor = watchdog_cursor->next;
  }

  return result;
}

FUNC(void, OS_CODE) schedule_watchdog(
  P2VAR(tpl_watchdog, OS_APPL_DATA, AUTOMATIC) this_watchdog,
  VAR(tpl_time, AUTOMATIC) expire_delay)
{
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) new_watchdog;
  VAR(tpl_time, AUTOMATIC) expire_date;
  VAR(tpl_time, AUTOMATIC) current_date;

  DOW_ASSERT (this_watchdog != NULL);
  DOW_ASSERT (expire_delay > 0);

  /* get only one time reference */
  current_date = tpl_get_local_current_date ();

  /* find a free watchdog */
  new_watchdog = new_scheduled_watchdog ();

  /* compute the expire date */
  expire_date = current_date + expire_delay;

  /* prepare the watchdog scheduling */
  new_watchdog->watchdog.exec_obj = this_watchdog->exec_obj;
  new_watchdog->watchdog.type = this_watchdog->type;
  new_watchdog->watchdog.resource = this_watchdog->resource;
  new_watchdog->scheduled_date = expire_date;

  /*
   * insert the watchdog in the list
   */
  if (insert_scheduled_watchdog(new_watchdog))
  {
    /* reschedule the real watchdog only if head of list changed */
    tpl_cancel_watchdog ();
    tpl_set_watchdog (expire_delay, internal_watchdog_callback);
  }
}

FUNC(void, OS_CODE) unschedule_watchdog(
  P2VAR(tpl_watchdog, OS_APPL_DATA, AUTOMATIC) this_watchdog)
{
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) watchdog_cursor;
  P2VAR(tpl_scheduled_watchdog, OS_APPL_DATA, AUTOMATIC) previous_cursor;
  VAR(u8, AUTOMATIC) found;

  DOW_ASSERT (this_watchdog != NULL);

  /* look for an similar watchdog */
  found = find_scheduled_watchdog (this_watchdog,
     &watchdog_cursor, &previous_cursor);

  if (found)
  {
    if (remove_scheduled_watchdog(watchdog_cursor, previous_cursor))
    {
      tpl_cancel_watchdog ();
      if (earliest_watchdog != NULL)
      {
        tpl_set_watchdog (tpl_get_local_current_date() -
           earliest_watchdog->scheduled_date, internal_watchdog_callback);
      }
    }
  }
}

FUNC(void, OS_CODE) unschedule_exec_obj_watchdogs (
  P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(u8, AUTOMATIC) need_to_reschedule;

  DOW_ASSERT (this_exec_obj != NULL);

  need_to_reschedule = remove_all_exec_obj_watchdogs (this_exec_obj);

  if (need_to_reschedule)
  {
    tpl_cancel_watchdog ();
    if (earliest_watchdog != NULL)
    {
      tpl_set_watchdog (tpl_get_local_current_date() -
         earliest_watchdog->scheduled_date, internal_watchdog_callback);
    }
  }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#else
/* some compiler do not work with empty source files */
static char nothing;
#endif /* !defined WITH_AUTOSAR_TIMING_PROTECTION */

