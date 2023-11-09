#include "tpl_os_std_types.h"

#define REG(x) ((volatile uint32 *)(x))
#define ADDR(x) ((volatile uint32 *)(x))
#define BIT(n) (1 << (n))

#define writeToReg(reg,value) \
  *REG(reg) = value

#define readFromReg(reg) \
  *REG(reg)

#define writeToAddress(address,value) \
  *ADDR(address) = value

#define readFromAddress(address) \
  *ADDR(address)

#define cp15_read32(op1, CRn, CRm, op2, val)                \
{                                                           \
    __asm__ volatile (                                      \
        "mrc p15, " #op1 ", %0, c" #CRn ", c"               \
        #CRm ", " #op2 : "=r" (val) :: "memory");           \
}

#define cp15_write32(op1, CRn, CRm, op2, val)               \
{                                                           \
    __asm__ volatile (                                      \
        "mcr p15, " #op1 ", %0, c" #CRn ", c"               \
        #CRm ", " #op2 :: "r" (val) : "memory");            \
}

#define cp15_read64(op1, CRm, val)                          \
{                                                           \
    __asm__ volatile (                                      \
        "mrrc p15, " #op1 ", %Q0, %R0, c"                   \
        #CRm : "=r" (val) :: "memory");                     \
}

#define cp15_write64(op1, CRm, val)                         \
{                                                           \
    __asm__ volatile (                                      \
        "mcrr p15, " #op1 ", %Q0, %R0, c"                   \
        #CRm :: "r" (val) : "memory");                      \
}
