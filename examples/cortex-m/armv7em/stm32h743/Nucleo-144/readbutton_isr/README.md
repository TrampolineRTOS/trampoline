|=-----=[ readbutton_isr example ]=-----=|

This application deals with alarms.
There are two tasks : "blink" and ""read_button" and 3 external interrupts (EXTI)

The task "blink" is activated by the alarm "blink_alarm".
The task "blink" toggles the Green LED (PB0) user led whenever it is executed.

The task "read_button" is activated by the alarm "read_button_alarm".
The push button is connected to the ISR, we use A5 (PF10), as it 
This task "read_button" is activated by the interrupt (external interrupt on "push button" (A5)) and toggles the alarm "blink_alarm".
2 other interrupts isr_button2 and isr_button2 are associated to `A4` (PC2) and `A3` (PB1) to toggle a led.

Have a look into "alarm.oil" file.
This application deals with alarms and ISR2.
There are two tasks `blink` and `read_button` and one ISR2 `isr_button`.

The system is based scheduled with a 1ms SysTick `SystemCounter`.

Configure the application with:

```
goil --target=cortex-m/armv7em/stm32h743 --templates=../../../../../../goil/templates/ readbutton_isr.oil
```
