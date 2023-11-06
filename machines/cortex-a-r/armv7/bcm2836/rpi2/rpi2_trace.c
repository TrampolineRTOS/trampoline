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

extern unsigned int __SP_irq_bot_ ;
extern unsigned int __SP_irq_top_;
extern unsigned int __SP_svc_bot_;
extern unsigned int __SP_svc_top_;
extern unsigned int __SP_usr_bot_;
extern unsigned int __SP_usr_top_;

void trace_1(void) {
  uart_write_string((const unsigned char*)"__TRACE__1__");
}

void trace_2(void) {
  uart_write_string((const unsigned char*)"__TRACE__2__");
}

void trace_3(void) {
  uart_write_string((const unsigned char*)"__TRACE__3__");
}

void trace_4(const unsigned char* str) {
  uart_write_string((const unsigned char*)"__TRACE__4__");
}

void trace_5(void) {
  uart_write_string((const unsigned char*)"__TRACE__5__");
}

void trace_6(void) {
  uart_write_string((const unsigned char*)"__TRACE__6__");
}

void trace_7(void) {
  uart_write_string((const unsigned char*)"__TRACE__7__");
}

void trace_8(void) {
  uart_write_string((const unsigned char*)"__TRACE__8__");
}

void trace_9(void) {
  uart_write_string((const unsigned char*)"__TRACE__9__");
}

void trace_10(void) {
  uart_write_string((const unsigned char*)"__TRACE__10__");
}

void trace_regs(void) {
  const unsigned char * regs_name[16] = {
    "r0", "r1", "r2", "r3",
    "r4", "r5", "r6", "r7",
    "r8", "r9", "r10", "r11",
    "r12", "sp", "lr", "pc"};
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

  for (index = 0; index <= 3; index++) {
    uart_write_strings(regs_name[index]);
    uart_write_strings((const unsigned char*)" | ");
    hexstrings(regs[index]);
    if (index < 3) {
      uart_write_strings((const unsigned char*)" | ");
    }
  }
  uart_write_char((unsigned char)0x0D);
  uart_write_char((unsigned char)0x0A);
  for (index = 4; index <= 7; index++) {
    uart_write_strings(regs_name[index]);
    uart_write_strings((const unsigned char*)" | ");
    hexstrings(regs[index]);
    if (index < 7) {
      uart_write_strings((const unsigned char*)" | ");
    }
  }
  uart_write_char((unsigned char)0x0D);
  uart_write_char((unsigned char)0x0A);
  for (index = 8; index <= 11; index++) {
    uart_write_strings(regs_name[index]);
    uart_write_strings((const unsigned char*)" | ");
    hexstrings(regs[index]);
    if (index < 11) {
      uart_write_strings((const unsigned char*)" | ");
    }
  }
  uart_write_char((unsigned char)0x0D);
  uart_write_char((unsigned char)0x0A);
  for (index = 12; index <= 15; index++) {
    uart_write_strings(regs_name[index]);
    uart_write_strings((const unsigned char*)" | ");
    hexstrings(regs[index]);
    if (index < 15) {
      uart_write_strings((const unsigned char*)" | ");
    }
  }
  uart_write_char((unsigned char)0x0D);
  uart_write_char((unsigned char)0x0A);

  uart_write_string((const unsigned char*)"___________________________________________");
}

void trace_context(tpl_proc_id proc_id) {
  struct ARM_CONTEXT *core_context;
  const tpl_proc_static *the_proc;

  the_proc = tpl_stat_proc_table[proc_id];
  core_context = the_proc->context;

  uart_write_string((const unsigned char*)"__TRACE__CONTEXT___________________________");
  uart_write_strings((const unsigned char*)"pc  : ");
  hexstring(core_context->r[armreg_pc]);
  uart_write_strings((const unsigned char*)"sp  : ");
  hexstring(core_context->r[armreg_sp]);
  uart_write_strings((const unsigned char*)"psr : ");
  hexstring(core_context->psr);
  uart_write_strings((const unsigned char*)"lr  : ");
  hexstring(core_context->r[armreg_lr]);
  uart_write_string((const unsigned char*)"___________________________________________");
}

void trace_context_idle(void) {
  trace_context(IDLE_TASK_ID);
}

void trace_context_blink(void) {
  trace_context(0);
}

void trace_idle(void) {
  uart_write_string((const unsigned char*)"Tache IDLE");
}

void trace_in(const unsigned char* fun) {
  uart_write_strings((const unsigned char*)"]================== ");
  uart_write_strings(fun);
  uart_write_string((const unsigned char*)"IN ==================[");
}

void trace_out(const unsigned char* fun) {
  uart_write_strings((const unsigned char*)"]================== ");
  uart_write_strings(fun);
  uart_write_string((const unsigned char*)"OUT =================[");
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

void trace_var(const unsigned char* var, uint32 value) {
  uart_write_strings(var);
  uart_write_strings((const unsigned char*)" -> ");
  hexstring(value);
}

void trace(const unsigned char* s, uint32 n) {
  uart_write_strings((const unsigned char*)s);
  uart_write_strings((const unsigned char*)" - ");
  hexstring(n);
}

void trace_irq_in(void) {
  trace_in((const unsigned char*)"IRQ ");
}

void trace_irq_out(void) {
  trace_out((const unsigned char*)"IRQ ");
}

void trace_svc_in(void) {
  trace_in((const unsigned char*)"SVC ");
}

void trace_svc_out(void) {
  trace_out((const unsigned char*)"SVC ");
}

void trace_val(uint32 val) {
  uart_write_strings((const unsigned char*)"_ ");
  hexstrings(val);
  uart_write_string((const unsigned char*)" _");
}

void trace_stack_irq(void) {
  uint32 index;
  uint32 baseAddr;
  uint32* ptr;
  uint32* sp_irq_value;
  uint32* sp_value;
  baseAddr = (uint32)&__SP_irq_top_;
  ptr = &baseAddr;

  __asm volatile ("mrs %0, SP_irq" : "=r" (sp_irq_value));
  __asm volatile ("mov %0, sp" : "=r" (sp_value));

  uart_write_strings((const unsigned char*)"SP_irq :");
  hexstrings(*sp_irq_value);
  uart_write_strings((const unsigned char*)" | ");
  uart_write_strings((const unsigned char*)"SP :");
  hexstring(*sp_value);

  for (index = 0; index < 40; index++) {
    uart_write_strings((const unsigned char*)"&");
    hexstrings(baseAddr - (4 * index));
    uart_write_strings((const unsigned char*)" -> ");
    hexstring(*ptr++);
  }
}

void trace_stacks(void) {
  uint32 sp_irq_value;
  uint32 sp_svc_value;
  uint32 sp_usr_value;

  __asm volatile ("mrs %0, SP_irq" : "=r" (sp_irq_value));
  __asm volatile ("mrs %0, SP_svc" : "=r" (sp_svc_value));
  __asm volatile ("mov %0, sp" : "=r" (sp_usr_value));

  uart_write_string((const unsigned char*)"SP_irq : ");
  hexstrings((uint32)&__SP_irq_bot_);
  uart_write_strings((const unsigned char*)" | ");
  hexstrings(sp_irq_value);
  uart_write_strings((const unsigned char*)" | ");
  hexstrings((uint32)&__SP_irq_top_);
  if ( (sp_irq_value < (uint32)&__SP_irq_bot_) || (sp_irq_value > (uint32)&__SP_irq_top_) ) {
    uart_write_string((const unsigned char*)"!!!");
  } else {
    uart_write_char((unsigned char)0x0D);
    uart_write_char((unsigned char)0x0A);
  }

  uart_write_string((const unsigned char*)"SP_svc : ");
  hexstrings((uint32)&__SP_svc_bot_);
  uart_write_strings((const unsigned char*)" | ");
  hexstrings(sp_svc_value);
  uart_write_strings((const unsigned char*)" | ");
  hexstrings((uint32)&__SP_svc_top_);
  if ( (sp_svc_value < (uint32)&__SP_svc_bot_) || (sp_svc_value > (uint32)&__SP_svc_top_) ) {
    uart_write_string((const unsigned char*)"!!!");
  } else {
    uart_write_char((unsigned char)0x0D);
    uart_write_char((unsigned char)0x0A);
  }

  uart_write_string((const unsigned char*)"SP_usr : ");
  hexstrings((uint32)&__SP_usr_bot_);
  uart_write_strings((const unsigned char*)" | ");
  hexstrings(sp_usr_value);
  uart_write_strings((const unsigned char*)" | ");
  hexstrings((uint32)&__SP_usr_top_);
  if ( (sp_usr_value < (uint32)&__SP_usr_bot_) || (sp_usr_value > (uint32)&__SP_usr_top_) ) {
    uart_write_string((const unsigned char*)"!!!");
  } else {
    uart_write_char((unsigned char)0x0D);
    uart_write_char((unsigned char)0x0A);
  }
}

void trace_pinout(void) {
  static uint8 etat = 0;

  if (etat == 0) {
    etat = 1;
    writeToReg(GPSET0,1<<21);
  } else {
    etat = 0;
    writeToReg(GPCLR0,1<<21);
  }
}
