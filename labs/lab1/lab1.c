#include <stdio.h>
#include "tpl_os.h"


#define _XOPEN_SOURCE 500
#include <unistd.h>

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void PreTaskHook(void)
{
    TaskType id;
    GetTaskID(&id);
    printf("Before %d\n",id);
}

void PostTaskHook(void)
{
    TaskType id;
    GetTaskID(&id);
    printf("After %d\n",id);
}

void StartupHook(void)
{
    printf("Starting !\n");
}

void ShutdownHook(StatusType error)
{
    printf("Bye bye :)\n");
}

TASK(a_task)
{
    TaskType id;
    GetTaskID(&id);
    
    printf("I am a task, my id is %d\n",id);

	TerminateTask();
}
