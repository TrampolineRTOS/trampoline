/**
 * @file tpl_time_enforcement.h
 *
 * @section descr File description
 *
 * Function to wait for a date. Used in time enforcement
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_time_enforcement.h"
#include "stm32f4xx_tim.h"

#define API_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Start a stopwatch
 *
 * This function uses the TIMER
 */
FUNC(void, OS_APPL_CODE) tpl_start_enforcement_timer(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

  /* Enable clock tree of TIM5 */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);

  /* Init the time base struct to default value */
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);

  /* Setup the Prescaler to 168 so that the timer inc every microsecond */
  TIM_TimeBaseStructure.TIM_Prescaler = 84 - 1;

  /* AutoReload value set to 0xFFFFFFFF, default value, do nothing */
  /* clock division value set to 0 (aka TIM_CKD_DIV1), default value, do nothing */
  /* ccount up, default value, do nothing */

  TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);

  TIM_SelectOnePulseMode(TIM5, TIM_OPMode_Repetitive);

  TIM_Cmd(TIM5, ENABLE);
}

/*
 * Wait for a stopwatch
 */
FUNC(void, OS_APPL_CODE) tpl_wait_enforcement_timer(
  CONST(uint32, AUTOMATIC) startDate,
  CONST(uint32, AUTOMATIC) absoluteDeadline)
{
    CONST(uint32, AUTOMATIC) initialCurrentDate = TIM_GetCounter(TIM5);
    VAR(uint32, AUTOMATIC) offset;

    if ( (absoluteDeadline - startDate) > (initialCurrentDate - startDate) )
    {
      /* We have to wait until the deadline */

      /* Manage the case when the timer will overflow during the wait loop */
      if (absoluteDeadline > initialCurrentDate)
      {
        offset = 0;
      }
      else
      {
        offset = absoluteDeadline - initialCurrentDate;
      }

      while ( (TIM_GetCounter(TIM5) + offset) <
              (absoluteDeadline + offset) );
    }
}

FUNC(uint32, OS_APPL_CODE) tpl_get_enforcement_timer(void)
{
  return TIM_GetCounter(TIM5);
}

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"
