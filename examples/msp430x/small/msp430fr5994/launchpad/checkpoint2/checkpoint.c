#include "tpl_os.h"
#include "msp430.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

extern void framUpWrite8(const uint16 address, const uint8 data);
extern void framUpWrite16(const uint16 address, const uint16 data);
extern uint8 framUpRead8(const uint16 address);
extern uint16 framUpRead16(const uint16 address);
extern void saveCheckpoint(const uint16 buffer);
extern void loadCheckpoint(const uint16 buffer);

FUNC(int, OS_APPL_CODE) main(void)
{
	// Disable the GPIO power-on default high-impedance mode
	// to activate previously configured port settings
	PM5CTL0 &= ~LOCKLPM5;
  //set GPIO P1.0 (LED1) as an output
	P1DIR = 0x01;

  // Disable the GPIO power-on default high-impedance mode
	// to activate previously configured port settings
	PM5CTL0 &= ~LOCKLPM5;
  P1OUT &= ~1;   /* light off LED1 */

  /* set GPIO P5.6 (button S1) as an input, with internal pull-up */
  P5DIR &= ~(1<<6); /* input                        */
  P5REN |= 1<<6;    /* pull-up/down resistor enable */
  P5OUT |= 1<<6;    /* pull-up                      */

  /* set GPIO P5.5 (button S2) as an input, with internal pull-up */
  P5DIR &= ~(1<<5); /* input                        */
  P5REN |= 1<<5;    /* pull-up/down resistor enable */
  P5OUT |= 1<<5;    /* pull-up                      */

  if (((P5IN >> 6) & 1) == 0) { //button S1 pushed during startup ?
    framUpWrite16(0x0006, 0xdead);
    framUpWrite16(0x0004, 0xbeef);
    framUpWrite8(0x0008, 1);
    framUpWrite8(0x0009, 2);
  }
  else if (((P5IN >> 5) & 1) == 0) { //button S2 pushed during startup ?
    saveCheckpoint(0);
  }

	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	P1OUT ^= 0x05; //toggle GPIO P1.0 (Led2)
	TerminateTask();
}

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
