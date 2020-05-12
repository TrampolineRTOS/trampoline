# Trace example

This application is a simple application to use the trace. It is based on the 'blink' example, and the trace over serial.

periodic example wich toggles the green led (LD3 - pin 13) of the board.
Have a look into "blink.oil" file.

The SystemCounter is at 1ms.

The task "blink" toggles the GREEN led when executed.
This is not scheduled when the program starts.

This task is activated by the alarm "blink_blink".
This alarm starts 50ms (ALARMTIME) after "StartOS".
This alarm has a 50ms (CYCLETIME) period.

Configure the application with

```sh
goil --target=msp430x/small/msp430fr5969/launchpad --templates=../../../../../../goil/templates/ trace.oil
```

then compile and flash:
```sh
./make.py flash
```

