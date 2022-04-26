#include "tpl_os.h"
#include "msp430.h"
#include <stdint.h>
#include "tpl_clocks.h"

/* Warning, task data outside of POWER_ON_INIT section won't be initialized */
#define APP_Task_serial_TX_START_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"
VAR(uint32_t,AUTOMATIC) dataSRAM = 100;
#define APP_Task_serial_TX_STOP_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"

/* At this date, NON_VOLATILE data is initialized only when flashing firmware */
#define APP_Task_serial_TX_START_SEC_VAR_NON_VOLATILE_32BIT
#include "tpl_memmap.h"
VAR(uint32_t,AUTOMATIC) dataFRAM = 100;
#define APP_Task_serial_TX_STOP_SEC_VAR_NON_VOLATILE_32BIT
#include "tpl_memmap.h"


#define APP_Task_serial_TX_START_SEC_CODE
#include "tpl_memmap.h"

/* debugging... */
FUNC(void, OS_CODE) memInit(
		P2VAR(void,AUTOMATIC,OS_CONST) src,
		P2VAR(void,AUTOMATIC,OS_CONST) dst,
		  VAR(uint16_t,AUTOMATIC)      size);

void framStart()
{
    /* set GPIO P5.6 (button S1) as an input, with internal pull-up */
    P5DIR &= ~(1<<6); /* input                        */
    P5REN |= 1<<6;    /* pull-up/down resistor enable */
    P5OUT |= 1<<6;    /* pull-up                      */

    if(((P5IN >> 6) & 1) == 0) { //button pushed during startup ?
		//ok button pushed => cold start
		P1OUT |= 1;   /* set green led LED1   */
		/* Init .nvdata section */
		extern unsigned __nvdata_load_start;
		extern unsigned __nvdata_start;
		extern unsigned __nvdata_end;
		memInit(
		  &__nvdata_load_start,
		  &__nvdata_start,
		  (uint16_t)&__nvdata_end-(uint16_t)&__nvdata_start
		);
	}
}

FUNC(int, OS_APPL_CODE) main(void)
{
	// Disable the GPIO power-on default high-impedance mode
	// to activate previously configured port settings
	PM5CTL0 &= ~LOCKLPM5;
	//set GPIO P1.0 and P1.1 (LED1 and 2) as an output
	P1DIR |= 0x03;
	framStart();
	tpl_serial_begin(SERIAL_TX_MODE_SKIP);
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
