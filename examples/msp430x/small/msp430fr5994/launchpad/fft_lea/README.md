# Basic example using LEA to perform fft

This application is a simple example with a variable defined in LEA_SRAM.
To define the appropriate section that is used, with follow the rules given by the AUTOSAR standard, using a symbol definition, followed by the inclusion of a tpl_memmap.h header file.

This approach make the application independant of the linker directives.

The SystemCounter is at 1ms. The serial configuration is 9600, 8N1, with the serial line connected to the debugger (/dev/ttyACM1 on Linux).

`
goil --target=msp430x/small/msp430fr5994/launchpad --templates=../../../../../../goil/templates/ fft_lea.oil
`
