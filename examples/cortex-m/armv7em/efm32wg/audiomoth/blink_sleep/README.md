# Basic blink example

Difference with blink example is that the EFM32 is put in DeepSleep in Idle Task.
An interruption on the RTC is done every ms to wake up the core.

This example use the CMake build system with VSCode.

- First open a terminal from this folder
- Then run goil
```sh
goil --target=cortex-m/armv7em/efm32wg --templates=../../../../../../goil/templates/ blink.oil
```
- Finally open vscode from this folder
```sh
code .
```
- Now use a toolkit to compile the application
- Finally flash and debug by preessing F5 within VSCode