|=-----=[ alarms example ]=-----=|

This application deals with alarms and ISR2.
There are two tasks "blink" and "read_button" and one ISR2 "isr_button".
There is an alarm "blink_alarm".

At start the program does nothing.
Something happens when pushing the button on the board.
A push on the button activates the task "read_button".

The task "read_button" will toggle the BLUE led and launch or cancel the alarm "blink_alarm".
This tasks launches the alarm "blink_alarm" whether or not it has already been launched.
It tests the return value of service SetRelAlarm to E_OK. If the value is different from E_OK 
then the alarm is canceled with CancelAlarm.
This alarm "blink_alarm" will activate the task "blink" on expiration and start again.

Leds are toggled by the following resources:

 * "blink" toggles GREEN led,
 * "isr_button" will toggle RED led,
 * "read_button" will toggle BLUE led.

Have a look into "alarms.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

Configure the application with:
```
goil --target=cortex-m/armv7em/stm32f407/stm32f4discovery --templates=../../../../../../goil/templates/ alarms.oil
```
