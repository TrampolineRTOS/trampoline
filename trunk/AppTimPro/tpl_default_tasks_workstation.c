#include <stdio.h>
#include "../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

#include "tpl_os_kernel.h"


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

void mon_callback ()
{
  printf ("WATCHDOG !!!\n");
  fflush (stdout);
}

TASK(periodicTask)
{
    static int compte = 0;
    StatusType result;
    TaskType my_id;
    volatile long bidule1, bidule2;
    
    compte++;
    printf("periodicTask (%d)\n", compte);
    fflush(stdout);
    if (compte == 10) 
      ShutdownOS(E_OK);
  
  
    printf ("TRAVAIL EN COURS...");
    bidule1 = 50 * 1000;
    while (bidule1--)
    {
      bidule2 = 10000;
      while (bidule2--); 
    }
    printf ("TERMINE\n");
    
  
	TerminateTask();
}

