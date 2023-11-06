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
