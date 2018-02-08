#include "tpl_os.h"
//#include "variant.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
	// GPIO->GPIO_1_CFG = 5; //output mode.
	// GPIO->GPIO_2_CFG = 5; //output mode.
  //initBoard();

	// Set LED to off
  //pinMode(LED_BUILTIN, OUTPUT);
  //digitalWrite(LED_BUILTIN, LOW);

	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	// GPIO->GPIO_OUT ^= 0x6; //toggle LED3 and 4.
	/*
	pinMode(PIN_LED2, INPUT);
	if (digitalRead(PIN_LED2) == HIGH)
	{
		pinMode(PIN_LED2, OUTPUT);
		digitalWrite(PIN_LED2, LOW);
	}
	else
	{
		pinMode(PIN_LED2, OUTPUT);
		digitalWrite(PIN_LED2, HIGH);
	}
	*/
	TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
