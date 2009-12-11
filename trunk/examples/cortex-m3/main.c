#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"

//ISR(boutonISR)
//{
//}

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
unsigned char val = 0;

TASK(secondTask)
{
	val++;
	TerminateTask();
}

TASK(startTask)
{
	val++;
	ChainTask(secondTask);
}

//TASK(periodicTask)
//{
//	TerminateTask();
//}

