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

#ifndef __TPL_MACHINE_AVR_H__
#define __TPL_MACHINE_AVR_H__

#include "tpl_os_custom_types.h"

typedef u16 avr_context; //The context... is only Stack Pointer (SP)
typedef avr_context *tpl_context;

/**
 * tpl_stack_word is the basic element of a stack in order to have a proper
 * data alignement.
 */
typedef u16 tpl_stack_word;

/**
 * tpl_stack_size is the data type used to store the stack size
 */
typedef u16 tpl_stack_size;


struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size   stack_size; 
};
typedef struct TPL_STACK tpl_stack;


/**
 * @def SIZE_OF_IDLE_TASK
 *
 * The size of the stack of the idle task which is also the stack
 * used for machine startup
 */
#define IDLE_STACK_SIZE  80

/* TODO : This function is called after an ISR2 has been terminated. It should
 *        restore the hardware's cpu priority if it has been increased before
 *        the execution of the ISR2 (see ppc/multicore/tpl_machine.h for an
 *        example).
 */
#define tpl_restore_cpu_priority()

#endif
