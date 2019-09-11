#include "tpl_os.h"
#include "msp430.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	// Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;
	P1DIR = 0x01;
	P1OUT = 0x01;
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	P1OUT ^= 0x01; //toggle led.
	//ActivateTask(task_4);
	//ChainTask(task_4);
	//ActivateTask(task_3);
	TerminateTask();
}

TASK(task_2)
{
	P1OUT ^= 1<<1; //toggle led
	//ChainTask(task_4);
	//ActivateTask(task_4);
	TerminateTask();
}

TASK(task_3)
{
	P4OUT ^= 1<<6;
	ActivateTask(task_4);
	TerminateTask();
}

TASK(task_4)
{
	P1OUT ^= 1<<1;
	TerminateTask();
}



#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

//extern VAR(tpl_counter, OS_VAR) SystemCounter_counter_desc;
//extern FUNC(tpl_bool, OS_CODE) __attribute__((interrupt(TIMER3_A0_VECTOR))) tpl_tick_TIMER3_A0_VECTOR(void);
/*{
  tpl_counter_tick(&SystemCounter_counter_desc);

  if (tpl_kern.need_schedule == TRUE)
  {
    tpl_schedule_from_running();
  }
  return TRUE;
}*/

