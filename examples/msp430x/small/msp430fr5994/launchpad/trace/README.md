# Trace example

This application show how to use the trampoline trace with a simple example that
use many features: periodic tasks, events, resources and internal communication:
 * task **taskPeriodicSend** is periodic (500ms) and:
	 * take/release an external resource (**resGPIO**)
	 * send a message **msgDataSend**
 * the message is associated to 2 receive messages with filters (1 every 3). 
   Each of them sends an event that wake up tasks **taskReceiver1** and
   **taskReceiver2**.
 * These receive tasks take/release the resource and wait for a new event.
This little scenario generates a lot of trace information.

The trace documentation is set in one chapter in documentation/manual/main.pdf

## How to run an example

1 - Step into the example directory

```sh
cd examples/msp430x/small/msp430fr5994/launchpad/trace
```

Configure the application with

```sh
goil --target=msp430x/small/msp430fr5994/launchpad --templates=../../../../../../goil/templates/ trace.oil
```

then compile and flash:
```sh
./make.py flash
```

To get the trace from serial and export the results on the command line, try the following command, the device name may vary from system to system, here the board name is `ttyACM0`.

```sh
./readTrace.py -s /dev/ttyACM1,9600 
```

6.2 - You can also save the trace info in a json file, try the following command, use `Ctrl + C` to interrupt, and `./readTrace.py` to explain the `trace.json` generated, the device name may vary from system to system, here the board name is `ttyACM0`.

```sh
./readTrace.py -s /dev/ttyACM1,9600 -o trace.json 
```



