#ifndef __PIN_ACCESS_H__
#define __PIN_ACCESS_H__

//port name
#define PORTA 0
#define PORTB 1

//mode
#define DISABLE        0
#define OUTPUT         1
#define INPUT          2
#define INPUT_PULLUP   3
#define INPUT_PULLDOWN 4

//pin configuration
// - port is either PORTA or PORTB
// - numBit is bit number: 0 to 31
// - mode is pin mode: DISABLE, OUTPUT, ...
void pinMode(unsigned char port, 
             unsigned char numBit,
             unsigned char mode);

//pin should be configured:
// state is high if value different from 0.
// state is low if value=0
void digitalWrite(unsigned char port, 
                  unsigned char numBit,
                  unsigned int value);

//pin should be configured:
//toggles pin state
// 0 => 1
// 1 => 0
void digitalToggle(unsigned char port, 
                  unsigned char numBit);

//pin should be configured:
//return: 
// - 0xFF if there is an error (bad port/pin number)
// - 0 or 1 depending on the pin state
unsigned char digitalRead(unsigned char port,
                          unsigned char numBit);

#endif
