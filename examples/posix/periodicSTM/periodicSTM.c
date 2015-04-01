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
  DeclareObject(my_object1);
    
  occurence++;
  printf("Activation #%d\n",occurence);
  ScreenDisplay("Coucou !");
  STMBeginReadTx();
	STMOpenReadObject(my_object1, &a);
    	printf("Après STMOpenReadObject, a vaut %d; adresse de a=%p\n", a, &a);
  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(one_second);
  TerminateTask();
}


