#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"

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
}

void PostTaskHook(void)
{
    TaskType id;
    GetTaskID(&id);
}

void StartupHook(void)
{
}

void ShutdownHook(StatusType error)
{
}

DeclareTask (t2);

TASK(periodicTask)
{
    static int compte = 0;
    StatusType result;
    
    compte++;
    if (compte == 4) ShutdownOS(E_OK);
    result = ActivateTask(t2);
    result = ActivateTask(t2);
    result = ActivateTask(t2);
    
    TerminateTask();
}

TASK(t2)
{
    TerminateTask();
}

