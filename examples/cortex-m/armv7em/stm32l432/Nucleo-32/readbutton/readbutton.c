#include "tpl_os.h"
#include "pinAccess.h"

#define APP_Task_read_button_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
    pinMode(GPIOB,3,OUTPUT); //led
	//We use a jumper between D2 and GND to simulate a push button.
    pinMode(GPIOA,12,INPUT_PULLUP); //D2
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

typedef enum {OFF,PUSH,ON,RELEASE} button_state;

button_state getButton()
{
	static button_state state = OFF;
	unsigned char bp = digitalRead(GPIOA,12);
	switch(state) {
		case OFF    : if(bp==0) state = PUSH;    break;
		case PUSH   :           state = ON;      break;
		case ON     : if(bp==1) state = RELEASE; break;
		case RELEASE:           state = OFF;     break;
	}
	return state;
}

TASK(read_button)
{
    static int a = 0;
    if (getButton() == PUSH) {
        if (a == 0) {
          SetRelAlarm(blink_alarm, 100, 100);
          a = 1;
        }
        else {
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
    digitalToggle(GPIOB,3);
    TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

