/*
 *  @file tpl_as_gt_kernel.c
 *
 * @section desc File description
 *
 * Trampoline autosar extension sync to global time implementation
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
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
#include "tpl_as_error.h"
#include "tpl_os_definitions.h"
#include "tpl_as_gt_kernel.h"

#ifndef NO_SCHEDTABLE
/**
 * Array of all schedule tables' full descriptors.
 *
 * Index in this array correspond to the #ScheduleTableType of the schedule
 * table. While it would be less time consuming to refer a schedule table
 * by a pointer to its descriptor, the AUTOSAR API requires a schedule table
 * to have an identifier. So a table of pointer is used. The size of this table
 * is static and known at compile time
 */
extern P2VAR(tpl_schedule_table, OS_APPL_DATA, OS_VAR)
    tpl_schedtable_table[SCHEDTABLE_COUNT];
#endif


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Start a schedule table sync with global time.
 *
 * see paragraph 8.4.15 page 71 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_start_schedule_table_synchron_service( 
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id, 
    VAR(tpl_tick, AUTOMATIC)            gt)
{
    VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, OS_APPL_DATA, AUTOMATIC) st;
#endif

    LOCK_KERNEL()

    STORE_SERVICE(OSServiceId_StartScheduleTableSynchron)
    STORE_SCHEDTABLE_ID(sched_table_id)
    STORE_TICK_1(gt)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)
    CHECK_SCHEDTABLE_SYNC(sched_table_id,result)
    CHECK_SCHEDTABLE_TICK_VALUE(sched_table_id,gt,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];

        if (st->b_desc.state == (tpl_schedtable_state)SCHEDULETABLE_NOT_STARTED)
        {
            /*  the schedule table is not already started, proceed  */
            st->cur_offset = gt;
            st->b_desc.state = SCHEDULETABLE_WAITING;
            /*  the schedule table is not put in the scheduling list
                of its counter since it will be really started with
                SyncScheduleTable                                   */
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

    UNLOCK_KERNEL()

    return result;
}

/*
 * Synchronize a schedule table with global time.
 *
 * see paragraph 8.4.16, page 72 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_sync_schedule_table_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            gt)
{
    VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, OS_APPL_DATA, AUTOMATIC) st;
    VAR(tpl_tick, AUTOMATIC) drift;
    VAR(tpl_tick, AUTOMATIC) counter_date;
#endif

    LOCK_WHEN_TASK()

    STORE_SERVICE(OSServiceId_SyncScheduleTable)
    STORE_SCHEDTABLE_ID(sched_table_id)
    STORE_TICK_1(gt)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)
    CHECK_SCHEDTABLE_SYNC(sched_table_id,result)
/*    CHECK_SCHEDTABLE_TICK_VALUE(sched_table_id,gt,result) */

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];

        /* The first thing to do is to compute the drift of local time */
        counter_date = st->b_desc.stat_part->counter->current_date;
        if (counter_date < gt)
        {
            drift = counter_date + st->b_desc.stat_part->counter->max_allowed_value - gt;
        }
        else
        {
            drift = counter_date - gt;
        }
        
        st->gt_offset = drift;

        if (st->b_desc.state == (tpl_schedtable_state)SCHEDULETABLE_WAITING)
        {
            /*  the schedule table has been started synchronous.
                so currently it is not actuelly running. The global time
                at which it should start is stored in cur_offset.
                The first thing to do is to compare the given global time
                with the global time at which the schedule table should
                start */
                
                
                
            st->b_desc.date = tick_val;
            st->b_desc.state = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
            tpl_insert_time_obj((tpl_time_obj *)st);
        }
        else
        {
            /*  the schedule table is already started,
                return the proper error code                        */
            result = E_OS_NOFUNC;
        }
    IF_NO_EXTENDED_ERROR_END()
#endif


    return result;
}

/**
 * Set the status of the schedule table to asynchronous
 *
 * see paragraph 8.4.17, page 73 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_set_schedule_table_async_service(
    VAR(tpl_schedtable_id, AUTOMATIC) sched_table_id)
{
    VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, OS_APPL_DATA, AUTOMATIC) st;
#endif

    LOCK_WHEN_TASK()

    STORE_SERVICE(OSServiceId_SetScheduleTableAsync)
    STORE_SCHEDTABLE_ID(sched_table_id)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];
        st->gt_sync = FALSE;
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    UNLOCK_WHEN_TASK()

    return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_gt_kernel.c */
