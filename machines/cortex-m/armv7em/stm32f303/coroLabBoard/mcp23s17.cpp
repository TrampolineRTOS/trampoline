#include "mcp23s17.h"
#include "spi.h"
#include "stm32f3xx.h"
#ifndef NULL
#define NULL 0
#endif

mcp23s17::mcp23s17()
{
    mOLAT[0] = 0;
    mOLAT[1] = 0;
    for(int i=0;i<16;i++) {
        mCallbacks[i] = NULL;
        mItTypeTab[i] = BOTH;
    }
}

void mcp23s17::begin()
{
    setupSPI();
    readReg(GPIO_A); //ack interrupts on mcp
    readReg(GPIO_B); //ack interrupts on mcp
    //INTEXP on PA9
    //on mcp23s17, default interrupt mode is active low
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN; //clock for GPIOA
    asm("nop");
    GPIOA->MODER &= ~GPIO_MODER_MODER9;	//input
    //GPIOA->PUPDR |= 1 << GPIO_PUPDR_PUPDR9_Pos; //pull-up...

    //RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    //EXTI->IMR  |= EXTI_IMR_MR9;
    //EXTI->FTSR |= EXTI_FTSR_TR9; //falling
    //SYSCFG->EXTICR[3] &= ~SYSCFG_EXTICR3_EXTI9;
    //SYSCFG->EXTICR[3] |= SYSCFG_EXTICR3_EXTI9_PA;
    //NVIC_SetPriority(EXTI9_5_IRQn, 3);
    //NVIC_EnableIRQ(EXTI9_5_IRQn);
}


void mcp23s17::writeReg(uint8_t reg, uint8_t val)
{
    beginTransaction();
    write8(0x40);	//write
    write8(reg);
    write8(val);
    endTransaction();
}

uint8_t mcp23s17::readReg(uint8_t reg)
{
    beginTransaction();
    write8(0x41);	//read
    write8(reg);
    uint8_t result = transfer8(0);
    endTransaction();
    return result;
}

int mcp23s17::pinMode(	port p,
                        unsigned char bitNum,
                        mode m)
{
    if(bitNum > 7) return -1;
    switch(m)
    {
        case OUTPUT:
            //reset bit in IODIR
            clearBitInReg(IODIRA+p,bitNum);
            break;
        case INPUT:
            //set bit in IODIR
            setBitInReg(IODIRA+p,bitNum);
            break;
        case INPUT_PULLUP:
            //set bit in IODIR
            setBitInReg(IODIRA+p,bitNum);
            //set bit in GPPUA
            setBitInReg(GPPUA+p,bitNum);
            break;
        default:
            break;
    }
    return 0;
}

void mcp23s17::digitalWrite(port p,
        uint8_t bitNum,
        bool value)
{
    if(bitNum > 7) return;
    if(value)
        mOLAT[p] |= 1<<bitNum;
    else
        mOLAT[p] &= ~(1<<bitNum);
    writeReg(OLATA+p,mOLAT[p]);
}

int8_t mcp23s17::digitalRead(port p, uint8_t bitNum)
{
    if(bitNum > 7) return -1;
    uint8_t val = readBits(p);
    return !!(val & (1<<bitNum));
}

void mcp23s17::digitalToggle(port p, uint8_t bitNum)
{
    if(bitNum > 7) return;
    mOLAT[p] ^= (1<<bitNum);
    writeReg(OLATA+p,mOLAT[p]);
}

void mcp23s17::setBits(port p,uint8_t bitField)
{
    mOLAT[p] |= bitField;
    writeReg(OLATA+p,mOLAT[p]);
}

void mcp23s17::clearBits(port p,uint8_t bitField)
{
    mOLAT[p] &= ~bitField;
    writeReg(OLATA+p,mOLAT[p]);
}

void mcp23s17::writeBits(port p,uint8_t val)
{
    mOLAT[p] = val;
    writeReg(OLATA+p,mOLAT[p]);
}

uint8_t mcp23s17::readBits(port p)
{
    //no latch access!
    return readReg(GPIO_A+p);
}

void mcp23s17::setBitInReg(uint8_t reg, uint8_t bitNum)
{
    uint8_t val = 0;
    if(bitNum > 7) return;
    val = readReg(reg);
    writeReg(reg,val | (1<<bitNum));
}

void mcp23s17::clearBitInReg(uint8_t reg, uint8_t bitNum)
{
    uint8_t val = 0;
    if(bitNum > 7) return;
    val = readReg(reg);
    writeReg(reg,val & ~(1<<bitNum));
}

//void mcp23s17::attachInterrupt(port p, uint8_t bitNum, itType type,mcpCallBack callback)
void mcp23s17::attachInterrupt(port p, uint8_t bitNum)
{
    if(bitNum > 7) return;
    //2 cases for interrupt:
    // - pin != previous => edge detection
    // - pin != defined value (DEFVAL) => level detection
    clearBitInReg(INTCONA+p,bitNum); //pin!=previous
    //setBitInReg(INTCONA+p,bitNum); //pin!=previous

    //mItTypeTab[8*p+bitNum] = type;
    //set callback
    //mCallbacks[8*p+bitNum] = callback;
    //interrupt enable
    setBitInReg(GPINTENA+p,bitNum);
}

void mcp23s17::detachInterrupt(port p, uint8_t bitNum)
{
    if(bitNum>7) return;
    //set callback
    mCallbacks[8*p+bitNum] = NULL;
    //interrupt disable
    clearBitInReg(GPINTENA+p,bitNum);
}

char mcp23s17::getInterrupt() {
    //detect falling edge only.
    const uint8_t valb = readReg(INTFB);
    const uint8_t capb=readReg(INTCAPB);
    char result = (valb & ~capb) & 0xff;
    return result;
}

//declare one instance.
mcp23s17 ioExt;

