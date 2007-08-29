/**
 * @file tpl_as_schedtable.c
 *
 * @section desc File description
 *
 * Trampoline autosar extension software schedule tables API implementation
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
 
#include "tpl_as_schedtable.h"
#include "tpl_as_st_kernel.h"
#include "tpl_as_error.h"
#include "tpl_os_definitions.h"

/*
 * Start a schedule table at a relative date.
 *
 * see paragraph 8.4.8 page 55 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
StatusType  StartScheduleTableRel(
    ScheduleTableType   sched_table_id,
    TickType            offset
)
{
    StatusType result = E_OK;
    
#ifndef NO_SCHEDTABLE
    tpl_schedule_table *st;
#endif
    
    STORE_SERVICE(OSServiceId_StartScheduleTableRel)
    STORE_SCHEDTABLE_ID(sched_table_id)
    STORE_TICK_1(offset)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];
    
        if (st->state == (tpl_schedtable_state)SCHEDULETABLE_NOT_STARTED)
        {
            /*  the schedule table is not already started, proceed  */
            st->date = st->stat_part->counter->current_date + offset;
            tpl_insert_alarm(st);
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
    
    return result;
}

/*
 * Start a schedule table at an absolute date.
 *
 * see paragraph 8.4.9 page 55 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
StatusType  StartScheduleTableAbs(
    ScheduleTableType   sched_table_id,
    TickType            tick_val
)
{
    StatusType result = E_OK;
    
#ifndef NO_SCHEDTABLE
    tpl_schedule_table *st;
#endif
    
    STORE_SERVICE(OSServiceId_StartScheduleTableAbs)
    STORE_SCHEDTABLE_ID(sched_table_id)
    STORE_TICK_1(tick_val)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];
    
        if (st->state == (tpl_schedtable_state)SCHEDULETABLE_NOT_STARTED)
        {
            /*  the schedule table is not already started, proceed  */
            st->date = tick_val;
            tpl_insert_time_obj(st);
           /* st->state = */
        }
        else
        {
            /*  the schedule table is already started,
                return the proper error code                        */
            result = E_OS_NOFUNC;
        }
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)
    
    return result;    
}

/*
 * Stop a schedule table.
 *
 * see paragraph 8.4.10 page 56 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
StatusType StopScheduleTable(
    ScheduleTableType   sched_table_id
)
{
    StatusType result = E_OK;
    
#ifndef NO_SCHEDTABLE
    tpl_schedule_table *st;
#endif

    STORE_SERVICE(OSServiceId_StopScheduleTable)
    STORE_SCHEDTABLE_ID(sched_table_id)
    
    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];

        /*  Check the schedule table is started */
        if (st->state != (tpl_schedtable_state)SCHEDULETABLE_NOT_STARTED)
        {
            tpl_remove_alarm(st);
        }
        else
        {
            result = E_OS_NOFUNC;
        }
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)
    
    return result;
}

/*
 * Switch the processing from one schedule table to another.
 *
 * see paragraph 8.4.11 page 57 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
StatusType NextScheduleTable(
    ScheduleTableType   current_sd_id,
    ScheduleTableType   next_sd_id
)
{
    StatusType result = E_OK;
    
#ifndef NO_SCHEDTABLE
    tpl_schedule_table *current_st;
    tpl_schedule_table *next_st;
#endif

    STORE_SERVICE(OSServiceId_NextScheduleTable)
    STORE_SCHEDTABLE_ID(current_sd_id)
    STORE_SCHEDTABLE_ID2(next_sd_id)
    
    CHECK_SCHEDTABLE_ID_ERROR(current_sd_id, result)
    CHECK_SCHEDTABLE_ID_ERROR(next_sd_id, result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        current_st = tpl_schedtable_table[current_sd_id];
        next_st = tpl_schedtable_table[next_sd_id];

        CHECK_SCHEDTABLE_COUNTERS(current_st, next_st, result)
        CHECK_SCHEDTABLE_NEXT(next_st, result)
        
        IF_NO_EXTENDED_ERROR(result)
            /*  Check the current schedule table is started         */
            if (current_st->state !=
                (tpl_schedtable_state)SCHEDULETABLE_NOT_STARTED)
            {
                /*  Get the static part of the schedule table       */
                tpl_schedtable_static *csst =
                    (tpl_schedtable_static *)current_st->stat_part;
                /*  Set the next pointer                            */
                csst->dyn_part->next = next_st;
            }
            else
            {
                result = E_OS_NOFUNC;
            }
        IF_NO_EXTENDED_ERROR_END()
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)
    
    return result;
}

/* End of file tpl_as_schedtable.c */
