#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdint.h>

/** basic serial line (TX only) for debug purpose
 *  We use USART2 on PA2 (alternative config 7)
 *  => compatible with Nucleo32 F303K8 and Nucleo64 F303RE and 
 *  available through the ST-Link MCU to support a virtual COM port.
 *  configuration is 115200 8N1.
 *
 *  If the FIFO is FULL, data is NOT sent. There is no blocking call
 *  print function returns the overflow flag. If the flag is set, some data was skip.
 */
void tpl_serial_begin();

// print a single ASCII char on the serial line
// if TX FIFO is full, data is not printed on serial line and
// a non zero value is returned.
//
int tpl_serial_putchar(char c);

// print a NULL terminated ASCII string on the serial line
// if TX FIFO is full, data is not printed on serial line and
// a non zero value is returned.
int tpl_serial_print_string(const char* str);

/* print a 32 bit signed integer on the serial line
 * @param base       defines the basis (decimal by default)
 * if TX FIFO is full, data is not printed on serial line and
 * a non zero value is returned.
 */
int tpl_serial_print_int(int32_t val, int base, int fieldWidth);

/* flush TX fifo (no more data sent)
 */
void tpl_serial_tx_fifo_discard();

/* waiting loop to re-synchronise output on Serial.
 * mainly for debug purpose
 */
void tpl_serial_wait_for_tx_complete();

void itUsart();
#endif // SERIAL_H
