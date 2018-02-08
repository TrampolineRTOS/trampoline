/**
 * @file tpl_os_semaphore.h
 *
 * @section desc File description
 *
 * Trampoline semaphore header
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
 * $Date:$
 * $Rev:$
 * $Author:$
 * $URL:$
 */

#ifndef TPL_OS_SEMAPHORE_KERNEL_H
#define TPL_OS_SEMAPHORE_KERNEL_H

#include "tpl_os_types.h"
#include "tpl_os_semaphore.h"

typedef struct {
  uint32      token;
  uint32      size;
  uint32      index;
  tpl_task_id waiting_tasks[TASK_COUNT];
} tpl_semaphore;

extern CONSTP2VAR(tpl_semaphore, AUTOMATIC, OS_APPL_DATA) tpl_sem_table[];

FUNC(tpl_status, OS_CODE) tpl_sem_wait_service(CONST(SemType, AUTOMATIC) sem_id);
FUNC(tpl_status, OS_CODE) tpl_sem_post_service(CONST(SemType, AUTOMATIC) sem_id);

#endif
