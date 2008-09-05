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
#include "tpl_as_isr.h"

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
 * see paragraph 8.4.8 page 80 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(StatusType, OS_CODE)  StartScheduleTableRel(
    VAR(ScheduleTableType, AUTOMATIC) sched_table_id,
    VAR(TickType, AUTOMATIC)          offset
)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

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
FUNC(StatusType, OS_CODE)  StartScheduleTableAbs(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id,
    VAR(TickType, AUTOMATIC)            tick_val
)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

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
FUNC(StatusType, OS_CODE)  StartScheduleTableSynchron(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id
)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

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
FUNC(StatusType, OS_CODE) StopScheduleTable(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id
)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

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
FUNC(StatusType, OS_CODE) NextScheduleTable(
    VAR(ScheduleTableType, AUTOMATIC)   current_st_id,
    VAR(ScheduleTableType, AUTOMATIC)   next_st_id
)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

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
FUNC(StatusType, OS_CODE) GetScheduleTableStatus(
    VAR(ScheduleTableType, AUTOMATIC)           sched_table_id,
    VAR(ScheduleTableStatusRefType, AUTOMATIC)  status)
{
    VAR(StatusType, AUTOMATIC)  result = E_OK;

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
FUNC(StatusType, OS_CODE) SyncScheduleTable(
    VAR(ScheduleTableType, AUTOMATIC)           sched_table_id,
    VAR(TickType, AUTOMATIC)  value)
{
    VAR(StatusType, AUTOMATIC)  result = E_OK;

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
FUNC(StatusType, OS_CODE) SetScheduleTableAsync(
    VAR(ScheduleTableType, AUTOMATIC) sched_table_id
)
{
    VAR(StatusType, AUTOMATIC)  result = E_OK;

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


/* End of file tpl_as_schedtable.c */
