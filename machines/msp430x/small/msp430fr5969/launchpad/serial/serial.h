#ifndef __TPL_SERIAL_H__
#define __TPL_SERIAL_H__

/* function that should be called each time 
 * the DCO frequency is changed to recalculate the
 * correct baud rate parameters.
 **/
void tpl_serial_update_freq();

/** simply put one char on the serial line */
void tpl_serial_putchar(char c);

/** print a standard null terminated string on the serial line*/
void tpl_serial_print_string(char *str);

/** configure the serial line. Should be called at startup.*/
void tpl_serial_begin();
#endif
