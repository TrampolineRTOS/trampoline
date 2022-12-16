/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline avr specifics
 *
 */

#ifndef __TPL_MACHINE_RENESAS_H__
#define __TPL_MACHINE_RENESAS_H__

#include "tpl_os_std_types.h"


typedef enum
{
  reg_pc = 0,
  reg_lr = 2,
} tpl_register_names;

#define NB_REG_ON_SC_HANDLER_FRAME 21

struct TPL_CONTEXT {
    u32 stackPointer;
};

typedef struct TPL_CONTEXT *tpl_context;

/**
 * tpl_stack_word is the basic element of a stack in order to have a proper
 * data alignement.
 */
typedef u32 tpl_stack_word;

/**
 * tpl_stack_size is the data type used to store the stack size
 */
typedef u32 tpl_stack_size;

struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size   stack_size; 
};

typedef struct TPL_STACK *tpl_stack;

/**
 * @def SIZE_OF_IDLE_TASK
 *
 * The size of the stack of the idle task which is also the stack
 * used for machine startup
 */
#define IDLE_STACK_SIZE 200

#endif