/**
 * @file tpl_os_task.h
 *
 * @section desc File description
 *
 * Trampoline task management public header file
 * See paragraph 13.2,
 * pages 49+ of OSEK/VDX 2.2.3 spec
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

#ifndef TPL_OS_TASK_H
#define TPL_OS_TASK_H

#include "tpl_os_types.h"

/*
 * Task Management
 * constructional elements
 * see paragraph 13.2.2,
 * pages 50+ of OSEK/VDX 2.2.3 spec
 */

/**
 * @def DeclareTask
 *
 * This is used to define a task
 *
 * @param task_id the task identifier (provide a C identifier here)
 *
 * see paragraph 13.2.2.1 page 50 of OSEK/VDX 2.2.3 spec
 */
#define DeclareTask(task_id)


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Task Management
 * System services
 * see paragraph 13.2.3,
 * pages 50+ of OSEK/VDX 2.2.3 spec
 */

/**
 * (re)activates a task.
 *
 * @param TaskID identifier of the task to be activated
 *
 * @retval E_OK no error
 * @retval E_OS_LIMIT too many task activations
 * @retval E_OS_ID (extended error only) TaskID is invalid
 *
 * see paragraph 13.2.3.1 page 50 of OSEK/VDX 2.2.3 spec
 */
FUNC(StatusType, OS_CODE) ActivateTask(
    CONST(TaskType, AUTOMATIC) task_id);


/**
 * Terminates the execution of a task.
 *
 * @note this function never returns unless extended error mode is
 * active and an error occurred
 *
 * @retval E_OS_RESOURCE (extended error only) task still occupies resources
 * @retval E_OS_CALLEVEL (extended error only) call at interrupt level
 *
 * see paragraph 13.2.3.2 page 51 of OSEK/VDX 2.2.3 spec
 */
FUNC(StatusType, OS_CODE) TerminateTask(void);


/**
 * Chain terminaison of current task with activation of another.
 *
 * @param TaskID identifier of the task to activate
 *
 * @note if this function succeeds, it does not returns (as the current
 * task is then finished)
 *
 * @retval E_OS_LIMIT too many task activations
 * @retval E_OS_ID (extended error only) TaskID is invalid
 *
 * see paragraph 13.2.3.3 page 51 of OSEK/VDX 2.2.3 spec
 */
FUNC(StatusType, OS_CODE) ChainTask(
    CONST(TaskType, AUTOMATIC) task_id);


/**
 * Call to the scheduler.
 *
 * @retval E_OK          no error
 * @retval E_OS_CALLEVEL (extended error only) call at interrupt level
 * @retval E_OS_RESOURCE (extended error only) task still occupies resource
 *
 * see paragraph 13.2.3.4 page 52 of OSEK/VDX 2.2.3 spec
 */
FUNC(StatusType, OS_CODE) Schedule(void);


/**
 * Gives the identifier of the running task
 *
 * @param TaskID reference of the variable where
 *               the identifier will be returned
 *
 * @retval E_OK  no error
 *
 * see paragraph 13.2.3.5 page 53 of OSEK/VDX 2.2.3 spec
 */
FUNC(StatusType, OS_CODE) GetTaskID(
    VAR(TaskRefType, AUTOMATIC) task_id);


/**
 * Gives the state of a task
 *
 * @param TaskID identifier of the task
 * @param State  reference of the variable where the state
 *               of the specified task will be stored
 *
 * @retval E_OK    no error
 * @retval E_OS_ID (extended error only) TaskID is invalid
 *
 * see paragraph 13.2.3.6 page 53 of OSEK/VDX 2.2.3 spec
 */
FUNC(StatusType, OS_CODE) GetTaskState(
    CONST(TaskType, AUTOMATIC)        task_id,
    VAR(TaskStateRefType, AUTOMATIC)  state);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_TASK_H */

/* End of file tpl_os_task.h */
