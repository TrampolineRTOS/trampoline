#include "Os.h"
#include "tpl_os_generated_configuration.h"
#include <stdio.h>
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

    GetTaskID (&id);
    printf("PreTaskHook (newly active task is #%d)\n",id);
}

void PostTaskHook(void)
{
    TaskType id;

    GetTaskID (&id);
    printf("PostTaskHook (last active task was #%d)\n", id);
}

void StartupHook(void)
{
    printf("Ca demarre !\n");
}

void ShutdownHook(StatusType error)
{
    printf("Au revoir et a bientot :)\n");
}

extern ProtectionReturnType ProtectionHook (StatusType FatalError)
{
  TaskType id;
  
  switch (FatalError)
  {
    case E_OS_PROTECTION_TIME:
      printf ("**Protection hook (E_OS_PROTECTION_TIME)");
      break;
    case E_OS_PROTECTION_LOCKED:
      printf ("**Protection hook (E_OS_PROTECTION_LOCKED)");
      break;
    case E_OS_STACKFAULT:
      printf ("**Protection hook (E_OS_STACKFAULT)");
      break;
    default:
      printf ("**Protection hook (unknown error code)");
      break; 
  }
  
  GetTaskID (&id);
  printf (" with task %d\n", id);
  
  return PRO_KILLTASKISR;  
}

TASK(r1_squatter)
{
    volatile long bidule1, bidule2;
    int i;
  
    printf ("starting r1squatter\n");
    for (i = 0 ; i < 10 ; i++)
    {
			printf ("GETR squatter\n");
    fflush(stdout);
      GetResource (r1);
      bidule1 = 50 * 1000;
      while (bidule1--)
      {
       
        bidule2 = 1 << (i * 2);
        while (bidule2--);
         
      }
      ReleaseResource(r1);
			printf ("RELEASER squatter\n");
    fflush(stdout);
    }
    
    TerminateTask ();
}

TASK(periodicTask)
{
    static int compte = 0;
    volatile long bidule1, bidule2;
    TaskType id;
		StatusType error;
    
    compte++;
    printf("periodicTask (activation %d)\n", compte);
    GetTaskID (&id);
    printf ("periodicTask is #%d\n", id);
    fflush(stdout);
    if (compte == 6)
      ShutdownOS(E_OK);
  
    printf ("TRAVAIL EN COURS...");
    fflush(stdout);
    bidule1 = 50 * 1000;
    GetResource (r1);
    while (bidule1--)
    {
     
      bidule2 = 0x1 << (3 * compte);
      while (bidule2--);
       
    }
    ReleaseResource(r1);
    printf ("TERMINE\n");
    
  
  error = TerminateTask();

  printf ("error terminate = %d\n", error);
  printf ("should never come here\n");
}
