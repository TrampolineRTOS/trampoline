#ifndef _RPI2_TRACE_H_
#define _RPI2_TRACE_H_

#include "tpl_os.h"
#include "tpl_os_kernel.h"
#include "bcm2836.h"
#include "emblib.h"
#include "rpi2_uart.h"

void trace_1(void);
void trace_2(void);
void trace_3(void);
void trace_4(const unsigned char*);
void trace_5(void);
void trace_6(void);
void trace_7(void);
void trace_8(void);
void trace_9(void);
void trace_10(void);
void trace_regs(void);
void trace_context(tpl_proc_id);
void trace_idle(void);
void trace_in(const unsigned char*);
void trace_out(const unsigned char*);
void trace_it(uint32, uint32);
void trace_a_reg(const unsigned char* , uint32);
void trace_var(const unsigned char* , uint32);
void trace_context_idle(void);
void trace_context_blink(void);
void trace_irq_in(void);
void trace_irq_out(void);
void trace_svc_in(void);
void trace_svc_out(void);
void trace_val(uint32);
void trace_stack_irq(void);
void trace_stacks(void);
void trace_pinout(void);

#endif /* _RPI2_TRACE_H_ */
