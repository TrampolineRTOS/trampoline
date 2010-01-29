#ifndef __NXT_AVR_H__
#  define __NXT_AVR_H__

#  include "mytypes.h"

/* Main user interface */
void nxt_avr_init(void);

void nxt_avr_1kHz_update(void);

void nxt_avr_set_motor(U32 n, int power_percent, int brake);

void nxt_avr_power_down(void);

void nxt_avr_test_loop(void);

void nxt_avr_update(void);

U32 buttons_get(void);

U32 battery_voltage(void);

U32 sensor_adc(U32 n);

void nxt_avr_set_input_power(U32 n, U32 power_type);

#endif
