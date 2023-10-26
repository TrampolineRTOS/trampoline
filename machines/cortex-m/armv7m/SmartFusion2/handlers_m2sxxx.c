/**
 * @file handlers_m2sxxx.c
 *
 * @section descr File description
 *
 * SmartFusion2 specific routines and variables
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
 */

#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h"
#include "tpl_os_hooks.h"
#include "tpl_compiler.h"
#include "m2sxxx.h"

extern void tpl_primary_syscall_handler(void);

/******************************************************************************
 * Exception handlers.
 ******************************************************************************/
FUNC(void, OS_CODE)NMI_Handler(void)
{
	CALL_PANIC_HOOK(PANIC_NMI);
	__ASM volatile("BKPT #01");
	while (1);
}

FUNC(void, OS_CODE)HardFault_Handler(void)
{
	CALL_PANIC_HOOK(PANIC_HARDFAULT);
	__ASM volatile("BKPT #02");
	while (1);
}

FUNC(void, OS_CODE)MemManage_Handler(void)
{
	CALL_PANIC_HOOK(PANIC_MEMMANAGE);
	__ASM volatile("BKPT #03");
	while (1);
}

FUNC(void, OS_CODE)BusFault_Handler(void)
{
	CALL_PANIC_HOOK(PANIC_BUSFAULT);
	__ASM volatile("BKPT #04");
	while (1);
}

FUNC(void, OS_CODE)UsageFault_Handler(void)
{
	CALL_PANIC_HOOK(PANIC_USAGEFAULT);
	__ASM volatile("BKPT #05");
	while (1);
}

FUNC(void, OS_CODE)DebugMonitor_Handler(void)
{
	while (1);
}

FUNC(void, OS_CODE)PendSV_Handler(void)
{
	while (1);
}

