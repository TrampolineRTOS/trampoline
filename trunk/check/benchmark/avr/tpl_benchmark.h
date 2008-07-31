// Benchmark GF 04/08

#define BENCHMARK


//#ifdef BENCHMARK
#include <avr/io.h>
void set_tb();
int get_tb();
extern unsigned int tpl_benchmark_tick;

#define TPL_BENCHMARK_MULTIPLIER 4
#define TPL_BENCHMARK_DIVISOR 10
#define TPL_BENCHMARK_UNIT 0xB5	   // 0xB5 = µ
//#endif
