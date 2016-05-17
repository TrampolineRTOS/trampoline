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
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
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
