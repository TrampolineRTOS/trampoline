/**
 * @file tpl_os_wrappers.h
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
 * $Date: 2006-12-03 16:27:57 +0100 (dim., 03 dÃ©c. 2006) $
 * $Rev: 225 $
 * $Author: mik $
 * $URL: https://trampoline.rts-software.org/svn/trunk/os/tpl_os_definitions.h $
 *
 * @section descr File description
 *
 * Macros in this file are wrappers which gives the ability to call a service
 * specifying directly a task name (instead of a TaskType value or variable).
 */

#ifndef __TPL_OS_WRAPPERS_H__
#define __TPL_OS_WRAPPERS_H__

/**
 * @def ActivateTask
 *
 * @see #ActivateTask
 */
#define ActivateTask(taskId) ActivateTask(task_id_of_##taskId##)

/**
 * @def ChainTask
 *
 * @see #ChainTask
 */
#define ChainTask(taskId) ChainTask(task_id_of_##taskId##)

/**
 * @def GetTaskState
 *
 * @see #GetTaskState
 */
#define GetTaskState(taskId,state) GetTaskState(task_id_of_##taskId##,state)

/**
 * @def setEvent
 *
 * @see #SetEvent
 */
#define setEvent(taskId,event) setEvent(task_id_of_##taskId##,event)

/**
 * @def getEvent
 *
 * @see #GetEvent
 */
#define getEvent(taskId,event) getEvent(task_id_of_##taskId##,event)

#endif
