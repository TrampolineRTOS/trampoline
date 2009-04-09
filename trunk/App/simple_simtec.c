#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"

#define TRACE(val) flags[count++] = val

int flags[10] = {0};
int count = 0;

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void ErrorHook(StatusType error)
{
}

void PreTaskHook(void)
{
/* FIXME */
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

void trap_func(void)
{

}

TASK(t4)
{
  TRACE(6);
	trap_func ();
	TerminateTask ();
	trap_func ();
}

ISR(it2)
{
  TRACE(5);
  trap_func ();
  ActivateTask (t4);
  TRACE(5);
  trap_func ();
  TerminateISR2 ();
  trap_func ();
}

ISR(it1)
{
  TRACE(4);
  trap_func ();
  TerminateISR2 ();
  trap_func ();
}

TASK(t3)
{
  TRACE(3);
	trap_func ();
	TerminateTask ();
	trap_func ();
}

TASK(t2)
{
  TRACE(2);
	trap_func ();
	ActivateTask (t3);
	trap_func ();
  TRACE(2);
	TerminateTask ();
	trap_func ();
}

TASK(t1)
{
  TRACE(1);
	trap_func ();
	ActivateTask (t2);
	trap_func ();
  TRACE(1);
  TerminateTask();
	trap_func ();
}


