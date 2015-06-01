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

extern CONSTP2VAR(tpl_semaphore, AUTOMATIC, OS_APPL_DATA) tpl_sem_table[SEMAPHORE_COUNT];

FUNC(tpl_status, OS_CODE) tpl_sem_wait_service(CONST(SemType, AUTOMATIC) sem_id);
FUNC(tpl_status, OS_CODE) tpl_sem_post_service(CONST(SemType, AUTOMATIC) sem_id);

#endif
