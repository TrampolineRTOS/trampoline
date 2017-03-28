/**
 * @file tpl_timing_protection.c
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

#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_as_timing_protec.h"
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"

#include "stm32f4xx_tim.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
extern volatile VAR(uint32, OS_VAR) tpl_time_counter;
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_init_tp(void)
{
  /*
   * Program the timer
   */
  NVIC_InitTypeDef NVIC_InitStructure;

  /* TIM2 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  /* Enable the TIM2 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 15;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC->IP[TIM2_IRQn] = 15 << 4;

  /* Time base configuration */
  /* Prescaler so the counter count every microsecond */
  TIM_TimeBaseStructure.TIM_Prescaler = 84 - 1;

  /* Time set to 0 microseconds */
  TIM_TimeBaseStructure.TIM_Period = 0;

  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  TIM_SelectOnePulseMode(TIM2, TIM_OPMode_Single);
}

/*
 * Get the current value of the timing protection timer
 *
 * The value is in microseconds. It is computed from the tpl_time_counter variable
 * which is incremented by the Systick handler and the current value of the Systick
 * timer. The Systick time decrements from SystemCoreClock / 1000 - 1 to 0. So, its
 * value in microseconds is equal to:
 * ((SystemCoreClock / 1000)  - SYST_CVR - 1) / ((SystemCoreClock / 1000000) - 1)
 *
 *
 */
FUNC(tpl_time, OS_CODE) tpl_get_tptimer(void)
{
    CONST(uint32, AUTOMATIC) millisTickDivision = SystemCoreClock / 1000;
    CONST(uint32, AUTOMATIC) microsTickDivision = millisTickDivision / 1000;
    CONST(uint32, AUTOMATIC) upSysTickValue = millisTickDivision - SysTick->VAL - 1;
    CONST(uint32, AUTOMATIC) microseconds = upSysTickValue / microsTickDivision;
    return tpl_time_counter * 1000 + microseconds;
}

FUNC(void, OS_CODE) tpl_set_tpwatchdog(tpl_time t)
{
    TIM_SetAutoreload(TIM2, t-1);
    TIM_SetCounter(TIM2, t-1);
    TIM2->EGR = TIM_PSCReloadMode_Immediate;
    TIM_Cmd(TIM2, ENABLE);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}

FUNC(void, OS_CODE) tpl_cancel_tpwatchdog(void)
{
    TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
}

FUNC(void, OS_CODE) tpl_timing_protection_isr(void)
{
  tpl_watchdog_expiration();
  TIM2_IRQ_ClearFlag();
  TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif
