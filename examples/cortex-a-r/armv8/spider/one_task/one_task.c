#include <stdio.h>
#include "tpl_os.h"

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(my_only_task)
{
	TerminateTask();
}
