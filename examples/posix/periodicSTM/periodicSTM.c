#include <stdio.h>
#include "tpl_os.h"

int g_a=2; 

DeclareObject(my_object1);

int main(void)
{
    STMObjectLinkedData(my_object1, &g_a);
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(one_second);




TASK(my_periodic_task)
{
  static int occurence = 0;
  int b;
  occurence++;
  printf("Activation #%d\n",occurence);
  ScreenDisplay("Coucou !");
  STMBeginReadTx();
	STMOpenReadObject(my_object1, &b);
    	printf("Après STMOpenReadObject, b vaut %d\n\n", b);
  g_a++;
  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(one_second);
  TerminateTask();
}


