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
#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"

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
#define DeclareTask(task_id) extern CONST(TaskType, AUTOMATIC) task_id

#endif /* TPL_OS_TASK_H */

/* End of file tpl_os_task.h */
