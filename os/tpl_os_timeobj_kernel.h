/**
 * @file tpl_os_timeobj_kernel.h
 *
 * @section desc File description
 *
 * Trampoline Alarm Kernel header file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
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

#ifndef TPL_OS_TIMEOBJ_KERNEL_H
#define TPL_OS_TIMEOBJ_KERNEL_H

#include "tpl_os_internal_types.h"

/* Forward declaration */
struct TPL_COUNTER;
struct TPL_TIME_OBJ;

/**
 * @typedef tpl_time_obj_state
 *
 * Describes an time object state. Value can be one of :
 * - #ALARM_SLEEP
 * - #ALARM_ACTIVE
 * - #ALARM_AUTOSTART (only before startup)
 */
typedef u8 tpl_time_obj_state;

/**
 * @typedef tpl_expire_func
 *
 * Prototype for expire functions
 */
typedef P2FUNC(tpl_status, OS_APPL_CODE, tpl_expire_func)(
    P2VAR(struct TPL_TIME_OBJ, AUTOMATIC, OS_APPL_CONST)
);

/**
 * @struct TPL_TIME_OBJ_STATIC
 *
 * This is the static data structure used to store the information about
 * an object that can be put in the queue of a counter with an expiration
 * date. This structure complement the dynamic part.
 *
 * @see #TPL_ALARM
 */
struct TPL_TIME_OBJ_STATIC {
    struct P2VAR(TPL_COUNTER, TYPEDEF, OS_APPL_DATA)  counter;  /**< a pointer to the counter the
                                                                     alarm belongs to               */
    VAR(tpl_expire_func, TYPEDEF)                     expire;   /**< expiration processing to be
                                                                     done when the time object
                                                                     expires                        */
};

/**
 * @typedef tpl_time_obj
 *
 * This is an alias for the structure #TPL_TIME_OBJ
 *
 * @see #TPL_TIME_OBJ
 */
typedef struct TPL_TIME_OBJ_STATIC tpl_time_obj_static;

/**
 * @struct TPL_TIME_OBJ
 *
 * This is the data structure used to describe the dynamic part of,
 * for instance, an alarm or, in future extensions, any dated object
 * that is stored in the queue of a counter.
 */
struct TPL_TIME_OBJ {
    P2VAR(tpl_time_obj_static, TYPEDEF, OS_APPL_DATA) stat_part;  /**< pointer to the static descriptor   */
    struct P2VAR(TPL_TIME_OBJ, TYPEDEF, OS_APPL_DATA) next_to;    /**< next alarm in the active
                                                                       alarm list                         */
    struct P2VAR(TPL_TIME_OBJ, TYPEDEF, OS_APPL_DATA) prev_to;    /**< previous alarm in the active
                                                                       alarm list                         */
    VAR(tpl_tick, TYPEDEF)                            cycle;      /**< cycle delay for cyclic alarms      */
    VAR(tpl_tick, TYPEDEF)                            date;       /**< absolute date of the alarm         */
    VAR(tpl_time_obj_state, TYPEDEF)                  state;      /**< state of the alarm. An alarm may
                                                                       have 2 states: ALARM_SLEEP and
                                                                       ALARM_ACTIVE.
                                                                       @see #tpl_alarm_state              */
};

/**
 * @typedef tpl_time_obj
 *
 * This is an alias for the structure #TPL_TIME_OBJ
 *
 * @see #TPL_TIME_OBJ
 */
typedef struct TPL_TIME_OBJ tpl_time_obj;

/**
 * @struct TPL_COUNTER
 *
 * This is the data structure used to describe a counter
 */
struct TPL_COUNTER {
    CONST(tpl_tick, TYPEDEF)                    ticks_per_base;     /**< number of ticks until the
                                                                         counter increments                 */
    CONST(tpl_tick, TYPEDEF)                    max_allowed_value;  /**< maximum allowed value for
                                                                         a counter                          */
    CONST(tpl_tick, TYPEDEF)                    min_cycle;          /**< number of ticks until the
                                                                         counter increments                 */
    VAR(tpl_tick, TYPEDEF)                      current_tick;       /**< current tick value of the counter  */
    VAR(tpl_tick, TYPEDEF)                      current_date;       /**< current value of the counter       */
#ifdef WITH_AUTOSAR
    CONST(tpl_counter_kind, TYPEDEF)            kind;               /**< kind (hardware or software) of the
                                                                         counter                            */
#endif
    P2VAR(tpl_time_obj, TYPEDEF, OS_APPL_DATA)  first_to;           /**< active alarms list head            */
    P2VAR(tpl_time_obj, TYPEDEF, OS_APPL_DATA)  next_to;            /**< next active alarms                 */
};

/**
 * @typedef tpl_counter
 *
 * This is an alias for the structure #TPL_COUNTER
 *
 * @see #TPL_COUNTER
 */
typedef struct TPL_COUNTER tpl_counter;


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

extern VAR(tpl_counter, OS_VAR) SystemCounter_counter_desc;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * tpl_insert_time_obj inserts a timeobject in the time object queue
 * of the counter it belongs to.
 *
 * The time object list of a counter is a double-linked list
 * and a time object is inserted starting from the
 * head of the list
 *
 * @param time_obj  The time object to insert.
 */
FUNC(void, OS_CODE) tpl_insert_time_obj(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) time_obj);

/**
 * @internal
 *
 * tpl_remove_time_obj removes a time object from the time object
 * queue of the counter it belongs to.
 *
 * @param time_obj  The time object to remove.
 */
FUNC(void, OS_CODE) tpl_remove_time_obj(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) time_obj);

/**
 * @internal
 *
 * tpl_counter_tick is called by the IT associated with a counter
 * It increment the counter tick and the counter value if needed
 * If the counter value is incremented, it checks the next alarm
 * date and raises alarms at that date. It does not perform the rescheduling,
 * tpl_schedule must be called explicitly.
 *
 * @param counter    A pointer to the counter
 */
FUNC(tpl_status, OS_CODE) tpl_counter_tick(
    P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_TIMEOBJ_KERNEL_H */

/* End of file tpl_os_timeobj_kernel.h */
