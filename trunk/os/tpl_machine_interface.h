/**
 * @file tpl_machine_interface.h
 *
 * @section descr File description
 *
 * Trampoline machine dependant functions interface
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
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

#ifndef TPL_MACHINE_INTERFACE_H
#define TPL_MACHINE_INTERFACE_H

#include "tpl_os_internal_types.h"

#define OS_START_SEC_CODE
#include "Memmap.h"

/**
 * @internal
 *
 * tpl_switch_context switches the context in a cooperative way
 *
 * @param old_context   Pointer to the context of the task that will be
 *                      descheduled.
 * @param new_context   Pointer to the context of the task that will be
 *                      scheduled.
 */
extern void tpl_switch_context(
    tpl_context *old_context,
    tpl_context *new_context
);

   
/**
 * @internal
 *
 * tpl_switch_context_from_it switches the context under interrupt,
 * ie in a preemptive way.
 *
 * @param old_context   Pointer to the context of the task that will be
 *                      descheduled.
 * @param new_context   Pointer to the context of the task that will be
 *                      scheduled.
 */
extern void tpl_switch_context_from_it(
    tpl_context *old_context,
    tpl_context *new_context
);

    
/**
 * @internal
 *
 * tpl_init_context initialized the context of a task that is being activated
 *
 * @param exec_obj      Pointer to the task descriptor
 */
extern void tpl_init_context(tpl_exec_common *exec_obj);


/**
 * @internal
 *
 * tpl_get_task_lock locks the kernel
 */
extern void tpl_get_task_lock(void);


/**
 * @internal
 *
 * tpl_release_task_lock unlocks the kernel
 */
extern void tpl_release_task_lock(void);


/**
 * @internal
 *
 * tpl_init_machine performs machine (hardware of virtual machine)
 * dependant initializations
 */
extern void tpl_init_machine(void);


/**
 * @internal
 *
 * tpl_sleep is called by the idle task. It should put the system in sleep
 * mode of go in an infinite loop if there is no sleep mode available.
 */
extern void tpl_sleep(void);


/**
 * @internal
 *
 * tpl_shutdown shutdown trampoline. It is called by ShutdownOS and should
 * perform hardware or virtual machine shutdown.
 */
extern void tpl_shutdown(void);

#define OS_STOP_SEC_CODE
#include "Memmap.h"

#endif /* TPL_MACHINE_INTERFACE_H */
