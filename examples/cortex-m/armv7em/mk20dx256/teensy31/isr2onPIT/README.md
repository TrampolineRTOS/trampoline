# isr2onPIT example

A periodic task toggles the built in led of the teensy the board every
500ms by using an alarm. In addition the task gets the current value
of the PIT0 timer and print it on the LCD. This runs at start.

PIT0 timer is programmed to count down from 100000000 (100 millions).
With the 48MHz clock, this corresponds to a 2,0833333 seconds period.
An IRQ (PIT0_IRQ) is programmed and, when the timer reaches 0, it
leads to the execution of ISR category 2 timer.

Have a look into "isr2onPIT.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

Configure the application with:

```
goil --target=cortex-m/armv7em/mk20dx256/teensy31 --templates=../../../../../../goil/templates isr2onPIT.oil
```

Then compile the application:

`./make.py`

If everything went well, program the board (teensy-loader-cli location should be in your path):

`./make.py burn`
