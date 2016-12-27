/**
 * @file tpl_machine_stm32f407.c
 *
 * @section descr File description
 *
 * Trampoline processor dependant memory protection for MPC551x mpu.
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
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_os_definitions.h"
#include "tpl_machine.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

__STATIC_INLINE FUNC(uint32, OS_CODE) tpl_configure_systick(
  CONST(uint32, AUTOMATIC) ticks)
{
  /* Reload value impossible */
  if ((ticks - 1) > SysTick_LOAD_RELOAD_Msk) return (E_OS_VALUE);
  /* Reload value ok, set reload register */
  SysTick->LOAD = ticks - 1;
  /* Set priority to 14 as the SVC priority */
  NVIC_SetPriority (SysTick_IRQn, 14);
  /* Load the SysTick Counter Value */
  SysTick->VAL = 0;
  /* Enable SysTick IRQ and SysTick Timer */
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                  SysTick_CTRL_TICKINT_Msk   |
                  SysTick_CTRL_ENABLE_Msk;
  return (E_OK);
}


FUNC(void, OS_CODE) tpl_set_systick_timer()
{
	if (tpl_configure_systick(SystemCoreClock / 1000) == E_OS_VALUE)
	{
		while(1);
	}
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
