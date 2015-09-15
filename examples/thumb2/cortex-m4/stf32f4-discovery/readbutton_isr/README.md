|=-----=[ readbutton_isr example ]=-----=|

This application deals with alarms and ISR2.
There are two tasks : "blink" and ""read_button".

The task "blink" is activated by the alarm "blink_alarm".
The task "blink" toggles the GREEN led whenever it is executed.

The task "read_button" is activated by the alarm "isr_button".
This task "read_button" toggles the alarm "blink_alarm" and the BLUE led.

Have a look into "alarm.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

At the beginning of the execution, the alarm "read_button_alarm" is started, and that's all.
 
Configure the application with
goil --target=thumb2/cortex-m4/stm32f4-discovery -v --templates=../../../../../goil/templates/ readbutton_isr.oil

