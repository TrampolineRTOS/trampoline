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
#include "tpl_as_st_definitions.h"

typedef VAR(u8, AUTOMATIC)  tpl_schedtable_state;

/* Synchronization strategies */
typedef enum
{
  SCHEDTABLE_NO_SYNC = 0,
  SCHEDTABLE_IMPLICIT_SYNC = 1,
  SCHEDTABLE_EXPLICIT_SYNC = 2
} tpl_sync_strategy;

typedef VAR(u16, TYPEDEF) tpl_action_count ;
typedef VAR(u16, TYPEDEF) tpl_expiry_count ;

/**
 * @struct TPL_SCHEDTABLE_SYNC
 *
 * Structure that stores information about the synchronization
 * scheme of a schedule table.
 */
struct TPL_SCHEDTABLE_SYNC {
    VAR(tpl_sync_strategy, TYPEDEF) sync_strat; /**< Synchronization strategy (hard or
                                                       smooth)                            */
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
    VAR(tpl_tick, TYPEDEF)                    offset;     /**< offset of the actions recalculated
                                                               for synchronization                */
    VAR(tpl_tick, TYPEDEF)                    sync_offset;/**< offset of the actions from the
                                                               start time of the schedule table   */
    VAR(tpl_action_count, TYPEDEF)            count;      /**< number of actions associated with
                                                               the expiry point                   */
    P2VAR(tpl_action, TYPEDEF, OS_APPL_DATA) *actions;    /**< pointer to an array of actions to
                                                               be done at that offset.            */
    VAR(tpl_tick, TYPEDEF)                    max_advance;/**< maximum advance deviation from
                                                               initial offset of expiry point
                                                               after synchronization              */
    VAR(tpl_tick, TYPEDEF)                    max_retard; /**< maximum delay deviation from
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
    VAR(tpl_time_obj_static, TYPEDEF)               b_desc;     /**< common part of all objects that
                                                                     derive from tpl_time_obj.          */
    P2VAR(tpl_expiry_point, TYPEDEF, OS_APPL_DATA) *expiry;     /**< pointer to an array of expiry
                                                                     points                             */
    VAR(tpl_expiry_count, TYPEDEF)                  count;      /**< number of expiry points in the
                                                                     schedule table                     */
    VAR(tpl_sync_strategy, TYPEDEF)                 sync_strat; /**< schedule table synchronization
                                                                     strategy.
                                                                     @see #tpl_sync_strategy            */
    VAR(tpl_bool, TYPEDEF)                          periodic;   /**< TRUE if the schedule table is a
                                                                     periodic schedule table, FALSE
                                                                     otherwise                          */
    VAR(tpl_tick, TYPEDEF)                          length;     /**< length of the  schedule table      */
    VAR(tpl_tick, TYPEDEF)                          precision;  /**< minimum deviation to be
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
 */
extern FUNC(tpl_status, OS_CODE) tpl_process_schedtable(
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
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
#endif /* TPL_AS_ST_KERNEL_H */

/* End of file tpl_as_st_kernel.h */
