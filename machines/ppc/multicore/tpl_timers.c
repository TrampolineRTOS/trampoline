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
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * tpl_init_pit starts the PIT peripheral
 *
 */
FUNC(void, OS_CODE) tpl_init_pit(void)
{
  TPL_PIT.MCR = PIT_MCR_FRZ;
}


#if 0 /* We're using the generated function tpl_load_pits for now */
/**
 * tpl_load_pit loads the given pit channel with a value and starts the channel
 *
 * @param pit     chan pit channel id to load
 * @param ticks   value to load
 *
 */
FUNC(void, OS_CODE) tpl_load_pit(
  VAR(uint8, AUTOMATIC) chan,
  VAR(uint32, AUTOMATIC) ticks)
{
  /* loads the value */
  PIT_LVR(chan) = ticks;
  /* clear interrupt flag */
  PIT_FR(chan) = PIT_FR_TIF;
  /* start the channel and enable interrupt */
  PIT_CR(chan) = PIT_CR_TEN | PIT_CR_TIE;
}

/**
 * tpl_start_pit starts a given pit channel
 *
 * @param pit     chan pit channel id to start
 *
 */
FUNC(void, OS_CODE) tpl_start_pit(
  VAR(uint8, AUTOMATIC) chan)
{
  PIT_CR(chan) = PIT_CR_TEN | PIT_CR_TIE;
}


/**
 * tpl_stop_pit stops a given pit channel
 *
 * @param pit     chan pit channel id to stop
 *
 */
FUNC(void, OS_CODE) tpl_stop_pit(
  VAR(uint8, AUTOMATIC) chan)
{
  /* stops the channel and disable interrupts */
  PIT_CR(chan) = (PIT_CR(chan)) & ~(PIT_CR_TEN | PIT_CR_TIE);
  /* clear interrupt flag */
  PIT_FR(chan) = PIT_FR_TIF;
}

#if WITH_AUTOSAR_TIMING_PROTECTION == YES
/**
 * tpl_watchdog_handler handler function for timing protection called by pit interrupt
 *
 */
FUNC(tpl_bool, OS_CODE) tpl_watchdog_handler(void)
{
  /* stops the channel and disable interrupts */
  PIT_CR(TPL_WDG_TIMER) = (PIT_CR(TPL_WDG_TIMER)) & ~(PIT_CR_TEN | PIT_CR_TIE);
  /* clear interrupt flag */
  PIT_FR(TPL_WDG_TIMER) = PIT_FR_TIF;

  /* call timing protection expiration function */
  tpl_watchdog_expiration();

  /* restore CPU priority */
  return TRUE;
}
#endif
#endif /* unused */

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


