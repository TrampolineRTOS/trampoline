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
#define SCHEDTABLE_NO_SYNC      0
#define SCHEDTABLE_SMOOTH_SYNC  1
#define SCHEDTABLE_HARD_SYNC    2

typedef VAR(u8, AUTOMATIC)  tpl_sync_strategy;
typedef VAR(u16, AUTOMATIC) tpl_action_count ;
typedef VAR(u16, AUTOMATIC) tpl_expiry_count ;

/**
 * @struct TPL_SCHEDTABLE_SYNC
 *
 * Structure that stores information about the synchronization
 * scheme of a schedule table.
 */
struct TPL_SCHEDTABLE_SYNC {
    VAR(tpl_sync_strategy, AUTOMATIC) sync_strat; /**< Synchronization strategy (hard or
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
    VAR(tpl_tick, AUTOMATIC)                    offset;   /**< offset of the actions from the
                                                               start time of the schedule table   */
    VAR(tpl_action_count, AUTOMATIC)            count;    /**< number of actions associated with
                                                               the expiry point                   */
    P2VAR(tpl_action, OS_APPL_DATA, AUTOMATIC) *actions;  /**< pointer to an array of actions to
                                                               be done at that offset.            */
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
    VAR(tpl_time_obj, AUTOMATIC)                              b_desc;     /**< common part for all
                                                                               objects that derive
                                                                               from tpl_time_obj          */
    struct P2VAR(TPL_SCHEDULE_TABLE, OS_APPL_DATA, AUTOMATIC) next;       /**< next schedule table to
                                                                               start                      */
    VAR(tpl_expiry_count, AUTOMATIC)                          index;      /**< next expiry point to
                                                                               process in the schedule
                                                                               table                      */
    VAR(tpl_bool, AUTOMATIC)                                  gt_sync;    /**< the schedule table has
                                                                               been started synchronous
                                                                               to global time             */
    VAR(tpl_tick, AUTOMATIC)                                  gt_offset;  /**< offset to the global time  */
    VAR(tpl_tick, AUTOMATIC)                                  cur_offset; /**< offset to reduce to be
                                                                               synchronous                */
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
    VAR(tpl_time_obj_static, AUTOMATIC)               b_desc;     /**< common part of all objects that
                                                                       derive from tpl_time_obj.          */
    P2VAR(tpl_expiry_point, OS_APPL_DATA, AUTOMATIC) *expiry;     /**< pointer to an array of expiry
                                                                       points                             */
    VAR(tpl_expiry_count, AUTOMATIC)                  count;      /**< number of expiry points in the
                                                                       schedule table                     */
    VAR(tpl_sync_strategy, AUTOMATIC)                 sync_strat; /**< schedule table synchronization
                                                                       strategy.
                                                                       @see #tpl_sync_strategy            */
    VAR(tpl_bool, AUTOMATIC)                          periodic;   /**< TRUE if the schedule table is a
                                                                       periodic schedule table, FALSE
                                                                       otherwise                          */
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
FUNC(tpl_status, OS_CODE) tpl_process_schedtable(
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC) t_obj);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_AS_ST_KERNEL_H */

/* End of file tpl_as_st_kernel.h */
