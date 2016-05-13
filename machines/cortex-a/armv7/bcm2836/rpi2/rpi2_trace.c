#include "rpi2_trace.h"

extern unsigned int GETSP_usr ( void );
extern unsigned int GETSP_irq ( void );
extern unsigned int GETR0(void);
extern unsigned int GETR1(void);
extern unsigned int GETR2(void);
extern unsigned int GETR3(void);
extern unsigned int GETR4(void);
extern unsigned int GETR5(void);
extern unsigned int GETR6(void);
extern unsigned int GETR7(void);
extern unsigned int GETR8(void);
extern unsigned int GETR9(void);
extern unsigned int GETR10(void);
extern unsigned int GETR11(void);
extern unsigned int GETR12(void);
extern unsigned int GETSP(void);
extern unsigned int GETLR(void);
extern unsigned int GETPC(void);

void trace_1(void) {
  // uart_write_string((const unsigned char*)"__TRACE__1__");
}

void trace_2(void) {
  // uart_write_string((const unsigned char*)"__TRACE__2__");
}

void trace_3(void) {
  // uart_write_string((const unsigned char*)"__TRACE__3__");
  // uart_write_string((const unsigned char*)" : tpl_action_activate_task");
}

void trace_4(const unsigned char* str) {
  // uart_write_string((const unsigned char*)"__TRACE__4__");
  // uart_write_string((const unsigned char*)" : tpl_activate_task : ");
  // uart_write_string((const unsigned char*)str);
}

void trace_5(void) {
  // uart_write_string((const unsigned char*)"__TRACE__5__");
  // uart_write_string((const unsigned char*)" : tpl_put_new_proc");
}

void trace_6(void) {
  // uart_write_string((const unsigned char*)"__TRACE__6__");
  // uart_write_string((const unsigned char*)" : tpl_schedule_from_running");
}

void trace_7(void) {
  // uart_write_string((const unsigned char*)"__TRACE__7__");
  // uart_write_string((const unsigned char*)" : tpl_preempt");
}

void trace_7_1(void) {
  // uart_write_string((const unsigned char*)"__TRACE__7_1__");
  // uart_write_string((const unsigned char*)" : tpl_preempt : preempt");
}

void trace_8(void) {
  // uart_write_string((const unsigned char*)"__TRACE__8__");
  // uart_write_string((const unsigned char*)" : tpl_start");
}

void trace_8_1(uint32 num) {
  // uart_write_string((const unsigned char*)"tpl_start : elected_id : ");
  // hexstring(num);
}

void trace_9(void) {
  // uart_write_string((const unsigned char*)"__TRACE__9__");
  // uart_write_string((const unsigned char*)" : tpl_start : new proc");
}

void trace_10(void) {
  // uart_write_string((const unsigned char*)"__TRACE__10__");
  // uart_write_string((const unsigned char*)" : tpl_init_context");
}

void trace_regs(void) {
  uint32 regs[16];
  uint32* ptr;
  uint8 index;
  ptr = &regs[0];
  __asm volatile ("mov %0, r0" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r1" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r2" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r3" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r4" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r5" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r6" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r7" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r8" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r9" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r10" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r11" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, r12" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, sp" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, lr" : "=r" (ptr) ); ptr++;
  __asm volatile ("mov %0, pc" : "=r" (ptr) );
  uart_write_string((const unsigned char*)"__TRACE__REGS______________________________");

  for (index = 0; index <= 7; index++) {
    hexstrings(regs[index]);
    if (index < 7) {
      uart_write_strings((const unsigned char*)" | ");
    }
  }
  uart_write_char((unsigned char)0x0D);
  uart_write_char((unsigned char)0x0A);
  for (index = 8; index <= 15; index++) {
    hexstrings(regs[index]);
    if (index < 15) {
      uart_write_strings((const unsigned char*)" | ");
    }
  }
  uart_write_char((unsigned char)0x0D);
  uart_write_char((unsigned char)0x0A);

  uart_write_string((const unsigned char*)"___________________________________________");
}

void trace_context(void) {
  uart_write_string((const unsigned char*)"__TRACE__CONTEXT___________________________");
  uart_write_string((const unsigned char*)"");
  uart_write_string((const unsigned char*)"___________________________________________");
}

void trace_idle(void) {
  uart_write_string((const unsigned char*)"Tache IDLE");
}

void trace_in(void) {
  uart_write_string((const unsigned char*)"]================== IN ==================[");
}

void trace_out(void) {
  uart_write_string((const unsigned char*)"]================== OUT =================[");
}

void trace_it(uint32 zeros, uint32 numit) {
  uart_write_string((const unsigned char*)"]================== IT =================[");
  hexstrings(zeros);
  uart_write_strings((const unsigned char*)" - ");
  hexstring(numit);
}

void trace_a_reg(const unsigned char* reg, uint32 value) {
  uart_write_strings(reg);
  uart_write_strings((const unsigned char*)" -> ");
  hexstring(value);
}
