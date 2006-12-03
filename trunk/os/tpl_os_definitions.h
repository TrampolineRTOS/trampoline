/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Result codes of the OS
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#ifndef __TPL_OS_DEFINITIONS_H__
#define __TPL_OS_DEFINITIONS_H__

/*
 * bool as usual
 */
#define FALSE   0
#define TRUE    1

/*
 * Result codes
 */
#define E_OK            0
#define E_OS_ACCESS     1
#define E_OS_CALLEVEL   2
#define E_OS_ID         3
#define E_OS_LIMIT      4
#define E_OS_NOFUNC     5
#define E_OS_RESOURCE   6
#define E_OS_STATE      7
#define E_OS_VALUE      8

/*
 * Task flags for the type field
 */
#define BASIC_TASK              0x0
#define EXTENDED_TASK           0x1
#define IS_ROUTINE              0x2
#define FULL_PREEMPTABLE_TASK   0x0
#define NON_PREEMPTABLE_TASK    0x4

/*
 * Alarms states and actions
 */
#define ALARM_SLEEP     0
#define ALARM_ACTIVE    1
#define ALARM_AUTOSTART 2

#define ALARM_CALLBACK          10
#define ALARM_TASK_ACTIVATION   11
#define ALARM_EVENT_SETTING     12

/*
 * selector for tpl_schedule parameter
 */
#define FROM_TASK_LEVEL 0
#define FROM_IT_LEVEL   1

/*
 * selector for tpl_put_exec_object parameter
 */
#define PREEMPTED_EXEC_OBJ          0
#define NEWLY_ACTIVATED_EXEC_OBJ    1

/*
 * Define NULL if not already defined
 */
#ifndef NULL
#define NULL 0
#endif

/*
 * Define the TASK macro
 */
#define TASK(name)              \
    void function_of_task_##name##(void)

/*
 * Define the ISR2 macro
 */
#define ISR2(name)              \
    void function_of_isr_##name##(void)

/*
 * Define the ALARMCALLBACK macro
 */
#define ALARMCALLBACK(name)     \
    void alarm_callback_##name(void)

/*
 * Define masks to access bits in the type field of
 * the task static descriptor
 */
#define EXECTYPE_MASK       0x3
#define PREEMPTABLE_MASK    0x2

#define tpl_is_basic(obj)     \
    ((obj->static_desc->type & EXECTYPE_MASK) == BASIC_TASK)

#define tpl_is_extended(obj)  \
    ((obj->static_desc->type & EXECTYPE_MASK) == EXTENDED_TASK)

#define tpl_is_full_preemptable(obj)   \
    ((obj->static_desc->type & PREEMPTABLE_MASK) == FULL_PREEMTABLE_TASK)

#define tpl_is_non_preemptable(obj)    \
    ((obj->static_desc->type & PREEMPTABLE_MASK) == NON_PREEMPTABLE_TASK)
    
#define tpl_is_isr(obj)     \
    ((obj->static_desc->type & EXECTYPE_MASK) == IS_ROUTINE)
    
#endif
