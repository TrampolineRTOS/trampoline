#ifndef __PIN_ACCESS_H__
#define __PIN_ACCESS_H__

#include "stm32f4xx.h"

#ifdef __cplusplus
  extern "C" {
#endif /* __cplusplus */

//mode
typedef enum {UNUSED, OUTPUT, INPUT, INPUT_PULLUP, INPUT_PULLDOWN} mode;

/* configure a pin
 * - port is GPIOA, GPIOB, ...
 * - numBit is the pin number (0 to 15)
 * - mode is in UNUSED , OUTPUT, INPUT, ...)
 */
int pinMode(GPIO_TypeDef *port, 
            unsigned char numBit,
            mode m);

/* set a pin, previously configured as OUTPUT
 * high state if 'value' is different from 0
 * low state if 'value' is 0.
 */
void digitalWrite(GPIO_TypeDef *port, 
                  unsigned char numBit,
                  unsigned int value);

/* toggle output state of a pin
 * 0 => 1
 * 1 => 0
 */
void digitalToggle(GPIO_TypeDef *port, 
                  unsigned char numBit);


/* read the state of a pin, previously configured as input.
 * returns
 * - 0xFF in case of error (bad arguments)
 * - 0 or 1, depending on pin state.
 */
unsigned char digitalRead(GPIO_TypeDef *port,
                          unsigned char numBit);

/* Activate the alternate function in parameter for the
 * pin.
 * \param AFId the alternate function id, between 0 and 15
 * \return
 * - 0xFF in case of error (bad arguments)
 */
unsigned char pinAlt(GPIO_TypeDef *port,
                     uint32_t numBit,
                     uint32_t AFId);

/* Activate the analog mode for a pin
 * Warning: it does not configure the ADC!
 * \return
 * - 0xFF in case of error (bad arguments)
 * - 0 in case of success.
 */
unsigned char pinAnalog(GPIO_TypeDef *port, uint32_t numBit);

#ifdef __cplusplus
  }
#endif /* __cpusplus */

#endif
