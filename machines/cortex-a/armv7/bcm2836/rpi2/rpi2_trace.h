#ifndef _RPI2_TRACE_H_
#define _RPI2_TRACE_H_


#include "rpi2_uart.h"

void trace_1(void);
void trace_2(void);
void trace_3(void);
void trace_4(const unsigned char*);
void trace_5(void);
void trace_6(void);
void trace_7(void);
void trace_7_1(void);
void trace_8(void);
void trace_8_1(uint32);
void trace_9(void);
void trace_10(void);
void trace_regs(void);
void trace_context(void);
void trace_idle(void);
void trace_in(void);
void trace_out(void);
void trace_it(uint32, uint32);
void trace_a_reg(const unsigned char* , uint32);

#endif /* _RPI2_TRACE_H_ */
