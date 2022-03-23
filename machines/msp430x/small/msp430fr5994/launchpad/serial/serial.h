#ifndef __TPL_SERIAL_H__
#define __TPL_SERIAL_H__
#include <stdint.h>

/* function that should be called each time 
 * the DCO frequency is changed to recalculate the
 * correct baud rate parameters.
 *
 * During init, this function is registered has a 
 * callback that should be called for each clock update.
 **/
void tpl_serial_update_freq();

/** simply put one char on the serial line */
void tpl_serial_putchar(char c);

/** print a standard null terminated string on the serial line*/
void tpl_serial_print_string(const char *str);

/** print an integer to the serial line
 *  @param val value to be printed  
 *  @param fieldWidth width (in char) of the value printed (right aligned)
 **/
void tpl_serial_print_int(int32_t val, uint8_t fieldWidth);

/** configure the serial line. Should be called at startup.*/
void tpl_serial_begin();

/** return the nb of available chars in the rx buffer */
uint16_t tpl_serial_available();

/** @return the last value received. If the rx buffer is empty,
 * it returns 0xff
 */
char tpl_serial_read();
#endif
