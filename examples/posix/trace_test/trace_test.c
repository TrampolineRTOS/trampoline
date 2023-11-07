#include "Os.h" // TODO: check this include
#include <stdio.h>

uint32 rcv_message_1 = 0;
uint32 snd_message_1 = 0;
uint32 rcv_message_2 = 0;
uint32 snd_message_2 = 0;

int main(void)
{
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

DeclareEvent(ev_1);
DeclareEvent(ev_2);

TASK(receiver_1)
{
  rcv_message_1 = 0;
  IocRead_test_ioc(&rcv_message_1);
  printf("Receiver Task 1 Reads : #%u\r\n", rcv_message_1);
  TerminateTask();
}

TASK(sender_1)
{
  snd_message_1 += 10;

  printf("sender_1 waiting for ev_1 \r\n");
  WaitEvent(ev_1);
  printf("sender_1 continue \r\n");
  ClearEvent(ev_1);

  IocWrite_test_ioc(snd_message_1);
  printf("! Sender Task 1 Sends : #%u\r\n", snd_message_1);
  TerminateTask();
}

TASK(receiver_2)
{
  IocReceive_test_ioc_2(&rcv_message_2);
  printf("Receiver Task 2 Reads : #%u\r\n", rcv_message_2);
  TerminateTask();
}

TASK(sender_2)
{
  snd_message_2 -= 10;
  IocSend_test_ioc_2(snd_message_2);
  printf("! Sender Task 2 Sends : #%u\r\n", snd_message_2);
  TerminateTask();
}
