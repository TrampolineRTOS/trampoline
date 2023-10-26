|=-----=[ readbutton example ]=-----=|

This application deals with alarms.
There are two tasks : "blink" and ""read_button".

The task "blink" is activated by the alarm "blink_alarm".
The task "blink" toggles the LED3 (PB3) user led whenever it is executed.

The task "read_button" is activated by the alarm "read_button_alarm".
The push button is connected to RST signal, we use D2 instead (PA12), as it can be connected to GND using a jumper.
This task "read_button" makes polling onto the state of the "push button" (D2) on the board and toggles the alarm "blink_alarm" when the putton is pushed (the jumper is inserted).

Have a look into "alarm.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

At the beginning of the execution, the alarm "read_button_alarm" is started, and that's all.
 
Configure the application with:

```
goil --target=cortex-m/armv7em/stm32l432 --templates=../../../../../../goil/templates/ readbutton.oil
```
