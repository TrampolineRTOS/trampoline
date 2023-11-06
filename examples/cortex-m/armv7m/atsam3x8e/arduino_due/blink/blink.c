#include "tpl_os.h"
#include "Arduino.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
	// Set LED to off
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);

	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	digitalWrite(LED_BUILTIN, !(digitalRead(LED_BUILTIN)));
	
	TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
