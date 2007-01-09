/**
 * @file tpl_os_kernel.h
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
 * @section desc File description
 *
 * Trampoline kernel structures header file
 *
 */

#ifndef __TPL_OS_KERNEL_H__
#define __TPL_OS_KERNEL_H__

#include "tpl_os_internal_types.h"
#include "tpl_os_interrupts.h"
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
#define OS_INIT 0

/**
 * @def OS_TASK
 *
 * State of trampoline : running a task
 * 
 * @see #tpl_os_state
 */
#define OS_TASK 1

/**
 * @def OS_IDLE
 *
 * State of Trampoline : idle (no task running and, OS have nothing else to do)
 */
#define OS_IDLE 2

/**
 * @def OS_ISR2
 *
 * State of Trampoline : running a category 2 interrupt service routine
 */
#define OS_ISR2 3

/*
 * Globals of the OS
 */
/*extern tpl_status       tpl_last_result; */

/**
 * Currently running executable object. This "executable object" can be a task
 * or an interrupt service routine
 */
extern tpl_exec_common  *tpl_running_obj;

/**
 * Head of the list of ready executable objects
 */
extern tpl_exec_common  *tpl_exec_obj_list_head;

#ifndef NO_TASK
/**
 * Array of all tasks' full descriptors.
 *
 * Index in this array correspond to the #TaskType of the task.
 */
extern tpl_task         *tpl_task_table[TASK_COUNT];  /* While it would be less time consuming to
                                                       * refer a task by a pointer to its descriptor
                                                       * the OSEK API requires a task to have an
                                                       * identifier. So a table of pointer
                                                       * is used. The size of this table is static
                                                       * and known at compile time
                                                       */

#endif

#ifndef NO_RESOURCE
/**
 * Array of all resources descriptors
 *
 * Index in this array correspond to the #ResourceType of the resource
 */
extern tpl_resource     *tpl_resource_table[RES_COUNT];
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
 * stores the current state of Trampoline
 *
 * Value can be one of :
 * - #OS_INIT
 * - #OS_TASK
 * - #OS_IDLE
 * - #OS_ISR2
 */
extern unsigned char    tpl_os_state;

/**
 * Locking the kernel.
 *
 * unused
 */
extern tpl_lock         *TASK_LOCK;

#endif
