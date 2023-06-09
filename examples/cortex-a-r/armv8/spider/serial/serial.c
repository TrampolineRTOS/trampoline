#include "tpl_os.h"

#include "spider_serial.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	Serial_Init();

	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

volatile uint32 tmp = 0;
TASK(serial_rx)
{
	uint8 uart_rx;
	while(1)
	{
		if (Serial_Rx(&uart_rx))
		{
			/* If received a char, send back the next one */
			Serial_Tx(uart_rx+1);
		}
	}
}

TASK(serial_tx)
{
	/* Send next alphabet letter each time*/
	static uint8 uart_char=0;
	uart_char = (uart_char+1) % 26;
	Serial_Tx('a' + uart_char);
}
