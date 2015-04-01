#include <stdio.h>
#include "tpl_os.h"

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(one_second);

DeclareObject(my_object1);

TASK(my_periodic_task)
{
  static int occurence = 0;
  int a=2; 
    
  occurence++;
  printf("Activation #%d\n",occurence);
  ScreenDisplay("Coucou !");
  STMBeginReadTx();
	STMOpenReadObject(my_object1, &a);
    
  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(one_second);
  TerminateTask();
}


