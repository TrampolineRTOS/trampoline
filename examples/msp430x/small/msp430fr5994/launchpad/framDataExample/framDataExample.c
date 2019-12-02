#include "tpl_os.h"
#include "msp430.h"
#include <stdint.h>
#include "tpl_clocks.h"


#define APP_Task_serial_TX_START_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"
VAR(uint32_t,OS_VAR) dataSRAM = 100;
#define APP_Task_serial_TX_STOP_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"

#define APP_Task_serial_TX_START_SEC_VAR_NON_VOLATILE_32BIT
#include "tpl_memmap.h"
VAR(uint32_t,OS_VAR) dataFRAM = 100;
#define APP_Task_serial_TX_STOP_SEC_VAR_NON_VOLATILE_32BIT
#include "tpl_memmap.h"


#define APP_Task_serial_TX_START_SEC_CODE
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

TASK(serial_TX)
{
	tpl_serial_print_string("data in SRAM :");
	tpl_serial_print_int(dataSRAM,0);
	tpl_serial_print_string("\r\n");

	tpl_serial_print_string("data in FRAM :");
	tpl_serial_print_int(dataFRAM,0);
	tpl_serial_print_string("\r\n");

	dataSRAM++;
	dataFRAM++;
	TerminateTask();
}

#define APP_Task_serial_TX_STOP_SEC_CODE
#include "tpl_memmap.h"
