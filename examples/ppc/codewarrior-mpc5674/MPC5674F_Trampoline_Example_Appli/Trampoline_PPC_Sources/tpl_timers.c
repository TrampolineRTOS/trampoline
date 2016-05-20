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
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * MPC5674F port - copyright(c) 2016 propriété de l'IRT Saint Exupery, tous droits reservés
 *
 * 
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
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
#include "tpl_mpc5674f_define.h"


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
 * tpl_stop_pit stops a given pit channel
 *
 * @param pit 	 pit channel id to stop
 *
 */
FUNC(void, OS_CODE) tpl_stop_pit(
  VAR(uint8, AUTOMATIC) pit)
{
  /* stops the channel and disable interrupts */
  *PIT_TCTRL(pit) = (*PIT_TCTRL(pit)) & ~(PIT_TCTRL_TEN | PIT_TCTRL_TIE);
  /* clear interrupt flag */
  /* MPC5674F_Porting_Modif : I supposed it is fault, it should taken pit as parameter */  
  *PIT_TFLG(pit) = PIT_TFLG_TIF; /* *PIT_TFLG(TPL_WDG_TIMER) = PIT_TFLG_TIF; */
  
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
FUNC(void, OS_CODE) AckPIT_0(void)
{
  /* MPC5674F_Porting_Modif : It seems that this counter is no longer used kernel time management */  
  /* increment current date */
  //tpl_current_date++;

  /* clear interrupt flag */
  *PIT_TFLG(TPL_TICK_TIMER) = PIT_TFLG_TIF;
}
#endif

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


