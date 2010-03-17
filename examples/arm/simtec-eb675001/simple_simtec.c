#include <stdio.h>
#include "tpl_os.h"
#include "uart.h"

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

TASK(t4)
{
  TRACE(6);
  TerminateTask ();
}

ISR(it2)
{
  TRACE(5);
  ActivateTask (t4);
  TRACE(5);
  TerminateISR ();
}

ISR(it1)
{
  TRACE(4);
  TerminateISR ();
}

TASK(t3)
{
  TRACE(3);
  UART_envoyer_chaine ("T3: I begin and I will terminate\r\n");
  TerminateTask ();
  UART_envoyer_chaine ("T3: I should never have print this\r\n");
  TRACE(13);
}

TASK(t2)
{
  TRACE(2);
  UART_envoyer_chaine ("T2: I begin and activate T3\r\n");
  ActivateTask (t3);
  TRACE(4);
  UART_envoyer_chaine ("T2: I have activated T3 and I will terminate\r\n");
  TerminateTask ();
  UART_envoyer_chaine ("T2: I should never have print this\r\n");
  TRACE(12);
}

TASK(t1)
{
  UART_initialiser();
  TRACE(1);
  UART_envoyer_chaine ("T1: I begin and activate T2\r\n");
  ActivateTask (t2);
  TRACE(5);
  UART_envoyer_chaine ("T1: I have activated T2 and U will terminate\r\n");
  TerminateTask();
  UART_envoyer_chaine ("T1: I should never have print this\r\n");
  TRACE(11);
}


