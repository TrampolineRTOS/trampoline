/**
 * @file tpl_os_task_kernel.h
 *
 * @section desc File description
 *
 * Kernel functions for task management
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS,
 * University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_TASK_KERNEL_H
#define TPL_OS_TASK_KERNEL_H

#include "tpl_os_kernel.h"

/**
 * @struct TPL_TASK_EVENTS
 *
 * This structure is used to store the event masks of the events
 * that have been set and the events a task waits for.
 */
struct TPL_TASK_EVENTS
{
  VAR(tpl_event_mask, TYPEDEF) evt_set;  /**< events received           */
  VAR(tpl_event_mask, TYPEDEF) evt_wait; /**< events the task waits for */
};

/**
 * @typedef tpl_task_events
 *
 * This type is an alias for the #TPL_TASK_EVENTS structure.
 *
 * @see #TPL_TASK_EVENTS
 */
typedef struct TPL_TASK_EVENTS tpl_task_events;

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#if EXTENDED_TASK_COUNT > 0
/**
 * Alias to the tpl_task_events_table table
 */
extern CONSTP2VAR(tpl_task_events, AUTOMATIC,
                  OS_APPL_DATA) tpl_task_events_table[EXTENDED_TASK_COUNT];
#endif /* EXTENDED_TASK_COUNT */

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * Activates a task.
 *
 * @param   task_id     identifier of the task to be activated
 *
 * @retval  E_OK        no error
 * @retval  E_OS_LIMIT  too many task activations
 * @retval  E_OS_ID     (extended error only) task_id is invalid
 *
 */
FUNC(tpl_status, OS_CODE)
tpl_activate_task_service(CONST(tpl_task_id, AUTOMATIC) task_id);

/**
 * Terminates the execution of a task.
 *
 * @note    this function never returns unless extended error mode is
 *          active and an error occurred
 *
 * @retval  E_OS_RESOURCE (extended error only) task still occupies resources
 * @retval  E_OS_CALLEVEL (extended error only) call at interrupt level
 *
 */
FUNC(tpl_status, OS_CODE) tpl_terminate_task_service(void);

/**
 * Chain terminaison of current task with activation of another.
 *
 * @param   task_id  identifier of the task to activate
 *
 * @note    if this function succeeds, it does not returns (as the current
 *          task is then finished)
 *
 * @retval  E_OS_LIMIT too many task activations
 * @retval  E_OS_ID (extended error only) task_id is invalid
 *
 */
FUNC(tpl_status, OS_CODE)
tpl_chain_task_service(CONST(tpl_task_id, AUTOMATIC) task_id);

/**
 * Call to the scheduler.
 *
 * @retval  E_OK            no error
 * @retval  E_OS_CALLEVEL   (extended error only) call at interrupt level
 * @retval  E_OS_RESOURCE   (extended error only) task still occupies resource
 *
 * see paragraph 13.2.3.4 page 52 of OSEK/VDX 2.2.3 spec
 */
FUNC(tpl_status, OS_CODE) tpl_schedule_service(void);

/**
 * Gives the identifier of the running task
 *
 * @param   task_id     reference of the variable where
 *                      the identifier will be returned
 *
 * @retval  E_OK        no error
 *
 * see paragraph 13.2.3.5 page 53 of OSEK/VDX 2.2.3 spec
 */
FUNC(tpl_status, OS_CODE)
tpl_get_task_id_service(CONSTP2VAR(tpl_task_id, AUTOMATIC, OS_APPL_DATA)
                            task_id);

/**
 * Gives the state of a task
 *
 * @param task_id   identifier of the task
 * @param state     reference of the variable where the state
 *                  of the specified task will be stored
 *
 * @retval  E_OK    no error
 * @retval  E_OS_ID (extended error only) task_id is invalid
 *
 * see paragraph 13.2.3.6 page 53 of OSEK/VDX 2.2.3 spec
 */
FUNC(tpl_status, OS_CODE)
tpl_get_task_state_service(CONST(tpl_task_id, AUTOMATIC) task_id,
                           CONSTP2VAR(tpl_proc_state, AUTOMATIC, OS_APPL_DATA)
                               state);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_TASK_KERNEL_H */

/* End of file tpl_os_task.h */
