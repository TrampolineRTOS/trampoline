#include <stdio.h>
#include "tpl_os.h"

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(one_second);

DeclareObject(my_object1);
DeclareObject(my_object2);

TASK(my_periodic_task)
{
  static int occurence = 0;
  int g_a_read;
  int g_b_write=15;
  occurence++;
  printf("Activation #%d\n",occurence);
  ScreenDisplay("Coucou !");
  printf("g_a=%d\n", g_a);
  //STMBeginReadTx();
	//STMOpenReadObject(my_object1, &g_a_read);
    	//printf("Après STMOpenReadObject, g_a_read vaut %d\n\n", g_a_read);
  STMOpenWriteObject(my_object2, &g_b_write);
  //g_a_read++;
  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(one_second);
  TerminateTask();
}


