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
#include "Memmap.h"

/**
 * Currently running executable object. This "executable object" can be a task
 * or an interrupt service routine
 */
extern tpl_exec_common  *tpl_running_obj;


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
extern tpl_task         *tpl_task_table[TASK_COUNT];
#endif


#ifndef NO_RESOURCE
/**
 * Array of all resources descriptors
 *
 * Index in this array correspond to the #ResourceType of the resource
 */
extern tpl_resource     *tpl_resource_table[RESOURCE_COUNT];
#endif


#ifndef NO_ALARM
/**
 * Array of all alarms descriptors
 *
 * Index in this array correspond to the #AlarmType of the alarm
 */
extern tpl_alarm        *tpl_alarm_table[ALARM_COUNT];
#endif


#ifndef NO_ISR
/**
 * Array of all category 2 interrupt service routine descriptor
 *
 * Index in this array correspond to the Isr identifier
 */
extern tpl_isr			*tpl_isr_table[ISR_COUNT];
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
extern u8   tpl_os_state;


/**
 * The scheduler resource descriptor
 *
 * @see #RES_SCHEDULER
 */
extern tpl_resource res_sched;

extern tpl_internal_resource INTERNAL_RES_SCHEDULER;


#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"


#define OS_START_SEC_CODE
#include "Memmap.h"
/**
 * Kernel functions
 */
extern void tpl_schedule(const u8 from);


extern tpl_status tpl_activate_task(tpl_task *a_task);


extern tpl_status tpl_set_event(
    tpl_task                *a_task,
    const tpl_event_mask    incoming_event);

extern void tpl_init_exec_object(tpl_exec_common *exec_obj);


extern void tpl_put_exec_object(
    tpl_exec_common *exec_obj,
    const u8        kind);

   
extern void tpl_init_os(const tpl_application_mode app_mode);


extern void tpl_release_internal_resource(tpl_exec_common *a_task);


#define OS_STOP_SEC_CODE
#include "Memmap.h"

#endif /* TPL_OS_KERNEL_H */

/* End of file tpl_os_kernel.h */
