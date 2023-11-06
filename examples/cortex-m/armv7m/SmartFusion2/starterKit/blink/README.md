# Blink example

This application is a simple periodic example wich toggles the two green leds (DS3, DS4) of the board.
Have a look into "blink.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

Configure the application with

``
goil --target=cortex-m/armv7m/SmartFusion2 --templates=../../../../../../goil/templates/ blink.oil
``

Then make with:

``
./make.py
``

The executable should be flashed using SoftConsole from Microsemi on Windows.
