#include "tpl_os.h"
#include "mcp23s17.h"
#include "pinAccess.h"
#include "tft.h"
#include "serial.h"


static  uint32 x=123456789, y=362436069, z=521288629;

uint32 xorshf96(void) {         
  uint32 t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}



FUNC(int, OS_APPL_CODE) main(void)
{

    initCoroBoard();
    ioExt.digitalWrite(mcp23s17::PORTA, 1, 1);
	tpl_serial_begin();
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareMessage(outMessage);
DeclareMessage(inMessage);
DeclareMessage(inMessage_emergency);
DeclareMessage(inMessage_NormalOperation);
DeclareEvent(Eve_Normal);
TASK(sender)
{
  ioExt.digitalWrite(mcp23s17::PORTA, 6, 1);
  static int counter = 0;
  counter++;
  // uint32 data_sent= (uint32)counter;
  uint32 data_sent= (uint32)xorshf96()%100;
  SendMessage(outMessage,&data_sent);
  Tft.setTextCursor(3,2);
  Tft.eraseText(20);
  Tft.print("data sent ");
  Tft.print(counter);
  TerminateTask();
}


TASK(receiver){
  ioExt.digitalWrite(mcp23s17::PORTA, 5, 1);
  uint32 data_rec;
  ReceiveMessage(inMessage,&data_rec);
  Tft.setTextCursor(3,3);
  Tft.eraseText(20);
  Tft.print("data receive ");
  Tft.print(data_rec);
  data_rec = data_rec+1;
  TerminateTask();
}



TASK(emergency){
  uint32 data_rec;
  ReceiveMessage(inMessage_emergency,&data_rec);
  Tft.setTextCursor(3,4);
  Tft.eraseText(20);
  Tft.print("emergency rcv:");
  Tft.print(data_rec);
  data_rec = data_rec+1;
  TerminateTask();
}

TASK(NormalOperation){
  uint32 data_rec;
  while (1)
  {
    Tft.setTextCursor(3,5);
    Tft.eraseText(20);
    Tft.print("Normal op wait");
    WaitEvent(Eve_Normal);
    ClearEvent(Eve_Normal);
    ReceiveMessage(inMessage_NormalOperation,&data_rec);
    Tft.setTextCursor(3,6);
    Tft.eraseText(20);
    Tft.print("Normal op rcv:");
    Tft.print(data_rec);
    data_rec = data_rec+1;

  }
  TerminateTask();
}

void itUsart();
ISR(usart)
{
	itUsart();
}





