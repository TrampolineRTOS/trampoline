#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdint.h>

#define SERIAL_TX_BUFFER_SIZE 64

/** basic serial line (TX only) for debug prupose
 *  We use USART2 on PA2 (alternative config 7)
 *  => compatible with Nucleo32 F303K8 and Nucleo64 F303RE and 
 *  available through the ST-Link MCU to support a virtual COM port.
 *  configuration is 115200 8N1.
 */
void tpl_serial_begin();

// print a single ASCII char on the serial line
void tpl_serial_putchar(char c);

// print a NULL terminated ASCII string on the serial line
void tpl_serial_print_string(const char* str);

/* print a 32 bit signed integer on the serial line
 * @param base       defines the basis (decimal by default)
 */
void tpl_serial_print_int(int32_t val, int base, int fieldWidth);

/* waiting loop to re-synchronise output on Serial.
 * mainly for debug purpose
 */
void tpl_serial_wait_for_tx_complete();

#endif // SERIAL_H
