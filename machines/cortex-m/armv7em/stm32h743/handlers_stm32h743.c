/**
 * @section descr File description
 *
 * STM32h743 platform specific routines and variables (based on file from STM32F4xx...)
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
 */

#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h"
#include "stm32h7xx.h"
#include "tpl_compiler.h"

extern void tpl_primary_syscall_handler(void);

/******************************************************************************
 * Exception handlers.
 ******************************************************************************/
FUNC(void, OS_CODE)NMI_Handler(void)
{
	__ASM volatile("BKPT #01");
	while (1)
    {
    }
}

FUNC(void, OS_CODE)HardFault_Handler(void)
{
  	while (1)
    {
    }
}

FUNC(void, OS_CODE)MemManage_Handler(void)
{
	__ASM volatile("BKPT #03");
	while (1)
    {
    }
}

FUNC(void, OS_CODE)BusFault_Handler(void)
{
	__ASM volatile("BKPT #04");
	while (1)
    {
    }
}

FUNC(void, OS_CODE)UsageFault_Handler(void)
{
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
void SysTick_ClearFlag(void)
{
}

