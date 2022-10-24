#include "tpl_os.h"
#include "msp430.h"
#include <stdint.h>

#define APP_COMMON_START_SEC_CODE
#include "tpl_memmap.h"


FUNC(void, OS_APPL_CODE) io_init()
{
	// Disable the GPIO power-on default high-impedance mode
	// to activate previously configured port settings
	PM5CTL0 &= ~LOCKLPM5;
  	//set GPIO P1.0 (LED1) as an output
	P1DIR |= BIT0 + BIT1;
    P1OUT &= ~(BIT0 + BIT1);

    tpl_serial_begin(SERIAL_TX_MODE_BLOCK);
    __bis_SR_register(GIE);
}
FUNC(int, OS_APPL_CODE) main(void)
{
    io_init();
    tpl_serial_print_string("main\n");
    tpl_serial_tx_fifo_flush();
	StartOSSequence(OSDEFAULTAPPMODE);
	return 0;
}

FUNC(int, OS_APPL_CODE) restart_main(void)
{
    io_init();
    tpl_serial_print_string("restart_main\n");
    tpl_serial_tx_fifo_flush();
    RestartOS();
    return 0;
}
#define APP_COMMON_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_blink_red_START_SEC_CODE
#include "tpl_memmap.h"

TASK(blink_red)
{
	P1OUT ^= BIT0; //toggle GPIO P1.0 (LED1)
	TerminateTaskSequence();
}

#define APP_Task_blink_red_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_blink_green_START_SEC_CODE
#include "tpl_memmap.h"

TASK(blink_green)
{
	P1OUT ^= BIT1; //toggle GPIO P1.0 (LED1)
	TerminateTaskSequence();
}

#define APP_Task_blink_green_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_fibo_START_SEC_CODE
#include "tpl_memmap.h"

TASK(fibo) {
    // TaskType runningTaskID ;
    // GetTaskID(&runningTaskID);
    // tpl_serial_print_string("fibo: ");
    // tpl_serial_print_int(runningTaskID, 0);
    // tpl_serial_print_string("\n");

    static uint16 l_value_ind_0 = 0;
    static uint16 l_value_ind_1 = 1;
    uint16 l_temp;

    /* Print last value of fibo */
    tpl_serial_print_string("fibo :");
    tpl_serial_print_int(l_value_ind_0,0);
    tpl_serial_print_string("\r\n");

    /* Compute next value of fibo */
    if (l_value_ind_0 > 28000) {
        /* No overflow, restart fibo */
        l_value_ind_0 = 0;
        l_value_ind_1 = 1;
    } 
    else {
        /* compute fibo */
        l_temp = l_value_ind_0 + l_value_ind_1;
        l_value_ind_0 = l_value_ind_1;
        l_value_ind_1 = l_temp;
    }
  TerminateTaskSequence();
}

#define APP_Task_fibo_STOP_SEC_CODE
#include "tpl_memmap.h"
