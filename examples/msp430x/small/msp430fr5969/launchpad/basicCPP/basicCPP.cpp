#include "tpl_os.h"
#include "msp430.h"
#include <stdint.h>
#include "tpl_clocks.h"

#define APP_Task_serial_TX_START_SEC_CODE
#include "tpl_memmap.h"

/* The purpose of this class is to test that the constructor 
 * of the instances are set properly
 * during the startup phase, bafore the main.
 * */
class basic {
	uint32_t mVal;
	public:
	basic(uint32_t val) { mVal = val;};
	uint32_t getVal() {return mVal;};
	void incVal() {mVal++;};
};

basic b1(1000);
basic b2(2000);

FUNC(int, OS_APPL_CODE) main(void)
{
	// Disable the GPIO power-on default high-impedance mode
	// to activate previously configured port settings
	PM5CTL0 &= ~LOCKLPM5;
	//set GPIO P1.0 (LED2) as an output
	P1DIR = 0x01;
	tpl_serial_begin(SERIAL_TX_MODE_BLOCK);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(serial_TX)
{
	tpl_serial_print_string("Object b1->val :");
	tpl_serial_print_int(b1.getVal(),0);
	tpl_serial_print_string("\r\n");

	tpl_serial_print_string("Object b2->val :");
	tpl_serial_print_int(b2.getVal(),0);
	tpl_serial_print_string("\r\n");

	b1.incVal();
	b2.incVal();
	TerminateTask();
}

#define APP_Task_serial_TX_STOP_SEC_CODE
#include "tpl_memmap.h"
