#include "teensy31_gpio.h"
#include "mk20dx256.h"

void digitalWrite(uint8 pin, uint8 val)
{
//--- Port PTC5 en sortie : led Teensy
  PORTC_PCR5 = (1 << 8) ;
  GPIOC_PDDR |= (1 << 5) ;

  GPIOC_PSOR = 1 << 5 ; // Led Teensy on
  
// 	if (pin >= CORE_NUM_DIGITAL) return;
// #ifdef KINETISK
// 	if (*portModeRegister(pin)) {
// 		if (val) {
// 			*portSetRegister(pin) = 1;
// 		} else {
// 			*portClearRegister(pin) = 1;
// 		}
// #else
// 	if (*portModeRegister(pin) & digitalPinToBitMask(pin)) {
// 		if (val) {
// 			*portSetRegister(pin) = digitalPinToBitMask(pin);
// 		} else {
// 			*portClearRegister(pin) = digitalPinToBitMask(pin);
// 		}
// #endif
// 	} else {
// 		volatile uint32 *config = portConfigRegister(pin);
// 		if (val) {
// 			// TODO use bitband for atomic read-mod-write
// 			*config |= (PORT_PCR_PE | PORT_PCR_PS);
// 			//*config = PORT_PCR_MUX(1) | PORT_PCR_PE | PORT_PCR_PS;
// 		} else {
// 			// TODO use bitband for atomic read-mod-write
// 			*config &= ~(PORT_PCR_PE);
// 			//*config = PORT_PCR_MUX(1);
// 		}
// 	}
// 
}

uint8 digitalRead(uint8 pin)
{
// 	if (pin >= CORE_NUM_DIGITAL) return 0;
// #ifdef KINETISK
// 	return *portInputRegister(pin);
// #else
// 	return (*portInputRegister(pin) & digitalPinToBitMask(pin)) ? 1 : 0;
// #endif
  return 0;
}



void pinMode(uint8 pin, uint8 mode)
{
// 	volatile uint32 *config;
// 
// 	if (pin >= CORE_NUM_DIGITAL) return;
// 	config = portConfigRegister(pin);
// 
// 	if (mode == OUTPUT) {
// #ifdef KINETISK
// 		*portModeRegister(pin) = 1;
// #else
// 		*portModeRegister(pin) |= digitalPinToBitMask(pin); // TODO: atomic
// #endif
// 		*config = PORT_PCR_SRE | PORT_PCR_DSE | PORT_PCR_MUX(1);
// 	} else {
// #ifdef KINETISK
// 		*portModeRegister(pin) = 0;
// #else
// 		*portModeRegister(pin) &= ~digitalPinToBitMask(pin);
// #endif
// 		if (mode == INPUT) {
// 			*config = PORT_PCR_MUX(1);
// 		} else {
// 			*config = PORT_PCR_MUX(1) | PORT_PCR_PE | PORT_PCR_PS; // pullup
// 		}
// 	}
}
