# startStopBlink example

The basis of this application is the same as the blink example.
A periodic task  toggles the built in led of the teensy the board.
This runs at start.

A second alarm with a period of 20ms scans a button connected on pin 8.
When the button is pressed, the alarm is cancelled.
When the button is pressed again the alarm is started again.

Have a look into "startStopBlink.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

Look at the CFLAGS in the blink.oil file. The tools are arm-none-eabi-xxx and their location should be in your path. Edit the paths of the libc and libgcc to adapt the project to your setup.

Configure the application with:

```
goil --target=cortex-m/armv7em/mk20dx256/teensy31 --templates=../../../../../../goil/templates startStopBlink.oil
```

Then compile the application:

`./make.py`

If everything went well, program the board (teensy_loader_cli location should be in your path):

`./make.py burn`
