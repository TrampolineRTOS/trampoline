#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_task_kernel.h"

#define _XOPEN_SOURCE 500
#include <unistd.h>

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void displayIdAndCurrentPriority()
{
	TaskType id;
	GetTaskID(&id);
	if (id >= 0)
	{
		tpl_priority prio = tpl_dyn_proc_table[id]->priority;
		printf("Id=%d Prio=%d\n",id,prio); 
	}
}

