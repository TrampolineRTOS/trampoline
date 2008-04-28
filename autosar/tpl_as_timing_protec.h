/**
 * @file tpl_as_timing_protec.h
 *
 * @section desc File description
 *
 * This module includes all what is needed for AUTOSAR timing protection.
 *
 * The timing protection is done with these tools :
 * - budget monitor, which controls for task execution time withing a
 *   timeframe
 * - execution time monitor, which controls execution time since last
 *   activation of an ISR2
 * - activation count monitor, which limit activation count in one timeframe
 *   for an ISR2
 * - all interrupt lock monitor, which controls the maximum lock time of
 *   all interrupts by a task or ISR2
 * - OS interrupt lock monitor, which controls the maximum lock time of
 *   ISR2 interrupts by a task or ISR2
 * - resource lock time, which controls the maximum time a resource is
 *   handled by a task or ISR2
 *
 * Of course, timing protection takes time itself. Refer to the machine
 * specific documentation to have an idea of the time resolution for
 * which the timing protection can be accurate.
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

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * Call this function to initialize the timing protection module.
 * This is a prerequisite to all other functions in this module.
 */
extern FUNC(void, OS_CODE) tpl_init_timing_protection(void);

/**
 * @internal
 *
 * Function to be called when a task is activated. This starts the budget
 * monitoring.
 *
 * @pre all interrupts should be disabled during this function execution
 *
 * @param this_exec_obj the task to monitor
 *
 * @see #tpl_pause_budget_monitor
 * @see #tpl_continue_budget_monitor
 */
extern FUNC(void, OS_CODE) tpl_start_budget_monitor (
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

/**
 * @internal
 *
 * Function to be called when a task is preempted. This pauses the budget
 * monitor until #tpl_continue_budget_monitor is called
 *
 * @pre all interrupts should be disabled during this function execution
 *
 * @param this_exec_obj the task to monitor
 *
 * @see #tpl_start_budget_monitor
 * @see #tpl_continue_budget_monitor
 */
extern FUNC(void, OS_CODE) tpl_pause_budget_monitor(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

/**
 * @internal
 *
 * Function to be called when a task is given back the processor (opposite
 * of preemption)
 *
 * @pre all interrupts should be disabled during this function execution
 *
 * @param this_exec_obj the task to monitor
 *
 * @see #tpl_start_budget_monitor
 * @see #tpl_pause_budget_monitor
 */
extern FUNC(void, OS_CODE) tpl_continue_budget_monitor(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

/**
 * @internal
 *
 * Function to zero activation count of an ISR at a new timeframe start.
 * If necessary, re-enable the disabled ISR.
 *
 * @pre all interrupts should be disabled during this function execution
 *
 * @param this_exec_obj the ISR to monitor
 */
extern FUNC(void, OS_CODE) tpl_reset_activation_count(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

/**
 * @internal
 *
 * Function to increment the activation count for an ISR. If the ISR
 * activation count is reached for the current timeframe, the ISR
 * is disabled.
 *
 * @pre all interrupts should be disabled during this function execution
 *
 * @param this_exec_obj the ISR to monitor
 */
extern FUNC(void, OS_CODE) tpl_add_activation_count(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

/**
 * @internal
 *
 * Function to start the execution time monitor for an ISR.
 *
 * If the ISR exceeds it execution time, the #ProtectionHook is called
 *
 * @pre all interrupts should be disabled during this function execution
 *
 * @param this_exec_obj the ISR to monitor
 */
extern FUNC(void, OS_CODE) tpl_start_exectime_monitor(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

/**
 * @internal
 *
 * Function to stop the execution time monitor for an ISR. It indicates
 * that the ISR finished its execution in time.
 *
 * @pre all interrupts should be disabled during this function execution
 *
 * @param this_exec_obj the ISR to monitor
 */
extern FUNC(void, OS_CODE) tpl_finish_exectime_monitor(
    P2CONST(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

/**
 * @internal
 *
 * function called when a resource is got.
 *
 * @param this_exec_obj the executable object that get the resource
 * @param this_resource the resource got
 *
 * @pre all interrupts should be disabled during this function execution
 */
extern FUNC(void, OS_CODE) tpl_start_resource_monitor(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj,
    VAR(tpl_resource_id, AUTOMATIC) this_resource);

/**
 * @internal
 *
 * function called when a resource is released.
 *
 * @param this_exec_obj the executable object that released the resource
 * @param this_resource the resource released
 *
 * @pre all interrupts should be disabled during this function execution
 */
extern FUNC(void, OS_CODE) tpl_disable_resource_monitor(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj,
    VAR(tpl_resource_id, AUTOMATIC) this_resource);

/**
 * @internal
 *
 * function called when all interrupts are locked by a task or ISR
 *
 * @param this_exec_obj the executable object which locked interrupts
 */
extern FUNC(void, OS_CODE) tpl_start_all_isr_lock_monitor(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);
/**
 * @internal
 *
 * function called when all interrupts are unlocked by a task or ISR
 *
 * @param this_exec_obj the executable object which unlocked interrupts
 */
extern FUNC(void, OS_CODE) tpl_disable_all_isr_lock_monitor(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

/**
 * @internal
 *
 * function called when ISR are locked by a task or ISR
 *
 * @param this_exec_obj the executable object which locked ISRs
 */
extern FUNC(void, OS_CODE) tpl_start_os_isr_lock_monitor(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

/**
 * @internal
 *
 * function called when ISRs are unlocked by a task or ISR
 *
 * @param this_exec_obj the executable object which locked ISRs
 */
extern FUNC(void, OS_CODE) tpl_disable_os_isr_lock_monitor(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_AS_TIMING_PROTEC_H */

