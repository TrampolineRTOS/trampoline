#include "tpl_os.h"
#include "stm32f30x.h"
#include "stm32f30x_rcc.h"
#include "stm32f30x_gpio.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

//init PB.3 as output (LED 1 on pin 13).
void initUserLed()
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Enable the GPIO_LED Clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

FUNC(int, OS_APPL_CODE) main(void)
{
  initUserLed();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink)
{
  GPIOB->ODR ^= GPIO_Pin_3;	//toggle user led.
  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
