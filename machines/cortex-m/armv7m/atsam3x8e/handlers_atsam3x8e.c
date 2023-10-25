/**
 * @file handlers_atsam3x8e.c
 *
 * @section descr File description
 *
 * ATSAM3X8E platform specific routines and variables
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
#define __SAM3X8E__
#include "sam.h"
// #include "stm32f4_discovery.h"
#include "tpl_compiler.h"
// #include "stm32f4xx_tim.h"

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
	// uint32 lregSCB_HFSR;
	// uint32 lregSCB_CFSR;
	// uint32 lregSCB_BFAR;
	// uint32 lregSCB_DFSR;
	// uint32 lregSCB_AFSR;
	// uint32 lregSCB_MMFR;
	//
	// lregSCB_HFSR = (uint32)0;
	// lregSCB_CFSR = (uint32)0;
	// lregSCB_BFAR = (uint32)0;
	// lregSCB_DFSR = (uint32)0;
	// lregSCB_AFSR = (uint32)0;
	// lregSCB_MMFR = (uint32)0;
	//
	// lregSCB_HFSR = (uint32)(SCB->HFSR);
	// if ((SCB->HFSR & (1 << 30)) != 0)
	// {
	// 	//printErrorMsg("Forced Hard Fault\n");
	// 	//sprintf(msg, "SCB->CFSR = 0x%08x\n", SCB->CFSR );
	// 	//printErrorMsg(msg);
	// 	if((SCB->CFSR & 0xFFFF0000) != 0)
	// 	{
	// 		lregSCB_CFSR = (uint32)SCB->CFSR;
	// 		//printUsageErrorMsg(SCB->CFSR);
	// 	}
	// 	lregSCB_BFAR = (uint32)SCB->BFAR;
	// 	lregSCB_DFSR = (uint32)SCB->DFSR;
	// 	lregSCB_AFSR = (uint32)SCB->AFSR;
	// 	lregSCB_MMFR = (uint32)SCB->MMFR;
	// }
	__ASM volatile("BKPT #02");
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
// void SysTick_ClearFlag(void)
// {
// }
//
// FUNC(void, OS_CODE) TIM2_IRQ_ClearFlag(void) {
//  	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
//    {
//      TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//    }
// }
