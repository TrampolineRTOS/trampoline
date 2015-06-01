#include "tp.h"
#include "tpl_os.h"

#define APP_ISR_buttonISR_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard(BUTTON_IT);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

ISR(buttonISR)
{
	ledToggle(LED3);
}
#define APP_ISR_buttonISR_STOP_SEC_CODE
#include "tpl_memmap.h"

/*
 * This is necessary for ST libraries
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

