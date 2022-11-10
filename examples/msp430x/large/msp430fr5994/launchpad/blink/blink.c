#include "tpl_os.h"
#include "msp430.h"
#include "leds.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"


FUNC(int, OS_APPL_CODE) main(void)
{
	ledInit();

	// Setup free running timer
	TA0CCTL0 = CCIE;
	TA0CTL = TASSEL__ACLK | MC__CONTINOUS | TACLR;
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	ledToggle(LED1);
	TerminateTask();
}

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_timerA_START_SEC_CODE
#include "tpl_memmap.h"

ISR(timerA)
{
	ledToggle(LED2);
}

#define APP_ISR_timerA_STOP_SEC_CODE
#include "tpl_memmap.h"