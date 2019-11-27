# Basic example using a data in FRAM

A data stored in FRAM is in a non volatile section, i.e. it won't be re-initialized in case of power failure.

This application is a simple example with 2 variables defined in SRAM and FRAM.
To define the appropriate section that is used, with follow the rules given by the AUTOSAR standard, using a symbol definition, followed by the inclusion of a tpl_memmap.h header file.

This approach make the application independant of the linker directives.

The SystemCounter is at 1ms. The serial configuration is 9600, 8N1, with the serial line connected to the debugger (/dev/ttyACM1 on Linux).

`
goil --target=msp430x/small/msp430fr5969/launchpad --templates=../../../../../../goil/templates/ framDataExample.oil
`
