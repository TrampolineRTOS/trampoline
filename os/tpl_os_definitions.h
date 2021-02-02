/**
 * @file tpl_os_definitions.h
 *
 * @section descr File description
 *
 * Here are defined all global symbolic values used in Trampoline.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 */

#ifndef TPL_OS_DEFINITIONS_H
#define TPL_OS_DEFINITIONS_H

#include "tpl_os_application_def.h"

/**
 * @def FALSE
 *
 * boolean false value
 *
 * @see #tpl_bool
 */
#ifndef FALSE
#define FALSE   ((tpl_bool)0)
#endif
/**
 * @def TRUE
 *
 * boolean true value
 *
 * @see #tpl_bool
 */
#ifndef TRUE
#define TRUE    ((tpl_bool)1)
#endif

#ifndef NULL
#define NULL 0
#endif

/***********************
 * Conformance classes *
 ***********************/

/**
 * @def CONFORM_ECC1
 *
 * identifies the ECC1 conformance class
 *
 * @see #CONFORMANCE_CLASS
 */
#define CONFORM_ECC1        1

/**
 * @def CONFORM_ECC2
 *
 * identifies the ECC2 conformance class
 *
 * @see #CONFORMANCE_CLASS
 */
#define CONFORM_ECC2        2

/**
 * @def CONFORMANCE_CLASS
 *
 * represents the configured conformance class
 *
 * @warning at this time, Trampoline only supports ECC2
 */
#define CONFORMANCE_CLASS   CONFORM_ECC2


/****************
 * Result codes *
 ****************/

/**
 * @def E_OK
 *
 * This error code means : no error
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning in this specific
 * context.
 */
#ifndef E_OK_DEFINED
#define E_OK_DEFINED
#define E_OK            0
#endif
/**
 * @def E_OS_ACCESS
 *
 * This error code means : calling task is not an extended task
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#define E_OS_ACCESS     1

/**
 * @def E_OS_CALLEVEL
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
 * This error code means : limit exceeded. The only limit known to raise this
 * error is the number of task activations
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

/**
 * @def E_NOT_OK
 *
 * This error code means : an error occured
 *
 * @warning OSEK error code meanings are not globally defined. Refer to each
 * standard service definition to know the exact meaning.
 */
#ifndef E_NOT_OK_DEFINED
#define E_NOT_OK_DEFINED
#define E_NOT_OK        9
#endif

/* Additional AUTOSAR error codes */

/**
 * @def E_OS_SERVICEID
 *
 * Service can not be called
 */
#define E_OS_SERVICEID            16

/**
 * @def E_OS_ILLEGAL_ADDRESS
 *
 * An invalid address is given as a parameter to a service
 */
#define E_OS_ILLEGAL_ADDRESS      17

/**
 * @def E_OS_MISSINGEND
 *
 * Tasks terminates without a TerminateTask() or ChainTask() call
 */
#define E_OS_MISSINGEND           18

/**
 * @def E_OS_DISABLEDINT
 *
 * A service of the OS is called inside an interrupt disable/enable pair
 */
#define E_OS_DISABLEDINT          19

/**
 * @def E_OS_STACKFAULT
 *
 * A stack fault detected via stack monitoring by the OS
 */
#define E_OS_STACKFAULT           20

/**
 * @def E_OS_PROTECTION_MEMORY
 *
 * A memory access violation occurred
 */
#define E_OS_PROTECTION_MEMORY    21

/**
 * @def E_OS_PROTECTION_TIME
 *
 * A Task exceeds its execution time budget,
 * A Category 2 OsIsr exceeds its execution time budget
 */
#define E_OS_PROTECTION_TIME      22

/**
 * @def E_OS_PROTECTION_ARRIVAL
 *
 * A Task/Category 2 arrives before its timeframe has expired
 */
#define E_OS_PROTECTION_ARRIVAL   23

/**
 * @def E_OS_PROTECTION_LOCKED
 *
 * A Task/Category 2 OsIsr blocks for too long
 */
#define E_OS_PROTECTION_LOCKED    24

/**
 * @def E_OS_PROTECTION_EXCEPTION
 *
 * A trap occurred
 */
#define E_OS_PROTECTION_EXCEPTION 25

/**
 * @def E_OS_INTERFERENCE_DEADLOCK
 *
 * In extended status: A TASK tries to occupy the spinlock while the lock is
 * already occupied by a TASK on the same core. This would cause a deadlock
 */
#define E_OS_INTERFERENCE_DEADLOCK  26

/**
 * @def E_OS_NESTING_DEADLOCK
 *
 * In extended status: A TASK tries to occupy a spinlock while a TASK on the
 * same core is holding a different spinlock in a way that may cause a deadlock
 */
#define E_OS_NESTING_DEADLOCK     27

/**
 * @def E_OS_SPINLOCK
 *
 * [SWS_Os_00612] [SWS_Os_00622] [SWS_Os_00624]
 * In extended status: TerminateTask, ChainTask, WaitEvent, Schedule is called
 * while the calling TASK holds a spinlock.
 */
#define E_OS_SPINLOCK             28

/**
 * @def E_OS_LOSTDATA
 *
 * IOC
 * This error can occur when receiving a data through the IOC. Some datas were
 * lost due to a previous send while the queue was full.
 */
#define E_OS_LOST_DATA            29

/**
 * @def E_OS_NO_DATA
 *
 * IOC
 * This error can occur when receiving a data through the IOC while the queue
 * is empty.
 */
#define E_OS_NO_DATA              30

/************************************
 * Public states of a task or ISR2  *
 ************************************/
/**
 * @def SUSPENDED
 *
 * Task is suspended.
 *
 * @see #tpl_exec_state
 */
#define SUSPENDED  0x0

/**
 * @def READY
 *
 * Task is ready (to be run, or elected by scheduler).
 *
 * @see #tpl_exec_state
 */
#define READY      0x1

/**
 * @def RUNNING
 *
 * Task is currently running.
 *
 * @see #tpl_exec_state
 */
#define RUNNING    0x2

#if (CONFORMANCE_CLASS == CONFORM_ECC1) || (CONFORMANCE_CLASS == CONFORM_ECC2)
/**
 * @def WAITING
 *
 * Task is waiting
 *
 * @see #tpl_exec_state
 */
#define WAITING    0x3
#endif


/************************************
 * bits of tpl_need_switch          *
 ************************************/

/**
 * @def NO_NEED_SWITCH
 *
 * Used for tpl_need_switch variable. No context switch should occur
 *
 * @see #tpl_need_switch
 */
#define NO_NEED_SWITCH  0x0

/**
 * @def NEED_SWITCH
 *
 * Used for tpl_need_switch variable. A context switch should occur
 *
 * @see #tpl_need_switch
 */
#define NEED_SWITCH     0x1

/**
 * @def NEED_SAVE
 *
 * Used for tpl_need_switch variable. The context of the process that
 * loses the CPU should be saved
 *
 * @see #tpl_need_switch
 */
#define NEED_SAVE       0x2

/**
 * @def NOAPPMODE
 *
 * Constant to initialize the application_mode.
 *
 * @see #StartOS
 * @see #AppModeType
 */
#define NOAPPMODE (-1)

/*********************************
 * Task flags for the type field *
 *********************************/

/**
 * @def TASK_BASIC
 *
 * identifies a basic task
 *
 * @see #tpl_exec_obj_type
 * @see #TPL_EXEC_STATIC
 */
#define TASK_BASIC              0x0

/**
 * @def TASK_EXTENDED
 *
 * identifies an extended task
 *
 * @see #tpl_exec_obj_type
 * @see #TPL_EXEC_STATIC
 */
#define TASK_EXTENDED           0x1

/**
 * @def IS_ROUTINE
 *
 * identifies a category 2 Interrupt Service Routine
 *
 * @see #tpl_exec_obj_type
 * @see #TPL_EXEC_STATIC
 */
#define IS_ROUTINE              0x2

/**
 * @def FULL_PREEMTABLE_TASK
 *
 * exec object characteristic is : fully preemptable
 *
 * @see #tpl_exec_obj_type
 * @see #TPL_EXEC_STATIC
 */
#define FULL_PREEMPTABLE_TASK   0x0

/**
 * @def NON_PREEMPTABLE_TASK
 *
 * exec object characteristic is : non-preemptable
 *
 * @see #tpl_exec_obj_type
 * @see #TPL_EXEC_STATIC
 */
#define NON_PREEMPTABLE_TASK    0x4

/*****************************
 * Alarms states and actions *
 *****************************/
#define TIME_OBJ_SLEEP      0
#define TIME_OBJ_ACTIVE     1
#define TIME_OBJ_AUTOSTART  2
/**
 * @def ALARM_SLEEP
 *
 * This state means the related alarm is not in use (de-activated)
 *
 * @see #tpl_alarm_state
 * @see #TPL_ALARM
 */
#define ALARM_SLEEP     TIME_OBJ_SLEEP

/**
 * @def ALARM_ACTIVE
 *
 * This state means the related alarm is in use (activated)
 *
 * @see #tpl_alarm_state
 * @see #TPL_ALARM
 */
#define ALARM_ACTIVE    TIME_OBJ_ACTIVE

/**
 * @def ALARM_AUTOSTART
 *
 * This state means alarm should be automatically activated at system startup.
 *
 * @see #tpl_alarm_state
 * @see #TPL_ALARM
 */
#define ALARM_AUTOSTART TIME_OBJ_AUTOSTART

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
 * Scheduler is called from a task (either directly or indirectly, but not
 * from an interrupt)
 *
 * @see #tpl_schedule
 */
#define FROM_TASK_LEVEL 0

/**
 * @def FROM_IT_LEVEL
 *
 * Scheduler is called from a task (either directly or indirectly, but not
 * from an interrupt)
 *
 * @see #tpl_schedule
 */
#define FROM_IT_LEVEL   1

/**
 * @def TASK
 *
 * Macro used to define (declare) a task
 *
 * @param name the name (C identifier) of the task
 */
#ifdef __cplusplus
    #define TASK(name)                                          \
    DeclareTask(name);                                          \
    extern "C" FUNC(void, OS_APPL_CODE) name##_function(void);  \
    FUNC(void, OS_APPL_CODE) name##_function(void)
#else
    #define TASK(name)                                          \
    DeclareTask(name);                                          \
FUNC(void, OS_APPL_CODE) name##_function(void)
#endif

/**
 * @def ISR
 *
 * Macro used to define (declare) an interrupt service routine.
 *
 * @param name the name (C identifier) of the IRS
 */
#ifdef __cplusplus
    #define ISR(name)                                           \
    extern "C" FUNC(void, OS_APPL_CODE) name##_function(void);  \
    FUNC(void, OS_APPL_CODE) name##_function(void)
#else
    #define ISR(name)                                           \
    FUNC(void, OS_APPL_CODE) name##_function(void)
#endif


/**
 * @def DeclareConterConstants
 *
 * Macro used to declare all the constants of a counter at once
 *
 * @param counter_id    the name of the counter
 */
#define DeclareCounterConstants(counter_id) \
extern CONST(TickType, OS_CONST) OSTICKSPERBASE_##counter_id; \
extern CONST(TickType, OS_CONST) OSMAXALLOWEDVALUE_##counter_id; \
extern CONST(TickType, OS_CONST) OSMINCYCLE_##counter_id

/**
 * @def ALARMCALLBACK
 *
 * Macro used to define an alarm callback function
 *
 * @param name callback name
 *
 * @warning don't be confused with ALARM_CALLBACK
 */
#ifdef __cplusplus
#define ALARMCALLBACK(name)                \
    extern "C" void name##_callback(void); \
    void name##_callback(void)
#else
#define ALARMCALLBACK(name)     \
    void name##_callback(void)
#endif

/**
 * @def MASK_EXECTYPE
 *
 * Don't use this macro directly, use one of the following macros instead :
 *
 * @see #tpl_is_basic
 * @see #tpl_is_extended
 * @see #tpl_is_full_preemptable
 * @see #tpl_is_non_preemptable
 * @see #tpl_is_isr
 */
#define MASK_EXECTYPE       0x3

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
#define PREEMPTABLE_MASK    0x4


#if WITH_AUTOSAR == YES
/**
 * @def HARDWARE_COUNTER
 *
 * Identifies a hardware counter
 *
 * @see #tpl_counter_kind
 */
#define HARDWARE_COUNTER    0

/**
 * @def SOFTWARE_COUNTER
 *
 * Identifies a software counter
 *
 * @see #tpl_counter_kind
 */
#define SOFTWARE_COUNTER    1

#endif

#if NUMBER_OF_CORES > 1

#define UNLOCKED_LOCK       0
#define LOCKED_LOCK         1

#endif

/**
 * @def PANIC_NMI
 */
#define PANIC_NMI         1

/**
 * @def PANIC_HARDFAULT
 */
#define PANIC_HARDFAULT   2

/**
 * @def PANIC_MEMMANAGE
 */
#define PANIC_MEMMANAGE   3

/**
 * @def PANIC_BUSFAULT
 */
#define PANIC_BUSFAULT    4

/**
 * @def PANIC_USAGEFAULT
 */
#define PANIC_USAGEFAULT  5

#endif /* TPL_OS_DEFINITIONS_H */

/* End of file tpl_os_definitions.h */
