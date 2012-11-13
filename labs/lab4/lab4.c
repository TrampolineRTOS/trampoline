#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_task_kernel.h"

#define _XOPEN_SOURCE 500
#include <unistd.h>

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareMessage(inMessage);
DeclareMessage(outMessage);

TASK(sender)
{
  static int value = 1;
  
  printf("send: %d\n",value);
  SendMessage(outMessage,&value);
  value++;
  TerminateTask();
}

TASK(receiver)
{
  int value;
  
  ReceiveMessage(inMessage,&value);
  printf("receive: %d\n",value);
  TerminateTask();
}
