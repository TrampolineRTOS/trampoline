#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "tpl_os.h"

GPIO_InitTypeDef  GPIO_InitStructure;
static int pin_state;

void setTimer()
{
  if (SysTick_Config(SystemCoreClock / 1000))
    {
        while(1);
    }
}

FUNC(int, OS_APPL_CODE) main(void)
{
	/* GPIOD Periph clock enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	/* Configure PD9, PD12, PD13, PD14 and PD15 in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_ResetBits(GPIOD, GPIO_Pin_9);
	GPIO_ResetBits(GPIOD, GPIO_Pin_12);
	GPIO_ResetBits(GPIOD, GPIO_Pin_13);
	GPIO_ResetBits(GPIOD, GPIO_Pin_14);
	GPIO_ResetBits(GPIOD, GPIO_Pin_15);

	/*  STM_EVAL_LEDInit(LED3);
	 * STM_EVAL_LEDInit(LED4);
	 * STM_EVAL_LEDInit(LED5);
	 * STM_EVAL_LEDInit(LED6);
	 */

	pin_state = 0;

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
//    static int pin_state = 0;
    
    occurence++;
//    printf("Activation #%d\n",occurence);
    
//    printf("error=%d\n",ChainTask(stop));
    /* PD9 to be toggled */
    if (pin_state == 0) {
        pin_state = 1;
      GPIO_SetBits(GPIOD, GPIO_Pin_9);
    } else {
        pin_state = 0;
      GPIO_ResetBits(GPIOD, GPIO_Pin_9);
    };
    TerminateTask();
}

TASK(stop)
{
//  CancelAlarm(one_second);
  TerminateTask();
}

void assert_failed(uint8_t* file, uint32_t line)
{
}
