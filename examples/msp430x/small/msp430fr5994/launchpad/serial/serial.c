#include "tpl_os.h"
#include "msp430.h"
#include <stdint.h>
#include "tpl_clocks.h"

#define APP_Task_serial_TX_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	// Disable the GPIO power-on default high-impedance mode
	// to activate previously configured port settings
	PM5CTL0 &= ~LOCKLPM5;
	//set GPIO P1.0 (LED2) as an output
	P1DIR = 0x01;
	// 2 modes:
	// * SERIAL_TX_MODE_BLOCK: active waiting loop. Get in LPM3 between characters.
 	// * SERIAL_TX_MODE_SKIP : the data is not sent. Overflow return value is set.
	tpl_serial_begin(SERIAL_TX_MODE_SKIP);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(serial_TX)
{
	tpl_serial_print_string("Test using the serial communication over USB\r\n");
	TerminateTask();
}

#define APP_Task_serial_TX_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_serial_RX_START_SEC_CODE
#include "tpl_memmap.h"

TASK(serial_RX)
{
	static uint16_t size = 0;
	if(size != tpl_serial_available())
	{
		size = tpl_serial_available();
		tpl_serial_print_string("chars in rx buffer: ");
		tpl_serial_print_int(size,0);
		tpl_serial_print_string("\r\n");

		if(size >= 10)
		{
			tpl_serial_print_string("=> ");
			while(tpl_serial_available())
				tpl_serial_putchar(tpl_serial_read());
		    tpl_serial_print_string("\r\n");
		}
	}
	TerminateTask();
}

#define APP_Task_serial_RX_STOP_SEC_CODE
#include "tpl_memmap.h"
