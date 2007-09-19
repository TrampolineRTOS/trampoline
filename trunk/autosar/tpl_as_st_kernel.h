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


/* Schedule tables states */

#define SCHEDULETABLE_AUTOSTART                 TIME_OBJ_AUTOSTART
#define SCHEDULETABLE_NOT_STARTED               TIME_OBJ_SLEEP
#define SCHEDULETABLE_RUNNING                   TIME_OBJ_ACTIVE
#define SCHEDULETABLE_NEXT                      (TIME_OBJ_ACTIVE | 0x04)
#define SCHEDULETABLE_WAITING                   (TIME_OBJ_ACTIVE | 0x08)
#define SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS   (TIME_OBJ_ACTIVE | 0x0C)

typedef u8  tpl_schedtable_state;

/* Synchronization strategies */
#define SCHEDTABLE_NO_SYNC      0
#define SCHEDTABLE_SMOOTH_SYNC  1
#define SCHEDTABLE_HARD_SYNC    2

typedef u8  tpl_sync_strategy;
typedef u16 tpl_action_count ;
typedef u16 tpl_expiry_count ;

/**
 * @struct TPL_SCHEDTABLE_SYNC
 *
 * Structure that stores information about the synchronization
 * scheme of a schedule table.
 */
struct TPL_SCHEDTABLE_SYNC {
    tpl_sync_strategy   sync_strat; /**< Synchronization strategy (hard or
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
    tpl_tick            offset;     /**< offset of the actions from the
                                         start time of the schedule table   */
    tpl_action_count    count;      /**< number of actions associated with
                                         the expiry point                   */
    tpl_action          **actions;  /**< pointer to an array of actions to
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
    tpl_time_obj                b_desc;     /**< common part for all
                                                 objects that derive
                                                 from tpl_time_obj          */
    struct TPL_SCHEDULE_TABLE   *next;      /**< next schedule table to
                                                 start                      */
    tpl_expiry_count            index;      /**< next expiry point to
                                                 process in the schedule
                                                 table                      */
    tpl_bool                    gt_sync;    /**< the schedule table has
                                                 been started synchronous
                                                 to global time             */
    tpl_tick                    gt_offset;  /**< offset to the global time  */
    tpl_tick                    cur_offset; /**< offset to reduce to be
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
    tpl_time_obj_static b_desc;     /**< common part of all objects that
                                         derive from tpl_time_obj.          */
    tpl_expiry_point    **expiry;   /**<  pointer to an array of expiry
                                         points                             */
    tpl_expiry_count    count;      /**< number of expiry points in the
                                         schedule table                     */
    tpl_sync_strategy   sync_strat; /**< schedule table synchronization
                                         strategy.
                                         @see #tpl_sync_strategy            */
    tpl_bool            periodic;   /**< TRUE if the schedule table is a
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
tpl_status tpl_process_schedtable(tpl_time_obj *t_obj);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_AS_ST_KERNEL_H */

/* End of file tpl_as_st_kernel.h */
