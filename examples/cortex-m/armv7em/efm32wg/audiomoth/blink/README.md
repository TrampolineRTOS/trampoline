# Basic blink example

This example use the CMake build system with VSCode.

- First open a terminal from this folder
- Then run goil
```sh
goil --target=cortex/armv7em/efm32wg --templates=../../../../../../goil/templates/ blink.oil
```
- Finally open vscode from this folder
```sh
code .
```
- Now use a toolkit to compile the application
- Finally flash and debug by preessing F5 within VSCode