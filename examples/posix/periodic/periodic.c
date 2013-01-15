#include <stdio.h>
#include "tpl_os.h"

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(one_second);

DeclareTask(stop);

TASK(my_periodic_task)
{
    static int occurence = 0;
    
    occurence++;
    printf("Activation #%d\n",occurence);
    
    printf("error=%d\n",ChainTask(stop));
}

TASK(stop)
{
  CancelAlarm(one_second);
  TerminateTask();
}