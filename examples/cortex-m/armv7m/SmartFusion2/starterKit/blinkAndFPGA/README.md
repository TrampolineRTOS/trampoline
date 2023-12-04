# Blink example with an internal interrupt from FPGA Fabric

This application is a simple periodic example wich toggles the green led DS3 of the board.
Moreover, an interrupt from the FPGA fabriq toggles the green led DS4 of the board.

Have a look into "blinkAndFPGA.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".
Obviously, the FPGA should be set to generate interrupts...

## Build
Configure the application with

``
goil --target=cortex-m/armv7m/SmartFusion2 --templates=../../../../../../goil/templates/ blinkAndFPGA.oil
``

Then make with:

``
./make.py
``

The executable should be flashed using SoftConsole from Microsemi on Windows.
