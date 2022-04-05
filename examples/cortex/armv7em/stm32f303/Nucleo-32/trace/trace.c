#include "tpl_os.h"
#include "pinAccess.h"

FUNC(int, OS_APPL_CODE) main(void)
{
  pinMode(GPIOB,3,OUTPUT); //led 1 is PB3
  pinMode(GPIOB,0,OUTPUT); //led 2 is PB0 (D3)
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

/* periodic task, each 100ms */
TASK(taskPeriodicSend)
{
  for(volatile uint32_t i = 0; i<100000;i++);
  static uint32 data = 0;
  data = (data+1)%5;
  GetResource(resGPIO);
  digitalToggle(GPIOB,3);
  ReleaseResource(resGPIO);
  //msg will be received by msgDataReceive1 and msgDataReceive2
  //associated to SetEvent for both
  SendMessage(msgDataSend,&data);
  TerminateTask();
}

TASK(taskReceiver1)
{
  uint32 incomingData;
  while(1)
  {
	  WaitEvent(evMsgIn1);
	  ClearEvent(evMsgIn1);
	  //job stuff
	  ReceiveMessage(msgDataReceive1,&incomingData);
      for(volatile uint32_t i = 0; i<200000;i++);
      GetResource(resGPIO);
      digitalWrite(GPIOB,0,0);
      ReleaseResource(resGPIO);
  }
  TerminateTask();
}

TASK(taskReceiver2)
{
  uint32 incomingData;
  while(1)
  {
	  WaitEvent(evMsgIn2);
	  ClearEvent(evMsgIn2);
	  //job stuff
	  ReceiveMessage(msgDataReceive2,&incomingData);
      GetResource(resGPIO);
      for(volatile uint32_t i = 0; i<300000;i++);
      digitalWrite(GPIOB,0,1);
      ReleaseResource(resGPIO);
  }
  TerminateTask();
}

//tmp TODO: add ISR into library.
void itUsart();
ISR(usart)
{
	itUsart();
}

