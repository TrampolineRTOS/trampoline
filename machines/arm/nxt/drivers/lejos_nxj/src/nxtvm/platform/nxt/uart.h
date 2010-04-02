#ifndef __AT91_UART_H__
#  define __AT91_UART_H__

#  include "mytypes.h"

/* Main user interface */
void uart_isr_C_0_function(void);
void uart_isr_C_1_function(void);
int uart_init(U32 u, U32 baudRate, U32 dataBits, U32 stopBits, char parity);
void uart_close(U32 u);
int uart_holding(U32 u);
int uart_get_byte(U32 u, U8 *b);
int uart_put_byte(U32 u, U8 b);
void uart_put_str(U32 u, const U8 *str);
int uart_clear_rx(U32 u);
int uart_clear_tx(U32 u);
int uart_set_break(U32 u);
int uart_clear_break(U32 u);
#endif
