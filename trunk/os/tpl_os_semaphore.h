#ifndef TPL_OS_SEMAPHORE_H
#define TPL_OS_SEMAPHORE_H

#include "tpl_os_std_types.h"

typedef uint8 SemType;

#define DeclareSemaphore(sem_id) extern CONST(SemType, AUTOMATIC) sem_id;

#endif
