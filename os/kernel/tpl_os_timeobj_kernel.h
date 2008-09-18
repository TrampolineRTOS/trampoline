/**
 * @file tpl_os_alarm_kernel.h
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

#ifndef TPL_OS_ALARM_KERNEL_H
#define TPL_OS_ALARM_KERNEL_H

/**
 * @typedef tpl_time_obj_state
 *
 * Describes an time object state. Value can be one of :
 * - #ALARM_SLEEP
 * - #ALARM_ACTIVE
 * - #ALARM_AUTOSTART (only before startup)
 */
typedef u8 tpl_time_obj_state;

/* Forward declaration */
struct TPL_COUNTER;

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

struct TPL_TIME_OBJ;

/**
 * @typedef tpl_expire_func
 *
 * Prototype for expire functions
 */
typedef P2FUNC(tpl_status, OS_APPL_CODE, tpl_expire_func)(
    P2CONST(struct TPL_TIME_OBJ, AUTOMATIC, OS_APPL_CONST)
);


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

#endif /* TPL_OS_ALARM_KERNEL_H */

/* End of file tpl_os_alarm_kernel.h */
