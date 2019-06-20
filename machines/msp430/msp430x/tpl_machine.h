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

#include "tpl_machine_msp430x.h"

#define USER_TASKS_OPERATION_MODE 0x0000

#define IDLE_STACK_SIZE 300

struct TPL_CONTEXT {
  msp430x_context *cc;
};

typedef struct MSP430X_CONTEXT *tpl_context;

extern struct MSP430X_CONTEXT idle_task_context;

extern unsigned long _estack;

FUNC(void, OS_CODE) tpl_set_systick_timer();

#define tpl_restore_cpu_priority();

#endif /* TPL_MACHINE_H */

/* End of file tpl_machine.h */
