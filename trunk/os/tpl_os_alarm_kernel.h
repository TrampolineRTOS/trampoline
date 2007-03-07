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
 * @internal
 *
 * tpl_insert_alarm inserts an alarm in the alarm queue of the counter
 * it belongs to.
 *
 * The alarm list of a counter is a double-linked list
 * and an alarm is inserted starting from the
 * head of the list
 *
 * @param alarm     The alarm to insert.
 */
void tpl_insert_alarm(tpl_alarm *alarm);

/**
 * @internal
 *
 * tpl_remove_alarm removes an alarm from the alarm queue of the counter
 * it belongs to.
 *
 * @param alarm     The alarm to remove.
 */
void tpl_remove_alarm(tpl_alarm *alarm);

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

#endif /* TPL_OS_ALARM_KERNEL_H */

/* End of file tpl_os_alarm_kernel.h */
