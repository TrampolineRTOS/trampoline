# Basic example for the Coro Lab board (based on Nucleo-32 STM32F303 with TFT display and O/I Expander)

 * a blink task just assures that the system do not crash (green led)
 * an ISR get the interrupt from the I/O expander and starts
	* TaskB4 to TaskB7, depending on the button pressed.

`
goil --target=cortex-m/armv7em/stm32f303/coroLabBoard --templates=../../../../../../goil/templates/ baseCMake.oil
`

This example uses CMake to build binary and add VSCode integration. VSCode requires extensions:
 * C/C++ (Microsoft)
 * Cortex-debug (marus25)
 * CMake tools (Microsoft)

To build the application:
* use goil the first time (bootstrap)
* then open the current folder with VSCode
* select the correct toolkit (cross compiler)
* build the application (F7)
* start the debug (F5). ST-link should be installed

**Note:** the VScode configuration (json files in '.vscode/') can be modified. The files won't be overwritten by another run of goil.
