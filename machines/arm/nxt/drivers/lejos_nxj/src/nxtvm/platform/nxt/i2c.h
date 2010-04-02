#ifndef __I2C_H__
#define __I2C_H__

#include "mytypes.h"

#define I2C_N_PORTS 4

void i2c_timer_isr_C_function(void);
void i2c_disable(int port);
void i2c_enable(int port);

void i2c_init(void);

int i2c_busy(int port);
int i2c_start_transaction(int port, 
                      U32 address, 
                      int internal_address, 
                      int n_internal_address_bytes, 
                      U8 *data, 
                      U32 nbytes,
                      int write);


void i2c_test(void);

#endif
