/**
 * @file nxt_irq.c
 *
 * @section descr File description
 *
 * SIMTEC platform specific routines and variables
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
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

#include "tpl_os_kernel.h"
#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#endif /* WITH_AUTOSAR */

#include "AT91SAM7.h"
#include "tpl_os_it_kernel.h"

extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[31];

#define OS_START_SEC_VAR_8BIT
#include "tpl_memmap.h"
u8 check_buttons_period = 0;
#define OS_STOP_SEC_VAR_8BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC (void, OS_CODE) tpl_arm_subarch_irq_handler (void)
{
  /* When the processor reads AIC_IVR (Interrupt Vector Register),
    the value written into AIC_SVR corresponding to the current
   interrupt is returned. */
  VAR(u16, AUTOMATIC) isr_id = *AT91C_AIC_IVR;
  
  /* Find Interrupt Peripheral ID */
  *AT91C_AIC_IVR = 0xFFFFF100;
  isr_id = *AT91C_AIC_ISR;
  
  /* Launch action (timer, ISR2...) */
  VAR(tpl_it_handler, AUTOMATIC) isr_vector;
  isr_vector = tpl_it_vector[isr_id].func;
  isr_vector(tpl_it_vector[isr_id].args);

  /* Acknowledge interrupt */
  *AT91C_AIC_EOICR = 0xFFFFF130;
}

FUNC (void, OS_CODE) tpl_arm_subarch_fiq_handler (void)
{
  /* TODO */
}


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file nxt_irq.c */
