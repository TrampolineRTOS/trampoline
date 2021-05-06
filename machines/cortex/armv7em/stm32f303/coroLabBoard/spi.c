#include "spi.h"
#include "stm32f3xx.h"


//use SPI1:
// CS MCP  : PA11 (I/O) - Arduino D10
// CS TFT  : PA4  (I/O) - Arduino A3
// MOSI: PB5 (AF5)  - Arduino D11
// MISO: PB4 (AF5)  - Arduino D12
// SCK : PB3 (AF5)  - Arduino D13
void setupSPI()
{
	//1 - input clock = 64MHz.
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	asm("nop");
	//reset peripheral (mandatory!)
	RCC->APB2RSTR |=  RCC_APB2RSTR_SPI1RST;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI1RST;
	//init procedure p.962 - section 30.5.7
	//2 - GPIOs
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN | //clock for GPIOA
	               RCC_AHBENR_GPIOBEN;  //clock for GPIOB
	asm("nop");					//wait until GPIOx clock is Ok.
	GPIOB->OSPEEDR = GPIO_OSPEEDER_OSPEEDR3 |
					 GPIO_OSPEEDER_OSPEEDR4 |
					 GPIO_OSPEEDER_OSPEEDR5 ;
	GPIOA->MODER |= GPIO_MODER_MODER11_0 |	//PA11 output (CS)
	                GPIO_MODER_MODER4_0;    //PA4  output (CS)
	GPIOB->AFR[0] |= 5 << 12 | //alternate func AF5 
	                 5 << 16 | //for 3 pins
	                 5 << 20;
	GPIOB->MODER |= GPIO_MODER_MODER3_1| //alternate function
	                GPIO_MODER_MODER4_1| //for these 3 pins
	                GPIO_MODER_MODER5_1;
	GPIOB->PUPDR |= 1 << 6 | //pull-up...
				    1 << 8|
				    1 << 10;
	//3 - Write the CR1 register
	SPI1->CR1 = SPI_CR1_BR_1 |	//fPCLK/8 => 8MHz (max 10MHz)
				//SPI_CR1_BR_2 |	//fPCLK/128 => 0.5MHz (tmp)
				SPI_CR1_MSTR ;	//master mode
	SPI1->CR2 = 0x7 << 8 | //select 8 bits
				SPI_CR2_FRXTH |			//Fifo RX threshold 8-bits
				SPI_CR2_SSOE;
	SPI1->CR1 |= SPI_CR1_SPE ;	//spi enabled
}

void beginTransaction()
{
	volatile uint16_t __attribute__((unused)) tmp;
	//while(SPI1->SR & SPI_SR_BSY);
	//while(SPI1->SR & SPI_SR_RXNE) //fifo not empty
	//	tmp = SPI1->DR;	//empty the Rx fifo
	GPIOA->BSRR = GPIO_BSRR_BR_11;	//CS=0
}

void endTransaction()
{
	while(SPI1->SR & SPI_SR_BSY);
	GPIOA->BSRR = GPIO_BSRR_BS_11;	//CS=1
}

//low speed transfer:
// * wait until fifo is not full
// * send data
// * be sure that transfer is complete
// * and return the last value.
uint8_t transfer8(uint8_t val)
{
	volatile uint16_t __attribute__((unused)) tmp;
	volatile SPI_TypeDef *__attribute((unused)) spi=SPI1;
	while(SPI1->SR & SPI_SR_BSY);
	while(SPI1->SR & SPI_SR_RXNE)  //fifo not empty
		tmp = SPI1->DR;	//empty the Rx fifo
	*(__IO uint8_t *)&SPI1->DR = val;
	while(SPI1->SR & SPI_SR_BSY);
	//while(!(SPI1->SR & SPI_SR_RXNE));
	return *(__IO uint8_t *)&SPI1->DR;
}

//higher speed write transfer (than transfer8)
// * wait until TX fifo is not full
// * send data
void write8(uint8_t val)
{
	//Fifo tx level full?
	while(((SPI1->SR & SPI_SR_FTLVL) >> 11) == 3); 
	*(__IO uint8_t *)&SPI1->DR = val;
}

