#include "../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "tpl_os_wrappers.h"
#include <stdio.h>

#include <C167CS.H>

sbit LED=P7^0;
sbit LED1=P7^1;

void InitApp(void)
{
}

TASK(tick)
{
	LED = !LED;
    TerminateTask();
}

void tpl_init_tick_timer();
TASK(init)
{
	tpl_init_tick_timer();
	TerminateTask();
}

