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
void tpl_insert_time_obj(tpl_time_obj *time_obj);

/**
 * @internal
 *
 * tpl_remove_time_obj removes a time object from the time object
 * queue of the counter it belongs to.
 *
 * @param time_obj  The time object to remove.
 */
void tpl_remove_time_obj(tpl_time_obj *time_obj);

/**
 * @internal
 *
 * tpl_raise_alarm is called by tpl_counter_tick
 * when an alarm time object is raised.
 *
 * @param time_obj  The alarm to raise.
 */
tpl_status tpl_raise_alarm(const tpl_time_obj *time_obj);

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
tpl_status tpl_counter_tick(tpl_counter *counter);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_ALARM_KERNEL_H */

/* End of file tpl_os_alarm_kernel.h */
