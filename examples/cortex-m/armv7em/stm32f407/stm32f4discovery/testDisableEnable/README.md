# Example of `DisableAllInterrupts` and `EnableAllInterrupts`

This application deals with ISR1 and `DisableAllInterrupts` and `EnableAllInterrupts` services.

There are two tasks `start_timer` and `periodic` and one ISR1 `isr_TIM2`.

In `main`, the Timer 2 is initialized to trigger an interrupt every 100µs. Task `start_timer` is an autostart task which starts the timer.

The task `periodic`executes every 1 ms and:

* does a loop that lasts 131µs (2000 iterations) 
* disable all interrupts
* switch on the BLUE led
* does a loop that lasts 476µs (8000 iterations)
* switch off the BLUE led
* enable all interrupts
* does a loop that lasts 131µs (2000 iterations) 
* Terminate

The ISR isr_TIM2 toggle the RED led.

The expected behavior is to not observe RED led toggles when the BLUE led is on.

Configure the application with:

```
goil --target=cortex-m/armv7em/stm32f407/stm32f4discovery --templates=../../../../../../goil/templates/ testDisableEnable.oil
```
