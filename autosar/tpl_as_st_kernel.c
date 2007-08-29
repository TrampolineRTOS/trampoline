/**
 * @file tpl_as_st_kernel.c
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

/*
 * This function is called when the alarm wrapped to the schedule table is
 * raised. After getting the static part of the alarm (that in this case is
 * a TPL_SCHEDTABLE_STATIC structure, this function get the next expiry point
 * and execute the corresponding actions. Then the alarm is updated to match
 * the offset of the next expiry point.
 */
tpl_status tpl_process_schedtable(tpl_schedule_table *st)
{
    /*  Get the TPL_SCHEDTABLE_STATIC structure                             */
    tpl_schedtable_static   *schedtable =
        (tpl_schedtable_static *)st->stat_part;
    /*  Get the current index                                               */
    tpl_expiry_count        index = schedtable->dyn_part->index;
    /*  Get the current expiry point                                        */
    tpl_expiry_point        *next_ep = &((schedtable->expiry)[index]);

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
    schedtable->dyn_part->index = index;
    /*  Reset the cycle of the alarm                                        */
    st->cycle = 0;
    
    /*  Test whether the schedule table is finished or not                  */
    if (index < schedtable->count)
    {
        /*  The schedule table is not finished                              */
        /*  Set the next cycle to the offset of the next expiry point
            (offsets are not relative to the start of the schedule table
            but to the previous expiry point                                */
        st->cycle = (schedtable->expiry)[index].offset;
    }
    else {
        /*  The schedule table is finished                                  */
        /*  Test whether a schedule table has been « nextified » or not     */
        tpl_schedule_table *next = schedtable->dyn_part->next;
        /*  Get the remaining time to fill the current schedule table
            period. This time is stored in the offset of the first expiry
            point                                                           */
        tpl_tick before = (schedtable->expiry)[0].offset;
        if (next != NULL) {
            /*  There is a next schedule table set, start it                */
            next->date = next->stat_part->counter->current_date + before;
            tpl_insert_alarm(next);
        }
        else if (schedtable->periodic == TRUE) {
            /*  No next schedule table but the current table is periodic    */
            st->cycle = before;
        }
    }

    return need_resched;
}

/* End of file tpl_as_st_kernel.c */
