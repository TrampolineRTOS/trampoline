#include <stdio.h>
#include "../os/tpl_os.h"
#include "tpl_app_objects.h"


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

TASK(periodicTask)
{
    static int compte = 0;
    int i;
    
    compte++;
    printf("toto (%d)\n", compte);
    fflush(stdout);
    if (compte == 30) ShutdownOS(E_OK);
	TerminateTask();
}

ISR2(trap_SIGUSR1) {
    printf("catch\n");
    TerminateISR2();
}
