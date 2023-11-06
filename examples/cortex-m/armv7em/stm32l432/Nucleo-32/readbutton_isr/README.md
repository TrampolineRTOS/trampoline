|=-----=[ readbutton_isr example ]=-----=|

This application deals with alarms.
There are two tasks : "blink" and ""read_button".

The task "blink" is activated by the alarm "blink_alarm".
The task "blink" toggles the LED3 (PB3) user led whenever it is executed.

The task "read_button" is activated by the alarm "read_button_alarm".
The push button is connected to RST signal, we use D2 instead (PA12), as it can be connected to GND using a jumper.
This task "read_button" is activated by the interrupt (external interrupt on "push button" (D2)) and toggles the alarm "blink_alarm".

Have a look into "alarm.oil" file.
This application deals with alarms and ISR2.
There are two tasks `blink` and `read_button` and one ISR2 `isr_button`.

The system is based scheduled with a 1ms SysTick `SystemCounter`.

Configure the application with:

```
goil --target=cortex-m/armv7em/stm32l432 --templates=../../../../../../goil/templates/ readbutton_isr.oil
```
