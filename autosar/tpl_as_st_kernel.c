/**
 * @file tpl_as_st_kernel.c
 *
 * @internal
 *
 * @section desc File description
 *
 * Trampoline autosar extension software schedule tables machinery
 * implementation file
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

#include "tpl_as_st_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_as_error.h"
#include "tpl_os_errorhook.h"
#include "tpl_as_protec_hook.h"
#include "tpl_machine_interface.h"
#include "tpl_dow.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

STATIC FUNC(tpl_tick, OS_CODE) tpl_min(
   VAR(tpl_tick, AUTOMATIC) var_1,
   VAR(tpl_tick, AUTOMATIC) var_2);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * This returns the min of 2 values provided
 */
STATIC FUNC(tpl_tick, OS_CODE) tpl_min(
   VAR(tpl_tick, AUTOMATIC) var_1,
   VAR(tpl_tick, AUTOMATIC) var_2)
{
  VAR(tpl_tick, AUTOMATIC) return_value;

  if(var_1 > var_2)
  {
    return_value = var_2;
  }
  else
  {
    return_value = var_1;
  }
  return return_value;
}



/*
 * This function is called when the alarm wrapped to the schedule table is
 * raised. After getting the static part of the alarm (that in this case is
 * a TPL_SCHEDTABLE_STATIC structure, this function get the next expiry point
 * and execute the corresponding actions. Then the alarm is updated to match
 * the offset of the next expiry point.
 */
FUNC(tpl_status, OS_CODE) tpl_process_schedtable(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st)
{
    /*  Get the TPL_SCHEDTABLE_STATIC structure                             */
    /* MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
      tpl_schedtable_static*. This cast behaves correctly because st is a
      tpl_schedtable */
    P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable =
        (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))st->stat_part;
    /*  Get the current index                                               */
    /* MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
      tpl_schedtable*. This cast behaves correctly because the first member
      of tpl_schedula_table is a tpl_time_obj */
    VAR(tpl_expiry_count, AUTOMATIC)  index =
        ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index;
    /*  Get the current expiry point                                        */
    P2VAR(tpl_expiry_point, AUTOMATIC, OS_APPL_DATA) next_ep =
        (schedtable->expiry)[index];

    /*  Process the current expiry point                                    */
    VAR(tpl_status, AUTOMATIC)              need_resched = NO_SPECIAL_CODE;

    P2VAR(tpl_action, AUTOMATIC, OS_APPL_DATA)  action_desc;
    VAR(tpl_action_count, AUTOMATIC)  i;

    VAR(tpl_tick, AUTOMATIC) before;
    VAR(tpl_tick, AUTOMATIC) deviation;

    for (i = 0; i < next_ep->count; i++)
    {
        action_desc = (next_ep->actions)[i];
        need_resched |= TRAMPOLINE_STATUS_MASK & (action_desc->action)(action_desc);
    }

    /* reset the offset of last expiry point to its default value,
       because adjustment for synchronisation of this expiry point has been done */
    (schedtable->expiry)[index]->sync_offset = (schedtable->expiry)[index]->offset;

    /*  Prepare the next expiry point                                       */
    index++;

    /*  Reset the cycle of the time object                                  */
    st->cycle = 0;

    /*  Test whether the schedule table is finished or not                  */
    if (index < schedtable->count)
    {
        /*  The schedule table is not finished                              */
        /*  Set the next cycle to the offset of the next expiry point
            (offsets are not relative to the start of the schedule table
            but to the previous expiry point                                */
        /* MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
          tpl_schedtable*. This cast behaves correctly because the first memeber
          of tpl_schedule_table is a tpl_time_obj */
        st->cycle = (schedtable->expiry)[index]->sync_offset;
        ((tpl_schedule_table *)st)->index = index;

        /* calculate the absolute value of the deviation */
        if ((schedtable->expiry)[index]->sync_offset >=
            (schedtable->expiry)[index]->offset )
        {
            deviation = (schedtable->expiry)[index]->sync_offset -
                        (schedtable->expiry)[index]->offset;
        }
        else
        {
            deviation = (schedtable->expiry)[index]->offset -
                        (schedtable->expiry)[index]->sync_offset;
        }

        /* if deviation is less than the configured precision,
           the schedule table is considered synchronized */
        if (deviation <= (schedtable->precision))
        {
            st->state = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
        }
        else
        {
            st->state = SCHEDULETABLE_RUNNING;
        }

    }
    else {
        /*  The schedule table is finished                                  */
        /*  Test whether a schedule table has been « nextified » or not     */
        /*  MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
            tpl_schedtable*. This cast behaves correctly because the
            first member of tpl_schedula_table is a tpl_time_obj            */
        tpl_schedule_table *next = ((tpl_schedule_table *)st)->next;
        /*  Get the remaining time to fill the current schedule table
            period. This time is stored in the offset of the first expiry
            point                                                           */
        before = (schedtable->expiry)[0]->offset;
        if (next != NULL) {
            /*  reset the state of the current schedule table               */
            st->state = SCHEDULETABLE_STOPPED;
            /*  There is a next schedule table set, start it                */
            next->b_desc.date =
                next->b_desc.stat_part->counter->current_date + before;
        /*  MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
            tpl_time_obj*. This cast behaves correctly because the
            first member of tpl_schedule_table is a tpl_time_obj            */
            ((tpl_time_obj *)next)->state = SCHEDULETABLE_RUNNING;
            tpl_insert_time_obj((tpl_time_obj *)next);
        }
        else if (schedtable->periodic == TRUE) {
            /*  No next schedule table but the current table is periodic    */
            st->cycle = before;
        }
        else {
            /*  reset the state of the current schedule table               */
            st->state = SCHEDULETABLE_STOPPED;
        }
        /*  Reset the index                                                 */
        /*  MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
            tpl_schedtable*. This cast behaves correctly because the
            first memberof tpl_schedule_table is a tpl_time_obj             */
        ((tpl_schedule_table *)st)->index = 0;
    }

    return need_resched;
}



/*
 * This function is called after a schedule table has been started
 * synchronously, when the synchronized time is provided to OS
 */
FUNC(void, OS_CODE) tpl_start_sched_table_sync(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st,
    VAR(tpl_time, AUTOMATIC) sync_date)
{
  /*  MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
      tpl_schedtable_static*. This cast behaves correctly because the
      first member of tpl_schedtable_static is a tpl_time_obj_static      */
  P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable =
        (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))st->stat_part;

  /* compute the start date of the synchronized schedule table:
   * start date = drive_cnt.now + (duration - sync_date)
   */
  st->date = (st->stat_part->counter->current_date)
             + (st->date) + ((schedtable->length) - sync_date);

  /* as the schdule table is started synchronously, it is synchronous     */
  st->state = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;

  /* insert the schedule table in the queue */
  tpl_insert_time_obj(st);
}



  /*
   * This function is called when a schedule table has been started
   * asynchronously and the synchronized time is provided to the OS
   */
FUNC(void, OS_CODE) tpl_sync_sched_table(
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)  st,
  VAR(tpl_time, AUTOMATIC)                      sync_date)
{
  /*  Get the TPL_SCHEDTABLE_STATIC structure                             */
  P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable;
  /*  Get the current index                                               */
  VAR(tpl_expiry_count, AUTOMATIC)  index;
  VAR(tpl_expiry_count, AUTOMATIC)  j;
  /*  Get the current expiry point                                        */
  P2VAR(tpl_expiry_point, AUTOMATIC, OS_APPL_DATA) next_ep;

  VAR(tpl_tick, AUTOMATIC)  drive_cnt_now;
  VAR(tpl_tick, AUTOMATIC)  drive_cnt_match;
  VAR(tpl_tick, AUTOMATIC)  position_on_tbl;
  VAR(tpl_tick, AUTOMATIC)  adjustment;
  VAR(tpl_tick, AUTOMATIC)  next_ep_offset=0;
  VAR(tpl_tick, AUTOMATIC)  deviation;

  /* remove the next expiry point, because its date is going to be changed */
  tpl_remove_time_obj(st);

  /* get the current date of the counter which drives the schedule table  */
  drive_cnt_now = st->stat_part->counter->current_date;

  /* get the date of expiration of the next expiry point */
  drive_cnt_match = st->date;

  /* MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
     tpl_schedtable_static*. This cast behaves correctly because st is a
     tpl_schedtable */
  schedtable =
      (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))(st->stat_part);
  /* MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
     tpl_schedtable*. This cast behaves correctly because the first memeber
     of tpl_schedule_table is a tpl_time_obj */
  index = ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index;

  /* this loop calculates the offset of the next_expiry point
     from the start of the schedule table */
  for(j = 0; j <= index; j++)
  {
    next_ep_offset = next_ep_offset +
                     (((schedtable->expiry)[j])->sync_offset);
  }

  /* calculate the current position in the schedule table */
  position_on_tbl = next_ep_offset;
  position_on_tbl = position_on_tbl - (drive_cnt_match - drive_cnt_now);

  /* compute resynchronization for each expiry point until
   * the end of the schedule table or the schedule table is synchronized
   */
  do
  {
    /* get the new next expiry point to compute */
    next_ep = ((schedtable->expiry)[index]);

    /* the algorithm is quite different if deviation is advance or overdue */
    if( position_on_tbl >= sync_date) /* advance */
    {
      /*  from the current date, calculate the deviation with the
          synchronisation time                                        */
      deviation = position_on_tbl - sync_date;
      /*  calculate offset adjustment for this expiry point,
       *  refer to OS420 of Autosar spec
       */
      adjustment = tpl_min(deviation, (next_ep->max_advance));
      next_ep->sync_offset = next_ep->offset + adjustment;
    }
    else /* overdue */
    {
      /*  from the current date, calculate the deviation with the
          synchronisation time                                        */
      deviation = sync_date - position_on_tbl;
      /* calculate offset adjustment for this expiry point,
       * refer to OS421 of Autosar spec
       */
      adjustment = tpl_min(deviation, (next_ep->max_retard));

      /* if this is the next expiry point, we have to take care that the
       * adjustment will not set the date before the current date
       */
      /*  MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
          tpl_schedule_table*. This cast behaves correctly because the
          first member of tpl_schedule_table is a tpl_time_obj        */
      if (index ==
          ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index)
      {
        if (adjustment >= ((st->date) - drive_cnt_now))
        {
            adjustment = ((st->date) - drive_cnt_now - 1);
        }
      }
      next_ep->sync_offset = next_ep->offset - adjustment;
    }

    /* calculate the remaining deviation to adjust */
    deviation = deviation - adjustment;

    /* next expiry point of the schedule table */
    index++;

  } while( (index < schedtable->count) && (deviation != 0) );

  /* re-insert the next expiry point with its new date */
  /* MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
     tpl_schedule_table*. This cast behaves correctly because the first member
     of tpl_schedule_table is a tpl_time_obj */
  index = ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index;
  st->date = (st->date) - (st->cycle)
             + ((schedtable->expiry)[index]->sync_offset);
  st->cycle = 0;
  tpl_insert_time_obj(st);
}

/*
 * Start a schedule table at a relative date.
 *
 * see paragraph 8.4.8 page 80 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_rel_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            offset
)
{
    VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
    P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) cnt;
    VAR(tpl_tick, AUTOMATIC) date;
    P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable;
#endif

    /* check interrupts are not disabled by user    */
    CHECK_INTERRUPT_LOCK(result)

    LOCK_WHEN_TASK()

    STORE_SERVICE(OSServiceId_StartScheduleTableRel)
    STORE_SCHEDTABLE_ID(sched_table_id)
    STORE_TICK_1(offset)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)
    CHECK_SCHEDTABLE_OFFSET_VALUE(sched_table_id,offset,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];
        /* MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
           tpl_schedtable_static*. This cast behaves correctly because the first memeber
           of tpl_schedula_table_static is a tpl_time_obj_static */
        schedtable = (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))(st->b_desc.stat_part);

        if (st->b_desc.state == (tpl_schedtable_state)SCHEDULETABLE_STOPPED)
        {
            if(schedtable->sync_strat != SCHEDTABLE_IMPLICIT_SYNC)
            {
                /*  the schedule table is not already started, proceed  */
                cnt = st->b_desc.stat_part->counter;
                date = cnt->current_date + offset + (schedtable->expiry[0])->offset;
                if (date > cnt->max_allowed_value)
                {
                    date -= cnt->max_allowed_value;
                }
                st->b_desc.date = date;
                st->b_desc.state = SCHEDULETABLE_RUNNING;
                /* MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
                   tpl_time_obj*. This cast behaves correctly because the first memeber
                   of tpl_schedula_table is a tpl_time_obj */
                tpl_insert_time_obj((tpl_time_obj *)st);
            }
            else
            {
              result = E_OS_ID;
            }
        }
        else
        {
            /*  the schedule table is already started,
                return the proper error code                        */
            result = E_OS_STATE;
        }
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    UNLOCK_WHEN_TASK()

    return result;
}

/*
 * Start a schedule table at an absolute date.
 *
 * see paragraph 8.4.9 page 80 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_abs_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            tick_val
)
{
    VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
    P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable;
    P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) cnt;
    VAR(tpl_tick, AUTOMATIC) date;
#endif

    /* check interrupts are not disabled by user    */
    CHECK_INTERRUPT_LOCK(result)

    LOCK_WHEN_TASK()

    STORE_SERVICE(OSServiceId_StartScheduleTableAbs)
    STORE_SCHEDTABLE_ID(sched_table_id)
    STORE_TICK_1(tick_val)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)
    CHECK_SCHEDTABLE_TICK_VALUE(sched_table_id,tick_val,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];
        /* MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
           tpl_schedtable_static*. This cast behaves correctly because the first memeber
           of tpl_schedula_table_static is a tpl_time_obj_static */
        schedtable = (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))(st->b_desc.stat_part);

        if (st->b_desc.state == (tpl_schedtable_state)SCHEDULETABLE_STOPPED)
        {
            /*  the schedule table is not already started, proceed  */
            cnt = st->b_desc.stat_part->counter;
            date = tick_val + (schedtable->expiry[0])->offset;
            if (date > cnt->max_allowed_value)
            {
                date -= cnt->max_allowed_value;
            }
            st->b_desc.date = date;
            st->b_desc.state = SCHEDULETABLE_RUNNING;
            /* MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
               tpl_time_obj*. This cast behaves correctly because the first memeber
               of tpl_schedula_table is a tpl_time_obj */
            tpl_insert_time_obj((tpl_time_obj *)st);
        }
        else
        {
            /*  the schedule table is already started,
                return the proper error code                        */
            result = E_OS_STATE;
        }
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    UNLOCK_WHEN_TASK()

    return result;
}


/*
 * Start a schedule table synchronized with global time
 *
 * see paragraph 8.4.12 page 84 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_synchron_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id
)
{
    VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
#endif

    /* check interrupts are not disabled by user    */
    CHECK_INTERRUPT_LOCK(result)

    LOCK_WHEN_TASK()

    STORE_SERVICE(OSServiceId_StartScheduleTableSynchron)
    STORE_SCHEDTABLE_ID(sched_table_id)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];

        if (st->b_desc.state == (tpl_schedtable_state)SCHEDULETABLE_STOPPED)
        {
            /*  the schedule table is not already started,
                it is put in the waiting state until the global time is provided */
            st->b_desc.state = SCHEDULETABLE_WAITING;
        }
        else
        {
            /*  the schedule table is already started,
                return the proper error code                        */
            result = E_OS_STATE;
        }
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    UNLOCK_WHEN_TASK()

    return result;
}


/*
 * Stop a schedule table.
 *
 * see paragraph 8.4.10 page 81 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE) tpl_stop_schedule_table_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id
)
{
    VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
#endif

    /* check interrupts are not disabled by user    */
    CHECK_INTERRUPT_LOCK(result)

    LOCK_WHEN_TASK()

    STORE_SERVICE(OSServiceId_StopScheduleTable)
    STORE_SCHEDTABLE_ID(sched_table_id)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];

        /*  Check the schedule table is started */
        if (st->b_desc.state != (tpl_schedtable_state)SCHEDULETABLE_STOPPED)
        {
            /* MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
               tpl_time_obj*. This cast behaves correctly because the first memeber
               of tpl_schedula_table is a tpl_time_obj */
            tpl_remove_time_obj((tpl_time_obj *)st);
            st->b_desc.state = SCHEDULETABLE_STOPPED;
            st->index = 0; /* reset the expiry point index to 0 */
        }
        else
        {
            result = E_OS_NOFUNC;
        }
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    UNLOCK_WHEN_TASK()

    return result;
}

/*
 * Switch the processing from one schedule table to another.
 *
 * see paragraph 8.4.11 page 83 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE) tpl_next_schedule_table_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   current_st_id,
    VAR(tpl_schedtable_id, AUTOMATIC)   next_st_id
)
{
    VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) current_st;
    P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) next_st;
#endif

    /* check interrupts are not disabled by user    */
    CHECK_INTERRUPT_LOCK(result)

    LOCK_WHEN_TASK()

    STORE_SERVICE(OSServiceId_NextScheduleTable)
    STORE_SCHEDTABLE_ID(current_st_id)
    STORE_SCHEDTABLE_ID2(next_st_id)

    CHECK_SCHEDTABLE_ID_ERROR(current_st_id, result)
    CHECK_SCHEDTABLE_ID_ERROR(next_st_id, result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        current_st = tpl_schedtable_table[current_st_id];
        next_st = tpl_schedtable_table[next_st_id];

        CHECK_SCHEDTABLE_COUNTERS(current_st, next_st, result)

        IF_NO_EXTENDED_ERROR(result)
            /*  Check the current schedule table is started         */
            if ((current_st->b_desc.state != SCHEDULETABLE_STOPPED) &&
                (current_st->b_desc.state != SCHEDULETABLE_NEXT))
            {
                /*  Set the next pointer                            */
                if (current_st->next != NULL)
                {
                    current_st->next->b_desc.state = SCHEDULETABLE_STOPPED;
                }
                current_st->next = next_st;
                /*  And the state of the next schedule table        */
                next_st->b_desc.state = SCHEDULETABLE_NEXT;
            }
            else
            {
                result = E_OS_NOFUNC;
            }
        IF_NO_EXTENDED_ERROR_END()
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    UNLOCK_WHEN_TASK()

    return result;
}


/**
 * Get the status of a schedule table
 *
 * see paragraph 8.4.15 page 86 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE) tpl_get_schedule_table_status_service(
    VAR(tpl_schedtable_id, AUTOMATIC)                       sched_table_id,
    P2VAR(tpl_schedtable_state, AUTOMATIC, OS_APPL_DATA)    status
)
{
    VAR(tpl_status, AUTOMATIC)  result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
#endif

    /* check interrupts are not disabled by user    */
    CHECK_INTERRUPT_LOCK(result)

    LOCK_WHEN_HOOK()

    /*  store information for error hook routine    */
    STORE_SERVICE(OSServiceId_GetScheduleTableStatus)
    STORE_SCHEDTABLE_ID(sched_table_id)
    STORE_ST_STATUS_REF(status)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id, result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];
        *status = st->b_desc.state;
    IF_NO_EXTENDED_ERROR_END()
#endif

    UNLOCK_WHEN_HOOK()

    return result;
}



/**
 *  Synchronize a schedule table with global time
 *
 * see paragraph 8.4.13 page 84 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE) tpl_sync_schedule_table_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            value
)
{
    VAR(tpl_status, AUTOMATIC)  result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
#endif

    /* check interrupts are not disabled by user    */
    CHECK_INTERRUPT_LOCK(result)

    LOCK_WHEN_HOOK()

    /*  store information for error hook routine    */
    STORE_SERVICE(OSServiceId_SyncScheduleTable)
    STORE_SCHEDTABLE_ID(sched_table_id)
    STORE_TICK_1(value)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id, result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];

        /* check the state of the schedude table */
        if( (SCHEDULETABLE_STOPPED == st->b_desc.state)
         || (SCHEDULETABLE_NEXT == st->b_desc.state) )
        {
          result=E_OS_STATE;
        }
        else
        {
            /* if schedule table is waiting, start it,
               else if running synchronize it */
            if( st->b_desc.state == SCHEDULETABLE_WAITING )
            {
                tpl_start_sched_table_sync(st, value);
            }
            else
            {
                tpl_sync_sched_table(st, value);
            }
        }

    IF_NO_EXTENDED_ERROR_END()
#endif

    UNLOCK_WHEN_HOOK()

    return result;
}


/**
 *  Set a schedule table asynchrone to global time
 *
 * see paragraph 8.4.14 page 85 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE) tpl_set_schedule_table_async(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id
)
{
    VAR(tpl_status, AUTOMATIC)  result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
    P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable;
    VAR(u16, AUTOMATIC) index;


#endif

    /* check interrupts are not disabled by user    */
    CHECK_INTERRUPT_LOCK(result)

    LOCK_WHEN_HOOK()

    /*  store information for error hook routine    */
    STORE_SERVICE(OSServiceId_SyncScheduleTable)
    STORE_SCHEDTABLE_ID(sched_table_id)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id, result)

#ifndef NO_SCHEDTABLE
    st = tpl_schedtable_table[sched_table_id];
        /* MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
           tpl_schedtable_static*. This cast behaves correctly because the first memeber
           of tpl_schedula_table_static is a tpl_time_obj_static */
    schedtable = (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))st->b_desc.stat_part;

    CHECK_SCHEDTABLE_SYNC_STRATEGY_ERROR(schedtable, result)

    IF_NO_EXTENDED_ERROR(result)

        /* check the state of the schedule table */
        if( (SCHEDULETABLE_RUNNING == st->b_desc.state)
         || (SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS == st->b_desc.state) )
        {
            st->b_desc.state = SCHEDULETABLE_RUNNING;

            for(index = 0; index < schedtable->count; index++)
            {
                (schedtable->expiry)[index]->sync_offset = (schedtable->expiry)[index]->offset;
            }
        }

    IF_NO_EXTENDED_ERROR_END()
#endif

    UNLOCK_WHEN_HOOK()

    return result;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_st_kernel.c */
