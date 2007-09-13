/**
 * @file tpl_as_watchdog_kernel.h
 *
 * @section desc File description
 *
 * @todo: finish documentation
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

/**
 * @todo document this
 */
typedef enum
{
  EXEC_BUDGET,
  TIME_LIMIT,
  ALL_INT_LOCK,
  OS_INT_LOCK,
  REZ_LOCK,
  TIMEFRAME_BOUNDARY
} tpl_watchdog_type;

/**
 * @todo document this
 */
typedef struct
{
  tpl_exec_common   *exec_obj;
  tpl_watchdog_type type;
  tpl_resource_id   resource;
} tpl_watchdog;

/**
 * @todo document this 
 */
struct TPL_SCHEDULED_WATCHDOG
{
  tpl_watchdog                   watchdog;
  struct TPL_SCHEDULED_WATCHDOG  *next;
  tpl_time                       delay_from_previous;
  tpl_time                       scheduled_date;
  u8                             allocated;
};

/**
 * @todo document this
 */
typedef struct TPL_SCHEDULED_WATCHDOG tpl_scheduled_watchdog;

typedef u8 (*watchdog_callback_function)(tpl_watchdog *);

/**
 * @todo document this
 */
void init_watchdog_kernel (watchdog_callback_function callback);

/**
 * Allocate a new watchdog 
 * 
 * @todo finish documentation
 */
tpl_scheduled_watchdog *new_scheduled_watchdog ();

/**
 * @todo finish documentation
 * 
 * @retval FALSE the head of the list did not changed
 * @retval TRUE the head of the list has changed (need to reschedule the
 * real underlying watchdog)
 */
u8 insert_scheduled_watchdog (
   tpl_scheduled_watchdog *this_scheduled_watchdog);

/**
 * @todo document this
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
u8 find_scheduled_watchdog (tpl_watchdog *like_this_watchdog,
   tpl_scheduled_watchdog **watchdog_cursor,
   tpl_scheduled_watchdog **previous_cursor);

/**
 * @todo document this
 * 
 * removes the specified scheduled watchdog from the list
 * 
 * @param watchdog_cursor the watchdog to remove from the list
 * @param previous_cursor the watchdog that preceeds the one to remove 
 * (required)
 * 
 * @retval FALSE the scheduled watchdog is not the earliest in the list
 * @retval TRUE the scheduled watchdog is the earliest in the list
 */
u8 remove_scheduled_watchdog (tpl_scheduled_watchdog *watchdog_cursor,
   tpl_scheduled_watchdog *previous_cursor);

/**
 * Schedule a watchdog at specified date
 * 
 * @warning should not be called in watchdog callback !
 * 
 * @param this_watchdog watchdog to schedule (data are copied)
 * @param expire_date date when the watchdog should expire
 * 
 * @todo finish documentation
 */
void schedule_watchdog (tpl_watchdog *this_watchdog, 
   tpl_time expire_delay);

/**
 * Cancels a watchdog to avoid its expiration.
 * 
 * @warning should not be called in watchdog callback !
 * 
 * @todo finish documentation
 */
void unschedule_watchdog (tpl_watchdog *this_watchdog);

#endif /*TPL_AS_WATCHDOG_KERNEL_H*/
