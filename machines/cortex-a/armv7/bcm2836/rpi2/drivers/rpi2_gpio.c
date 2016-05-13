#include "rpi2_gpio.h"

/**
 * @brief Set GPIO pin function/mode. Used in multiple peripherals.
 *
 * @param[in] gpio_pin       BCM2835 pin number
 * @param[in] mode          GPIO pin function
 *
 * @notapi
 */
void bcm2836_gpio_fnsel(uint32_t gpio_pin, uint32_t gpio_fn) {
  uint32_t gpfnbank = gpio_pin/10;
  uint32_t offset = (gpio_pin - (gpfnbank * 10)) * 3;
  volatile uint32_t *gpfnsel = &GPFSEL0 + gpfnbank;
  *gpfnsel &= ~(0x07 << offset);
  *gpfnsel |= (gpio_fn << offset);
}

void pinMode(uint32 pin, uint8 mode) {

}

void digitalWrite(uint32 ) {

}

uint32 digitalRead(uint32 ) {

}
