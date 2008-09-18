/**
 * @file tpl_os_kernel.h
 *
 * @section desc File description
 *
 * Trampoline kernel structures header file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Copyright ESEO for function and data structures documentation
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

#ifndef TPL_OS_KERNEL_H
#define TPL_OS_KERNEL_H

#include "tpl_os_internal_types.h"
#include "tpl_os_it_kernel.h"
#include "tpl_os_application_def.h"

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#include "tpl_as_timing_protec.h"
#include "tpl_as_st_kernel.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

/**
 * @def INVALID_TASK
 *
 * This value is used to specify an invalid #TaskType
 */
#define INVALID_TASK    (-1)

/**
 * @def OS_INIT
 *
 * State of Trampoline : initialization
 *
 * @see #tpl_os_state
 */
#define OS_INIT 0U

/**
 * @def OS_TASK
 *
 * State of trampoline : running a task
 *
 * @see #tpl_os_state
 */
#define OS_TASK 1U

/**
 * @def OS_IDLE
 *
 * State of Trampoline : idle (no task running and OS have nothing else to do)
 */
#define OS_IDLE 2U

/**
 * @def OS_ISR2
 *
 * State of Trampoline : running a category 2 interrupt service routine
 */
#define OS_ISR2 3U


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * Currently running executable object. This "executable object" can be a task
 * or an interrupt service routine
 */
extern P2VAR(tpl_exec_common, OS_VAR, OS_APPL_DATA) tpl_running_obj;


#ifndef NO_TASK
/**
 * Array of all tasks' full descriptors.
 *
 * Index in this array correspond to the #TaskType of the task.
 * While it would be less time consuming to refer a task by a pointer
 * to its descriptor, the OSEK API requires a task to have an identifier.
 * So a table of pointer is used. The size of this table is static
 * and known at compile time
 */
extern P2VAR(tpl_task, AUTOMATIC, OS_APPL_DATA) tpl_task_table[TASK_COUNT];
#endif


#ifndef NO_RESOURCE
/**
 * Array of all resources descriptors
 *
 * Index in this array correspond to the #ResourceType of the resource
 */
extern P2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA) tpl_resource_table[RESOURCE_COUNT];
#endif


#ifndef NO_ALARM
/**
 * Array of all alarms descriptors
 *
 * Index in this array correspond to the #AlarmType of the alarm
 */
extern P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) tpl_alarm_table[ALARM_COUNT];
#endif


#ifndef NO_ISR
/**
 * Array of all category 2 interrupt service routine descriptors
 *
 * Index in this array correspond to the Isr identifier
 */
extern P2VAR(tpl_isr, AUTOMATIC, OS_APPL_DATA) tpl_isr_table[ISR_COUNT];
#endif

#ifdef WITH_AUTOSAR
#ifndef NO_SCHEDTABLE
/**
 * Array of all schedule table descriptors
 *
 * Index in this array correspond to the schedule table identifier
 */
extern P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) tpl_schedtable_table[SCHEDTABLE_COUNT];
#endif
#endif

/**
 * tpl_os_state stores the current state of Trampoline
 * it is set when the OS go from a state to another one
 * and used in various services. For instance, if the
 * OS is in the ISR state, tpl_schedule is not executed
 * and is postponed at the end of the ISR execution

 * Value can be one of :
 * - #OS_INIT
 * - #OS_TASK
 * - #OS_IDLE
 * - #OS_ISR2
 */
extern VAR(u8, OS_VAR)  tpl_os_state;


/**
 * The scheduler resource descriptor
 *
 * @see #RES_SCHEDULER
 */
extern VAR(tpl_resource, OS_VAR) res_sched;

extern VAR(tpl_internal_resource, OS_VAR) INTERNAL_RES_SCHEDULER;


#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * Kernel functions
 */
extern FUNC(void, OS_CODE) tpl_schedule(
    CONST(u8, AUTOMATIC) from);

extern FUNC(void, OS_CODE) tpl_schedule_from_running(
    CONST(u8, AUTOMATIC) from);

extern FUNC(void, OS_CODE) tpl_schedule_from_dying(void);

extern FUNC(void, OS_CODE) tpl_schedule_from_idle(void);

extern FUNC(void, OS_CODE) tpl_schedule_from_waiting(void);

extern FUNC(tpl_status, OS_CODE) tpl_activate_task(
    P2VAR(tpl_task, AUTOMATIC, OS_APPL_DATA) a_task);

extern FUNC(tpl_status, OS_CODE) tpl_set_event(
    P2VAR(tpl_task, AUTOMATIC, OS_APPL_DATA)  a_task,
    CONST(tpl_event_mask, AUTOMATIC)          incoming_event);

extern FUNC(void, OS_CODE) tpl_init_exec_object(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) exec_obj);

extern FUNC(void, OS_CODE) tpl_put_preempted_exec_object(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) exec_obj);

extern FUNC(void, OS_CODE) tpl_put_new_exec_object(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) exec_obj);

extern FUNC(void, OS_CODE) tpl_init_os(
    CONST(tpl_application_mode, AUTOMATIC) app_mode);

extern FUNC(void, OS_CODE) tpl_get_internal_resource(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) a_task);

extern FUNC(void, OS_CODE) tpl_release_internal_resource(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) a_task);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_KERNEL_H */

/* End of file tpl_os_kernel.h */
