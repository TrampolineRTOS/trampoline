#include <stdio.h>
#include "tpl_benchmark.h"
#include "../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

void InitApp();
void StartOS();

void main (void)
	{
	InitApp();
	StartOS(OSDEFAULTAPPMODE);
	}


asm void set_tb(unsigned int time)
{
  nofralloc
    mtspr 268,time
    blr
}

asm unsigned int get_tb(void)
{
  nofralloc
    mfspr r3,268
    blr
}
