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

#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h"
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "tpl_compiler.h"

extern void tpl_primary_syscall_handler(void);

/******************************************************************************
 * Exception handlers.
 ******************************************************************************/
FUNC(void, OS_CODE)NMI_Handler(void)
{
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
  while (1)
    {
    }
}

FUNC(void, OS_CODE)BusFault_Handler(void)
{
  while (1)
    {
    }
}

FUNC(void, OS_CODE)UsageFault_Handler(void)
{
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

void EXTI0_IRQ_ClearFlag(void)
{
  while (EXTI_GetITStatus(USER_BUTTON_EXTI_LINE) != RESET) {
    /* Clear the USER Button EXTI line pending bit */
    EXTI_ClearFlag(USER_BUTTON_EXTI_LINE);
    EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
  }
}
