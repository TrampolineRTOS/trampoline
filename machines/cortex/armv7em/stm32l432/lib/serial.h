#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdint.h>

/* define TX MODE when TX buffer is full
 * SERIAL_TX_MODE_BLOCK: active waiting loop.
 * SERIAL_TX_MODE_SKIP : the data is not sent. Overflow return value is set.
 * */
#define SERIAL_TX_MODE_BLOCK 0
#define SERIAL_TX_MODE_SKIP 1

/** basic serial line (TX only) for debug purpose
 *  We use USART2 on PA2 (alternative config 7)
 *  => compatible with Nucleo32 L432 
 *  available through the ST-Link MCU to support a virtual COM port.
 *  configuration is 115200 8N1.
 *
 * txMode defines the behavior when TX buffer is full
 * SERIAL_TX_MODE_BLOCK: active waiting loop.
 * SERIAL_TX_MODE_SKIP : the data is not sent. Overflow return value is set.
 * There is only the blocking mode if no buffer is defined.
 **/
void tpl_serial_begin(uint8_t txMode);

/** print a single ASCII char on the serial line
 * if TX FIFO is full, behavior depends on config defined in tpl_serial_begin.
 * It can be either a blocking or a non-blocking call
 **/
int tpl_serial_putchar(char c);

/** print a NULL terminated ASCII string on the serial line
 * The function calls tpl_serial_putchar()
 **/
int tpl_serial_print_string(const char *str);

/** print a 32 bit signed integer on the serial line
 * @param base       defines the basis (decimal by default)
 * @param fieldWidth minimum size of the field (in chars)
 * The function calls tpl_serial_putchar()
 **/
int tpl_serial_print_int(int32_t val, int base, int fieldWidth);

/** flush TX fifo (no more data sent)
 */
void tpl_serial_tx_fifo_flush();

/** waiting loop to re-synchronise output on Serial.
 * mainly for debug purpose
 */
void tpl_serial_wait_for_tx_complete();

void itUsart();
#endif // __SERIAL_H__
