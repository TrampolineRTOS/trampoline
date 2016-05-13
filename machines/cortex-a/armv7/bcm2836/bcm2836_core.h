#include "bcm2836.h"

/** \brief  Count leading zeros

    This function counts the number of leading zeros of a data value.

    \param [in]  value  Value to count the leading zeros
    \return             number of leading zeros in value
 */
__attribute__( ( always_inline ) ) static inline uint8 __CLZ(uint32 value)
{
  uint32 result;

  __asm volatile ("clz %0, %1" : "=r" (result) : "r" (value) );
   return (result);    /* Add explicit type cast here */
}
