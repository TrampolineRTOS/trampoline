#include "tpl_os.h"
#include "msp430.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	P4DIR |= 1<<6; //P4.6 as output (red led)
	P1DIR |= 1<<1; //P1.0 as output (green led)
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	P4OUT ^= 1<<6; //toggle led.
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
FUNC(tpl_bool, OS_CODE) __attribute__((interrupt(TIMER3_A0_VECTOR))) tpl_tick_SystemCounter(void)
{
//  tpl_counter_tick(&SystemCounter_counter_desc);
//
//  if (tpl_kern.need_schedule == TRUE)
//  {
//    tpl_schedule_from_running();
//  }
  return TRUE;
}

