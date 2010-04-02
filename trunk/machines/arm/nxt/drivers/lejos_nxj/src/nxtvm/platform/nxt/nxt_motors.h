#ifndef __NXT_MOTORS_H__
#  define __NXT_MOTORS_H__

#  include "mytypes.h"

#  define NXT_N_MOTORS 3

void nxt_motor_isr_C_function(void);

int nxt_motor_get_count(U32 n);
void nxt_motor_set_count(U32 n, int count);

void nxt_motor_set_speed(U32 n, int speed_percent, int brake);

void nxt_motor_command(U32 n, int cmd, int target_count, int speed_percent);

void nxt_motor_init(void);


// ISR points used by motor processing
void nxt_motor_1kHz_process(void);

#endif
