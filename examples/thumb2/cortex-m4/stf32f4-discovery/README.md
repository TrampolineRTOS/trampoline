# Bunch of running examples for Cortex-M4

This directory provides a set of examples ready for use on a 
stm32f4-discovery board from ST-microelectronics.

The stm32f4-discovery board is equiped with a st-link/v2 embedded debug tool interface.

## Prerequisite

### Compile

You need a compiler for your plateform.
Trampoline has been previously compiled with industrial compilers and GNU GCC.
The examples have all been compiled with :
gcc version 4.8.4 20140526 (release) [ARM/embedded-4_8-branch revision 211358] (GNU Tools for ARM Embedded Processors)

### Program and debug
 
You need [ stlink ] tool to program and debug with the st-link/v2 embedded debug tool interface.

[ stlink ] is a tool to communicate with the st-link/v2 in-circuit debugger.
You get [ stlink ] from 
https://github.com/texane/stlink

Read the documentation README form the Github repository.

[ stlink ] needs the development version of libusb.
For MAC OS X plateform you'll have to install it with BREW
http://brew.sh

> brew install libusb

We will use st-util hereafter.

## How to run an example

We present hereafter the successive steps to follow to get the first example [ blink ] run.

1 - Step into the example directory
    > cd blink 

2 - Replace paths into blink.oil file
   You must replace those path in file blink.oil looking for tags
    [YOUR PATH TO COMPILER]
    [YOUR PATH TO COMPILER LIB]
    For example, my personal path are 
    /usr/local/dev-arm/i386-Darwin-arm-gcc-4.9.2/lib/gcc/arm-eabi/4.9.2
    /usr/local/dev-arm/i386-Darwin-arm-gcc-4.9.2/arm-eabi/lib/thumb
 
2 - Generate all source files from a configuration with the command :
    > goil --target=thumb2/cortex-m4/stm32f4-discovery -v --templates=../../../../../goil/templates/ blink.oil

3 - Compile
    > make

4 - Connect a stm32f4-discovery board with a USB cable

5 - Flash the binary file
    > make burn 

6 - You should see the BLUE led blink 

## How to debug an example

You should have a terminal opened [ 0 ].

1 - Open another terminal and launch the server for listening on default port 
    > st-util
    
2 - Launch gdb in the previous terminal [ 0 ] and initialize the debug session
    > arm-none-eabi-gdb blink_exe
    > source init.gdb
You are now ready to debug blink_exe

## Tips

We have not fully integrated the complete development cycle in makefiles so I advise you to clean your working directory 
if you have modified any template file ( i.e. a file ending with ".goilTemplate".
In that case, just do
> make clean
> make
to ensure that all source file a well re-generated.

This shall be corrected in a further version

## The examples

### blink

This example just toggles a led.

### readbutton

This example presents two tasks and two alarms that interact.
It uses polling for reading push button states.

### readbutton_isr

This example presents two tasks and one alarm.
It uses an ISR2 that activates a task. That last task then start or stop an alarm.
