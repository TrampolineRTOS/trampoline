# Trace example

This application show how to use the trampoline trace with a simple example that
use many features: periodic tasks, events, resources and internal communication:
 * task **taskPeriodicSend** is periodic (100ms) and:
	 * take/release an external resource (**resGPIO**)
	 * send a message **msgDataSend**
 * the message is associated to 2 receive messages with filters (1 every 3). 
   Each of them sends an event that wake up tasks **taskReceiver1** and
   **taskReceiver2**.
 * These receive tasks take/release the resource and wait for a new event.
This little scenario generates a lot of trace information.

The trace documentation is set in one chapter in documentation/manual/main.pdf

You may limit the TXBUFFER parameter to get some overflow errors (too much data 
on the serial line). There are some overflows with TXBUFFER = 128 bytes.

## How to run an example

1 - Step into the example directory

```sh
cd examples/cortex-m/armv7em/stm32f303/Nucleo-32/trace
```

2 - Generate all source files from a configuration with the command 

```sh
goil --target=cortex-m/armv7em/stm32f303 --templates=../../../../../../goil/templates/ trace.oil
```

3 - Connect a stm32f303 board with a USB cable, you can find your board through this command

```sh
lsusb
```

4 - Flash the binary file

```sh
./make.py burn 
```

5 - You should see the green LED blinks, if not, press the reset button.

6.1 - To get the trace from serial and export the results on the command line, try the following command, the device name may vary from system to system, here the board name is `ttyACM0`.

```sh
./readTrace.py -i /dev/ttyACM0,115200 -a list
```

Other features are defined in the help:
```sh
./readTrace.py --help
```



