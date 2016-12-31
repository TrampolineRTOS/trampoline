#include "tp.h"
#include "tpl_os.h"
#include "stm32f4xx_tim.h"

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
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

  /* TIM2 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  /* Enable the TIM2 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 13;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  /* Time base configuration */
  /* Prescaler so the counter count every microsecond */
  TIM_TimeBaseStructure.TIM_Prescaler = 84 - 1;

  /* Time set to 100 µs */
  TIM_TimeBaseStructure.TIM_Period = 100 - 1;

  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  TIM_SelectOnePulseMode(TIM2, TIM_OPMode_Repetitive);

  initBoard();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_start_timer_START_SEC_CODE
#include "tpl_memmap.h"
TASK(start_timer)
{
  /* TIM2 enable counter */
  TIM_Cmd(TIM2, ENABLE);

  /* TIM Interrupts enable */
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

  TerminateTask();
}
#define APP_Task_start_timer_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_periodic_START_SEC_CODE
#include "tpl_memmap.h"
TASK(periodic)
{
  volatile int i;
  for (i = 0; i < 2000; i++);
  DisableAllInterrupts();
  ledOn(BLUE);
  for (i = 0; i < 8000; i++);
  ledOff(BLUE);
  EnableAllInterrupts();
  for (i = 0; i < 2000; i++);
  TerminateTask();
}
#define APP_Task_periodic_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_isr_TIM2_START_SEC_CODE
#include "tpl_memmap.h"

ISR(isr_TIM2)
{
  ledToggle(RED);
}
#define APP_ISR_isr_TIM2_STOP_SEC_CODE
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
