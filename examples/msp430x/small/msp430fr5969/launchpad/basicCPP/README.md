# Basic example using C++

This application is a simple example in C++.
It simply defines a class and 2 global objects. 
The prupose is to check that the objects constructors are correctly called before the main in the startup code so that their value is correctly initialized.

The SystemCounter is at 1ms. The serial configuration is 9600, 8N1, with the serial line connected to the debugger (/dev/ttyACM1 on Linux).

`
goil --target=msp430x/small/msp430fr5969/launchpad --templates=../../../../../../goil/templates/ basicCPP.oil
`
