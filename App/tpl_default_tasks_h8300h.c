#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "api_moniteur.h"

int main(void)
{
    orPxDDR (11, 0xFF) ;
    PBDR = 1;
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
/*    TaskType id;
    GetTaskID(&id);*/
}

void PostTaskHook(void)
{
/*    TaskType id;
    GetTaskID(&id);*/
}

void StartupHook(void)
{
}

void ShutdownHook(StatusType error)
{
}

TASK(maTask2)
{
	volatile long i ;
	printString (" CLEAR") ;
	PBDR = 0 ;
	for (i=0 ; i<500000 ; i++);
	ChainTask(maTask);
}

TASK(maTask)
{
	volatile long i ;
	printString (" SET") ;
	PBDR = 0xFF ;
	for (i=0 ; i<500000 ; i++);
	ChainTask(maTask2);
}
