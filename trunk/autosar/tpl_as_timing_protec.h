/**
 * @file tpl_as_timing_protec.h
 *
 * @section desc File description
 *
 * TODO: finish documentation
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
 * @define MAXIMUM_SCHEDULED_WATCHDOGS
 * TODO: document this
 *
 * OIL should provide this value, based on
 * the needed watchdogs. In the worst case,
 * you can schedule this number of watchdogs :
 * number of resources + 4 * number of tasks
 */
/* #define MAXIMUM_SCHEDULED_WATCHDOGS 20 */

/**
 * TODO
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
 * TODO: improve documentation
 */
void tpl_start_budget_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * function to be called when a task is preempted
 * TODO: improve documentation
 */
void tpl_pause_budget_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * function to be called when a task get back the processor
 * (opposite of preemption)
 * TODO: improve documentation
 */
void tpl_continue_budget_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * function to be called when a task is terminated (cancel the
 * watchdog)
 * TODO: improve documentation
 */
void tpl_disable_budget_monitor (tpl_exec_common *this_exec_obj);

/**
 * @internal
 *
 * function called when a resource is got
 * TODO: improve documentation
 */
void tpl_start_resource_monitor (tpl_exec_common *this_exec_obj, 
   tpl_resource_id this_resource);
/**
 * @internal
 *
 * function called when a resource is released
 * TODO: improve documentation
 */
void tpl_disable_resource_monitor (tpl_exec_common *this_exec_obj, 
   tpl_resource_id this_resource);

/**
 * @internal
 *
 * function called when all interrupts are locked
 * TODO: improve documentation
 */
void tpl_start_all_isr_lock_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * function called when all interrupts are unlocked
 * TODO: improve documentation
 */
void tpl_disable_all_isr_lock_monitor (tpl_exec_common *this_exec_obj);

/**
 * @internal
 *
 * function called when isr 2 are locked
 * TODO: improve documentation
 */
void tpl_start_os_isr_lock_monitor (tpl_exec_common *this_exec_obj);
/**
 * @internal
 *
 * function called when isr 2 are unlocked
 * TODO: improve documentation
 */
void tpl_disable_os_isr_lock_monitor (tpl_exec_common *this_exec_obj);

#endif /* TPL_AS_TIMING_PROTEC_H */

