#include <msp430.h>
#include <stdlib.h> /* NULL */
#include "tpl_clocks.h"
#include "tpl_app_define.h" /* buffer sizes */ 
#include "serial.h"

#define OS_START_SEC_CONST_16BIT
#include "tpl_memmap.h"

/** these 2 tabulars are generated from the serial.py script
 *  that off-line compute the register values to configure
 *  UART timings (depending on both the input frequency (dco)
 *  and the uart frequency (9600 bauds)
 */  

// 9600 bauds
// const uint16_t tpl_brwTab[] = {
// 	0x6, 0x6, 0x11, 0x22, 0x16, 0x2d, 0x1a, 0x34, 
// 	0x22, 0x68, 0x2d, 0x88, 0x34, 0x9c, 0x0, 0x0};
// const uint16_t tpl_mctlwTab[] = {
// 	0x2081, 0x2081, 0x861, 0x11b1, 0x6bc1, 0x2091, 0xb601, 0x2511, 
// 	0x11b1, 0xb621, 0x2091, 0x55b1, 0x2511, 0x41, 0x0, 0x0};

// 19200 bauds
// const uint16_t tpl_brwTab[] = {
// 	0x3, 0x3, 0x8, 0x11, 0xb, 0x16, 0xd, 0x1a, 
// 	0x11, 0x34, 0x16, 0x44, 0x1a, 0x4e, 0x0, 0x0};
// const uint16_t tpl_mctlwTab[] = {
// 	0x241, 0x241, 0x1b1, 0xad51, 0x4461, 0x6bc1, 0x2501, 0xb601, 
// 	0xad51, 0x2511, 0x6bc1, 0xbb51, 0xb601, 0x21, 0x0, 0x0};

// 28800 bauds
// const uint16_t tpl_brwTab[] = {
// 	0x2, 0x2, 0x5, 0xb, 0x7, 0xf, 0x8, 0x11, 
// 	0xb, 0x22, 0xf, 0x2d, 0x11, 0x34, 0x0, 0x0};
// const uint16_t tpl_mctlwTab[] = {
// 	0xbb21, 0xbb21, 0xb7c1, 0x191, 0xab91, 0x131, 0xf7a1, 0xdd51, 
// 	0x191, 0xabb1, 0x131, 0x2091, 0xdd51, 0x2511, 0x0, 0x0};

// 57600 bauds
const uint16_t tpl_brwTab[] = {
	0x1, 0x1, 0x2, 0x5, 0x3, 0x7, 0x4, 0x8, 
	0x5, 0x11, 0x7, 0x16, 0x8, 0x1a, 0x0, 0x0};
const uint16_t tpl_mctlwTab[] = {
	0x4a11, 0x4a11, 0x49e1, 0xabc1, 0xddc1, 0xab91, 0x5551, 0xf7a1, 
	0xabc1, 0xdd51, 0xab91, 0x6bc1, 0xf7a1, 0xb601, 0x0, 0x0};

#define OS_STOP_SEC_CONST_16BIT
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_16BIT
#include "tpl_memmap.h"

/* TX buffer 
 * write index = (read + size) % capacity
 * */
#if SERIAL_TX_BUFFER_SIZE > 0
#if SERIAL_TX_BUFFER_SIZE > 255
  typedef uint16_t tpl_serial_tx_ring_buffer_index_t;
#else 
  typedef uint8_t  tpl_serial_tx_ring_buffer_index_t;
#endif
struct tpl_serial_tx_ring_buffer
{
	uint8_t  buffer[SERIAL_TX_BUFFER_SIZE];
	volatile tpl_serial_tx_ring_buffer_index_t read;
	volatile tpl_serial_tx_ring_buffer_index_t size;
};

struct tpl_serial_tx_ring_buffer tx_buffer = { { 0 }, 0, 0 };

#endif /* SERIAL_TX_BUFFER_SIZE */

uint8_t tpl_serial_tx_mode = 0;

/* RX buffer */
#if SERIAL_RX_BUFFER_SIZE > 0
#if SERIAL_RX_BUFFER_SIZE > 255
  typedef uint16_t tpl_serial_rx_ring_buffer_index_t;
#else 
  typedef uint8_t  tpl_serial_rx_ring_buffer_index_t;
#endif
struct tpl_serial_rx_ring_buffer
{
	uint8_t  buffer[SERIAL_RX_BUFFER_SIZE];
	volatile tpl_serial_rx_ring_buffer_index_t read;
	volatile tpl_serial_rx_ring_buffer_index_t size;
};

struct tpl_serial_rx_ring_buffer rx_buffer = { { 0 }, 0, 0 };
#endif /* SERIAL_RX_BUFFER_SIZE */

#define OS_STOP_SEC_VAR_16BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

void tpl_serial_update_freq()
{
	uint16_t dcoConfig = tpl_getDCOConfig();
	/* set Software reset (and reinit register) */
	UCA0CTLW0 = UCSWRST;	
	/* default 8N1, lsb first, uart, input clk SMCLK */
	UCA0CTLW0 |= UCSSEL__SMCLK;
	/* baud rates are pre-calculated for 9600. */
	UCA0BRW   = tpl_brwTab[dcoConfig];
	UCA0MCTLW = tpl_mctlwTab[dcoConfig];
	/* get out of reset state */
	UCA0CTLW0 &= ~UCSWRST;
}

int tpl_serial_putchar(char c)
{
#if SERIAL_TX_BUFFER_SIZE > 0
	/* overflow depends on the tx mode */
	if(tpl_serial_tx_mode == SERIAL_TX_MODE_BLOCK)
	{
		while(tx_buffer.size == SERIAL_TX_BUFFER_SIZE) { 
			LPM3; /* wait until it is not full */
		}
	} else {/* SERIAL_TX_MODE_SKIP mode assumed */
		if(tx_buffer.size == SERIAL_TX_BUFFER_SIZE) { 
			/* overflow */
			return 1;
		}
	}
	/* add in ring buffer */
	UCA0IE &= ~UCTXIE; /* disable TX interrupt */
	const uint16_t wi = (tx_buffer.read + tx_buffer.size) % SERIAL_TX_BUFFER_SIZE;
	tx_buffer.buffer[wi] = c;
	tx_buffer.size += 1;
	/* make sure interrupt is enabled */
	UCA0IE |= UCTXIE;
#else
	/* wait until previous op is ok */
	while(!(UCA0IFG & UCTXIFG));
	UCA0IFG &= ~UCTXIFG; /* RAZ */
	UCA0TXBUF = c;
#endif
	return 0;
}

int tpl_serial_print_string(const char *str)
{
	int overflow = 0;
	while(*str && !overflow) {	
		overflow |= tpl_serial_putchar(*str++);
	}
	return overflow;
}

int tpl_serial_print_int(int32_t val, uint8_t fieldWidth)
{
	int overflow = 0;
	uint8_t negative = 0; 
	char buffer[11]; /* min val: -2147483648 => 11 chars */
	int8_t index = 0;
	
	if (val < 0)
	{
      negative = 1;
	  val = -val;
	}
	if (val == 0) buffer[index++] = '0';
	else
	{
		while (val != 0)
		{
			int remaining = val % 10;
			buffer[index++] = (char)remaining + '0';
			val = val / 10;
		}
	}
	if (negative) buffer[index++] = '-';
	int8_t i;
	for (i = index; i < (int8_t)fieldWidth; i++) overflow |= tpl_serial_putchar(' ');
	for (i = index - 1; i >= 0; i--) 
	{
		overflow |= tpl_serial_putchar(buffer[i]);
	}
	return overflow;
}

tpl_freq_update_item tpl_serial_callback = {&tpl_serial_update_freq,NULL};

void tpl_serial_begin(uint8_t txMode)
{
	tpl_serial_tx_mode = txMode;
	/* make sure we are informed of a clock update. */
	tpl_add_freq_update_callback(&tpl_serial_callback);
	/* First: set SMCLK to DCO */
	CSCTL0 = CSKEY;			/* Get access to CSCTLx regs */
	CSCTL2 &= ~SELS_7;      /* Set DCO as SMCLK (clear field..      */
	CSCTL2 |= SELS__DCOCLK; /* .. and set correct DCO value)        */
	/* then remove the DIVS division */
	CSCTL3 &= ~(DIVS0_L | DIVS1_L | DIVS2_L); 
	/* set IO: fonction 10 for P2.0 (Tx) and P2.1 (Rx) */
	P2SEL0 &= ~0x03;
	P2SEL1 |=  0x03;
	/** use USCI A0, that is connected to the USB target.
	 *  connect using 9600 8N1
	 *  set the initial frequency 
	 **/
	tpl_serial_update_freq();
#if SERIAL_RX_BUFFER_SIZE > 0
	/* RX interrupt only if there is a buffer */
	UCA0IE |= UCRXIE;
#endif
}

uint16_t tpl_serial_available()
{
#if SERIAL_RX_BUFFER_SIZE > 0
	return rx_buffer.size;
#else
	return UCA0IFG & UCRXIFG; /* as UCRXIFG is bit 0 */
#endif
}

char tpl_serial_read(void)
{
	char result;
#if SERIAL_RX_BUFFER_SIZE > 0
	UCA0IE &= ~UCRXIE; /* disable RX interrupt (rx_buffer manip)*/
	if (rx_buffer.size > 0) {
		result = rx_buffer.buffer[rx_buffer.read];
		rx_buffer.read = (rx_buffer.read + 1) % SERIAL_RX_BUFFER_SIZE;
		rx_buffer.size --;
	} else {
		result = 0xff;
	}
	UCA0IE |= UCRXIE; /* re-enable RX interrupt */
#else
	if(UCA0IFG & UCRXIFG) /* RX interrupt set*/
		result =  UCA0RXBUF;
	else
		result =  0xff;
#endif
	return result;
}

void tpl_serial_tx_fifo_flush()
{
	#if SERIAL_TX_BUFFER_SIZE > 0
		/* wait until it is empty */
		while(tx_buffer.size != 0) ; //TODO LPM3
	#endif
}

void tpl_serial_tx_fifo_discard()
{
#if SERIAL_TX_BUFFER_SIZE > 0
	//the current transmitting byte is sent, but
	//won't generate any interrupt.
	UCA0IE &= ~UCTXIE; /* disable TX interrupt */
	//reinit TX fifo.
	tx_buffer.read = 0;
	tx_buffer.size = 0;
#endif //one buffer.
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#if __GXX_ABI_VERSION == 1011 || __GXX_ABI_VERSION == 1013
/* ISR1 related to USCI_A0_VECTOR */
__attribute__((section ( ".irq_func"))) 
void __attribute__ ((interrupt())) tpl_direct_irq_handler_USCI_A0_VECTOR (void)
#elif __GXX_ABI_VERSION == 1002
void __attribute__((interrupt(USCI_A0_VECTOR))) tpl_direct_irq_handler_USCI_A0_VECTOR()
#else
    #error "Unsupported ABI"
#endif
{
#if (SERIAL_TX_BUFFER_SIZE > 0) && (SERIAL_TX_BUFFER_SIZE > 0)
	uint8_t c;
	uint16_t wi; //only for rx.
	switch(UCA0IV) 
	{
#if SERIAL_TX_BUFFER_SIZE > 0
		case USCI_UART_UCTXIFG:
			c = tx_buffer.buffer[tx_buffer.read];
			uint8_t wasFull = 0;
			if(tpl_serial_tx_mode == SERIAL_TX_MODE_BLOCK) {
				wasFull = tx_buffer.size == SERIAL_TX_BUFFER_SIZE;
			}
			tx_buffer.size -= 1;
			tx_buffer.read = (tx_buffer.read+1) % SERIAL_TX_BUFFER_SIZE;
			if(tx_buffer.size == 0) /* empty */
			{
				UCA0IE &= ~UCTXIE; /* disable TX interrupt */
			} else { 
				
				/* RAZ. If empty, does not remove the flag 
				 * so that next time a char is written, the interrupt
				 * is re-enabled, and the interrupt will occur 
				 * immediately
				 */
				UCA0IFG &= ~UCTXIFG;
			}
			UCA0TXBUF = c; /* send char */
			if(wasFull) { /* only for the TX blocking mode */
				/* WARNING, if we were in LPM from user space, we get out!!! */
				LPM3_EXIT; /* if buffer is full, we have entered in LPM */
			}
			break;
#endif

#if SERIAL_RX_BUFFER_SIZE > 0
		case USCI_UART_UCRXIFG:
			wi = (rx_buffer.read + rx_buffer.size) % SERIAL_RX_BUFFER_SIZE;
			rx_buffer.buffer[wi] = UCA0RXBUF;
			if(rx_buffer.size == SERIAL_RX_BUFFER_SIZE) /* overflow */
			{
				/* overwrite the oldest value (i.e. read idx increased) */
				rx_buffer.read = (rx_buffer.read + 1) % SERIAL_RX_BUFFER_SIZE;
			} else {
				rx_buffer.size += 1;
			}
			UCA0IFG &= ~UCRXIFG;
			break;
#endif
	}
#endif //one buffer.
}



