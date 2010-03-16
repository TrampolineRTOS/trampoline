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


void tpl_init_benchmark_timer()
{
	// Benchmark GF 04/08
	#ifdef BENCHMARK
	T78CON&=0xFF00;
	T78CON|=0x0040;
	#endif
}

void set_tb (void)
{
T7 = 0;
}

int get_tb (void)
{
return(T7);
}
