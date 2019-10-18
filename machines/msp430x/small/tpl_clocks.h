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

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_CLOCKS_H_ */

