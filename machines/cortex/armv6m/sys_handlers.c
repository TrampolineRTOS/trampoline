/**
 * @file cm4_irq.c
 *
 * @section descr File description
 *
 * System Exception handlers
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2016+
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

#include "tpl_machine.h"
#include "tpl_os.h"

/******************************************************************************
 * Exception handlers.
 ******************************************************************************/
FUNC(void, OS_CODE)NMI_Handler(void)
{
	__ASM volatile("bkpt #01");
	while (1);
}

FUNC(void, OS_CODE)HardFault_Handler(void)
{
	__ASM volatile("bkpt #02");
	while (1);
}

FUNC(void, OS_CODE)MemManage_Handler(void)
{
	__ASM volatile("bkpt #03");
	while (1);
}

FUNC(void, OS_CODE)BusFault_Handler(void)
{
	__ASM volatile("bkpt #04");
	while (1);
}

FUNC(void, OS_CODE)UsageFault_Handler(void)
{
	__ASM volatile("bkpt #05");
	while (1);
}

FUNC(void, OS_CODE)DebugMonitor_Handler(void)
{
	__ASM volatile("bkpt #06");
	while (1);
}

