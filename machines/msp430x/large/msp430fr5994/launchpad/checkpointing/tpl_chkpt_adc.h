#ifndef __TPL_CHECKPOINTING_ADC_H__
#define __TPL_CHECKPOINTING_ADC_H__
#include <stdint.h>

/* board dependant function to access to the 
 * supply voltage.
 * Function should be defined in board specific code.
 */

FUNC(void, OS_APPL_CODE) tpl_adc_init_simple(void);

FUNC(void, OS_APPL_CODE) tpl_adc_init(void);

uint16_t readPowerVoltage(void);

uint16_t readPowerVoltage_simple(void);

#endif
