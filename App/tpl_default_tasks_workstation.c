#include "../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include <stdio.h>

#define _XOPEN_SOURCE 500
#include <unistd.h>

void InitApp(void)
{
}

void damned(void)
{
}

void ErrorHook(StatusType error)
{
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

TASK(titi)
{
    printf("titi\n");
    ActivateTask(toto);
    TerminateTask();
}

TASK(toto)
{
    static int compte = 0;
    int i;
    
    compte++;
    printf("toto\n");
    fflush(stdout);
    for (i=0; i<10000000; i++);
    ActivateTask(tata);
	printf("toto2\n");
	fflush(stdout);
    if (compte < 30) {
        ChainTask(toto);
    }
    else {
        ShutdownOS(E_OK);
    }
}

TASK(tata)
{
    printf("tata\n");
    TerminateTask();
}

ISR2(trap_SIGUSR1) {
    printf("catch\n");
    TerminateISR2();
}
