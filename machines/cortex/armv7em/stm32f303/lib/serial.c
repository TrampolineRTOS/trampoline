#include "pinAccess.h"
#include "serial.h"

/* TX FIFO buffer
 * updated in interrupt handler
 */
volatile char tpl_serial_TXbuf[SERIAL_TX_BUFFER_SIZE];

/* TX head of TX FIFO index (write index)
 * updated in interrupt handler
 */
volatile int tpl_serial_TXbufHead;

/* TX head of TX FIFO index (write index)
 * updated in interrupt handler
 */
volatile int tpl_serial_TXbufTail;

/** System Core clock in Hertz. Defined in system files.*/
extern uint32_t SystemCoreClock;

void tpl_serial_begin()
{
    tpl_serial_TXbufHead = 0;
    tpl_serial_TXbufTail = 0;

    pinAlt(GPIOA,2,7); // PA2 (TX) => alternative config 7

    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    __asm("nop");
    RCC->APB1RSTR |=  RCC_APB1RSTR_USART2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST;
    __asm("nop");
	//PCLK is the default clock 
	//(choice is in RCC->CFGR3, but not for F303x8)
	const uint32_t PCLK =  SystemCoreClock >> 1;
    USART2->BRR = PCLK/115200; //115200 bauds

    USART2->CR2 = 0; //default
    USART2->CR3 = 0; //default
    USART2->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
    NVIC_EnableIRQ(USART2_IRQn);
    NVIC_SetPriority(USART2_IRQn,1);
}

//void USART2_Handler()
void itUsart()
{
    //interrupt updates tpl_serial_TXbufTail index!!

    //only "TX Empty interrupt" is enabled
    char c = tpl_serial_TXbuf[tpl_serial_TXbufTail];
    tpl_serial_TXbufTail = (tpl_serial_TXbufTail+1)%SERIAL_TX_BUFFER_SIZE;
    if(tpl_serial_TXbufTail == tpl_serial_TXbufHead) { //empty
        USART2->CR1 &= ~USART_CR1_TXEIE; //remove the interrupt.
    }
    //send
    USART2->TDR = c;
}

void tpl_serial_putchar(char c)
{
    if(c == '\n') tpl_serial_putchar('\r');   // newline should be preceeded by CR

    //routine updates tpl_serial_TXbufHead index
    const int next=(tpl_serial_TXbufHead+1) % SERIAL_TX_BUFFER_SIZE;
    while(next == tpl_serial_TXbufTail); //TX buffer full. Wait
    tpl_serial_TXbuf[tpl_serial_TXbufHead] = c;
    tpl_serial_TXbufHead = next;
    USART2->CR1 |= USART_CR1_TXEIE; //TX empty interrupt
}

void tpl_serial_print_string(const char* str)
{
    while(*str) tpl_serial_putchar(*str++);
}

void tpl_serial_print_int(int32_t val, int base, int fieldWidth)
{
    if(base != 10 && base != 16)
    {
        tpl_serial_print_string("<base error>");
        return;
    }

    char negative = 0;
    char buffer[11]; /* min val: -2 000 000 000 => 11 chars */
    int index = 0;

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
            char digit;
            int remaining = val % base;
            if(remaining<10) digit = (char)(remaining + (int)'0');
            else digit=(char)(remaining-10+(int)'A');
            buffer[index++] = digit;
            val = val / base;
        }
    }
    if (negative) buffer[index++] = '-';
    int i;
    for (i = index; i < fieldWidth; i++) tpl_serial_putchar(' ');
    for (i = index - 1; i >= 0; i--)
    {
        tpl_serial_putchar(buffer[i]);
    }
}

void tpl_serial_wait_for_tx_complete()
{
    /* The TX Interrupt is disabled when the TX buffer
     * is empty.
     */
    while(USART2->CR1 & USART_CR1_TXEIE);
}
