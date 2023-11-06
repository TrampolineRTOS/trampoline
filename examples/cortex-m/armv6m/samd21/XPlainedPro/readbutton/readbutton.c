#include "tpl_os.h"
//the READY tasks state definition conflicts with registers definition (in sam.h)
#undef READY
#include "pinAccess.h" //provided in machines/cortex-m/armv6m/samd21/utils

#define APP_Task_read_button_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
  pinMode(PORTA,15,INPUT);  //button SW0
  pinMode(PORTB,30,OUTPUT); //LED0
  digitalWrite(PORTB,30,1); //switch off led

  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

DeclareAlarm(blink_alarm);

TASK(read_button)
{
	static int a = 0;
	if (digitalRead(PORTA,15) == 0) //BUTTON_PRESSED
	{
		if (a == 0) {
			SetRelAlarm(blink_alarm, 100, 100);
			a = 1;
		} else {
			CancelAlarm(blink_alarm);
			a = 0;
		}
	}
	TerminateTask();
}
#define APP_Task_read_button_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
TASK(blink)
{
  digitalToggle(PORTB,30); //led
  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

