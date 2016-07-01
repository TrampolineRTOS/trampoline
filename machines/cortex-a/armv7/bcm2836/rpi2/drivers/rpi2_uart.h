#ifndef _RPI2_UART_H_
#define _RPI2_UART_H_

#include "tpl_os_std_types.h"

/*****************************************************************************
 *                        UART FUNCTIONS
 *
 * Cf BCM2835 documentation, chapter 13, page 175.
 *
 *****************************************************************************/
uint8 mystrlen(const unsigned char*);
void uart_init();
void uart_write_char(unsigned char);
void uart_write_chars(const unsigned char*, uint8);
void uart_write_string(const unsigned char*);
void uart_write_strings(const unsigned char*);
void uart_disable();
void hexstrings (unsigned int);
void hexstring (unsigned int);
void test_uart();

// #define uart_write_cr() uart_write_char((unsigned char)0x0D)
// #define uart_write_lf() uart_write_char((unsigned char)0x0A)

#endif /* _RPI2_UART_H_ */
