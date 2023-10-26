# timer example

This application deals with alarms and ISR2.

alarm `blink_alarm` runs at start and activates task `blink` every 100ms
Task `blink` programs timer TIM2 to trigger an interrupt after 30ms
ISR2 `isr_timer` is connected to TIM2_IRQ.

Leds are toggled by the following resources:
* `blink` toggles the GREEN led,
* `isr_timer` toggles the RED led,

Both leds are toggled every 100ms but the RED led toggle is delayed by 30ms

Have a look into `timer.oil` file.

The system is based scheduled with a 1ms SysTick `SystemCounter`.

Configure the application with
goil --target=cortex-m/armv7em/stm32f407/stm32f4discovery --templates=../../../../../../goil/templates/ timer.oil

