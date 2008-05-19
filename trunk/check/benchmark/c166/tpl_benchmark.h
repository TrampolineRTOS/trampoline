#include <C167CS.H>

// Benchmark GF 04/08
#ifdef BENCHMARK
#define tpl_benchmark_timer T7
extern u16 tpl_benchmark_tick;

#define TPL_BENCHMARK_MULTIPLIER 4
#define TPL_BENCHMARK_DIVISOR 10
#define TPL_BENCHMARK_UNIT 0xB5	   // 0xB5 = µ
#endif

void tpl_stop_interruption (void);
void tpl_start_interruption (void);