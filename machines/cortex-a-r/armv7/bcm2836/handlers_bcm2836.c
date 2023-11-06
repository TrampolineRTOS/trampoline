/**
 * @file cm4_irq.c
 *
 * @section descr File description
 *
 * STM32F4 platform specific routines and variables
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright DG for function and data structures documentation and THUMB2 port
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

#include "handlers_bcm2836.h"

extern void tpl_primary_syscall_handler(void);
/******************************************************************************
 * Exception handlers.
 ******************************************************************************/

FUNC(void, OS_CODE) c_undefined_handler(void) {
  while(1);
}

FUNC(void, OS_CODE) c_prefetch_handler(void) {
  while(1);
}

FUNC(void, OS_CODE) c_data_handler(void) {
  while(1);
}

FUNC(void, OS_CODE)  c_reserved_handler(void) {
  while(1);
}

FUNC(void, OS_CODE) c_fiq_handler(void) {
  while(1);
}

FUNC(void, OS_CODE) c_irq_handler(void) {
	while(1);
}

FUNC(void, OS_CODE) c_svc_handler(void) {
	while(1);
}

FUNC(void, OS_CODE) c_hang_handler(void) {
  while(1);
}

/******************************************************************************
 * IRQ acknowledge functions.
 ******************************************************************************/
FUNC(void, OS_CODE) ARM_TIMER_ClearFlag(void) {
	/* Clear the ARM Timer interrupt - it's the only interrupt we have
	 * enabled, so we want don't have to work out which interrupt source
	 * caused us to interrupt
	 */
	RPI_GetArmTimer()->IRQClear = 1;
	// writeToReg(ARM_TIMER_CLI,0);
}
