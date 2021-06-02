#include <stdio.h>
#include "Os.h" // TODO: check this include

uint32 rcv_message = 0;
uint32 snd_message = 0;

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(one_second);

TASK(receiver)
{
  rcv_message++;
#if IOC_UNQUEUED_COUNT > 0
  IocRead_my_ioc_one(&rcv_message);
#elif IOC_QUEUED_COUNT > 0
  IocReceive_my_ioc_one(&rcv_message);
#endif
  printf("Receiver Task Reads : #%ld\r\n", rcv_message);
  TerminateTask();
}

TASK(sender)
{
  snd_message+=10;
#if IOC_UNQUEUED_COUNT > 0
  IocWrite_my_ioc_one(snd_message);
#elif IOC_QUEUED_COUNT > 0
  IocSend_my_ioc_one(snd_message);
#endif
  printf("! Sender Task Sends : #%ld\r\n", snd_message);
  TerminateTask();
}

