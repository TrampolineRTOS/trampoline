#include "tpl_os.h"
#include "msp430.h"
#include <stdint.h>
#include "tpl_clocks.h"

#define APP_Task_serial_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	// Disable the GPIO power-on default high-impedance mode
	// to activate previously configured port settings
	PM5CTL0 &= ~LOCKLPM5;
	//set GPIO P1.0 (LED2) as an output
	P1DIR = 0x01;
	tpl_serial_begin();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(serial)
{
	tpl_serial_print_string("Hello world!\n");
	TerminateTask();
}

#define APP_Task_serial_STOP_SEC_CODE
#include "tpl_memmap.h"
