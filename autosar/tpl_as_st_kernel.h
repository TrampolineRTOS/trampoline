/**
 * @file tpl_as_st_kernel.h
 *
 * @section desc File description
 *
 * Trampoline autosar extension software schedule tables machinery header file
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

#ifndef TPL_AS_ST_KERNEL_H
#define TPL_AS_ST_KERNEL_H

#include "tpl_os_internal_types.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_as_definitions.h"

typedef VAR(uint8, AUTOMATIC)  tpl_schedtable_state;

/* Synchronization strategies */
typedef enum
{
  SCHEDTABLE_NO_SYNC = 0,
  SCHEDTABLE_IMPLICIT_SYNC = 1,
  SCHEDTABLE_EXPLICIT_SYNC = 2
} tpl_sync_strategy;

typedef VAR(uint16, TYPEDEF) tpl_action_count ;
typedef VAR(uint16, TYPEDEF) tpl_expiry_count ;

/**
 *
 * This returns the min of 2 values provided
 *
 */
FUNC(tpl_tick, OS_CODE) tpl_min(
	VAR(tpl_tick, AUTOMATIC) var_1,
	VAR(tpl_tick, AUTOMATIC) var_2);

/*
 * @def tpl_adjust_next_expiry_point
 *
 * tpl_adjust_next_expiry_point adjusts the next expiry point
 * of a schedule table, depending on its deviation.
 *
 * @param st schedule table's pointer
 * @param index index of the current expiry point
 * @param last_expiry_point boolean to know if the actual is
 * the last expiry point of the schedule table or not (if 
 * last one, the adjustment have to be done to the first one
 * of the next period of the schedule table).
 *
 */
FUNC(void, OS_CODE) tpl_adjust_next_expiry_point(
	 P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st,
	 VAR(tpl_expiry_count, AUTOMATIC) index,
	 VAR(tpl_bool, AUTOMATIC) last_expiry_point
	 );

/**
 * @struct TPL_SCHEDTABLE_SYNC
 *
 * Structure that stores information about the synchronization
 * scheme of a schedule table.
 */
struct TPL_SCHEDTABLE_SYNC {
    VAR(tpl_sync_strategy, TYPEDEF) sync_strat; /**< Synchronization strategy
                                                     (hard or smooth)         */
};

/**
 * @struct TPL_EXPIRY_POINT
 *
 * This structure put together a time offset, the number of actions
 * associated with the expiry point and a pointer to an array
 * of actions to be done at that time offset for a schedule table.
 *
 * The offset of the first expiry point of a schedule table is the
 * period of the schedule table.
 */
struct TPL_EXPIRY_POINT {
    VAR(tpl_tick, TYPEDEF)                     offset;     /**< offset of the actions recalculated
                                                               for synchronization                */
    VAR(tpl_tick, TYPEDEF)                     sync_offset;/**< offset of the actions from the
                                                               start time of the schedule table   */
    VAR(tpl_action_count, TYPEDEF)             count;      /**< number of actions associated with
                                                               the expiry point                   */
    P2CONST(tpl_action, TYPEDEF, OS_APPL_DATA) *actions;    /**< pointer to an array of actions to
                                                               be done at that offset.            */
    VAR(tpl_tick, TYPEDEF)                     max_advance;/**< maximum advance deviation from
                                                               initial offset of expiry point
                                                               after synchronization              */
    VAR(tpl_tick, TYPEDEF)                     max_retard; /**< maximum delay deviation from
                                                               initial offset of expiry point
                                                               after synchronization              */
};

/**
 * @typedef tpl_expiry_point
 *
 * This is an alias for the structure #TPL_EXPIRE_ACTIONS
 *
 * @see #TPL_EXPIRY_POINT
 */
typedef struct TPL_EXPIRY_POINT tpl_expiry_point;

/**
 * @struct TPL_SCHEDULE_TABLE
 *
 * Data structure to store dynamic informations about a schedule table.
 * This structure inherit from the TPL_TIME_OBJ structure
 */
struct TPL_SCHEDULE_TABLE {
  VAR(tpl_time_obj, TYPEDEF)                              b_desc;     /**< common part for all
                                                                             objects that derive
                                                                             from tpl_time_obj          */
  struct P2VAR(TPL_SCHEDULE_TABLE, TYPEDEF, OS_APPL_DATA) next;       /**< next schedule table to
                                                                             start                      */
  VAR(tpl_expiry_count, TYPEDEF)                          index;      /**< next expiry point to
                                                                             process in the schedule
                                                                             table                      */
	VAR(sint32, TYPEDEF)										deviation;                	/**< deviation of the schedule
																			                                       table from counter synchro */
};

/**
 * @typedef tpl_schedule_table
 *
 * This is an alias for the structure #TPL_SCHEDULE_TABLE
 *
 * @see #TPL_SCHEDULE_TABLE
 */
typedef struct TPL_SCHEDULE_TABLE tpl_schedule_table;

/**
 * @struct TPL_SCHEDTABLE_STATIC
 *
 * This is the data structure used to describe the static part of a
 * schedule table.
 * It extends the #TPL_TIME_OBJ_STATIC structure by adding a pointer to
 * an array of expiry points, the number of expiry points, the sync
 * strategy of the schedule table and a boolean to specify whether the
 * schedule table is periodic or not.
 *
 * @see #TPL_TIME_OBJ_STATIC
 */
struct TPL_SCHEDTABLE_STATIC {
    VAR(tpl_time_obj_static, TYPEDEF)                b_desc;     /**< common part of all objects that
                                                                     derive from tpl_time_obj.          */
    P2VAR(tpl_expiry_point, TYPEDEF, OS_APPL_DATA)   *expiry;     /**< pointer to an array of expiry
                                                                     points                             */
    VAR(tpl_expiry_count, TYPEDEF)                   count;      /**< number of expiry points in the
                                                                     schedule table                     */
    VAR(tpl_sync_strategy, TYPEDEF)                  sync_strat; /**< schedule table synchronization
                                                                     strategy.
                                                                     @see #tpl_sync_strategy            */
    VAR(tpl_bool, TYPEDEF)                           periodic;   /**< TRUE if the schedule table is a
                                                                     periodic schedule table, FALSE
                                                                     otherwise                          */
    VAR(tpl_tick, TYPEDEF)                           length;     /**< length of the  schedule table      */
    VAR(tpl_tick, TYPEDEF)                           precision;  /**< minimum deviation to be
                                                                     synchronized                       */
};

/**
 * @typedef tpl_schedtable_static
 *
 * This is an alias for the structure #TPL_SCHEDTABLE_STATIC
 *
 * @see #TPL_SCHEDTABLE_STATIC
 */
typedef struct TPL_SCHEDTABLE_STATIC tpl_schedtable_static;

#if SCHEDTABLE_COUNT > 0

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

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

extern CONSTP2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA)
  tpl_schedtable_table[SCHEDTABLE_COUNT];

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#endif /* SCHEDTABLE_COUNT > 0 */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * This function is called when the time object wrapped to the schedule table
 * is raised. After getting the static part of the time object (that in this
 * case is a TPL_SCHEDTABLE_STATIC structure, this function get the next expiry
 * point and execute the corresponding actions. Then the alarm is updated to
 * match the offset of the next expiry point.
 *
 * For adjustable schedule table, if the actual expiry point is the finalize one,
 * the sync_offset has to be restored.
 *
 * Otherwise, first change the state of the
 * schedule table, depending to Duration. If EXPLICIT, RUNNING_AND_SYNCHRONOUS,
 * if IMPLICIT, non-synchronised schedule table or asynchronous schedule table,
 * RUNNING.
 * Next, if actual expiry point is the last one, adjust the first expiry point
 * (next one), if repeating schedule table (careful to the adjustment, if superior
 * to first.delay, adjust the finalize expiry point too), otherwise (next and
 * single shot), place the finalize expiry point in the queue. Otherwise (not last
 * expiry point), adjust the next expiry point.
 * Increment index and store it and store cycle.
 *
 */
extern FUNC(void, OS_CODE) tpl_process_schedtable(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st);

/**
 * @internal
 *
 * This function is called after a schedule table has been started synchronously,
 * when the synchronized time is provided to OS
 */
extern FUNC(void, OS_CODE) tpl_start_sched_table_sync(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st,
    VAR(tpl_time, AUTOMATIC) sync_date);

/**
 * @internal
 *
 * This function is called when a schedule table has been started asynchronously
 * and the synchronized time is provided to the OS
 */
extern FUNC(void, OS_CODE) tpl_sync_sched_table(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st,
    VAR(tpl_time, AUTOMATIC) sync_date);
    
/**
 * Start a schedule table at a relative date system service.
 *
 * @param   sched_table_id  identifier of the schedule table to be started
 * @param   offset          relative tick value between now and the first
 *                          alarm expiry
 *
 * @retval  E_OK        no error
 *                      requirement OS278
 * @retval  E_OS_ID     sched_table_id is not valid (EXTENDED status only)
 *                      requirement OS275
 * @retval  E_OS_VALUE  offset was set to 0 or is greater than the
 *                      MAXALLOWEDVALUE of the counter (EXTENDED status only)
 *                      requirement OS276 and OS332
 * @retval  E_OS_STATE  the schedule table is already started or currently in
 *                      state SCHEDULETABLE_NEXT
 *                      requirement OS277
 *
 * see paragraph 8.4.8 page 55 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
#if SCHEDTABLE_COUNT > 0
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_rel(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            offset
);
#endif
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_rel_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            offset
);

/**
 * Start a schedule table at an absolute date system service.
 *
 * @param   sched_table_id  identifier of the schedule table to be started
 * @param   tick_val        absolute tick value between of the first
 *                          alarm expiry
 *
 * @retval  E_OK        no error
 *                      requirement OS351
 * @retval  E_OS_ID     sched_table_id is not valid (EXTENDED status only)
 *                      requirement OS348
 * @retval  E_OS_VALUE  tick_val is greater than the
 *                      MAXALLOWEDVALUE of the counter
 *                      requirement OS349
 * @retval  E_OS_STATE  the schedule table is already started or currently in
 *                      state SCHEDULETABLE_NEXT
 *                      requirement OS350
 *
 * see paragraph 8.4.9 page 55 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
#if SCHEDTABLE_COUNT > 0
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_abs(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            tick_val
);
#endif
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_abs_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            tick_val
);

/*
 * Start a schedule table synchronized with global time system service
 *
 * @param   sched_table_id  identifier of the schedule table to be started
 *
 * @retval  E_OS_STATE  the schedule table is already started
 *
 * @retval  E_OS_ID     invalid schedule table id, or the schedule table
 *                      is not configured as explicit synchronized
 *
 * @retval  E_OK        no error
 *
 */
#if SCHEDTABLE_COUNT > 0
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_synchron(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id
);
#endif
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_synchron_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id
);

/**
 * Stop a schedule table system service.
 *
 * @param   sched_table_id  identifier of the schedule table to be started
 *
 * @retval  E_OK        no error
 *                      requirement OS281
 * @retval  E_OS_ID     sched_table_id is not valid (EXTENDED status only)
 *                      requirement OS279
 * @retval  E_OS_NOFUNC the schedule table was not started
 *                      requirement OS280
 *
 * see paragraph 8.4.10 page 56 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
FUNC(tpl_status, OS_CODE) tpl_stop_schedule_table_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id
);

/**
 * Switch the processing from one schedule table to another (system service).
 *
 * @param   current_sd_id   identifier of the schedule table currently in use
 * @param   next_sd_id      identifier of the next schedule table to process
 *
 * @retval  E_OK        no error
 *                      requirement OS284
 * @retval  E_OS_ID     current_sd_id or next_sd_id are not valid
 *                      (EXTENDED status only).
 *                      requirement OS282
 * @retval  E_OS_NOFUNC the schedule table current_sd_id is not started or
 *                      currently in state SCHEDULETABLE_NEXT.
 *                      requirement OS283
 * @retval  E_OS_STATE  the schedule table next_sd_id is already started or
 *                      already the next schedule table to switch to
 *                      (EXTENDED status only).
 *                      requirement OS309
 *
 * see paragraph 8.4.11 page 57 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
FUNC(tpl_status, OS_CODE) tpl_next_schedule_table_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   current_st_id,
    VAR(tpl_schedtable_id, AUTOMATIC)   next_st_id
);

/**
 * Get the status of a schedule table system service
 *
 * @param   sched_table_id  identifier of the schedule table
 * @param   status          reference to a variable where the status is returned
 *
 * @retval  E_OK        no error
 *                      requirements OS289, OS353, OS354, OS290 and OS291
 * @retval  E_OS_ID     sched_table_id is not valid (EXTENDED status only)
 *                      requirement OS293
 *
 * see paragraph 8.4.18 page 73 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_get_schedule_table_status_service(
    VAR(tpl_schedtable_id, AUTOMATIC)                       sched_table_id,
    P2VAR(tpl_schedtable_state, AUTOMATIC, OS_APPL_DATA)    status
);

/**
 * Synchronize a schedule table with global time system service
 *
 * @param   sched_table_id  identifier of the schedule table
 *
 * @retval  E_OK        no error
 *
 * @retval  E_OS_STATE  the schedule table is not waiting or running
 *
 * @retval  E_OS_ID     invalid schedule table id, or the schedule table
 *                      is not configured as explicit synchronized
 *
 */
FUNC(tpl_status, OS_CODE) tpl_sync_schedule_table_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            value
);

/**
 * Set a schedule table asynchrone to global time system service
 *
 * @param   sched_table_id  identifier of the schedule table
 *
 * @retval  E_OK        no error
 *
 * @retval  E_OS_ID     invalid schedule table id, or the schedule table
 *                      is not configured as explicit synchronized
 */
FUNC(tpl_status, OS_CODE) tpl_set_schedule_table_async_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id
);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
#endif /* TPL_AS_ST_KERNEL_H */

/* End of file tpl_as_st_kernel.h */
