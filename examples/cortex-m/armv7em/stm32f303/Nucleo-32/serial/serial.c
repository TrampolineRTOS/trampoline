#include "tpl_os.h"
#include "pinAccess.h"

//see machines/cortex-m/armv7em/stm32f303/lib/serial.h
#include "serial.h"

#define APP_Task_serial_TX_START_SEC_CODE
#include "tpl_memmap.h"


FUNC(int, OS_APPL_CODE) main(void)
{
  pinMode(GPIOB,3,OUTPUT); //led 1 is PB3
  tpl_serial_begin();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(serial_TX)
{
  static int i = 0;
  tpl_serial_print_string("count: ");
  tpl_serial_print_int(i,10,6); //val, base, field width
  tpl_serial_print_string("\r\n");
  i++;
  digitalToggle(GPIOB,3); //led
  TerminateTask();
}

//tmp TODO: add ISR into library.
void itUsart();
ISR(usart)
{
	itUsart();
}

#define APP_Task_serial_TX_STOP_SEC_CODE
#include "tpl_memmap.h"

