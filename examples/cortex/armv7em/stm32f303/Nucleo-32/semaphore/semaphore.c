#include "tpl_os.h"
#include "pinAccess.h"

//see machines/cortex/armv7em/stm32f303/lib/serial.h
#include "serial.h"

#define APP_Task_serial_TX_long_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
  pinMode(GPIOB,3,OUTPUT); //led 1 is PB3
  /* the TX buffer is quite short (.oil), so the transmission will wait
  for the serial device.
  */
  tpl_serial_begin(SERIAL_TX_MODE_BLOCK);
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

/**
 * @brief Low priority task that sends a looong string on serial (and should not be cut)
 */
TASK(serial_TX_long)
{
  static int i = 0;
  SemWait(semSerial);
  tpl_serial_print_string("This is a very long string that should not be cut: ");
  tpl_serial_print_int(i,10,6); //val, base, field width
  tpl_serial_print_string("\r\n");
  SemPost(semSerial);
  i++;
  digitalToggle(GPIOB,3); //led
  TerminateTask();
}

#define APP_Task_serial_TX_long_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_serial_TX_short_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @brief High priority task that sends a short string on serial
 */
TASK(serial_TX_short)
{
  SemWait(semSerial);
  tpl_serial_print_string("*short*\r\n");
  SemPost(semSerial);
  TerminateTask();
}

//tmp TODO: add ISR into library.
void itUsart();
ISR(usart)
{
	itUsart();
}

#define APP_Task_serial_TX_short_STOP_SEC_CODE
#include "tpl_memmap.h"

