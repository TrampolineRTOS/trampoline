#include "tp.h"
#include "tpl_os.h"
#include "stm32f4xx_tim.h"

#define APP_Task_blink_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
#define APP_Task_blink_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{

  /*
   * Program the timer
   *
   *
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
  /* Prescaler so the counter count every half milli */
  TIM_TimeBaseStructure.TIM_Prescaler = 42000 - 1;

  /* Time set to 30 ms */
  TIM_TimeBaseStructure.TIM_Period = 60 - 1;

  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  TIM_SelectOnePulseMode(TIM2, TIM_OPMode_Single);

  initBoard();

  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
TASK(blink)
{
  ledToggle(GREEN);

  /* TIM2 enable counter */
  TIM_Cmd(TIM2, ENABLE);

  /* TIM Interrupts enable */
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_isr_timer_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_timer)
{
  ledToggle(RED);
}


#define APP_ISR_isr_timer_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
