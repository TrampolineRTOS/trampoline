#include "tpl_os.h"
#include "msp430.h"
#include <stdint.h>
#include "tpl_clocks.h"

#define APP_COMMON_START_SEC_CODE
#include "tpl_memmap.h"

/*----------------------------------------------------------------------------*/
/* io_init                                                                    */
/*----------------------------------------------------------------------------*/
/*
 * init some I/Os of the board:
 * - red   LED1  on P1.0
 * - green LED2  on P1.1
 */
FUNC(void, OS_APPL_CODE) io_init()
{
  /*
   * Disable the GPIO power-on default high-impedance mode
   * to activate previously configured port settings
   */
  PM5CTL0 &= ~LOCKLPM5;

  /* set GPIO P1.0 and 1.1 (red LED1 and green LED2) as an output */
  P1DIR |= 0x03;
  P1OUT &= ~1; /* red led off */
  P1OUT &= ~2; /* green led off */

  /* set GPIO P5.5 (button S2) as an input, with internal pull-up */
  P5DIR &= ~(1<<5); /* input                                      */
  P5REN |= 1<<5;    /* pull-up/down resistor enable               */
  P5OUT |= 1<<5;    /* pull-up                                    */
  P5IES &= ~(0<<5); /* low to high interrupt edge selection       */
  //  P5IE  |= 1<<5;    /* interrupt enabled for the button           */
  
  //NOTE: button S1 is defined in the OS to switch from 
  //cold/hot start just after the reset

  tpl_serial_begin(SERIAL_TX_MODE_BLOCK);
  __bis_SR_register(GIE);
}

/*----------------------------------------------------------------------------*/
/* main function                                                              */
/*----------------------------------------------------------------------------*/
FUNC(int, OS_APPL_CODE) main(void)
{
  io_init();
  tpl_serial_print_string("main\n");
  tpl_serial_tx_fifo_flush();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

/*----------------------------------------------------------------------------*/
/* function called for a restart                                              */
/* it initializes peripherals                                                 */
/*----------------------------------------------------------------------------*/
FUNC(int, OS_APPL_CODE) restart_main(void)
{
  io_init();
  // P1OUT |= 1;   /* light on red led */
  tpl_serial_print_string("restart_main\n");
  tpl_serial_tx_fifo_flush();
  RestartOS();
  return 0;
}

#define APP_COMMON_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_serial_TX_START_SEC_CODE
#include "tpl_memmap.h"
/*----------------------------------------------------------------------------*/
/* TASK serial_TX                                                             */
/*----------------------------------------------------------------------------*/
TASK(task_serial_TX)
{
  //	tpl_serial_print_string("data in SRAM :");
  //	tpl_serial_print_int(dataSRAM,0);
  //	tpl_serial_print_string("\r\n");

  //	tpl_serial_print_string("data in FRAM :");
  //	tpl_serial_print_int(dataFRAM,0);
  //	tpl_serial_print_string("\r\n");

  //	dataSRAM++;
  //	dataFRAM++;
	TerminateTask();
}
#define APP_Task_task_serial_TX_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_check_button_START_SEC_CODE
#include "tpl_memmap.h"
/*----------------------------------------------------------------------------*/
/* TASK check button S2                                                       */
/*----------------------------------------------------------------------------*/
TASK(task_check_button)
{
  if(((P5IN >> 5) & 1) == 0) { //button S2 pushed ?
    tpl_serial_print_string("\r\n");
    tpl_serial_print_string("Hibernate");
    Hibernate();
  }
  TerminateTask();
}
#define APP_Task_task_check_button_STOP_SEC_CODE
#include "tpl_memmap.h"

/*----------------------------------------------------------------------------*/
/* TASK fibo                                                                  */
/*----------------------------------------------------------------------------*/
#define APP_Task_task_fibo_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_fibo)
{
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
  } else {
    /* compute fibo */
    l_temp = l_value_ind_0 + l_value_ind_1;
    l_value_ind_0 = l_value_ind_1;
    l_value_ind_1 = l_temp;
  }
	TerminateTask();
}
#define APP_Task_task_serial_TX_STOP_SEC_CODE
#include "tpl_memmap.h"

// #define APP_ISR_rtc_check_START_SEC_CODE
// #include "tpl_memmap.h"

// ISR(rtc_check) {
//   P1OUT ^= BIT0;
// }
// #define APP_ISR_rtc_check_STOP_SEC_CODE
// #include "tpl_memmap.h"