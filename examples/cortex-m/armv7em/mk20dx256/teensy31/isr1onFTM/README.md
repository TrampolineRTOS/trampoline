# isr1onFTM example

Periodic task "pulse" runs every 20ms (ALARMTIME and CYCLETIME = 20).
It sets output 3 to HIGH and programs the FTM0 to generate an interrupt
after a time between 66,67µs and 13,33ms. The time is updated according
to the speed variable. This runs at start.

ISR 1 "fmt_timer" sets output 3 to LOW and stops FTM0.

As a result a pulse with a width between 66,67µs and 13,33ms is generated
on output 3. 

A periodic task toggles the built in led of the teensy the board every
500ms by using an alarm. In addition the task gets the pulse width and
the speed variable and print it on the LCD. This runs at start.

Have a look into "isr1onFTM.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

Configure the application with:

```
goil --target=cortex-m/armv7em/mk20dx256/teensy31 --templates=../../../../../../goil/templates isr1onFTM.oil
```

Then compile the application:

`./make.py`

If everything went well, program the board (teensy-loader-cli location should be in your path):

`./make.py burn`
