#if WITH_IT_TABLE == NO
#if ISR_COUNT > 0
#include <signal.h>

int signal_for_isr_id[] = {
$ISR_SIGNAL_LIST$
};
#endif
#else
$IT_TABLE$
#endif