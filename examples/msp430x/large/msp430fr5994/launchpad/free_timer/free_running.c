

#include "tpl_os.h"
#include "msp430.h"
#include "leds.h"


uint16_t val = 0;

#define APP_Task_free_running_START_SEC_CODE
#include "tpl_memmap.h"


FUNC(int, OS_APPL_CODE) main(void)
{
	ledInit();

	// Setup free running timer
	TA0CCTL0 = CCIE;
	TA0CTL = TASSEL__ACLK | MC__CONTINOUS | TACLR | TAIE;
    tpl_serial_begin(SERIAL_TX_MODE_BLOCK);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(free_running)
{
    __bic_SR_register(GIE);
    uint32_t start = ((uint32_t)val<<16) | TA0R;
    __bis_SR_register(GIE);

	ledToggle(LED1);

    __bic_SR_register(GIE);
    uint32_t stop = ((uint32_t)val<<16) | TA0R;
    __bis_SR_register(GIE);

    uint32_t result = stop - start;
    tpl_serial_print_int(result,0);
    tpl_serial_print_string("\r\n");
	TerminateTask();
}

#define APP_Task_free_running_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_timerA_START_SEC_CODE
#include "tpl_memmap.h"

ISR(timerA)
{
	val++;
}

#define APP_ISR_timerA_STOP_SEC_CODE
#include "tpl_memmap.h"