/**
 * @file tpl_machine_rp2040.c
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
 */

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_os_definitions.h"
#include "tpl_machine.h"
#include "tpl_cortex_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#include "hardware/structs/systick.h"

extern uint32_t SystemCoreClock;

__STATIC_INLINE FUNC(uint32, OS_CODE) tpl_configure_systick(
  CONST(uint32, AUTOMATIC) ticks,
  CONST(uint32, AUTOMATIC) priority)
{
  /* Reload value impossible */
  if ((ticks - 1) > M0PLUS_SYST_RVR_BITS) return (E_OS_NOFUNC);
  /* priority impossible */
  if (priority > (1 << PRIO_BITS_IN_NVIC) - 1) return (E_OS_VALUE);
  /* Reload value ok, set reload register */
  systick_hw->rvr = ticks - 1;
  /* Set priority */
  NVIC_SetPriority(SysTick_IRQn, priority);
  /* Load the SysTick Counter Value */
  systick_hw->cvr = 0;
  /* Enable SysTick IRQ and SysTick Timer */
  systick_hw->csr = 1 << M0PLUS_SYST_CSR_CLKSOURCE_LSB |
	                1 << M0PLUS_SYST_CSR_TICKINT_LSB   |
	                1 << M0PLUS_SYST_CSR_ENABLE_LSB;
  return (E_OK);
}


FUNC(void, OS_CODE) tpl_set_systick_timer()
{
  if (tpl_configure_systick(SystemCoreClock / 1000, OS_ISR_PRIO_UNSHIFTED) != E_OK)
  {
    /* Failed to initialize Systick, fall back in an infinite loop */
    while(1);
  }
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
