#include <stdio.h>
#include <C167CS.H>

void tpl_init_benchmark_timer()
{
	// Benchmark GF 04/08
	#ifdef BENCHMARK
	T78CON&=0xFF00;
	T78CON|=0x0040;
	#endif
}


void tpl_stop_interruption (void)
{
IEN = 0;
}

void tpl_start_interruption (void)
{
IEN = 1;
}