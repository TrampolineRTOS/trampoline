#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "tpl_os.h"
#include "tpl_posixvp_irq_gen.h"

DeclareEvent(ev_new_message);
DeclareMessage(from_send);
DeclareMessage(for_receive1);
DeclareMessage(for_receive2);
DeclareMessage(always_in);
DeclareMessage(never_out);

int main(void) {
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

unsigned int xorshift() {
  /* Xorshift pseudo-rng from
   *  https://en.wikipedia.org/wiki/Xorshift */
  static unsigned int state = 0xCAFECAFE;

  state ^= state << 13;
  state ^= state >> 17;
  state ^= state << 5;

  return state;
}

TASK(send) {
  uint32_t data = xorshift();
  printf("send data: %x\r\n", data);
  SendMessage(from_send, &data);
  SendMessage(always_in, &data);
  TerminateTask();
}

TASK(receive1) {
  unsigned int data;
  ReceiveMessage(for_receive1, &data);
  printf("[1] received data: %x\r\n", data);
  ShutdownOS(E_OK);
  TerminateTask();
}

TASK(receive2) {
  uint32_t data;
  size_t loops = 0;

  while (loops < 10) {
    WaitEvent(ev_new_message);
    ClearEvent(ev_new_message);
    ReceiveMessage(for_receive2, &data);
    printf("[2] received data: %x\r\n", data);
    loops = loops + 1;
  }
  ShutdownOS(E_OK);
  TerminateTask();
}

TASK(dummy) {
  uint32_t data;

  ReceiveMessage(never_out, &data);
  printf("dummy: %x\r\n", data);
  TerminateTask();
}
