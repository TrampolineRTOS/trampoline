/**
 * @file tpl_os_semaphore_kernel.c
 *
 * @section desc File description
 *
 * Trampoline semaphore implementation
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

#include "tpl_os_semaphore_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_machine_interface.h"

FUNC(void, OS_CODE) tpl_sem_enqueue(
  P2VAR(tpl_semaphore, AUTOMATIC, OS_APPL_DATA) sem,
  CONST(tpl_task_id, AUTOMATIC)                 task_id)
{
  sem->size++;
  sem->waiting_tasks[sem->index] = task_id;
  sem->index++;
  if (sem->index == TASK_COUNT)
  {
    sem->index = 0;
  }
}

FUNC(tpl_task_id, OS_CODE) tpl_sem_dequeue(
  P2VAR(tpl_semaphore, AUTOMATIC, OS_APPL_DATA) sem)
{
  VAR(uint32, AUTOMATIC) read_index = sem->index - sem->size;
  VAR(tpl_task_id, AUTOMATIC) task_id;

  if (sem->index < sem->size)
  {
    read_index += TASK_COUNT;
  }
  task_id = sem->waiting_tasks[read_index];
  sem->size--;

  /* release the task */
  tpl_release(task_id);

  return task_id;
}

#if WITH_DOW == YES
#include <stdio.h>
#include "tpl_app_config.h"
FUNC(void, OS_CODE) tpl_sem_print(CONST(SemType, AUTOMATIC) sem_id)
{
  CONSTP2VAR(tpl_semaphore, AUTOMATIC, OS_CONST) sem = tpl_sem_table[sem_id];
  VAR(uint32, AUTOMATIC) index = sem->index - sem->size;
  VAR(uint32, AUTOMATIC) count = sem->size;

  printf("(%lu)", sem->token);
  if (sem->index < sem->size)
  {
    index += TASK_COUNT;
  }

  if (sem->size > 0)
  {
    printf("[%lu]", sem->size);
    while (count > 0)
    {
      printf(" %s", proc_name_table[sem->waiting_tasks[index]]);
      index++;
      if (index == TASK_COUNT) index = 0;
      count--;
    }
  }
  else
  {
    printf("[empty]");
  }
  printf("\n");
}
#endif

FUNC(tpl_status, OS_CODE) tpl_sem_wait_service(CONST(SemType, AUTOMATIC) sem_id)
{
  GET_CURRENT_CORE_ID(core_id)
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  VAR(tpl_task_id, AUTOMATIC) task_id;
  P2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)  s_task;
  CONSTP2VAR(tpl_semaphore, AUTOMATIC, OS_CONST) sem = tpl_sem_table[sem_id];

  LOCK_KERNEL()

  task_id = TPL_KERN_REF(kern).running_id;
  s_task = tpl_stat_proc_table[task_id];
  if (s_task->max_activate_count == 1)
  {
    if (sem->token == 0)
    {
      tpl_sem_enqueue(sem, task_id);
      /* block the running task */
      tpl_block();
    }
    else
    {
      sem->token--;
    }
  }
  else
  {
    result = E_OS_ACCESS;
  }

  UNLOCK_KERNEL()

  return result;
}

FUNC(tpl_status, OS_CODE) tpl_sem_post_service(CONST(SemType, AUTOMATIC) sem_id)
{
  GET_CURRENT_CORE_ID(core_id)
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(tpl_task_id, AUTOMATIC) task_id;
  CONSTP2VAR(tpl_semaphore, AUTOMATIC, OS_CONST) sem = tpl_sem_table[sem_id];

  LOCK_KERNEL()

  if (sem->size > 0)
  {
    task_id = tpl_sem_dequeue(sem);
    /* release the task */
    tpl_release(task_id);
    if (TPL_KERN_REF(kern).need_schedule)
    {
      tpl_schedule_from_running(CORE_ID_OR_NOTHING(core_id));
      SWITCH_CONTEXT(CORE_ID_OR_NOTHING(core_id))
    }
  }
  else
  {
    sem->token++;
  }

  UNLOCK_KERNEL()

  return E_OK;
}



