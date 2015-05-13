#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "tpl_os.h"

DeclareAlarm(one_second);
DeclareTask(stop);
DeclareTask(my_periodic_task);
DeclareTask(phare_ouest);

uint32_t tabMainStack[100];
uint32_t ptrMainStack;

void setTimer()
{
  if (SysTick_Config(SystemCoreClock / 1000))
    {
        while(1);
    }
}

#define APP_Task_periodic_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	ptrMainStack = (uint32_t)&tabMainStack[99];

 	__set_PSP(__get_MSP());
 	__set_CONTROL(0x2); // Switch to use Process Stack, privileged state
 	__ISB(); // Execute ISB after changing CONTROL (architectural recommendation)
 	__set_MSP(ptrMainStack);

/* Set SVCall priority to 2 */
	NVIC_SetPriority(SVCall_IRQn, 2);

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
#define APP_Task_periodic_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) ErrorHook(VAR(StatusType, AUTOMATIC) error)
{
	ActivateTask(stop);
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_periodic_START_SEC_CODE
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
#define APP_Task_periodic_STOP_SEC_CODE

#define APP_Task_periodic_START_SEC_CODE
TASK(phare_ouest)
{
  STM_EVAL_LEDToggle(LED5);

  TerminateTask();
}
#define APP_Task_periodic_STOP_SEC_CODE

#define APP_Task_periodic_START_SEC_CODE
TASK(stop)
{
  CancelAlarm(one_second);
  TerminateTask();
}
#define APP_Task_periodic_STOP_SEC_CODE

ISR(isr_button1)
{
	EXTI0_IRQ_ClearFlag();
	STM_EVAL_LEDToggle(LED3);
}

#define APP_Task_periodic_START_SEC_CODE
void assert_failed(uint8_t* file, uint32_t line)
{
}
#define APP_Task_periodic_STOP_SEC_CODE
