/**
 * @file tpl_as_timing_protec.h
 *
 * @section desc File description
 *
 * This module includes all what is needed for AUTOSAR timing protection.
 *
 * The timing protection is done with these tools :
 * - budget monitor, which controls the execution time of a task or isr
 * - time frame, which controls time between two activations of a task or isr
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
#include "tpl_os_definitions.h"
#include "tpl_os_internal_types.h"

struct TPL_TP_WATCHDOG
{
  VAR(tpl_bool, TYPEDEF) is_active;  /* flag set when the watchdog is active */
  VAR(tpl_time, TYPEDEF) start_date; /* last start date of this watchdog     */
  VAR(tpl_time, TYPEDEF) remaining;  /* remaining budget of this watchdog    */
};

typedef struct TPL_TP_WATCHDOG tpl_tp_watchdog;

/**
 * @def NB_WATCHDOGS_PER_PROC
 *
 * Number of watchdogs per proc: 4
 * 0 is EXECUTIONBUDGET
 * 1 is RESOURCELOCK
 * 2 is ALLINTERRUPTLOCK
 * 3 is OSINTERRUPTLOCK
 */
#define NB_WATCHDOGS_PER_PROC 4

/**
 * @def EXECUTIONBUDGET
 *
 * Id of the EXECUTIONBUDGET watchdog
 */
#define EXECUTIONBUDGET 0

/**
 * @def RESOURCELOCK
 *
 * Id of the RESOURCELOCK watchdog
 */

#define RESOURCELOCK 1

/**
 * @def ALLINTERRUPTLOCK
 *
 * Id of the ALLINTERRUPTLOCK watchdog
 */
#define ALLINTERRUPTLOCK 2

/**
 * @def OSINTERRUPTLOCK
 *
 * Id of the OSINTERRUPTLOCK watchdog
 */
#define OSINTERRUPTLOCK 3

/**
 * @internal
 *
 * @struct TPL_TIMING_PROTECTION
 *
 * This structure gathers all informations about timing protection
 * of an executable object (task or isr). See AUTOSAR OS SWS §7.6.2
 * about timing protection.
 *
 * @see #tpl_timing_protection
 * @see #tpl_exec_static
 */

struct TPL_TIMING_PROTECTION
{
  VAR(tpl_time, TYPEDEF)
  last_activation; /* date of the last successfull activation */
  VAR(tpl_bool, TYPEDEF)
  first_instance; /* initialized to TRUE to change
                     the behavior of the timeframe watchdog
                     for the first instance of a task */
  VAR(tpl_tp_watchdog, TYPEDEF) watchdogs[NB_WATCHDOGS_PER_PROC];
  /* set of watchdogs of this task */
};

typedef struct TPL_TIMING_PROTECTION tpl_timing_protection;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * This function is called when a watchdog is expired
 */
extern FUNC(tpl_bool, OS_CODE) tpl_watchdog_expiration(void);

/**
 * Function used to initialize the activity flags of the watchdog
 * of the timing protection service. Must be called when an instance is
 * terminated.
 *
 * @param this_exec_obj: id of the concerned proc
 */
extern FUNC(tpl_bool, OS_CODE)
    tpl_tp_reset_watchdogs(CONST(tpl_proc_id, AUTOMATIC) proc_id);
/**
 * Function used to start the measure of a time frame for a task/isr2
 *
 * @param this_exec_obj: object owner of the time frame to start
 *
 */
extern FUNC(tpl_bool, OS_CODE)
    tpl_tp_on_activate_or_release(CONST(tpl_proc_id, AUTOMATIC) proc_id);

/**
 * Function used to stop the measure of a time frame for a task/isr2
 *
 * @param this_exec_obj: object owner of the time frame to stop
 *
 */
extern FUNC(tpl_bool, OS_CODE)
    tpl_tp_on_terminate_or_wait(CONST(tpl_proc_id, AUTOMATIC) proc_id);

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
extern FUNC(tpl_bool, OS_CODE)
    tpl_tp_on_start(CONST(tpl_proc_id, AUTOMATIC) proc_id);

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
extern FUNC(tpl_bool, OS_CODE)
    tpl_tp_on_preempt(CONST(tpl_proc_id, AUTOMATIC) proc_id);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_AS_TIMING_PROTEC_H */
