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

TASK(read_button)
{
    static int a = 0;
    if (a == 0) {
        SetRelAlarm(blink_alarm, 100, 100);
        a = 1;
    }
    else {
        CancelAlarm(blink_alarm);
        a = 0;
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

#define APP_ISR_isr_button_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button)
{
    ActivateTask(read_button);
}
#define APP_ISR_isr_button_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_isr_button2_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button2)
{
    //nothing yet
}
#define APP_ISR_isr_button2_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_isr_button3_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button3)
{
    //nothing yet
}
#define APP_ISR_isr_button3_STOP_SEC_CODE
#include "tpl_memmap.h"
