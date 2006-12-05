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
 * $Date: 2006-12-03 16:27:57 +0100 (dim., 03 dÃ©c. 2006) $
 * $Rev: 225 $
 * $Author: mik $
 * $URL: https://trampoline.rts-software.org/svn/trunk/os/tpl_os_definitions.h $
 *
 */

#ifndef __TPL_OS_WRAPPERS_H__
#define __TPL_OS_WRAPPERS_H__

#define ActivateTask(taskId) ActivateTask(task_id_of_##taskId##)
#define ChainTask(taskId) ChainTask(task_id_of_##taskId##)
#define GetTaskState(taskId,state) GetTaskState(task_id_of_##taskId##,state)
#define setEvent(taskId,event) setEvent(task_id_of_##taskId##,event)
#define getEvent(taskId,event) getEvent(task_id_of_##taskId##,event)

#endif
