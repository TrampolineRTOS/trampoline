#include "bcm2836_misc.h"


void bcm2836_delay(uint32 n)
{
  volatile uint32 i = 0;
  for(i = 0; i < n; i++); /* Ouhhhh pas beau */
}
