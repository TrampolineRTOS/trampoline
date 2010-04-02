#ifndef __AT91_TWI_H__
#  define __AT91_TWI_H__

#  include "mytypes.h"

/* Main user interface */
int twi_init(void);
void twi_isr_C_function(void);
void twi_start_write(U32 dev_addr, const U8 *data, U32 nBytes);
void twi_start_read(U32 dev_addr, U8 *data, U32 nBytes);
int twi_status(void);
void twi_reset(void);

#endif
