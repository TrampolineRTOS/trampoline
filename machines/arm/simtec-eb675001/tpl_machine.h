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
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
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

#endif /* TPL_MACHINE_H */
