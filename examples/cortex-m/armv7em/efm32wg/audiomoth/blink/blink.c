#include "tpl_os.h"
#include <stdint.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void){
	CHIP_Init();
	// Enable Clock to GPIO
	CMU_ClockEnable(cmuClock_GPIO, true);
	// Set GPIO Red Led to Output
	GPIO->P[gpioPortC].MODEL |= 4 << (16);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink){
	
	GPIO->P[gpioPortC].DOUT ^= 1<<4;
	TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
