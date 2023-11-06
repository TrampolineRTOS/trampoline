#include "tpl_os.h"
//the READY tasks state definition conflicts with registers definition (in sam.h)
#undef READY
#include "pinAccess.h"	//provided in machines/cortex-m/armv6m/samd21/utils
#include "eic.h"		//provided in machines/cortex-m/armv6m/samd21/utils
#include "pinMux.h"		//provided in machines/cortex-m/armv6m/samd21/utils



FUNC(int, OS_APPL_CODE) main(void)
{
  pinMode(PORTA,15,INPUT);  //button SW0
  pinMode(PORTB,30,OUTPUT); //LED0
  digitalWrite(PORTB,30,1); //switch off led

  //start EIC@32KHz. Rest of config is automatic.
  EICInitClock(F32KHZ);
  
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

#define APP_ISR_isr_button_START_SEC_CODE
#include "tpl_memmap.h"

DeclareAlarm(blink_alarm);

ISR(isr_button)
{
	static int a = 0;
	if (a == 0) {
		SetRelAlarm(blink_alarm, 100, 100);
	} else {
		CancelAlarm(blink_alarm);
	}
	a = !a;
}

#define APP_ISR_isr_button_STOP_SEC_CODE
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

