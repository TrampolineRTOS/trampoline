#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "tpl_os.h"

uint32_t tabMainStack[100];
uint32_t ptrMainStack;

void setTimer()
{
  if (SysTick_Config(SystemCoreClock / 1000))
    {
        while(1);
    }
}

FUNC(int, OS_APPL_CODE) main(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  ptrMainStack = (uint32_t)&tabMainStack[99];

  __set_PSP(__get_MSP());
  __set_CONTROL(0x2); // Switch to use Process Stack, privileged state
  __ISB(); // Execute ISB after changing CONTROL (architectural recommendation)
  __set_MSP(ptrMainStack);

  /* GPIOD Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  /* Configure PD9, PD12, PD13, PD14 and PD15 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  /* Re initialise GPIO_InitStructure */
  GPIO_InitStructure.GPIO_Pin = 0;
  GPIO_InitStructure.GPIO_Mode = 0;
  GPIO_InitStructure.GPIO_OType = 0;
  GPIO_InitStructure.GPIO_Speed = 0;
  GPIO_InitStructure.GPIO_PuPd = 0;

  /* Initialise button */
  STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI);
  EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);

  /* Initialise output ports */
  GPIO_ResetBits(GPIOD, GPIO_Pin_9);
  GPIO_ResetBits(GPIOD, GPIO_Pin_12);
  GPIO_ResetBits(GPIOD, GPIO_Pin_13);
  GPIO_ResetBits(GPIOD, GPIO_Pin_14);
  GPIO_ResetBits(GPIOD, GPIO_Pin_15);

  /* Initialise LEDs */
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);

  tpl_init_machine_specific();
  setTimer();

  StartOS(OSDEFAULTAPPMODE);

  return 0;
}

DeclareAlarm(one_second);

DeclareTask(stop);

TASK(my_periodic_task)
{
  static int occurence = 0;
    
  occurence++;
//    printf("Activation #%d\n",occurence);
    
//    printf("error=%d\n",ChainTask(stop));
    /* PD9 to be toggled */
  STM_EVAL_LEDToggle(LED4);
  GPIO_ToggleBits(GPIOD, GPIO_Pin_9);

  TerminateTask();
}

TASK(phare_ouest)
{
  STM_EVAL_LEDToggle(LED5);

  TerminateTask();
}

TASK(stop)
{
//  CancelAlarm(one_second);
  TerminateTask();
}

FUNC(void, OS_APPL_CODE) isr_button1_function(void)
{
  STM_EVAL_LEDToggle(LED3);

  ActivateTask(phare_ouest);

  CallTerminateISR2();
}

void assert_failed(uint8_t* file, uint32_t line)
{
}
