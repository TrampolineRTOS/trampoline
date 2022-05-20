#include <stdint.h>
#include <stdio.h>
#include "tpl_os.h"
#include "pico/stdlib.h" //gpio_xxx()

#define APP_Task_serialTX_START_SEC_CODE
#include "tpl_memmap.h"

#define LED_BUILTIN 25

FUNC(int, OS_APPL_CODE) main(void)
{
  stdio_uart_init();
  //set led pin as output.
  gpio_init(LED_BUILTIN);
  gpio_set_dir(LED_BUILTIN, GPIO_OUT);

  //and start Trampoline
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(serialTX)
{
  static char val = 0;
  gpio_xor_mask(1<<LED_BUILTIN); //toggle
  uart_puts(uart0, "blink ");
  uart_putc_raw(uart0, (char)(val++%10)+'0');
  uart_puts(uart0, "\r\n");
  TerminateTask();
}
#define APP_Task_serialTX_STOP_SEC_CODE
#include "tpl_memmap.h"

