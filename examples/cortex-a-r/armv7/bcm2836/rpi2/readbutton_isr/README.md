|=-----=[ readbutton_isr example ]=-----=|

This application deals with alarms and ISR2.
There are two tasks `blink` and `read_button` and one ISR2 `isr_button`.

At start the program does nothing.
Something happens when pushing the button on the board.
A push on the button activates the task "read_button".

The task "read_button" will toggle the BLUE led and launch or cancel the alarm "blink_alarm".
This alarm "blink_alarm" will activate the task "blink" on expiration and start again.

Leds are toggled by the following resources:

* "blink" toggles GREEN led,
* "isr_button" will toggle RED led,
* "read_button" will toggle BLUE led.

Have a look into `readbutton_isr.oil` file.

The system is based scheduled with a 1ms SysTick `SystemCounter`.

Configure the application with:

```
goil --target=cortex-m/armv7em/stm32f407/stm32f4discovery --templates=../../../../../../goil/templates/ readbutton_isr.oil
```
