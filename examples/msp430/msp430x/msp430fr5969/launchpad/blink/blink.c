#include "tpl_os.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	pinMode(RED_LED,OUTPUT);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	static int state = 0;
	if(state) digitalWrite(RED_LED,HIGH);
	else digitalWrite(RED_LED,LOW);
	state = !state;
	TerminateTask();
}

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

