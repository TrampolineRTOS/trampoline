#include <stdio.h>
#include "Os.h"
#include "tpl_os_generated_configuration.h"

#define _XOPEN_SOURCE 500
#include <unistd.h>

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void ErrorHook(StatusType error)
{
  printf ("ERROR HOOK = %d\n", error);
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
    volatile long bidule1, bidule2;
    
    compte++;
    printf("periodicTask (activation %d)\n", compte);
    fflush(stdout);
    if (compte == 10)
      ShutdownOS(E_OK);
  
  
    printf ("TRAVAIL EN COURS...");
    fflush(stdout);
    bidule1 = 50 * 1000;
    while (bidule1--)
    {
      bidule2 = 100;
      while (bidule2--); 
    }
    printf ("TERMINE\n");
    
  
	TerminateTask();
  printf ("should never come here\n");
}

