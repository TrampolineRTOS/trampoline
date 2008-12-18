#include <stdio.h>
#include "tpl_os.h"
#include "tpl_com_internal.h"

#define _XOPEN_SOURCE 500
#include <unistd.h>

#ifdef WITH_UNITTEST
#include "tpl_os_kernel.h"
extern FUNC(void, OS_CODE) printrl(P2VAR(char, OS_APPL_DATA, AUTOMATIC) msg);
#endif

DeclareTask(t2);
DeclareTask(t3);
DeclareTask(t4);
DeclareTask(t5);
DeclareTask(t6);
DeclareTask(t7);
DeclareTask(t8);
DeclareTask(t9);
DeclareTask(t10);
DeclareTask(t11);
DeclareTask(t12);
DeclareTask(t13);
DeclareTask(t14);
DeclareTask(t15);
DeclareTask(periodicTask);

int main(void)
{
#ifdef WITH_UNITTEST
  printrl("Doit etre vide");
  tpl_put_new_proc(t2);
  tpl_put_new_proc(t4);
  tpl_put_new_proc(t8);
  printrl("Ajout de 3 taches");
  tpl_put_new_proc(t9);
  tpl_put_new_proc(t10);
  tpl_put_new_proc(t4);
  tpl_put_new_proc(t4);
  tpl_put_new_proc(t9);
  tpl_put_new_proc(t10);
  printrl("Ajout de 5 autres taches");
  tpl_remove_proc(t4);
  printrl("t4 a ete enleve");
  tpl_remove_proc(t9);
  printrl("t9 a ete enleve");
#else
  StartOS(OSDEFAULTAPPMODE);
#endif
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

DeclareTask(t2);
DeclareEvent(evt1);
DeclareResource(r1);
DeclareAlarm(alarm1s);
DeclareMessage(sm);
DeclareMessage(rm);

TASK(periodicTask)
{
  static u32 compte = 0;
  StatusType result;
  
  compte++;
  printf("periodicTask (%d)\n", compte);
  fflush(stdout);
  if (compte == 4) ShutdownOS(E_OK);
  printf("Premier act t2\n");
  GetResource(r1);
  result = ActivateTask(t2);
  ReleaseResource(r1);
  printf("2e act t2\n");
  result = ActivateTask(t2);
  printf("3e act t2\n");
  result = ActivateTask(t2);
  
  SetEvent(t2,evt1);
  SendMessage(sm,&compte);
  
  if (result == E_OS_ID)
  {
    printf("Mauvaise tache\n");
  }
  
  SetRelAlarm(alarm1s,10,0);
  
	TerminateTask();
}

TASK(t2)
{
  printf("t2\n");
	TerminateTask();
}

TASK(t3)
{
  printf("t3\n");
	TerminateTask();
}

TASK(t4)
{
  printf("t4\n");
	TerminateTask();
}

TASK(t5)
{
  printf("t5\n");
	TerminateTask();
}

TASK(t6)
{
  printf("t6\n");
	TerminateTask();
}

TASK(t7)
{
  printf("t7\n");
	TerminateTask();
}

TASK(t8)
{
  printf("t8\n");
	TerminateTask();
}

TASK(t9)
{
  printf("t9\n");
	TerminateTask();
}

TASK(t10)
{
  printf("t10\n");
	TerminateTask();
}

TASK(t11)
{
  printf("t11\n");
	TerminateTask();
}

TASK(t12)
{
  printf("t12\n");
	TerminateTask();
}

TASK(t13)
{
  printf("t13\n");
	TerminateTask();
}

TASK(t14)
{
  printf("t14\n");
	TerminateTask();
}

TASK(t15)
{
  printf("t15\n");
	TerminateTask();
}
