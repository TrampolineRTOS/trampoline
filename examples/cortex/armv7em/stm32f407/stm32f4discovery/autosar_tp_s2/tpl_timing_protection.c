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
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  /* Time base configuration */
  /* Prescaler so the counter count every milli */
  TIM_TimeBaseStructure.TIM_Prescaler = 84 - 1;

  /* Time set to 0 ms */
  TIM_TimeBaseStructure.TIM_Period = 0;

  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  TIM_SelectOnePulseMode(TIM2, TIM_OPMode_Single);
}


/*
 * Get the current value of the timing protection timer
 */
FUNC(tpl_time, OS_CODE) tpl_get_tptimer(void)
{
    return TIM_GetCounter(TIM2);
}

FUNC(void, OS_CODE) tpl_set_tpwatchdog(tpl_time t)
{
    TIM_TimeBaseStructure.TIM_Period = t-1;
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM2, ENABLE);
}

FUNC(void, OS_CODE) tpl_cancel_tpwatchdog(void)
{
    TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
}

ISR(isr_tpl_tp)
{
    tpl_watchdog_expiration();
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif
