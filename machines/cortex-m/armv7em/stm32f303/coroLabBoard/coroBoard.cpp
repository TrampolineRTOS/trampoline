#include "stm32f3xx.h"
#include "mcp23s17.h"
#include "pinAccess.h"
#include "tft.h"

void setupIOExtender()
{
    ioExt.begin();
    //portA => leds.
    for(int i=0; i<8;i++)
        ioExt.pinMode(mcp23s17::PORTA,i,mcp23s17::OUTPUT);
    //portB => push buttons and switches
    for(int i=0; i<8;i++)
        ioExt.pinMode(mcp23s17::PORTB,i,mcp23s17::INPUT_PULLUP);
    ioExt.attachInterrupt(mcp23s17::PORTB,4);
    ioExt.attachInterrupt(mcp23s17::PORTB,5);
    ioExt.attachInterrupt(mcp23s17::PORTB,6);
    ioExt.attachInterrupt(mcp23s17::PORTB,7);
}

void setupTimer()
{
    // Timer TIM6 INIT
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
    asm("nop");
    // mandatory reset
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM6RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM6RST;
    asm("nop");
    TIM6->PSC = 64 - 1; /* tick@1us */
    TIM6->EGR |= TIM_EGR_UG; /* take into account PSC update */
    TIM6->CR1 |= TIM_CR1_CEN;
}

void resetTimer()
{
    TIM6->CNT = 0;
}

uint32_t getTimerValue()
{
   return TIM6->CNT;
}

void initCoroBoard()
{
	Tft.setup();
	setupIOExtender();
	setupTimer();
	pinMode(GPIOB,0,OUTPUT);	//user led is PB0
}

