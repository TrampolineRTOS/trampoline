/**
 * @file handlers_mk20dx256.c
 *
 * @section descr File description
 *
 * mk20dx256 specific routines and variables
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

#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h"
#include "tpl_os_hooks.h"
#include "tpl_compiler.h"
#include "mk20dx256.h"
#include "gpio.h"

extern void tpl_primary_syscall_handler(void);

/******************************************************************************
 * Exception handlers.
 ******************************************************************************/
FUNC(void, OS_CODE)NMI_Handler(void)
{
  CALL_PANIC_HOOK(PANIC_NMI);
	__ASM volatile("BKPT #01");
	while (1)
    {
    }
}

FUNC(void, OS_CODE)HardFault_Handler(void)
{
  CALL_PANIC_HOOK(PANIC_HARDFAULT);
  while (1) {
		// keep polling some communication while in fault
		// mode, so we don't completely die.
/*		if (SIM_SCGC4 & SIM_SCGC4_USBOTG) usb_isr();
		if (SIM_SCGC4 & SIM_SCGC4_UART0) uart0_status_isr();
		if (SIM_SCGC4 & SIM_SCGC4_UART1) uart1_status_isr();
		if (SIM_SCGC4 & SIM_SCGC4_UART2) uart2_status_isr(); */
	}
}

FUNC(void, OS_CODE)MemManage_Handler(void)
{
  CALL_PANIC_HOOK(PANIC_MEMMANAGE);
	__ASM volatile("BKPT #03");
	while (1)
    {
    }
}

FUNC(void, OS_CODE)BusFault_Handler(void)
{
  CALL_PANIC_HOOK(PANIC_BUSFAULT);
	__ASM volatile("BKPT #04");
	while (1)
    {
    }
}

FUNC(void, OS_CODE)UsageFault_Handler(void)
{
  CALL_PANIC_HOOK(PANIC_USAGEFAULT);
	__ASM volatile("BKPT #05");
	while (1)
    {
    }
}

//FUNC(void, OS_CODE)SVCall_Handler(void)
//{
//  tpl_primary_syscall_handler();
//}

FUNC(void, OS_CODE)DebugMonitor_Handler(void)
{
  while (1)
    {
    }
}

FUNC(void, OS_CODE)PendSV_Handler(void)
{
  while (1)
    {
    }
}

/******************************************************************************
 * IRQ acknowledge functions.
 ******************************************************************************/
