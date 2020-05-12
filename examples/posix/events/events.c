#include <stdio.h>
#include <stdbool.h>
#include "tpl_os.h"

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(one_second);
DeclareEvent(ev_act);
DeclareEvent(ev_stop);

TASK(my_periodic_task)
{
  int occurence = 0;
  EventMaskType received;
  bool out = false;

  while(!out)
  {
    WaitEvent(ev_act | ev_stop);
    GetEvent(my_periodic_task, &received);
    if (received & ev_act) {
      ClearEvent(ev_act);
      occurence++;
      printf("Activation #%d\r\n",occurence);
    }
    if (received & ev_stop) {
      ClearEvent(ev_stop);
      out = true;
    }
  }
  ShutdownOS(E_OK);
  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(one_second);
  SetEvent(my_periodic_task, ev_stop);
  TerminateTask();
}
