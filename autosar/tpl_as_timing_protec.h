/**
 * @file tpl_as_timing_protec.h
 *
 * @section desc File description
 *
 * TODO
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

#include "tpl_os_custom_types.h"

/**
 * TODO
 */
struct TPL_RESOURCE_LOCK_MONITOR
{
    ResourceType resource;
    TickType resource_lock_time;
};

/**
 * TODO
 */
typedef struct TPL_RESOURCE_LOCK_MONITOR tpl_resource_lock_monitor;

/**
 * TODO
 */
struct TPL_INTERRUPT_LOCK_MONITOR
{
    TickType os_interrupt_lock_time;
    TypeType all_interrupt_lock_time;
};

/**
 * TODO
 */
typedef struct TPL_INTERRUPT_LOCK_MONITOR tpl_interrupt_lock_monitor;

/**
 * TODO
 */
struct TPL_LOCKING_TIME
{
    enum {RESOURCE, INTERRUPT} type;
    union
    {
        tpl_resource_lock_monitor resource;
        tpl_interrupt_lock_monitor interrupt;
    } monitor;
};

/**
 * TODO
 */
typedef union TPL_LOCKING_TIME tpl_locking_time;

/** 
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
    tpl_tick exection_budget; /**< maximum duration the task/isr can be active
	                               within a timeframe */
    tpl_tick time_limit;      /**< maximum number of activations of the task/
                                   isr withing a timeframe */
    tpl_tick timeframe;       /**< configured timeframe for this timing
                                   protection */
    tpl_locking_monitor locking_monitors_count; /**< number of locking
                                                     monitors */
    tpl_locking_time *locking_monitors;         /**< list of locking time
                                                     monitors */
};

typedef struct tpl_timing_protection

/**
 * function to be called when a task is activated (start the watchdog)
 * TODO: improve documentation
 */
void tpl_start_budget_monitor (tpl_exec_common *this_exec_obj);
/**
 * function to be called when a task is preempted
 * TODO: improve documentation
 */
void tpl_pause_budget_monitor (tpl_exec_common *this_exec_obj);
/**
 * function to be called when a task get back the processor
 * (opposite of preemption)
 * TODO: improve documentation
 */
void tpl_continue_budget_monitor (tpl_exec_common *this_exec_obj);
/**
 * function to be called when a task is terminated (cancel the
 * watchdog)
 * TODO: improve documentation
 */
void tpl_disable_budget_monitor (tpl_exec_common *this_exec_obj);

/**
 * function called when a resource is got
 * TODO: improve documentation
 */
void tpl_start_resource_monitor (tpl_exec_common *this_exec_obj);
/**
 * function called when a resource is released
 * TODO: improve documentation
 */
void tpl_disable_resource_monitor (tpl_exec_common *this_exec_obj);

/**
 * function called when all interrupts are locked
 * TODO: improve documentation
 */
void tpl_start_all_isr_lock_monitor (tpl_exec_common *this_exec_obj);
/**
 * function called when all interrupts are unlocked
 * TODO: improve documentation
 */
void tpl_disable_all_isr_lock_monitor (tpl_exec_common *this_exec_obj);

/**
 * function called when isr 2 are locked
 * TODO: improve documentation
 */
void tpl_start_os_isr_lock_monitor (tpl_exec_common *this_exec_obj);
/**
 * function called when isr 2 are unlocked
 * TODO: improve documentation
 */
void tpl_disable_os_isr_lock_monitor (tpl_exec_common *this_exec_obj);

#endif

