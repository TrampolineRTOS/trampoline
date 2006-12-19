/**
 * @file tpl_os_definitions.h
 *
 * @section copyright Copyright
 * 
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 * @section descr Module description
 *
 * Here are defined all global symbolic values used in Trampoline.
 */

#ifndef __TPL_OS_DEFINITIONS_H__
#define __TPL_OS_DEFINITIONS_H__

/**
 * @def FALSE
 *
 * boolean false value
 */
#define FALSE   0

/**
 * @def TRUE
 *
 * boolean true value
 */
#define TRUE    1

#ifndef NULL
#define NULL 0
#endif

/****************
 * Result codes *
 ****************/

/**
 * @def E_OK
 *
 * This error code means : no error
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#define E_OK            0

/**
 * @def E_OS_ACCESS
 *
 * This error code means : calling task is not an extended task"
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#define E_OS_ACCESS     1

/**
 * @def E_OS_CALLLEVEL
 *
 * This error code means : call at interrupt level
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#define E_OS_CALLEVEL   2

/**
 * @def E_OS_ID
 *
 * This error code means : invalid identifier
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#define E_OS_ID         3

/**
 * @def E_OS_LIMIT
 *
 * This error code means : limit exceeded. The only limit known to raise this error is the number
 * of task activations
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#define E_OS_LIMIT      4

/**
 * @def E_OS_NOFUNC
 *
 * This error code means : not appropriate.
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#define E_OS_NOFUNC     5

/**
 * @def E_OS_RESOURCE
 *
 * This error code means : calling task still occupies resources
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#define E_OS_RESOURCE   6

/**
 * @def E_OS_STATE
 *
 * This error code means : related state not appropriate
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#define E_OS_STATE      7

/**
 * @def E_OS_VALUE
 *
 * This error code means : value outside of the admissible limits
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#define E_OS_VALUE      8

/*********************************
 * Task flags for the type field *
 *********************************/

/**
 * @def BASIC_TASK
 *
 * @see #tpl_exec_obj_type
 * @see #TPL_EXEC_STATIC
 */
#define BASIC_TASK              0x0

/**
 * @def EXTENDED_TASK
 *
 * @see #tpl_exec_obj_type
 * @see #TPL_EXEC_STATIC
 */
#define EXTENDED_TASK           0x1

/**
 * @def IS_ROUTINE
 *
 * @see #tpl_exec_obj_type
 * @see #TPL_EXEC_STATIC
 */
#define IS_ROUTINE              0x2

/**
 * @def FULL_PREEMTABLE_TASK
 *
 * @see #tpl_exec_obj_type
 * @see #TPL_EXEC_STATIC
 */
#define FULL_PREEMPTABLE_TASK   0x0

/**
 * @def NON_PREEMPTABLE_TASK
 *
 * @see #tpl_exec_obj_type
 * @see #TPL_EXEC_STATIC
 */
#define NON_PREEMPTABLE_TASK    0x4

/*****************************
 * Alarms states and actions *
 *****************************/

/**
 * @def ALARM_SLEEP
 *
 * This state means the related alarm has not raised
 *
 * @see #tpl_alarm_state
 * @see #TPL_ALARM
 */
#define ALARM_SLEEP     0

/**
 * @def ALARM_ACTIVE
 *
 * This state means the related alarm has raised
 *
 * @see #tpl_alarm_state
 * @see #TPL_ALARM
 */
#define ALARM_ACTIVE    1
#define ALARM_AUTOSTART 2

/**
 * @def ALARM_CALLBACK
 *
 * The alarm is a callback (call a function when raise)
 *
 * @see #tpl_alarm_kind
 * @see #TPL_ALARM
 */
#define ALARM_CALLBACK          10

/**
 * @def ALARM_TASK_ACTIVATION
 *
 * The alarm activates a task when raised
 *
 * @see #tpl_alarm_kind
 * @see #TPL_ALARM
 */
#define ALARM_TASK_ACTIVATION   11

/**
 * @def ALARM_EVENT_SETTING
 *
 * The alarm sets an event when raised
 *
 * @see #tpl_alarm_kind
 * @see #TPL_ALARM
 */
#define ALARM_EVENT_SETTING     12

/***************************************
 * selector for tpl_schedule parameter *
 ***************************************/

/**
 * @def FROM_TASK_LEVEL
 *
 * Scheduler is called from a task (either directly or indirectly, but not from an interrupt)
 *
 * @see #tpl_schedule
 */
#define FROM_TASK_LEVEL 0

/**
 * @def FROM_IT_LEVEL
 *
 * Scheduler is called from a task (either directly or indirectly, but not from an interrupt)
 *
 * @see #tpl_schedule
 */
#define FROM_IT_LEVEL   1

/**********************************************
 * selector for tpl_put_exec_object parameter *
 **********************************************/

/**
 * @def PREEMPTED_EXEC_OBJ
 *
 * The object (task or interrupt) added to the ready list has been preempted (and have to be
 * added to the front of the list)
 *
 * @see #tpl_put_exec_object
 */
#define PREEMPTED_EXEC_OBJ          0

/**
 * @def NEWLY_ACTIVATED_EXEC_OBJ
 *
 * The object (task or interrupt) added to the ready list is newly activated (and have to be
 * added to the back of the list)
 *
 * @see #tpl_put_exec_object
 */
#define NEWLY_ACTIVATED_EXEC_OBJ    1

/**
 * @def TASK
 *
 * Macro used to define (declare) a task
 *
 * @param name the name (C identifier) of the task
 */
#define TASK(name)              \
    void function_of_task_##name##(void)

/**
 * @def ISR2
 *
 * Macro used to define (declare) a category 2 interrupt service routine.
 *
 * @param name the name (C identifier) of the IRS
 */
#define ISR2(name)              \
    void function_of_isr_##name##(void)

/**
 * @def ALARMCALLBACK
 *
 * Macro used to define an alarm callback function
 *
 * @param name callback name
 *
 * @warning don't be confused with ALARM_CALLBACK
 */
#define ALARMCALLBACK(name)     \
    void alarm_callback_##name(void)

/**
 * @def EXECTYPE_MASK
 *
 * Don't use this macro directly, use one of the following macros instead :
 *
 * @see #tpl_is_basic
 * @see #tpl_is_extended
 * @see #tpl_is_full_preemptable
 * @see #tpl_is_non_preemptable
 * @see #tpl_is_isr
 */
#define EXECTYPE_MASK       0x3

/**
 * @def PREEMPTABLE_MASK
 *
 * Don't use this macro directly, use one of the following macros instead :
 *
 * @see #tpl_is_basic
 * @see #tpl_is_extended
 * @see #tpl_is_full_preemptable
 * @see #tpl_is_non_preemptable
 * @see #tpl_is_isr
 */
#define PREEMPTABLE_MASK    0x2

/**
 * @def tpl_is_basic
 *
 * @param obj exec object to test
 *
 * true if obj is a basic task
 */
#define tpl_is_basic(obj)     \
    ((obj->static_desc->type & EXECTYPE_MASK) == BASIC_TASK)

/**
 * @def tpl_is_extended
 *
 * @param obj exec object to test
 *
 * true if obj is an extended task
 */
#define tpl_is_extended(obj)  \
    ((obj->static_desc->type & EXECTYPE_MASK) == EXTENDED_TASK)

/**
 * @def tpl_is_full_preemptable
 *
 * @param obj exec object to test
 *
 * true if obj is preemptable
 */
#define tpl_is_full_preemptable(obj)   \
    ((obj->static_desc->type & PREEMPTABLE_MASK) == FULL_PREEMTABLE_TASK)

/**
 * @def tpl_is_non_preemptable
 *
 * @param obj exec object to test
 *
 * true if obj is not preemptable
 */
#define tpl_is_non_preemptable(obj)    \
    ((obj->static_desc->type & PREEMPTABLE_MASK) == NON_PREEMPTABLE_TASK)
    
/**
 * @def tpl_is_isr
 *
 * @param obj exec object to test
 *
 * true if obj is an ISR
 */
#define tpl_is_isr(obj)     \
    ((obj->static_desc->type & EXECTYPE_MASK) == IS_ROUTINE)
    
#endif
