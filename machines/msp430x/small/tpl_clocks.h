#ifndef TPL_CLOCKS_H
#define TPL_CLOCKS_H
#include <stdint.h>
#include "tpl_compiler.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/* configure the frequency in MHz: 1,2,4,6,8,12,16,(21,24 overclock)
 * set to 1MHz in case of bad input frequency.
 **/

FUNC(void,OS_CODE) tpl_set_mcu_clock(uint16_t freq);

typedef void (*tpl_freq_update_callback)();

struct tpl_freq_update_item_s {
	tpl_freq_update_callback   observer;
	struct tpl_freq_update_item_s    *next;
} ;
typedef struct tpl_freq_update_item_s tpl_freq_update_item;

void tpl_add_freq_update_callback(tpl_freq_update_item *freqObs);

/* get the configuration of the DCO (to get a clock source) */
uint16_t tpl_getDCOConfig();
/* return the frequency of the DCO in Hz
 * It can differ from the frequency of MCLK! */
uint32_t tpl_getDCOFrequency();
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_CLOCKS_H_ */

