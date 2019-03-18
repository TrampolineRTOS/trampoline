#ifndef __PIN_ACCESS_H__
#define __PIN_ACCESS_H__

#include "stm32f30x.h"

//mode
typedef enum {UNUSED, OUTPUT, INPUT, INPUT_PULLUP, INPUT_PULLDOWN} mode;

//configure a pin
// - port is GPIOA, GPIOB, ...
// - numBit is the pin number (0 to 15)
// - mode is in DISABLE, OUTPUT, INPUT, ...)
int pinMode(GPIO_TypeDef *port, 
            unsigned char numBit,
            mode m);

//set a pin, previously configured as OUTPUT
// high state if 'value' is different from 0
// low state if 'value' is 0.
void digitalWrite(GPIO_TypeDef *port, 
                  unsigned char numBit,
                  unsigned int value);

//toggle output state of a pin
// 0 => 1
// 1 => 0
void digitalToggle(GPIO_TypeDef *port, 
                  unsigned char numBit);

//read the state of a pin, previously configured as input.
//returns
// - 0xFF in case of error (bad arguments)
// - 0 or 1, depending on pin state.
unsigned char digitalRead(GPIO_TypeDef *port,
                          unsigned char numBit);

#endif
