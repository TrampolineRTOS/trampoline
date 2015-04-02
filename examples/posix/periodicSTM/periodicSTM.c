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
  int b;
  occurence++;
  printf("Activation #%d\n",occurence);
  ScreenDisplay("Coucou !");
  printf("g_a=%d\n", g_a);
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


