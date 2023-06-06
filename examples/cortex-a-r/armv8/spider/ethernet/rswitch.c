#include "tpl_os.h"
#include "rswitch.h"

#define RSWITCH_BASE            0xE6880000

#define RSWITCH_FWD_ADDR      (RSWITCH_BASE + 0x00000000)
#define RSWITCH_FAB_ADDR      (RSWITCH_BASE + 0x00008000)
#define RSWITCH_COMA_ADDR     (RSWITCH_BASE + 0x00009000)
#define RSWITCH_ETHA0_ADDR    (RSWITCH_BASE + 0x0000a000)
#define RSWITCH_ETHA1_ADDR    (RSWITCH_BASE + 0x0000c000)
#define RSWITCH_ETHA2_ADDR    (RSWITCH_BASE + 0x0000e000)
#define RSWITCH_GWCA0_ADDR    (RSWITCH_BASE + 0x00010000)
#define RSWITCH_GWCA1_ADDR    (RSWITCH_BASE + 0x00012000)
#define RSWITCH_GPTP_ADDR     (RSWITCH_BASE + 0x00018000)

static inline uint32 reg_read32(void *addr)
{
    return *((volatile uint32*)addr);
}

static inline void reg_write32(uint32 data, void *addr)
{
    *((volatile uint32*)addr) = data;
}

int rswitch_init(void)
{
    return 0;
}