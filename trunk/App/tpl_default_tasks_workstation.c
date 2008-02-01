#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"


#define _XOPEN_SOURCE 500
#include <unistd.h>

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
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
    StatusType result;
    
    compte++;
    printf("periodicTask (%d)\n", compte);
    fflush(stdout);
    if (compte == 4) ShutdownOS(E_OK);
    printf("Premier act t2\n");
    result = ActivateTask(t2);
    printf("2e act t2\n");
    result = ActivateTask(t2);
    printf("3e act t2\n");
    result = ActivateTask(t2);
    
    if (result == E_OS_ID) {
        printf("Mauvaise tache\n");
    }
    
	TerminateTask();
}

TASK(t2)
{
    printf("t2\n");
	TerminateTask();
}
