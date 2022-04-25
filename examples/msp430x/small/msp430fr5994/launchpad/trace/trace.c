#include "tpl_os.h"
#include "msp430.h"

#define APP_Task_taskPeriodicSend_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
  // Disable the GPIO power-on default high-impedance mode
  // to activate previously configured port settings
  PM5CTL0 &= ~LOCKLPM5;
  //set GPIO P1.0 (LED1) as an output
  //set GPIO P1.1 (LED2) as an output
  P1DIR = 0x03;
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}



/* periodic task, each 100ms */
TASK(taskPeriodicSend)
{
  static uint32 data = 0;
  data = (data+1)%5;
  GetResource(resGPIO);
  P1OUT ^= 0x01; //toggle GPIO P1.0 (Led1)
  ReleaseResource(resGPIO);
  //msg will be received by msgDataReceive1 and msgDataReceive2
  //associated to SetEvent for both
  SendMessage(msgDataSend,&data);
  TerminateTask();
}

#define APP_Task_taskPeriodicSend_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_taskReceiver1_START_SEC_CODE
#include "tpl_memmap.h"

TASK(taskReceiver1)
{
  uint32 incomingData;
  while(1)
  {
	  WaitEvent(evMsgIn1);
	  ClearEvent(evMsgIn1);
	  //job stuff
	  ReceiveMessage(msgDataReceive1,&incomingData);
      GetResource(resGPIO);
      P1OUT &= ~0x02; //clear LED2
      ReleaseResource(resGPIO);
  }
  TerminateTask();
}

#define APP_Task_taskReceiver1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_taskReceiver2_START_SEC_CODE
#include "tpl_memmap.h"
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
      P1OUT |= 0x02; //set LED2
      ReleaseResource(resGPIO);
  }
  TerminateTask();
}

#define APP_Task_taskReceiver2_STOP_SEC_CODE
#include "tpl_memmap.h"
