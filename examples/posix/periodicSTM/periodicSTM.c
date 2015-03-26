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
  printf("Activation #%d\n",occurence);
  ScreenDisplay("Coucou !");
  STMBeginReadTx();
    
  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(one_second);
  TerminateTask();
}


