#include "tpl_os.h"
#include "rp2040.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

#define LED_BUILTIN 25

FUNC(int, OS_APPL_CODE) main(void)
{
  //set led pin as output.
  sio_hw->gpio_oe_set = 1ul << LED_BUILTIN; // enable output
  sio_hw->gpio_clr = 1ul << LED_BUILTIN;    // clear
  iobank0_hw->io[LED_BUILTIN].ctrl = 5; //5 is alternate function for SIO

  //and start Trampoline
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink)
{
  sio_hw->gpio_togl = 1ul << LED_BUILTIN;    // toggle
  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

