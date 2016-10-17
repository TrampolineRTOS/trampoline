#include "tpl_os_internal_types.h"
#include "tpl_os_std_types.h"
#include "tpl_os_kernel.h"
#include "Compiler.h"

#include "arm_string.h"
#include "arm_stdio.h"

long arm_tick = 0;
long tpl_call_counter_tick_nbcall = 0;
long tpl_counter_tick_nbcall = 0;
long test_nbcall = 0;

extern FUNC(tpl_bool, OS_CODE) tpl_call_counter_tick();

void tpl_shutdown(void) {}
void tpl_init_machine(void) {}

// FUNC(void, OS_CODE) tpl_tick_ARM_TIMER() {
//   arm_tick++;
//
//   if (tpl_call_counter_tick()) {
//
//   };
// }
//
FUNC(void, OS_CODE) ARM_TIMER_ClearFlag(void) {}

FUNC(void, OS_CODE) tpl_set_systick_timer(void) {}

/*
 * Trace functions
 */
void trace(unsigned int n) {
  char num[32];
  arm_puts ("trace ");
  arm_uint2hexstr(num, n);
	arm_puts(num);
  arm_puts("\n");
}

void tracereg(unsigned int n) {
  char num[32];
  arm_puts ("trace registre : ");
  arm_uint2hexstr(num, n);
	arm_puts(num);
  arm_puts("\n");
}

void trace_svc(unsigned int n) {
  char num[32];
  arm_puts ("trace_svc ");
  arm_uint2hexstr(num, n);
	arm_puts(num);
  arm_puts("\n");
}

void trace_0_() {
  arm_puts ("trace_0_\n");
}
void trace_0__() {
  arm_puts ("trace_0__\n");
}
void trace_0___() {
  arm_puts ("trace_0___\n");
}
void trace_0() {
  arm_puts ("trace_0\n");
}
void trace_1() {
  arm_puts ("trace_1\n");
}
void trace_2() {
  arm_puts ("trace_2\n");
}
void trace_3() {
  arm_puts ("trace_3\n");
}
void trace_4() {
  arm_puts ("trace_4\n");
}
void trace_5() {
  arm_puts ("trace_5\n");
}
void trace_6() {
  arm_puts ("trace_6\n");
}
void trace_7() {
  arm_puts ("trace_7\n");
}
void trace_8() {
  arm_puts ("trace_8\n");
}
void trace_9() {
  arm_puts ("trace_9\n");
}
void trace_10() {
  arm_puts ("trace_10\n");
}
void trace_11() {
  arm_puts ("trace_11\n");
}
void trace_12() {
  arm_puts ("trace_12\n");
}

void trace_irq_0() {
  arm_puts ("trace_irq_0\n");
}
void trace_irq_1() {
  arm_puts ("trace_irq_1\n");
}
void trace_irq_2() {
  arm_puts ("trace_irq_2\n");
}

void tracekern(void) {
  char str[32];

  arm_puts("@tpl_kern = ");
  arm_uint2hexstr(str,(uint32)&tpl_kern);
  arm_puts(str);
  arm_puts("\n");
  arm_puts("tpl_kern.s_running = ");
  if (tpl_kern.s_running != 0) {
    arm_uint2hexstr(str,(uint32)tpl_kern.s_running);
    arm_puts(str);
    arm_puts("\n");
	} else {
		arm_puts("NULL\n");
	}

  arm_puts("tpl_kern.s_elected = ");
  /* tpl_task_id -> tpl_proc_id -> sint8 */
  if (tpl_kern.s_elected != 0) {
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected);
    arm_puts(str);
    arm_puts("\n");
    arm_puts("tpl_kern.s_elected->context = ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context);
    arm_puts(str);
    arm_puts("\n");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[15]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[14]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[13]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[12]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[11]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[10]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[9]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[8]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[7]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[6]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[5]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[4]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[3]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[2]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[1]);
    arm_puts(str);
    arm_puts(" ; ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->context->r[0]);
    arm_puts(str);
    arm_puts("\n");

    arm_puts("tpl_kern.s_elected->stack.stack_zone = ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->stack.stack_zone);
    arm_puts(str);
    arm_puts("\n");
    arm_puts("tpl_kern.s_elected->entry = ");
    arm_uint2hexstr(str,(uint32)tpl_kern.s_elected->entry);
    arm_puts(str);
    arm_puts("\n");
  } else {
    arm_puts("NULL\n");
  }
  arm_puts("tpl_kern.running = ");
  if (tpl_kern.running != 0) {
    arm_uint2hexstr(str,(uint32)tpl_kern.running);
    arm_puts(str);
    arm_puts("\n");
  } else {
    arm_puts("NULL\n");
  }
  arm_puts("tpl_kern.elected = ");
  if (tpl_kern.elected != 0) {
    arm_uint2hexstr(str,(uint32)tpl_kern.elected);
    arm_puts(str);
    arm_puts("\n");
  } else {
    arm_puts("NULL\n");
  }
  arm_puts("tpl_kern.running_id = ");
  arm_int2str(str,(sint32)tpl_kern.running_id);
  arm_puts(str);
  arm_puts("\n");
  arm_puts("tpl_kern.elected_id = ");
  arm_int2str(str,(sint32)tpl_kern.elected_id);
  arm_puts(str);
  arm_puts("\n");
  arm_puts("tpl_kern.need_switch = ");
  arm_uint2hexstr(str,(uint8)tpl_kern.need_switch);
  arm_puts(str);
  arm_puts("\n");
  arm_puts("tpl_kern.need_schedule = ");
  /* tpl_bool -> uint8 */
  arm_uint2hexstr(str,(tpl_bool)tpl_kern.need_schedule);
  arm_puts(str);
  arm_puts("\n");
}

void tracecontext(tpl_proc_id proc_id) {
  char str[32];
  struct ARM_CONTEXT *core_context;
  const tpl_proc_static *the_proc;
  the_proc = tpl_stat_proc_table[proc_id];
  core_context = the_proc->context;

  arm_puts("@core_context = ");
  arm_uint2hexstr(str,(uint32)core_context);
  arm_puts(str);
  arm_puts("\n");

  arm_puts("core_context->r[armreg_pc] = ");
  arm_uint2hexstr(str,core_context->r[armreg_pc]);
  arm_puts(str);
  arm_puts("\n");

  arm_puts("core_context->r[armreg_sp] = ");
  arm_uint2hexstr(str,core_context->r[armreg_sp]);
  arm_puts(str);
  arm_puts("\n");

  arm_puts("core_context->psr = ");
  arm_uint2hexstr(str,core_context->psr);
  arm_puts(str);
  arm_puts("\n");

  arm_puts("core_context->[armreg_lr] = ");
  arm_uint2hexstr(str,core_context->r[armreg_lr]);
  arm_puts(str);
  arm_puts("\n");
}
