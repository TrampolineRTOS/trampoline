
#if ISR_COUNT > 0

#define OS_START_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"

/* associative table to get isr_id from an IRQ source */
CONST(u16, AUTOMATIC)
simtec_isr_by_src[32] = {
 /* $SIMTEC_ISR_LIST$*/
0
};

#define OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"

#endif

