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
    printf("PreTaskHook\n");
}

void PostTaskHook(void)
{
    printf("PostTaskHook\n");
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
  
    for (i = 0 ; i < 10 ; i++)
    {
      GetResource (r1);
      bidule1 = 50 * 1000;
      while (bidule1--)
      {
       
        bidule2 = 1 << (i * 2);
        while (bidule2--);
         
      }
      ReleaseResource(r1);
    }
    
    TerminateTask ();
}

TASK(periodicTask)
{
    static int compte = 0;
    volatile long bidule1, bidule2;
    
    compte++;
    printf("periodicTask (activation %d)\n", compte);
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
    
  
	TerminateTask();
  printf ("should never come here\n");
}
