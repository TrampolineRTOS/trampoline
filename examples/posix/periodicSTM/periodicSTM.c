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
  tpl_screen_display_service("Coucou !");
  tpl_stm_begin_read_tx_service();
    
  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(one_second);
  TerminateTask();
}


