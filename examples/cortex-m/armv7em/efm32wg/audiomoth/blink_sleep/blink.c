#include "tpl_os.h"
#include <stdint.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_letimer.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void){
	CHIP_Init();
	// Enable Clock to GPIO
	CMU_ClockEnable(cmuClock_GPIO, true);
	// Set GPIO Red Led to Output
	GPIO->P[gpioPortC].MODEL |= 4 << (16);
	/* Enable high frequency HFXO clock */
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
	CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_1);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
	CMU_OscillatorEnable(cmuOsc_HFRCO, false, false);

	/* Enable clock to Low energy module */
	CMU_ClockEnable(cmuClock_CORELE, true);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink){
	GPIO->P[gpioPortC].DOUT ^= 1<<4;
	TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
