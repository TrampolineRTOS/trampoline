#ifndef _UTILS_H_
#define _UTILS_H_

#include "tpl_os.h"

#define BIT(x)      (1UL << x)

void rswitch_enable_clock_and_reset(void);
void port_init(void);
uint32 get_time(void);
uint32 get_elapsed_time(uint32 start_val);

#endif /* _UTILS_H_ */