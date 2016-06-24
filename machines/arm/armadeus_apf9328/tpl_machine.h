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
 * $Date: 2010-01-29 15:35:55 +0100 (Ven, 29 jan 2010) $
 * $Rev: 1043 $
 * $Author: fp $
 * $URL: https://trampoline.rts-software.org/svn/trunk/machines/arm/olimex_lpc_e2294/tpl_machine.h $
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

typedef struct ARM_CONTEXT *tpl_context;

extern struct ARM_CONTEXT idle_task_context;

/* TODO : This function is called after an ISR2 has been terminated. It should
 *        restore the hardware's cpu priority if it has been increased before
 *        the execution of the ISR2 (see ppc/multicore/tpl_machine.h for an
 *        example).
 */
#define tpl_restore_cpu_priority()

#endif /* TPL_MACHINE_H */

/* End of file tpl_machine.h */
