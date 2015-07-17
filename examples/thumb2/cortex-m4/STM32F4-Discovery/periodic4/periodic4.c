#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "tpl_os.h"

DeclareAlarm(one_second);
DeclareTask(stop);
DeclareTask(my_periodic_task);

// #define OS_START_SEC_VAR_32BIT
// #include "tpl_memmap.h"
// VAR(int, OS_VAR) tabMainStack[100];
// VAR(int, OS_VAR) ptrMainStack;
// #define OS_STOP_SEC_VAR_32BIT
// #include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
void setTimer()
{
	if (SysTick_Config(SystemCoreClock / 1000))
	{
		while(1);
	}
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_my_periodic_task_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
//	int i;
	GPIO_InitTypeDef  GPIO_InitStructure;

// 	ptrMainStack = (uint32_t)&tabMainStack[99];
// 	/* Initialize stack footprint */
// 	for (i = 99; i >= 0; i-- )
// 	{
// 		tabMainStack[i] = OS_STACK_PATTERN;
// 	};
//
	/* Set SVCall priority to 2 */
	NVIC_SetPriority(SVCall_IRQn, 2);

// 	__set_PSP(__get_MSP());
// 	__set_MSP(ptrMainStack);

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

//	tpl_init_machine_specific();
	setTimer();

//	__set_CONTROL(0x3); // Switch to use Process Stack, privileged state
//	__ISB(); // Execute ISB after changing CONTROL (architectural recommendation)

	StartOS(OSDEFAULTAPPMODE);

	return 0;
}
#define APP_Task_my_periodic_task_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_my_periodic_task_START_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"
VAR(int, AUTOMATIC) period = 10;
VAR(int, AUTOMATIC) occurence = 0;
#define APP_Task_my_periodic_task_STOP_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"

#define APP_Task_my_periodic_task_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, AUTOMATIC) v32_1;
VAR(int, AUTOMATIC) v32_2;
#define APP_Task_my_periodic_task_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_my_periodic_task_START_SEC_VAR_8BIT
#include "tpl_memmap.h"
VAR(short, AUTOMATIC) v8_1;
VAR(short, AUTOMATIC) v8_2;
#define APP_Task_my_periodic_task_STOP_SEC_VAR_8BIT
#include "tpl_memmap.h"

#define APP_Task_my_periodic_task_START_SEC_CODE
#include "tpl_memmap.h"
TASK(my_periodic_task)
{
	if (occurence == 0)
	{
		occurence = period;
		STM_EVAL_LEDToggle(LED5);
	} else {
		occurence--;
	}
//    printf("Activation #%d\n",occurence);

//    printf("error=%d\n",ChainTask(stop));
    /* PD9 to be toggled */
  	STM_EVAL_LEDToggle(LED4);
	GPIO_ToggleBits(GPIOD, GPIO_Pin_9);

	TerminateTask();
}
#define APP_Task_my_periodic_task_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_stop_START_SEC_CODE
#include "tpl_memmap.h"
TASK(stop)
{
//  CancelAlarm(one_second);
  TerminateTask();
}
#define APP_Task_stop_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button1)
{
  STM_EVAL_LEDToggle(LED3);

  /* If button1 is an ISR2 then call CallTerminateISR2 at the end of the handler */
//  CallTerminateISR2();
  /* otherwise do nothing more, just ends the handler */
}

void assert_failed(uint8_t* file, uint32_t line)
{
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
