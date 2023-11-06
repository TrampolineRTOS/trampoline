# Blink example

This application is a simple periodic example wich toggles the amber led (LED 13 or L) of the board.
Have a look into "blink.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

Configure the application with

``
goil --target=cortex-m/armv7m/atsam3x8e/arduino_due --templates=../../../../../../goil/templates/ blink.oil
``

Then make with:

``
./make.py
``

Then flash with:

``
./make.py burn
``
and use the command in JLink prompt:
``
qc
``

Clean project with:

``
./make.py clean
``

The executable can be flashed using JLinkExe.
