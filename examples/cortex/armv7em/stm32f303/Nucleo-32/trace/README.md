# Blink example

This application show how to use the trampoline trace with a simple periodic example 
that toggles the green led (LD3 - pin 13) of the board.
Have a look into "trace.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

The task "blink" toggles the GREEN led when executed.
This is not scheduled when the program starts.

The trace documentation is set in one chapter in documentation/manual/main.pdf

## How to run an example

1 - Step into the example directory

```sh
cd examples/cortex/armv7em/stm32f303/Nucleo-32/trace 
```

2 - Generate all source files from a configuration with the command 

```sh
goil --target=cortex/armv7em/stm32f303 --templates=../../../../../../goil/templates/ trace.oil
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
./readTrace.py -s /dev/ttyACM0,115200 
```

6.2 - You can also save the trace info in a json file, try the following command, use `Ctrl + C` to interrupt, and `./readTrace.py` to explain the `trace.json` generated, the device name may vary from system to system, here the board name is `ttyACM0`.

```sh
./readTrace.py -s /dev/ttyACM0,115200 -o trace.json 
```



