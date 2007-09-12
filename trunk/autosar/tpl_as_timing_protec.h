/**
 * @file tpl_as_timing_protec.h
 *
 * @section desc File description
 *
 * @todo: finish documentation
 * 
 * Explain that the error due to watchdog time resolution
 * can be cumulated over each task preemption. Provide some elements to
 * determine the timing protection limit depending on watchdog time resolution
 * and other parameters (e.g. number of tasks, ...).
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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
 
#ifndef TPL_AS_TIMING_PROTEC_H
#define TPL_AS_TIMING_PROTEC_H

#include "tpl_os_application_def.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"
#include "tpl_machine_interface.h"
#include "tpl_as_protec_hook.h"

/**
 * @todo document this
 */
typedef struct TPL_INTERRUPT_LOCK_MONITOR tpl_interrupt_lock_monitor;

/**
 * @internal
 *
 * Call this function to initialize the timing protection module.
 */
void tpl_init_timing_protection ();

/**
 * @internal
 *
 * function to be called when a task is activated (start the watchdog)
 * 
 * @pre all interrupts should be disabled during this function execution
 * 
 * @todo: improve documentation
 */
void tpl_start_budget_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * function to be called when a task is preempted
 * @todo: improve documentation
 */
void tpl_pause_budget_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * function to be called when a task get back the processor
 * (opposite of preemption)
 * @todo: improve documentation
 */
void tpl_continue_budget_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * function to be called when a task is terminated (cancel the
 * watchdog)
 * @todo: improve documentation
 */
void tpl_disable_budget_monitor (tpl_exec_common *this_exec_obj);

/**
 * @internal
 *
 * @todo: do the documentation
 */
void tpl_reset_activation_count (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * @todo: do the documentation
 */
void tpl_add_activation_count (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * @todo: do the documentation
 */
void tpl_start_exectime_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * @todo: do the documentation
 */
void tpl_finish_exectime_monitor (tpl_exec_common *this_exec_obj);

/**
 * @internal
 *
 * function called when a resource is got
 * @todo: improve documentation
 */
void tpl_start_resource_monitor (tpl_exec_common *this_exec_obj, 
   tpl_resource_id this_resource);
/**
 * @internal
 *
 * function called when a resource is released
 * @todo: improve documentation
 */
void tpl_disable_resource_monitor (tpl_exec_common *this_exec_obj, 
   tpl_resource_id this_resource);

/**
 * @internal
 *
 * function called when all interrupts are locked
 * @todo: improve documentation
 */
void tpl_start_all_isr_lock_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * function called when all interrupts are unlocked
 * @todo: improve documentation
 */
void tpl_disable_all_isr_lock_monitor (tpl_exec_common *this_exec_obj);

/**
 * @internal
 *
 * function called when isr 2 are locked
 * @todo: improve documentation
 */
void tpl_start_os_isr_lock_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * function called when isr 2 are unlocked
 * @todo: improve documentation
 */
void tpl_disable_os_isr_lock_monitor (tpl_exec_common *this_exec_obj);

#endif /* TPL_AS_TIMING_PROTEC_H */

