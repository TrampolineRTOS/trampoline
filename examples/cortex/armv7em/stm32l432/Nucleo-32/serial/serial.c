#include "tpl_os.h"
#include "stm32l4xx.h"
#include "pinAccess.h"

//see machines/cortex/armv7em/stm32l432/lib/serial.h
#include "serial.h"

#define APP_Task_blinkSerial_START_SEC_CODE
#include "tpl_memmap.h"

//init PB.3 as output (LED 1 on pin 13).
void initUserLed()
{
	pinMode(GPIOB,3,OUTPUT);
}

FUNC(int, OS_APPL_CODE) main(void)
{
	initUserLed(); 
	tpl_serial_begin();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blinkSerial)
{
	static uint32_t i = 0;
	tpl_serial_print_string("counter: ");
	tpl_serial_print_int(i,10,5); //value, base, fieldwidth
	tpl_serial_print_string("\r\n");
	i++;
	GPIOB->ODR ^= GPIO_ODR_OD3;	//toggle user led.
	TerminateTask();
}

//tmp TODO: add ISR into library.
void itUsart();
ISR(usart)
{
	itUsart();
}
#define APP_Task_blinkSerial_STOP_SEC_CODE
#include "tpl_memmap.h"

