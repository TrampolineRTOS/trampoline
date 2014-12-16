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
 * $Date: 2010-10-27 15:34:11 +0200 (mer., 27 oct. 2010) $
 * $Rev: 1227 $
 * $Author: pacco $
 * $URL: https://trampoline.rts-software.org/svn/trunk/machines/thumb2/cortex-m3/tpl_machine.h $
 */
#ifndef TPL_MACHINE_H
#define TPL_MACHINE_H

#include "../tpl_machine_arm_generic.h"

/**
 * Gives the ARM processor mode the normal user tasks
 * will run into. The value can be :
 * - 0x10 : unprivileged
 * - 0x1F : privileged
 */
#define USER_TASKS_ARM_MODE 0x1F

/**
 * @def SIZE_OF_IDLE_TASK
 *
 * The size of the stack of the idle task which is also the stack
 * used for machine startup
 */
#define IDLE_STACK_SIZE  300

struct TPL_CONTEXT {
	arm_core_context	*cc;
#ifdef WITH_FLOAT
    arm_float_context	*fc;
#endif
};


//typedef struct TPL_CONTEXT tpl_context;

typedef struct ARM_CORE_CONTEXT *tpl_context;

extern struct ARM_CORE_CONTEXT idle_task_context;

extern unsigned int _estack;

#endif /* TPL_MACHINE_H */

/* End of file tpl_machine.h */
