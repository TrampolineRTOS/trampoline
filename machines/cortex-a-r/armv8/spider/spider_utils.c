#include "emblib.h"

#define DCACHE_LINE_SIZE      64

void invalidate_data_cache_by_address(volatile void *addr, sint32 dsize)
{
    if ( dsize > 0 ) {
        sint32 op_size = dsize + (((uint32)addr) & (DCACHE_LINE_SIZE - 1U));
        uint32 op_addr = (uint32)addr;

        __asm__ volatile ("dsb");

        do {
            cp15_write32(0, 7, 6, 1, op_addr);
            op_addr += DCACHE_LINE_SIZE;
            op_size -= DCACHE_LINE_SIZE;
        } while ( op_size > 0 );

        __asm__ volatile ("dsb");
        __asm__ volatile ("isb");
    }
}