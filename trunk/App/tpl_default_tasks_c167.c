#include "../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "tpl_os_wrappers.h"
#include <stdio.h>

#include <C167CS.H>

sbit LED=P7^0;
sbit LED1=P7^1;

void InitApp(void)
{
	DP7 |= 0x0F;
}

TASK(tick)
{
	LED = !LED;
    TerminateTask();
}
