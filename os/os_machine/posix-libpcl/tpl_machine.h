
#ifndef TPL_MACHINE_H
#define TPL_MACHINE_H

#include "tpl_os_custom_types.h"
#include "pcl.h"

typedef coroutine_t tpl_context;
/*typedef void* tpl_context;*/
extern tpl_context idle_task_context;

#define IDLE_CONTEXT &idle_task_context



struct TPL_STACK {
    tpl_stack_word      *stack_zone;
    tpl_stack_size      stack_size; 
};

typedef struct TPL_STACK tpl_stack;

#define IDLE_STACK {NULL,0}


#endif /* TPL_MACHINE_H */
