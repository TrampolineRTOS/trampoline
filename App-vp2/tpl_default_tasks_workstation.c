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
    printf("Avant %d\n",id);
}

void PostTaskHook(void)
{
    TaskType id;
    GetTaskID(&id);
    printf("Apres %d\n",id);
}

void StartupHook(void)
{
    printf("Ca demarre !\n");
}

void ShutdownHook(StatusType error)
{
    printf("Au revoir et a bientot :)\n");
}

DeclareTask(bar);

TASK(bar)
{
    while(1)
    {
        printf("bar\n");
        sleep(1);
    } 
	TerminateTask();
}

ISR(foo)
{
    printf("foo\n");
}
