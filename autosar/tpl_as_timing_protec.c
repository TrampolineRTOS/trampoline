/**
 * @file tpl_as_timing_protec_alt.c
 *
 * @internal
 *
 * @section desc File description
 *
 * @todo document this
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

/*
 * We assume that the local time is "infinite". 
 * If the underlying timer is cyclic, the implementation of
 * tpl_get_local_current_time handles overflow.
 * If the time is coded on 32 bits and the time unit is 1 ms, 
 * the maximal lifetime of the system is 49 days.
 */

#include "tpl_as_timing_protec.h"
#include "tpl_dow.h"
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_machine_interface.h"
#include "tpl_as_protec_hook.h"

#if WITH_AUTOSAR_TIMING_PROTECTION == YES

#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "tpl_memmap.h"

#if NUMBER_OF_CORES > 1
VAR(unsigned int, OS_VAR) tpl_tp_watchdog_id[NUMBER_OF_CORES];
VAR(tpl_proc_id, OS_VAR) tpl_tp_watchdog_owner[NUMBER_OF_CORES];
#define GET_TP_WATCHDOG_ID(core_id) tpl_tp_watchdog_id[core_id]
#define GET_TP_WATCHDOG_OWNER(core_id) tpl_tp_watchdog_owner[core_id]
#else
VAR(unsigned int, OS_VAR) tpl_tp_watchdog_id;
VAR(tpl_proc_id, OS_VAR) tpl_tp_watchdog_owner;
#define GET_TP_WATCHDOG_ID(core_id) tpl_tp_watchdog_id
#define GET_TP_WATCHDOG_OWNER(core_id) tpl_tp_watchdog_owner
#endif

#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

void tpl_tp_set_watchdog_id(unsigned int id,
                            CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    GET_PROC_CORE_ID(proc_id, core_id)
    /* Id shall be between 0 and 3. Let's check this */
    DOW_ASSERT(0 <= id && id <= 3);
    GET_TP_WATCHDOG_ID(core_id) = id;
    GET_TP_WATCHDOG_OWNER(core_id) = proc_id;
    return ;
}

unsigned int tpl_tp_get_watchdog_id(CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    GET_PROC_CORE_ID(proc_id, core_id)
    /* tpl_tp_watchdog_id shall be between 0 and 3. Let's check this */
    DOW_ASSERT(0 <= GET_TP_WATCHDOG_ID(core_id) && GET_TP_WATCHDOG_ID(core_id) <= 3);
    return GET_TP_WATCHDOG_ID(core_id);
}

/**
 * Reset the activity flag of the watchdogs of a proc. This
 * function must be called every time an instance of a task enters 
 * the RUNNING state for the first time.
 */
FUNC(tpl_bool, OS_CODE) tpl_tp_reset_watchdogs (
        CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    VAR(tpl_bool, AUTOMATIC) result = TRUE;
    CONSTP2VAR(tpl_timing_protection, AUTOMATIC, OS_APPL_DATA) tp =
        tpl_stat_proc_table[proc_id]->timing_protection;

    if(tp != NULL)
    {
        tp->watchdogs[EXECUTIONBUDGET].is_active    = TRUE;
        tp->watchdogs[RESOURCELOCK].is_active       = FALSE;
        tp->watchdogs[ALLINTERRUPTLOCK].is_active   = FALSE;
        tp->watchdogs[OSINTERRUPTLOCK].is_active    = FALSE;
    }
    return result;
}

/**
 * OS465: The Operating System module shall limit the inter-arrival 
 * time of tasks to one per OsTaskTimeFrame
 *
 * OS469: The Operating System module shall start an OsTaskTimeFrame 
 * when a task is activated successfully.
 *
 * OS472: The Operating System module shall start an OsTaskTimeFrame 
 * when a task is released successfully.
 *
 */
FUNC(tpl_bool, OS_CODE) tpl_tp_on_activate_or_release (
        CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  VAR(tpl_bool, AUTOMATIC) result = TRUE;
  VAR(tpl_time, AUTOMATIC) now;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)  s_proc =
    tpl_stat_proc_table[proc_id];
  CONSTP2VAR(tpl_timing_protection, AUTOMATIC, OS_APPL_DATA) tp =
    tpl_stat_proc_table[proc_id]->timing_protection;

   /* printf("TPL_TP : %s(proc %u @ %u)\n", __FUNCTION__, proc_id, (unsigned int)tpl_get_local_current_date()); */
    
    if(tp != NULL)
    {
        now = tpl_get_tptimer();
        
        /* Activation is allowed if the current timeframe is finished
         OR  this is the first activation request */
        if( ((now - tp->last_activation) > s_proc->timeframe) ||
            (tp->first_instance == TRUE) )
        {
            /* mark the starting date of a new timeframe */
            tp->last_activation = now;
            
            /* reset the first_instance flag */
            tp->first_instance = FALSE;
        }
        else
        {
            result = FALSE;
        }
    }
  return result;
}

/**
 * OS473: The Operating System module shall reset a task's
 * OsTaskExecutionBudget on a transition to the SUSPENDED or 
 * WAITING states.
 */
FUNC(tpl_bool, OS_CODE) tpl_tp_on_terminate_or_wait(
        CONST(tpl_proc_id, AUTOMATIC) proc_id)
{

    CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)  s_proc =
      tpl_stat_proc_table[proc_id];
    CONSTP2VAR(tpl_timing_protection, AUTOMATIC, OS_APPL_DATA) tp =
      tpl_stat_proc_table[proc_id]->timing_protection;

    if(tp != NULL)
    {
        /* *LOCK watchdogs shall be inactive, therefore, the active watchdog 
         * shall be EXECUTIONBUDGET. Let's check this 
         */
        DOW_ASSERT(tpl_tp_get_watchdog_id(proc_id) == EXECUTIONBUDGET);

        /* If the watchdog is active, cancel it */ 
        if(tp->watchdogs[EXECUTIONBUDGET].is_active == TRUE)
        {
            tpl_cancel_tpwatchdog();
        }
        /* and we reset the EXECUTIONBUDGET watchdog data for the next instance */
        tp->watchdogs[EXECUTIONBUDGET].remaining = s_proc->executionbudget;        
    }
    return TRUE;
}

/** 
 * The task is started: its active watchdogs shall be started too
 */
FUNC(tpl_bool, OS_CODE) tpl_tp_on_start(
        CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    VAR(tpl_time, AUTOMATIC) now;
    CONSTP2VAR(tpl_timing_protection, AUTOMATIC, OS_APPL_DATA)           
        tp = tpl_stat_proc_table[proc_id]->timing_protection;
    VAR(unsigned char, AUTOMATIC) min_id = 0;
    VAR(unsigned char, AUTOMATIC) c = 0;

    if(tp != NULL)
    {
        now = tpl_get_tptimer();
        
        /* 
         * 1/ Updates the start date of active watchdogs
         * 2/ Finds the one with the shortest remaining time
         */
        for(c = 0; c < NB_WATCHDOGS_PER_PROC; c++)
        {
            if (tp->watchdogs[c].is_active == TRUE)
            {
                tp->watchdogs[c].start_date = now;
                if(tp->watchdogs[c].remaining < tp->watchdogs[min_id].remaining)
                {
                    min_id = c;
                }
            }
        }
        
        /* Set an expiry point when the shortest remaining budget will reach 0 */
        tpl_tp_set_watchdog_id(min_id, proc_id);

        tpl_set_tpwatchdog(tp->watchdogs[min_id].remaining);
    }
    return TRUE;
}

/**
 * The task is stopped: its active watchdogs shall be stopped too
 */
FUNC(tpl_bool, OS_CODE) tpl_tp_on_preempt(
        CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    VAR(tpl_time, AUTOMATIC) now;
    CONSTP2VAR(tpl_timing_protection, AUTOMATIC, OS_APPL_DATA)  
        tp = tpl_stat_proc_table[proc_id]->timing_protection;
    VAR(unsigned int, AUTOMATIC) c;
    /* printf("TPL_TP : %s(proc %u @ %u)\n", __FUNCTION__, proc_id, (unsigned int)tpl_get_tptimer()); */
    if(tp != NULL)
    {
        now = tpl_get_tptimer();

        /* First, we cancel the expiry point */
        tpl_cancel_tpwatchdog();

        /* Then we update the remaining budgets of active watchdogs */
        for(c = 0; c < NB_WATCHDOGS_PER_PROC; c++)
        {
            if(tp->watchdogs[c].is_active == TRUE)
            {
                tp->watchdogs[c].remaining -= now - tp->watchdogs[c].start_date;
            }
        }
    }
    return TRUE;
}

/**
 * OS064: If a task's OsTaskExecutionBudget is reached then the Operating System
 * module shall call the ProtectionHook() with E_OS_PROTECTION_TIME.
 * 
 * OS210: If a Category 2 ISRs OsIsrExecutionBudget is reached then the Operating
 * System module shall call the ProtectionHook() with E_OS_PROTECTION_TIME.
 *
 * OS033: If a Task/Category 2 ISR holds an OSEK Resource and exceeds the
 * Os[Task|Isr]ResourceLockBudget, the Operating System module shall call the 
 * ProtectionHook() with E_OS_PROTECTION_LOCKED.
 *
 * OS037: If a Task/Category 2 ISR disables interrupts 
 * (via Suspend/Disable|All/OS|Interrupts()) and exceeds the configured 
 * Os[Task|Isr][All|OS]InterruptLockBudget, the Operating System module shall call 
 * the ProtectionHook() with E_OS_PROTECTION_LOCKED.
 */
FUNC(tpl_bool, OS_CODE) tpl_watchdog_expiration(void)
{
    GET_CURRENT_CORE_ID(core_id)
    CONSTP2VAR(tpl_timing_protection, AUTOMATIC, OS_APPL_DATA)  
        tp = tpl_stat_proc_table[GET_TP_WATCHDOG_OWNER(core_id)]->timing_protection;
    VAR(unsigned int, AUTOMATIC) error_code = E_OS_PROTECTION_LOCKED;
    VAR(unsigned int, AUTOMATIC) cpt = 0;
    VAR(tpl_bool, AUTOMATIC) at_least_one = FALSE;

    /* printf("TPL_TP : %s(void)\n", __FUNCTION__); */

    /* check if at least one watchdog was active and 
     * set the active flag to false for the proc that has caused the error */
    for(cpt=0; cpt<NB_WATCHDOGS_PER_PROC; cpt++)
    {
        if(tp->watchdogs[cpt].is_active == TRUE)
        {
            at_least_one = TRUE;
        }
        tp->watchdogs[cpt].is_active = FALSE;
    }

    /* if at least one watchdog was active, process the error */
    if (at_least_one == TRUE)
    {
        /* change the error code from E_OS_PROTECTION_LOCKED to E_OS_PROTECTION_TIME if needed */
        if (tpl_tp_get_watchdog_id(GET_TP_WATCHDOG_OWNER(core_id)) == EXECUTIONBUDGET)
        {
            error_code = E_OS_PROTECTION_TIME;
        }
        tpl_call_protection_hook(error_code);
    }
    return TRUE;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#else /* defined WITH_AUTOSAR_TIMING_PROTECTION */
/* volatile static u8 nothing; */
#endif /* !defined WITH_AUTOSAR_TIMING_PROTECTION */
