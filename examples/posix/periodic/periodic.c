#include <stdio.h>
#include "tpl_os.h"

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(one_second);

TASK(my_periodic_task)
{
  static int occurence = 0;
    
  occurence++;
  printf("Activation #%d\r\n",occurence);
    
  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(one_second);
  printf("Shutdown\r\n");
  ShutdownOS(E_OK);
  TerminateTask();
}
