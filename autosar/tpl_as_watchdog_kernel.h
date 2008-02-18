/**
 * @file tpl_as_watchdog_kernel.h
 *
 * @section desc File description
 *
 * This module gives a way to use multiple virtual watchdogs while
 * underlying hardware only provides one (see #tpl_set_watchdog and
 * #tpl_cancel_watchdog).
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
#ifndef TPL_AS_WATCHDOG_KERNEL_H
#define TPL_AS_WATCHDOG_KERNEL_H

#include "tpl_os_application_def.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_definitions.h"
#include "tpl_os_internal_types.h"
#include "tpl_machine_interface.h"

#if defined WITH_AUTOSAR_TIMING_PROTECTION

/**
 * @internal
 *
 * This is the watchdog type.
 *
 * @see #tpl_watchdog
 */
typedef enum
{
  EXEC_BUDGET,         /**< watchdog for an execution budget */
  TIME_LIMIT,          /**< watchdog for a count limit */
  ALL_INT_LOCK,        /**< watchdog for all interrupts lock */
  OS_INT_LOCK,         /**< watchdog for ISR2 lock */
  REZ_LOCK,            /**< watchdog for a resource lock (see resource
                            field in #tpl_watchdog to know which
                            resource is implied */
  TIMEFRAME_BOUNDARY   /**< watchdog for a timeframe boundary */
} tpl_watchdog_type;

/**
 * @internal
 *
 * This describes a watchdog associated informations. Attributes
 * here describe what to do when the watchdog raises.
 */
struct TPL_WATCHDOG
{
  P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) exec_obj; /**< the executable object implied */
  VAR(tpl_watchdog_type, AUTOMATIC)               type;     /**< the watchdog type */
  VAR(tpl_resource_id, AUTOMATIC)                 resource; /**< the resource implied if any */
};

/**
 * @internal
 *
 * this is an alias for #TPL_WATCHDOG structure
 *
 * @see #TPL_WATCHDOG
 */
typedef struct TPL_WATCHDOG tpl_watchdog;

/**
 * @internal
 *
 * This structure wraps a watchdog into the scheduled watchdog list.
 *
 * It essentially adds informations about when the watchdog should raise.
 */
struct TPL_SCHEDULED_WATCHDOG
{
  VAR(tpl_watchdog, AUTOMATIC)                                  watchdog;             /**< the watchdog */
  struct P2VAR(TPL_SCHEDULED_WATCHDOG, OS_VAR_NOINIT, AUTOMATIC) next;                 /**< the next watchdog
                                                                                           in the list */
  VAR(tpl_time, AUTOMATIC)                                      delay_from_previous;  /**< delay (in tpl_time
                                                                                           unit after
                                                                                           previous scheduled
                                                                                           watchdog */
  VAR(tpl_time, AUTOMATIC)                                      scheduled_date;       /**< absolute scheduled
                                                                                           date in tpl_time
                                                                                           unit (useful to
                                                                                           compute relative
                                                                                           delays) */
  VAR(u8, AUTOMATIC)                                            allocated;            /**< indicates that
                                                                                           this scheduled
                                                                                           watchdog is free
                                                                                           (or not) for
                                                                                           allocation */
};

/**
 * @internal
 *
 * This is an alias for the #TPL_SCHEDULED_WATCHDOG structure
 *
 * @see #TPL_SCHEDULED_WATCHDOG
 */
typedef struct TPL_SCHEDULED_WATCHDOG tpl_scheduled_watchdog;

/**
 * @internal
 *
 * This is the format for the watchdog callback function.
 *
 * This function must not call #schedule_watchdog nor #unschedule_watchdog.
 * Prefer any other function in this module.
 *
 * @param watchdog the watchdog which raised (do not change any
 * field into it)
 *
 * @retval TRUE indicates that a rescheduling is needed
 * @retval FALSE indicates that a rescheduling is no required
 *
 * @see #insert_scheduled_watchdog
 * @see #find_scheduled_watchdog
 * @see #remove_scheduled_watchdog
 */
typedef P2FUNC(u8, OS_APPL_CODE, watchdog_callback_function)(
  P2VAR(tpl_watchdog, OS_VAR_NOINIT, AUTOMATIC) watchdog);

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * This function must be called before any other in this module.
 */
FUNC(void, OS_CODE) init_watchdog_kernel(
  VAR(watchdog_callback_function, AUTOMATIC) callback);

/**
 * @internal
 *
 * Allocate a new watchdog
 *
 * @return the new watchdog allocated
 */
FUNC(P2VAR(tpl_scheduled_watchdog, OS_VAR_NOINIT, AUTOMATIC), OS_CODE) new_scheduled_watchdog(void);
/**
 * @internal
 *
 * Insert a scheduled watchdog in the list but don't really schedule it
 * if needed.
 *
 * @note this function is intended to be called by the watchdog callback
 * (or internally in this module)
 *
 * @retval FALSE the head of the list did not changed
 * @retval TRUE the head of the list has changed (need to reschedule the
 * real underlying watchdog)
 */
FUNC(u8, OS_CODE) insert_scheduled_watchdog(
  P2VAR(tpl_scheduled_watchdog, OS_VAR_NOINIT, AUTOMATIC) this_scheduled_watchdog);

/**
 * @internal
 *
 * finds a similar watchdog in the list
 *
 * @note this function is intended to be called by the watchdog callback
 * (or internally in this module)
 *
 * @param like_this_watchdog find a scheduled watchdog with the same
 * attributes values
 * @param watchdog_cursor address of a pointer on the found watchdog
 * @param previous_cursor address of a pointer on the watchdog that
 * preceeds the found watchdog
 *
 * @retval FALSE no similar watchdog found
 * @retval TRUE a similar watchdog was found (see output parameters)
 */
FUNC(u8, OS_CODE) find_scheduled_watchdog(
  P2VAR(tpl_watchdog, OS_APPL_DATA, AUTOMATIC) like_this_watchdog,
  P2VAR(tpl_scheduled_watchdog, OS_VAR_NOINIT, AUTOMATIC) *watchdog_cursor,
  P2VAR(tpl_scheduled_watchdog, OS_VAR_NOINIT, AUTOMATIC) *previous_cursor);

/**
 * @internal
 *
 * removes the specified scheduled watchdog from the list
 *
 * @note this function is intended to be called by the watchdog callback
 * (or internally in this module)
 *
 * @param watchdog_cursor the watchdog to remove from the list
 * @param previous_cursor the watchdog that preceeds the one to remove
 * (required)
 *
 * @retval FALSE the scheduled watchdog is not the earliest in the list
 * @retval TRUE the scheduled watchdog is the earliest in the list
 */
FUNC(u8, OS_CODE) remove_scheduled_watchdog(
  P2VAR(tpl_scheduled_watchdog, OS_VAR_NOINIT, AUTOMATIC) watchdog_cursor,
  P2VAR(tpl_scheduled_watchdog, OS_VAR_NOINIT, AUTOMATIC) previous_cursor);

/**
 * @internal
 *
 * Schedule a watchdog at specified date
 *
 * @warning should not be called in watchdog callback !
 *
 * @param this_watchdog watchdog to schedule (data are copied)
 * @param expire_date date when the watchdog should expire
 */
FUNC(void, OS_CODE) schedule_watchdog(
  P2VAR(tpl_watchdog, OS_APPL_DATA, AUTOMATIC) this_watchdog,
  VAR(tpl_time, AUTOMATIC) expire_delay);

/**
 * @internal
 *
 * Cancels a watchdog to avoid its expiration.
 *
 * @warning should not be called in watchdog callback !
 *
 * @param this_watchdog watchdog to unschedule
 */
FUNC(void, OS_CODE) unschedule_watchdog(
  P2VAR(tpl_watchdog, OS_APPL_DATA, AUTOMATIC) this_watchdog);

/**
 * @internal
 *
 * Cancels all watchdogs related to a task/isr.
 *
 * @warning should not be called in watchdog callback !
 *
 * @param this_exec_obj the task/isr concerned
 */
FUNC(void, OS_CODE) unschedule_exec_obj_watchdogs(
  P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* defined WITH_AUTOSAR_TIMING_PROTECTION */

#endif /*TPL_AS_WATCHDOG_KERNEL_H*/
