# Basic example for the Coro Lab board (based on Nucleo-32 STM32F303 with TFT display and O/I Expander)

 * a blink task just assures that the system do not crash (green led)
 * an ISR get the interrupt from the I/O expander and starts
	* TaskB4 to TaskB7, depending on the button pressed.


`
goil --target=cortex-m/armv7em/stm32f303/coroLabBoard --templates=../../../../../../goil/templates/ base.oil
`
