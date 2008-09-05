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
      tpl_schedtable*. This cast behaves correctly because the first memeber
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
        need_resched |= (action_desc->action)(action_desc);
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
        if( (schedtable->expiry)[index]->sync_offset >= (schedtable->expiry)[index]->offset )
        {
          deviation = (schedtable->expiry)[index]->sync_offset - (schedtable->expiry)[index]->offset;
        }
        else
        {
          deviation = (schedtable->expiry)[index]->offset - (schedtable->expiry)[index]->sync_offset;
        }

        /* if deviation is less than the configured precision,
           the schedule table is considered synchronized */
        if( deviation <= (schedtable->precision) )
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
        /* MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
          tpl_schedtable*. This cast behaves correctly because the first memeber
          of tpl_schedula_table is a tpl_time_obj */
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
        /* MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
          tpl_time_obj*. This cast behaves correctly because the first memeber
          of tpl_schedule_table is a tpl_time_obj */
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
        /* MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
          tpl_schedtable*. This cast behaves correctly because the first member
          of tpl_schedule_table is a tpl_time_obj */
        ((tpl_schedule_table *)st)->index = 0;
    }

    return need_resched;
}



/*
 * This function is called after a schedule table has been started synchronously,
 * when the synchronized time is provided to OS
 */
FUNC(void, OS_CODE) tpl_start_sched_table_sync(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st,
    VAR(tpl_time, AUTOMATIC) sync_date)
{
    /* MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
      tpl_schedtable_static*. This cast behaves correctly because the first member
      of tpl_schedtable_static is a tpl_time_obj_static */
    P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable =
          (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))st->stat_part;

    /* compute the start date of the synchronized schedule table:
     * start date = drive_cnt.now + (duration - sync_date)
     */
    st->date = (st->stat_part->counter->current_date)
               + (st->date) + ((schedtable->length) - sync_date);

    /* as the schdule table is started synchronously, it is synchronous */
    st->state = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;

    /* insert the schedule table in the queue */
    tpl_insert_time_obj(st);
  }



  /*
   * This function is called when a schedule table has been started asynchronously
   * and the synchronized time is provided to the OS
   */
  FUNC(void, OS_CODE) tpl_sync_sched_table(
      P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st,
      VAR(tpl_time, AUTOMATIC) sync_date)
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
    VAR(tpl_tick, AUTOMATIC) next_ep_offset=0;
    VAR(tpl_tick, AUTOMATIC)       deviation;

    /* remove the next expiry point, because its date is going to be changed */
    tpl_remove_time_obj(st);

    /* get the current date of the counter which drives the schedule table */
    drive_cnt_now = st->stat_part->counter->current_date;

    /* get the date of expiration of the next expiry point */
    drive_cnt_match = st->date;

    /* MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
       tpl_schedtable_static*. This cast behaves correctly because st is a
       tpl_schedtable */
    schedtable = (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))(st->stat_part);
    /* MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
       tpl_schedtable*. This cast behaves correctly because the first memeber
       of tpl_schedula_table is a tpl_time_obj */
    index = ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index;

    /* this loop calculates the offset of the next_expiry point
       from the start of the schedule table */
    for(j=0; j <= index; j++)
    {
      next_ep_offset = next_ep_offset + (((schedtable->expiry)[j])->sync_offset);
    }

    /* calculate the current position in the scheduel table */
    position_on_tbl = next_ep_offset;
    position_on_tbl = position_on_tbl - (drive_cnt_match - drive_cnt_now);

    /* compute resynchronization for each expiry point until
     * the end of the schedule table or the schedule table is synchronized
     */
    do
    {
        /* get the new next expiry point to compute */
        next_ep = ((schedtable->expiry)[index]);

        /* the algorith is quite different if deviation is advance or overdue */
        if( position_on_tbl >= sync_date) /* advance */
        {
            /* from the current date, calculate the deviation with the synchronisation time */
            deviation = position_on_tbl - sync_date;
            /* calculate offset adjustment for this expiry point,
             * refer to OS420 of Autosar spec
             */
            adjustment = tpl_min(deviation, (next_ep->max_advance));
            next_ep->sync_offset = next_ep->offset + adjustment;
        }
        else /* overdue */
        {
            /* from the current date, calculate the deviation with the synchronisation time */
            deviation = sync_date - position_on_tbl;
            /* calculate offset adjustment for this expiry point,
             * refer to OS421 of Autosar spec
             */
            adjustment = tpl_min(deviation, (next_ep->max_retard));

            /* if this is the next expiry point, we have to take care that the adjustment
             * will not set the date before the current date
             */
            /* MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
               tpl_schedule_table*. This cast behaves correctly because the first memeber
               of tpl_schedule_table is a tpl_time_obj */
            if(index == ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index)
            {
                if(adjustment >= ((st->date)- drive_cnt_now))
                {
                    adjustment = ((st->date)- drive_cnt_now -1);
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
       tpl_schedule_table*. This cast behaves correctly because the first memeber
       of tpl_schedule_table is a tpl_time_obj */
    index = ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index;
    st->date = (st->date) - (st->cycle)
               + ((schedtable->expiry)[index]->sync_offset);
    st->cycle = 0;
    tpl_insert_time_obj(st);

}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_st_kernel.c */
