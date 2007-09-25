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

/*
 * This function is called when the alarm wrapped to the schedule table is
 * raised. After getting the static part of the alarm (that in this case is
 * a TPL_SCHEDTABLE_STATIC structure, this function get the next expiry point
 * and execute the corresponding actions. Then the alarm is updated to match
 * the offset of the next expiry point.
 */
tpl_status tpl_process_schedtable(tpl_time_obj *st)
{
    /*  Get the TPL_SCHEDTABLE_STATIC structure                             */
    tpl_schedtable_static   *schedtable =
        (tpl_schedtable_static *)st->stat_part;
    /*  Get the current index                                               */
    tpl_expiry_count        index = ((tpl_schedule_table *)st)->index;
    /*  Get the current expiry point                                        */
    tpl_expiry_point        *next_ep = (schedtable->expiry)[index];

    /*  Process the current expiry point                                    */
    tpl_status              need_resched = NO_SPECIAL_CODE;

    tpl_action              *action_desc;
    tpl_action_count        i;
    
    for (i = 0; i < next_ep->count; i++)
    {
        action_desc = (next_ep->actions)[i];
        need_resched |= (action_desc->action)(action_desc);
    }
    
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
        st->cycle = (schedtable->expiry)[index]->offset;
        ((tpl_schedule_table *)st)->index = index;
        
        DOW_DO(printf("next expiry point : %d\n",st->cycle);)
        
    }
    else {
        DOW_DO(printf("End of schedule table\n");)
        /*  The schedule table is finished                                  */
        /*  Test whether a schedule table has been « nextified » or not     */
        tpl_schedule_table *next = ((tpl_schedule_table *)st)->next;
        /*  Get the remaining time to fill the current schedule table
            period. This time is stored in the offset of the first expiry
            point                                                           */
        tpl_tick before = (schedtable->expiry)[0]->offset;
        if (next != NULL) {
            /*  reset the state of the current schedule table               */
            st->state = SCHEDULETABLE_NOT_STARTED;
            /*  There is a next schedule table set, start it                */
            next->b_desc.date =
                next->b_desc.stat_part->counter->current_date + before;
            ((tpl_time_obj *)next)->state = SCHEDULETABLE_RUNNING;
            tpl_insert_time_obj((tpl_time_obj *)next);
        }
        else if (schedtable->periodic == TRUE) {
            /*  No next schedule table but the current table is periodic    */
            st->cycle = before;
        }
        /*  Reset the index                                                 */
        ((tpl_schedule_table *)st)->index = 0;
    }

    return need_resched;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_st_kernel.c */
