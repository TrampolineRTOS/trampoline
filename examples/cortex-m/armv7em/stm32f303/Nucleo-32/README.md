# Bunch of running examples for Cortex-M4

This directory provides a set of examples ready for use on a 
[stm32f303 Nucleo-32 board from ST-microelectronics](https://os.mbed.com/platforms/ST-Nucleo-F303K8/).

The stm32f303 Nucleo-32 board is equiped with a st-link/v2 embedded debug tool interface.

## Prerequisite

### Compile

You need a compiler for your plateform.
Trampoline has been previously compiled with industrial compilers and GNU GCC.
The examples have all been compiled with :

```
(GNU Tools for ARM Embedded Processors) 5.4.1 20160919 (release) [ARM/embedded-5-branch revision 240496]
```

### Program and debug
 
You need `stlink` tool to program and debug with the st-link/v2 embedded debug tool interface.

`stlink` is a tool to communicate with the st-link/v2 in-circuit debugger.
You get `stlink` from [github](https://github.com/texane/stlink).

Read the documentation README form the Github repository.

`stlink` needs the development version of libusb.
For MAC OS X plateform you'll have to install it with [BREW](http://brew.sh)

```sh
$ brew install libusb
```

We will use st-util hereafter.

## How to run an example

We present hereafter the successive steps to follow to get the first example [ blink ] run.

1 - Step into the example directory

```sh
cd examples/cortex-m/armv7em/stm32f303/Nucleo-32/blink
```

2 - Generate all source files from a configuration with the command :

```sh
goil --target=cortex-m/armv7em/stm32f303 --templates=../../../../../../goil/templates/ blink.oil
```

3 - Compile

```sh
./make.py
```

4 - Connect a stm32f4-discovery board with a USB cable

5 - Flash the binary file

```sh
./make.py burn 
```

6 - You should see the BLUE led blink 

## How to debug an example

1 - Open a terminal [ 0 ] and launch the server for listening on default port 

```sh
st-util
```
It should open a gdbserver connection with the Nucleo-32 on port 4242 (default)

```
...
Listening at *:4242...
```

2 - Open another [ 1 ] and initialize the debug session

```sh
arm-none-eabi-gdb blink_exe
source init.gdb
```

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
