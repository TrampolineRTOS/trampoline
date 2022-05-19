#include "tpl_os.h"
#include "pico/stdlib.h" //gpio_xxx()

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

#define LED_BUILTIN 25

FUNC(int, OS_APPL_CODE) main(void)
{
  //set led pin as output.
  gpio_init(LED_BUILTIN);
  gpio_set_dir(LED_BUILTIN, GPIO_OUT);

  //and start Trampoline
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink)
{
  gpio_xor_mask(1<<LED_BUILTIN); //toggle
  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

