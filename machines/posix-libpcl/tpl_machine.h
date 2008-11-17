
#ifndef TPL_MACHINE_H
#define TPL_MACHINE_H

#include "tpl_os_custom_types.h"
#include "pcl.h"

typedef coroutine_t *tpl_context;

extern coroutine_t idle_task_context;

#define IDLE_CONTEXT &idle_task_context

/**
 * tpl_stack_word is the basic element of a stack in order to have a proper
 * data alignement.
 */
typedef u32 tpl_stack_word;

/**
 * tpl_stack_size is the data type used to store the stack size
 */
typedef u16 tpl_stack_size;

struct TPL_STACK {
    tpl_stack_word      *stack_zone;
    tpl_stack_size      stack_size; 
};

typedef struct TPL_STACK tpl_stack;

#define IDLE_STACK {NULL,0}

#endif /* TPL_MACHINE_H */
