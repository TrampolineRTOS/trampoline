#include <stdio.h>
#include "tpl_benchmark.h"
#include "../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"


void InitApp();

int main (void)
	{
	InitApp();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
	}


void tpl_init_benchmark_timer()
{
	// Benchmark GF 04/08
	//#ifdef BENCHMARK
	TCCR1A = 0;
	TCCR1B = 1;
    TIMSK1 = 1;
	//#endif
}

void set_tb (void)
{
TCNT1 = 0;
}

int get_tb (void)
{
return(TCNT1);
}
