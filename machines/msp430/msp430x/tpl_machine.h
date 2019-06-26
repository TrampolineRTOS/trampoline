/**
 * @file tpl_machine.h
 *
 * @section descr File description
 *
 * Trampoline core exported definitions
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 */
#ifndef TPL_MACHINE_H
#define TPL_MACHINE_H

#include "tpl_os_std_types.h"
#include "tpl_os_custom_types.h"

#include "tpl_machine_msp430x.h"

//typedef uint16 tpl_stack_word;
//typedef uint16 tpl_stack_size;

/**
 * @def SIZE_OF_IDLE_TASK
 *
 * The size of the stack of the idle task
 */
#define IDLE_STACK_SIZE  100

struct TPL_CONTEXT {
  uint16  sp;
};

//typedef struct TPL_CONTEXT tpl_context;

typedef struct MSP430X_CONTEXT *tpl_context;

extern struct MSP430X_CONTEXT idle_task_context;

//extern unsigned long _estack;

/**
 * Stack definition
 */
/*typedef struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size  stack_size;
} tpl_stack;*/

/*
 * Configuration of systick timer (can be a generic timer if systick is not available
 * on the target) for alarms and schedule tables.
 */
FUNC(void, OS_CODE) tpl_set_systick_timer();

/* TODO : This function is called after an ISR2 has been terminated. It should
 *        restore the hardware's cpu priority if it has been increased before
 *        the execution of the ISR2 (see ppc/multicore/tpl_machine.h for an
 *        example).
 */
#define tpl_restore_cpu_priority()

#endif /* TPL_MACHINE_H */

/* End of file tpl_machine.h */
