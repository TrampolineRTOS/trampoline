# Blink example

This application is a simple periodic example wich toggles the green led (LD3 - pin 13) of the board.
Have a look into "blink.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

The task "blink" toggles the GREEN led when executed.
This is not scheduled when the program starts.

This task is activated by the alarm "blink_blink".
This alarm starts 100ms (ALARMTIME) after "StartOS".
This alarm has a 100ms (CYCLETIME) period.

Configure the application with

`
goil --target=cortex-m/armv7em/stm32l432 --templates=../../../../../../goil/templates/ blink.oil
`
