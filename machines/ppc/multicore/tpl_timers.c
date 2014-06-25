/**
 * @file tpl_timers.c
 *
 * @section descr File description
 *
 * Trampoline machine dependant functions
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
 *
 * @section infos File informations
 *
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */

#include "tpl_os_internal_types.h"
#include "tpl_os_kernel.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os.h"
#include "tpl_app_define.h"
#include "tpl_timers.h"
#include "tpl_registers.h"


/*****************************************************************************/
/* VERSION CHECKING                                                          */
/*****************************************************************************/
#define OS_C_FILE_MAJOR_VERSION 0
#define OS_C_FILE_MINOR_VERSION 4

#if ((OS_SW_MAJOR_VERSION != OS_C_FILE_MAJOR_VERSION)   \
     || (OS_SW_MINOR_VERSION != OS_C_FILE_MINOR_VERSION))
#error "Os.h et Os.c files do not have the same version"
#endif

#if ((OS_SW_MAJOR_VERSION != OS_CFG_H_FILE_MAJOR_VERSION)       \
     || (OS_SW_MINOR_VERSION != OS_CFG_H_FILE_MINOR_VERSION))
#error "Os.h et Os_Cfg.h files do not have the same version"
#endif

/* Autosar version check between Os.h and configuration files */
#if ((OS_AR_RELEASE_MAJOR_VERSION != OS_CFG_H_FILE_AR_RELEASE_MAJOR_VERSION) \
     || (OS_AR_RELEASE_MINOR_VERSION != OS_CFG_H_FILE_AR_RELEASE_MINOR_VERSION) \
     || (OS_AR_RELEASE_REVISION_VERSION != OS_CFG_H_FILE_AR_RELEASE_REVISION_VERSION))
#error "Os.h and Os_Cfg.h files do not have the same AUTOSAR release version"
#endif


#define PIT_MCR_FRZ     ((uint32)0x1<<0U)
#define PIT_MCR_MDIS    ((uint32)0x1<<1U)
#define PIT_TCTRL_TEN   ((uint32)0x1<<0U)
#define PIT_TCTRL_TIE   ((uint32)0x1<<1U)
#define PIT_TFLG_TIF    ((uint32)0x1<<0U)

/* MISRA RULE 19.7 VIOLATION: this macro is used to compute pit adresses,
 * it would be very inefficient to use a function here, and this part
 * of code has to be kept the fastest possible
 */
#define PIT_MCR         ((volatile uint32*)(PIT_BASE_ADDR + PIT_MCR_ADDR))
#define PIT_LDVAL(pit)  ((volatile uint32*)(PIT_BASE_ADDR + PIT_LDVAL_ADDR + ((pit)<<4)))
#define PIT_CVAL(pit)   ((volatile uint32*)(PIT_BASE_ADDR + PIT_CVAL_ADDR + ((pit)<<4)))
#define PIT_TCTRL(pit)  ((volatile uint32*)(PIT_BASE_ADDR + PIT_TCTRL_ADDR + ((pit)<<4)))
#define PIT_TFLG(pit)   ((volatile uint32*)(PIT_BASE_ADDR + PIT_TFLG_ADDR + ((pit)<<4)))




#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * tpl_init_pit starts the PIT peripheral
 *
 */
FUNC(void, OS_CODE) tpl_init_pit(void)
{
  *PIT_MCR = PIT_MCR_FRZ;
}


/**
 * tpl_load_pit loads the given pit channel with a value and starts the channel
 *
 * @param pit     pit channel id to load
 * @param ticks   value to load
 *
 */
FUNC(void, OS_CODE) tpl_load_pit(
  VAR(uint8, AUTOMATIC) pit,
  VAR(uint32, AUTOMATIC) ticks)
{
  /* loads the value */
  *PIT_LDVAL(pit) = ticks;
  /* clear interrupt flag */
  *PIT_TFLG(pit) = PIT_TFLG_TIF;
  /* start the channel and enable interrupt */
  *PIT_TCTRL(pit) = PIT_TCTRL_TEN | PIT_TCTRL_TIE;
}


/**
 * tpl_start_pit starts a given pit channel
 *
 * @param pit     pit channel id to start
 *
 */
FUNC(void, OS_CODE) tpl_start_pit(
  VAR(uint8, AUTOMATIC) pit)
{
  *PIT_TCTRL(pit) = PIT_TCTRL_TEN | PIT_TCTRL_TIE;
}


/**
 * tpl_stop_pit stops a given pit channel
 *
 * @param pit     pit channel id to stop
 *
 */
FUNC(void, OS_CODE) tpl_stop_pit(
  VAR(uint8, AUTOMATIC) pit)
{
  /* stops the channel and disable interrupts */
  *PIT_TCTRL(pit) = (*PIT_TCTRL(pit)) & ~(PIT_TCTRL_TEN | PIT_TCTRL_TIE);
  /* clear interrupt flag */
  *PIT_TFLG(TPL_WDG_TIMER) = PIT_TFLG_TIF;
}


#if WITH_AUTOSAR_TIMING_PROTECTION == YES
/**
 * tpl_watchdog_handler handler function for timing protection called by pit interrupt
 *
 */
FUNC(void, OS_CODE) tpl_watchdog_handler(void)
{
  /* stops the channel and disable interrupts */
  *PIT_TCTRL(TPL_WDG_TIMER) = (*PIT_TCTRL(TPL_WDG_TIMER)) & ~(PIT_TCTRL_TEN | PIT_TCTRL_TIE);
  /* clear interrupt flag */
  *PIT_TFLG(TPL_WDG_TIMER) = PIT_TFLG_TIF;

  /* call timing protection expiration function */
  tpl_watchdog_expiration();

}
#endif


#if TPL_TICK_TIMER != TPL_DECREMENTER
/**
 * tpl_watchdog_handler handler function for tick called by pit interrupt
 *
 */
FUNC(void, OS_CODE) tpl_tick_handler(void)
{
  /* increment current date */
  tpl_current_date++;

  /* clear interrupt flag */
  *PIT_TFLG(TPL_TICK_TIMER) = PIT_TFLG_TIF;

  /* call counter tick, which will increment counters, and potentially raise alarms and schedule tables expiry points */
  tpl_call_counter_tick();

}
#endif

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


