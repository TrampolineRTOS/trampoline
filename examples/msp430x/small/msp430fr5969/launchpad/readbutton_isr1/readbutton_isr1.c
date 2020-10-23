#include <stdint.h>
#include "tpl_os.h"
#include "msp430.h"

/*-----------------------------------------------------------------------------
 * Hardware init and main
 */
#define OS_START_SEC_CODE
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
  P4IES |= 1<<5;    //high to low interrupt edge selection
  P4IE  |= 1<<5;    //interrupt enabled for the button
}

FUNC(int, OS_APPL_CODE) main(void)
{
	ioInit();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * task blink
 */
#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

TASK(blink)
{
	P1OUT ^= 1; // toggle green led
	TerminateTask();
}

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * ISR button
 */
#define APP_ISR_buttonS1_START_SEC_CODE
#include "tpl_memmap.h"

ISR(buttonS1)
{
	P4OUT ^= 1 << 6; //toggle red led
}

#define APP_ISR_buttonS1_STOP_SEC_CODE
#include "tpl_memmap.h"
