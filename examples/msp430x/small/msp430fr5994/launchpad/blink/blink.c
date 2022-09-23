#include "tpl_os.h"
#include "msp430.h"
#include "leds.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"


FUNC(int, OS_APPL_CODE) main(void)
{
	ledInit();
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
