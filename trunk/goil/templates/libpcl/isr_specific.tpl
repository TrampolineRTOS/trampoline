#if ISR_COUNT > 0
#include <signal.h>

int signal_for_isr_id[] = {
$ISR_SIGNAL_LIST$
};
#endif
