#include "tpl_clocks.h"
#include <msp430.h>
#include <stdlib.h> //NULL

#define OS_START_SEC_CONST_16BIT
#include "tpl_memmap.h"

/** these 2 tabulars are generated from the serial.py script
 *  that off-line compute the register values to configure
 *  UART timings (depending on both the input frequency (dco)
 *  and the uart frequency (115200 bauds)
 */  
const uint16_t tpl_brwTab[] = {
	0x8, 0x8, 0x1, 0x2, 0x1, 0x3, 0x2, 0x4, 
	0x2, 0x8, 0x3, 0xb, 0x4, 0xd, 0x0, 0x0};
const uint16_t tpl_mctlwTab[] = {
	0xd600, 0xd600, 0x1171, 0x44e1, 0x52e1, 0xddc1, 0xbb21, 0x5551, 
	0x44e1, 0xf7a1, 0xddc1, 0x4461, 0x5551, 0x2501, 0x0, 0x0};

#define OS_STOP_SEC_CONST_16BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

void tpl_serial_update_freq()
{
	uint16_t dcoConfig = tpl_getDCOConfig();
	//set Software reset (and reinit register)
	UCA0CTLW0 = UCSWRST;	
	//default 8N1, lsb first, uart, input clk SMCLK
	UCA0CTLW0 |= UCSSEL__SMCLK;
	//baud rates are pre-calculated for 115200.
	UCA0BRW   = tpl_brwTab[dcoConfig];
	UCA0MCTLW = tpl_mctlwTab[dcoConfig];
	//get out of reset state
	UCA0CTLW0 &= ~UCSWRST;	
}

void tpl_serial_putchar(char c)
{
	//wait until previous op is ok
	while(!(UCA0IFG & UCTXIFG));
	UCA0IFG &= ~UCTXIFG; //RAZ
	UCA0TXBUF = c;
}

void tpl_serial_print_string(char *str)
{
	while(*str)	
		tpl_serial_putchar(*str++);
}

tpl_freq_update_item tpl_serial_callback = {&tpl_serial_update_freq,NULL};

void tpl_serial_begin()
{
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
	 *  connect using 115200 8N1
	 *  set the initial frequency 
	 **/
	tpl_serial_update_freq();
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

