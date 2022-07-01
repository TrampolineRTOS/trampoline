#ifndef __TPL_SERIAL_H__
#define __TPL_SERIAL_H__
#include <stdint.h>

/* define TX MODE when TX buffer is full
 * SERIAL_TX_MODE_BLOCK: active waiting loop. Get in LPM3 between characters.
 * SERIAL_TX_MODE_SKIP : the data is not sent. Overflow return value is set.
 * */
#define SERIAL_TX_MODE_BLOCK  0
#define SERIAL_TX_MODE_SKIP   1

/* function that should be called each time 
 * the DCO frequency is changed to recalculate the
 * correct baud rate parameters.
 *
 * During init, this function is registered has a 
 * callback that should be called for each clock update.
 **/
void tpl_serial_update_freq();

/** simply put one char on the serial line 
 * @return 0 if there is no overflow (TX buffer)
 * */
int tpl_serial_putchar(char c);

/** print a standard null terminated string on the serial line
 * @return 0 if there is no overflow (TX buffer)
 **/
int tpl_serial_print_string(const char *str);

/** print an integer to the serial line
 *  @param val value to be printed  
 *  @param fieldWidth width (in char) of the value printed (right aligned)
 *  @return 0 if there is no overflow (TX buffer)
 **/
int tpl_serial_print_int(int16_t val, uint8_t fieldWidth);

/** configure the serial line. Should be called at startup.
 *
 * txMode defines the behavior when TX buffer is full
 * SERIAL_TX_MODE_BLOCK: active waiting loop. Get in LPM3 between characters.
 * SERIAL_TX_MODE_SKIP : the data is not sent. Overflow return value is set.
 * There is only the blocking mode if no buffer is defined.
 **/
void tpl_serial_begin(uint8_t txMode);

/** return the nb of available chars in the rx buffer */
uint16_t tpl_serial_available();

/** @return the last value received. If the rx buffer is empty,
 * it returns 0xff
 */
char tpl_serial_read();

void tpl_serial_tx_fifo_discard();
#endif
