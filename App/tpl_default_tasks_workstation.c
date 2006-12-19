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
    
    SetRelAlarm(alr1,10,0);
    SetRelAlarm(alr2,20,0);
    /*SetRelAlarm(alr4,10,0);*/
    
    compte++;
    printf("toto (%d)\n", compte);
    fflush(stdout);
    for (i=0; i<100000000; i++);
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
