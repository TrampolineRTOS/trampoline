#include "tpl_os.h"
//#include "rp2040.h"
#include "pico/stdlib.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

#include "hardware/structs/iobank0.h"
#include "hardware/structs/sio.h"

#define LED_BUILTIN 25

FUNC(int, OS_APPL_CODE) main(void)
{
  //set led pin as output.
  //gpio_init(LED_BUILTIN);
  sio_hw->gpio_oe_set = 1ul << LED_BUILTIN; // enable output
  sio_hw->gpio_clr = 1ul << LED_BUILTIN;    // clear
  iobank0_hw->io[LED_BUILTIN].ctrl = 5; //5 is alternate function for SIO

  //and start Trampoline
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink)
{
  gpio_xor_mask(1<<LED_BUILTIN); //toggle
  sio_hw->gpio_togl = 1ul << LED_BUILTIN;    // toggle
  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

