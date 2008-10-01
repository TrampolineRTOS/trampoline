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

#include "tpl_os_internal_types.h"
#include "tpl_os_application_def.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_definitions.h"

/**
 * @internal
 *
 * This is the watchdog type.
 *
 * @see #tpl_watchdog
 */
typedef enum
{
  EXEC_BUDGET,      /**< watchdog for an execution budget   */
  TIME_FRAME,       /**< watchdog for a count limit         */
  ALL_INT_LOCK,     /**< watchdog for all interrupts lock   */
  OS_INT_LOCK,      /**< watchdog for ISR2 lock             */
  REZ_LOCK          /**< watchdog for a resource lock (see resource field
                         in #tpl_watchdog to know which resource is implied */
} tpl_watchdog_type;

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
    VAR(tpl_time, TYPEDEF)                  execution_budget;   /**< maximum duration the task
                                                                     can be active within a
                                                                     timeframe or maximum isr
                                                                     execution time since last
                                                                     activation */
    VAR(tpl_time, TYPEDEF)                  timeframe;          /**< configured timeframe for this
                                                                     timing protection */
    P2VAR(tpl_time, TYPEDEF, OS_APPL_DATA)  resource_lock_time; /**< array where timing protection
                                                                     is specified (or not) for
                                                                     each resource (zero if no
                                                                     timing protection) */
    VAR(tpl_time, TYPEDEF)                  os_interrupt_lock_time;
    VAR(tpl_time, TYPEDEF)                  all_interrupt_lock_time;
};

/**
 * @internal
 *
 * this is an alias for the type #TPL_TIMING_PROTECTION
 *
 * @see #TPL_TIMING_PROTECTION
 */
typedef struct TPL_TIMING_PROTECTION tpl_timing_protection;

/* Forward declaration  */
struct TPL_EXEC_COMMON;

/**
 * @internal
 *
 * This describes a watchdog associated informations. Attributes
 * here describe what to do when the watchdog raises.
 */
struct TPL_WATCHDOG
{
  struct P2VAR( TPL_EXEC_COMMON, TYPEDEF, OS_APPL_DATA) exec_obj;             /**< the executable object implied  */
  struct P2VAR(TPL_WATCHDOG, AUTOMATIC, OS_VAR_NOINIT)  next;                 /**< the next watchdog
                                                                                   in the list                    */
  struct P2VAR(TPL_WATCHDOG, AUTOMATIC, OS_VAR_NOINIT)  previous;             /**< the previous watchdog
                                                                                   in the list                    */
  VAR(tpl_time, TYPEDEF)                                scheduled_date;       /**< absolute scheduled
                                                                                   date in tpl_time
                                                                                   unit (useful to
                                                                                   compute relative
                                                                                   delays)                        */
  VAR(tpl_time, TYPEDEF)                                start_date;           /**< absolute scheduled
                                                                                   date in tpl_time
                                                                                   unit (useful to
                                                                                   compute relative
                                                                                   delays)                        */
  VAR(tpl_time, TYPEDEF)                                time_left;            /**< remaining time of execution
                                                                                   for the conecerned object      */
  VAR(tpl_watchdog_type, TYPEDEF)                       type;                 /**< the watchdog type              */
  VAR(tpl_resource_id, TYPEDEF)                         resource;             /**< the resource implied if any    */
};

/**
 * @internal
 *
 * this is an alias for #TPL_WATCHDOG structure
 *
 * @see #TPL_WATCHDOG
 */
typedef struct TPL_WATCHDOG tpl_watchdog;


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * This function is called when a watchdog is expired
 */
extern FUNC(void, OS_CODE) tpl_watchdog_expiration(void);

/**
 * @internal
 *
 * Call this function to initialize the timing protection module.
 * This is a prerequisite to all other functions in this module.
 */
extern FUNC(void, OS_CODE) tpl_init_timing_protection(void);

/**
 * Function used to start the measure of a time frame for a task/isr2
 *
 * @param this_exec_obj: object owner of the time frame to start
 *
 */
extern FUNC(void, OS_CODE) tpl_start_timeframe (
    struct P2VAR(TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA) this_exec_obj);

/**
 * Function used to stop the measure of a time frame for a task/isr2
 *
 * @param this_exec_obj: object owner of the time frame to stop
 *
 */
extern FUNC(void, OS_CODE) tpl_stop_timeframe (
    P2CONST(struct TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA) this_exec_obj);

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
    struct P2VAR(TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA) this_exec_obj);

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
    P2CONST(struct TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA) this_exec_obj);

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
    struct P2VAR(TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA) this_exec_obj);

/**
 * @internal
 *
 */
extern FUNC(void, OS_CODE) tpl_stop_budget_monitor(
    P2CONST(struct TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA) this_exec_obj);

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
    struct P2VAR(TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA)  this_exec_obj,
    VAR(tpl_resource_id, AUTOMATIC)                         this_resource);

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
extern FUNC(void, OS_CODE) tpl_stop_resource_monitor(
    P2CONST(struct TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA)    this_exec_obj,
    VAR(tpl_resource_id, AUTOMATIC)                             this_resource);

/**
 * @internal
 *
 * function called when all interrupts are locked by a task or ISR
 *
 * @param this_exec_obj the executable object which locked interrupts
 */
extern FUNC(void, OS_CODE) tpl_start_all_isr_lock_monitor(
    struct P2VAR(TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA) this_exec_obj);
/**
 * @internal
 *
 * function called when all interrupts are unlocked by a task or ISR
 *
 * @param this_exec_obj the executable object which unlocked interrupts
 */
extern FUNC(void, OS_CODE) tpl_stop_all_isr_lock_monitor(
    P2CONST(struct TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA) this_exec_obj);

/**
 * @internal
 *
 * function called when ISR are locked by a task or ISR
 *
 * @param this_exec_obj the executable object which locked ISRs
 */
extern FUNC(void, OS_CODE) tpl_start_os_isr_lock_monitor(
    P2VAR(struct TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA) this_exec_obj);

/**
 * @internal
 *
 * function called when ISRs are unlocked by a task or ISR
 *
 * @param this_exec_obj the executable object which locked ISRs
 */
extern FUNC(void, OS_CODE) tpl_stop_os_isr_lock_monitor(
    P2CONST(struct TPL_EXEC_COMMON, AUTOMATIC, OS_APPL_DATA) this_exec_obj);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_AS_TIMING_PROTEC_H */

