#ifndef _UTILS_H_
#define _UTILS_H_

#include "tpl_os_types.h"
#include "printf.h"

#define debug_msg(...) \
        do { \
            debug_printf(__VA_ARGS__); \
            debug_printf("\n\r"); \
        } while(0)

#define BIT(x)      (1UL << x)
#define BITS_PER_TYPE(x)    (sizeof(x) * 8)
#define BITS_PER_LONG       (BITS_PER_TYPE(unsigned long))

#define GENMASK(h, l) \
        (((~(0UL)) - ((1UL) << (l)) + 1) & \
         (~(0UL) >> (BITS_PER_LONG - 1 - (h))))

#define CHECK_RET(f)    \
    ret = (f); \
    if (ret != 0) { \
        return ret; \
    }

uint32 reg_read32(uint32 addr);
void reg_write32(uint32 data, uint32 addr);

void rswitch_enable_clock_and_reset(void);
void port_init(void);

void enable_int(uint32 irq);

uint32 get_time(void);
uint32 get_elapsed_time(uint32 start_val);
void ms_delay(uint32 value);

void debug_print_buffer(uint8 *buf, uint32 len);

#endif /* _UTILS_H_ */
