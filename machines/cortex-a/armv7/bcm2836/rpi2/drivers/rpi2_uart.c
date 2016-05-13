#include "bcm2836.h"
#include "rpi2_uart.h"
#include "bcm2836_misc.h"
#include "emblib.h"

/*****************************************************************************
 *                        UART FUNCTIONS
 *
 * Cf BCM2835 documentation, chapter 13, page 175.
 *
 *****************************************************************************/
void nothing(unsigned int d) {
  //nothing
}

 void uart_init() {
   unsigned int ra;

   writeToReg(AUX_ENABLES,1);
   writeToReg(AUX_MU_IER_REG,0);
   writeToReg(AUX_MU_CNTL_REG,0);
   writeToReg(AUX_MU_LCR_REG,3);
   writeToReg(AUX_MU_MCR_REG,0);
   writeToReg(AUX_MU_IER_REG,0);
   writeToReg(AUX_MU_IIR_REG,0xC6);
   writeToReg(AUX_MU_BAUD_REG,270);
   ra=readFromReg(GPFSEL1);
   ra&=~(7<<12); //gpio14
   ra|=2<<12;    //alt5
   ra&=~(7<<15); //gpio15
   ra|=2<<15;    //alt5
   writeToReg(GPFSEL1,ra);
   writeToReg(GPPUD,0);
   for(ra=0;ra<150;ra++) nothing(ra);
   writeToReg(GPPUDCLK0,(1<<14)|(1<<15));
   for(ra=0;ra<150;ra++) nothing(ra);
   writeToReg(GPPUDCLK0,0);
   writeToReg(AUX_MU_CNTL_REG,3);
   //
  //  /* Clear interrupts */
  //  writeToAddress(UART0_ICR, 0x7FF);
  //  /* Set integer part of Baud rate divisor to 1. */
  //  writeToAddress(UART0_IBRD, 1); //NOTE: Number not in hexadecimal
  //  /* Set fractional part of Baud rate divisor to 40. */
  //  writeToAddress(UART0_FBRD, 40); //NOTE: Number not in hexadecimal
  //  /* Enable FIFO and set word length to 8. */
  //  writeToAddress(UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));
  //  /* Set all supported UART-related interrupt masks. */
  //  writeToAddress(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5)
  //                             | (1 << 6) | (1 << 7) | (1 << 8)
  //                             | (1 << 9) | (1 << 10));
  //  /* Enable both transmission and reception over the UART. */
  //  writeToAddress(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
}

/* Returns the length of a C-style string. */
uint8 mystrlen(const unsigned char* str) {
  uint8 ret = 0;

 	while ((str[ret] != 0) & (ret < 256)) {
 		ret++;
 	}

 	return ret;
}

void uart_write_char(unsigned char c) {
  while(1)
  {
      if(readFromReg(AUX_MU_LSR_REG)&0x20) break;
  }
  writeToReg(AUX_MU_IO_REG,c);
 // 	/* Wait for UART to become ready to transmit
  //  * wait while bit 5 in UART_FR is set, meaning that the
  //  * transmit FIFO is full.
  //  */
  // while (readFromAddress(UART0_FR) & (1 << 5)){}
  //
 // 	/* When FIFO is enabled, data written to UART_DR will be put in the FIFO. */
 // 	writeToAddress(UART0_DR, byte);
}
 /*
 unsigned char uart_getc(){
 	while (read_from_address(UART0_FR) & (1 << 4)){
 		//Do nothing...
 	}
 	return read_from_address(UART0_DR);
 }
 */

/* Writes all the chars in buffer to the UART. */
void uart_write_chars(const unsigned char* buffer, uint8 size) {
  uint8 i;

 	for (i = 0; i < size; i++) {
 		uart_write_char(buffer[i]);
 	}
}

/* Simply a wrapper for uart_write_chars */
void uart_write_string(const unsigned char* str) {
  uart_write_chars((const unsigned char*) str, mystrlen((const unsigned char*)str));
  uart_write_char((unsigned char)0x0D);
  uart_write_char((unsigned char)0x0A);
}

/* Simply a wrapper for uart_write_chars */
void uart_write_strings(const unsigned char* str) {
  uart_write_chars((const unsigned char*) str, mystrlen((const unsigned char*)str));
}

/* Disables the UART. */
void uart_disable() {
  /* Disable UART */
 	writeToAddress(UART0_CR, 0);

 	/*
 	//Empty RX FIFO if necessary
 	if (read_from_address(UART0_CR) & (1 << 0)) {
 		//Empty RX FIFO
 		while (!(read_from_address(UART0_FR) & (1 << 4)))
 			read_from_address(UART0_DR);

 		//Empty TX FIFO
 		while (!(read_from_address(UART0_FR) & (1 << 7)))
 			delay();

 		//Delay while busy
 		while (!(read_from_address(UART0_FR) & (1 << 3)))
 			delay();

 		//Disable UART
 		write_to_address(UART0_CR, 0);
 	}
 	*/
}

void hexstrings ( unsigned int d )
{
    //unsigned int ra;
    unsigned int rb;
    unsigned int rc;

    rb=32;
    while(1)
    {
        rb-=4;
        rc=(d>>rb)&0xF;
        if(rc>9) rc+=0x37; else rc+=0x30;
        uart_write_char(rc);
        if(rb==0) break;
    }
    uart_write_char(0x20);
}

void hexstring ( unsigned int d )
{
    hexstrings(d);
    uart_write_char(0x0D);
    uart_write_char(0x0A);
}

void test_uart() {
    uart_write_char('U');
}
