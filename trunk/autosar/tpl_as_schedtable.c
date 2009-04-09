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

#ifdef WITH_SYSTEM_CALL
#error "This file should not be part of your project since WITH_SYSTEM_CALL is defined"
#endif

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
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_start_schedule_table_rel_service(sched_table_id, offset);
#endif
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
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_start_schedule_table_abs_service(sched_table_id, tick_val);
#endif
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
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_start_schedule_table_synchron_service(sched_table_id);
#endif
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
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_stop_schedule_table_service(sched_table_id);
#endif
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
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_next_schedule_table_service(current_st_id, next_st_id);
#endif
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
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_get_schedule_table_status_service(sched_table_id, status);
#endif
}



/**
 *  Synchronize a schedule table with global time
 *
 * see paragraph 8.4.13 page 84 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(StatusType, OS_CODE) SyncScheduleTable(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id,
    VAR(TickType, AUTOMATIC)            value)
{
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_sync_schedule_table_service(sched_table_id, value);
#endif
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
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_set_schedule_table_async(sched_table_id);
#endif
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file tpl_as_schedtable.c */
