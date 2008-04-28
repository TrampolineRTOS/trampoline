/**
 * @file tpl_as_schedtable.c
 *
 * @internal
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

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

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
 /* MISRA RULE 27 VIOLATION: This variable is used only in this file
    but decalred in the configuration file, this is why it does not need
    to be declared as external in a header file */
extern P2VAR(tpl_schedule_table, OS_APPL_DATA, OS_VAR)  tpl_schedtable_table[SCHEDTABLE_COUNT];
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Start a schedule table at a relative date.
 *
 * see paragraph 8.4.8 page 55 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
FUNC(StatusType, OS_CODE)  StartScheduleTableRel(
    VAR(ScheduleTableType, AUTOMATIC) sched_table_id,
    VAR(TickType, AUTOMATIC)          offset
)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, OS_APPL_DATA, AUTOMATIC) st;
    P2VAR(tpl_counter, OS_APPL_DATA, AUTOMATIC) cnt;
    VAR(tpl_tick, AUTOMATIC) date;
#endif

    LOCK_WHEN_TASK()

    STORE_SERVICE(OSServiceId_StartScheduleTableRel)
    STORE_SCHEDTABLE_ID(sched_table_id)
    STORE_TICK_1(offset)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)
    CHECK_SCHEDTABLE_OFFSET_VALUE(sched_table_id,offset,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];

        if (st->b_desc.state == (tpl_schedtable_state)SCHEDULETABLE_NOT_STARTED)
        {
            /*  the schedule table is not already started, proceed  */
            cnt = st->b_desc.stat_part->counter;
            date = cnt->current_date + offset;
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
 * Start a schedule table at an absolute date.
 *
 * see paragraph 8.4.9 page 55 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
FUNC(StatusType, OS_CODE)  StartScheduleTableAbs(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id,
    VAR(TickType, AUTOMATIC)            tick_val
)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, OS_APPL_DATA, AUTOMATIC) st;
#endif

    LOCK_WHEN_TASK()

    STORE_SERVICE(OSServiceId_StartScheduleTableAbs)
    STORE_SCHEDTABLE_ID(sched_table_id)
    STORE_TICK_1(tick_val)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)
    CHECK_SCHEDTABLE_TICK_VALUE(sched_table_id,tick_val,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];

        if (st->b_desc.state == (tpl_schedtable_state)SCHEDULETABLE_NOT_STARTED)
        {
            /*  the schedule table is not already started, proceed  */
            st->b_desc.date = tick_val;
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
            result = E_OS_NOFUNC;
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
 * see paragraph 8.4.10 page 56 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
FUNC(StatusType, OS_CODE) StopScheduleTable(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id
)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, OS_APPL_DATA, AUTOMATIC) st;
#endif

    LOCK_WHEN_TASK()

    STORE_SERVICE(OSServiceId_StopScheduleTable)
    STORE_SCHEDTABLE_ID(sched_table_id)

    CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)

#ifndef NO_SCHEDTABLE
    IF_NO_EXTENDED_ERROR(result)
        st = tpl_schedtable_table[sched_table_id];

        /*  Check the schedule table is started */
        if (st->b_desc.state != (tpl_schedtable_state)SCHEDULETABLE_NOT_STARTED)
        {
            /* MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
               tpl_time_obj*. This cast behaves correctly because the first memeber
               of tpl_schedula_table is a tpl_time_obj */
            tpl_remove_time_obj((tpl_time_obj *)st);
            st->b_desc.state = SCHEDULETABLE_NOT_STARTED;
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
 * see paragraph 8.4.11 page 57 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
FUNC(StatusType, OS_CODE) NextScheduleTable(
    VAR(ScheduleTableType, AUTOMATIC)   current_st_id,
    VAR(ScheduleTableType, AUTOMATIC)   next_st_id
)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, OS_APPL_DATA, AUTOMATIC) current_st;
    P2VAR(tpl_schedule_table, OS_APPL_DATA, AUTOMATIC) next_st;
#endif

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
            if ((current_st->b_desc.state != SCHEDULETABLE_NOT_STARTED) &&
                (current_st->b_desc.state != SCHEDULETABLE_NEXT))
            {
                /*  Set the next pointer                            */
                if (current_st->next != NULL)
                {
                    current_st->next->b_desc.state = SCHEDULETABLE_NOT_STARTED;
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
 * see paragraph 8.4.18 page 73 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) GetScheduleTableStatus(
    VAR(ScheduleTableType, AUTOMATIC)           sched_table_id,
    VAR(ScheduleTableStatusRefType, AUTOMATIC)  status)
{
    VAR(StatusType, AUTOMATIC)  result = E_OK;

#ifndef NO_SCHEDTABLE
    P2VAR(tpl_schedule_table, OS_APPL_DATA, AUTOMATIC) st;
#endif

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

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file tpl_as_schedtable.c */
