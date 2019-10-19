#include <stdint.h>
#include "tpl_os.h"
#include "msp430.h"

#define APP_Task_read_button_START_SEC_CODE
#include "tpl_memmap.h"

//init some I/Os of the board:
//- red   led1  on P4.6
//- green led2  on P1.0
//- user button on P4.5
FUNC(void, OS_APPL_CODE) ioInit()
{
	// Disable the GPIO power-on default high-impedance mode
	// to activate previously configured port settings
	PM5CTL0 &= ~LOCKLPM5;
	//set GPIO P1.0 (green LED2) as an output
	P1DIR |= 0x01;
	//set GPIO P4.6 (red LED1) as an output
	P4DIR |= 1 << 6;
	//set GPIO P4.5 (button S1) as an input, with internal pull-up
	P4DIR &= ~(1<<5);	//input
	P4REN |= 1<<5;		//pull-up/down resistor enable
	P4OUT |= 1<<5;		//pull-up
}


FUNC(int, OS_APPL_CODE) main(void)
{
	ioInit();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

typedef enum { BUTTON_OFF, BUTTON_PUSH, BUTTON_ON, BUTTON_RELEASE } ButtonState;

//get button 1 state (P4.5), using a software debounce. 
//@return the button state.
FUNC(ButtonState, OS_APPL_CODE) getButton1()
{
	static ButtonState state = BUTTON_OFF;
	uint8_t button = (P4IN >> 5) & 1;

	switch (state)
	{
		case BUTTON_OFF:     if (button == 0) state = BUTTON_PUSH; break;
		case BUTTON_PUSH:    state = BUTTON_ON; break;
		case BUTTON_ON:      if (button == 1) state = BUTTON_RELEASE; break;
		case BUTTON_RELEASE: state = BUTTON_OFF; break;
	}
	return state;
}

TASK(read_button)
{
	static int a = 1;
	if (getButton1() == BUTTON_PUSH) {
		if (a == 0) {
			P4OUT |= (1<<6);	//set red led LED1
			SetRelAlarm(blink_alarm, 100, 100);
			a = 1;
		} else {
			P4OUT &= ~(1<<6);	//reset red led LED1
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
	P1OUT ^= 1; //toggle green led 1
	TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

