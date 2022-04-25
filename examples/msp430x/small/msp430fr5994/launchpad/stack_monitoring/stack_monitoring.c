#include <stdint.h>
#include "tpl_os.h"
#include "msp430.h"

/*-----------------------------------------------------------------------------
 * Hardware init and main
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * init some I/Os of the board:
 * - red   LED1  on P1.0
 * - green LED2  on P1.1
 */
FUNC(void, OS_APPL_CODE) ioInit()
{
  /*
   * Disable the GPIO power-on default high-impedance mode
   * to activate previously configured port settings
   */
  PM5CTL0 &= ~LOCKLPM5;
  /* set GPIO P1.0 and 1.1 (red LED1 and green LED2) as an output */
  P1DIR |= 0x03;
  P1OUT &= ~(BIT0 + BIT1);
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

long factorial(int n)  
{  
  if (n == 0)  
    return 1;  
  else  
    return(n * factorial(n-1));  
}  

TASK(blink)
{
	long fact;
	int number = 3;
	fact = factorial(number);
	//P1OUT ^= 1 << 1;      /* toggle green led */
	if(tpl_check_stack_footprint(blink)){
		P1OUT |= BIT1;
	}
	else{
		P1OUT |= BIT0;
	}
	TerminateTask();
}

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
