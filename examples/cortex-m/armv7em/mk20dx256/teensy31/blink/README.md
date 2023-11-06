# Blink example

This application is a simple periodic example that toggles
the built in led of the teensy the board.
Have a look into "blink.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

The task "blink" toggles the built in led when executed.
This is not scheduled when the program starts.

This task is activated by the alarm "blink_blink".
This alarm starts 500ms (ALARMTIME) after "StartOS".
This alarm has a 500ms (CYCLETIME) period.

Look at the CFLAGS in the blink.oil file. The tools are arm-none-eabi-xxx and their location should be in your path. Edit the paths of the libc and libgcc to adapt the project to your setup.

Configure the application with:

```
goil --target=cortex-m/armv7em/mk20dx256/teensy31 --templates=../../../../../../goil/templates blink.oil
```

Then compile the application:

`./make.py`

If everything went well, program the board (teensy-loader-cli location should be in your path):

`./make.py burn`
