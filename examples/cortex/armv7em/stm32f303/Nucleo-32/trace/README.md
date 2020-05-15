# Blink example

This application show how to use the trampoline trace with a simple periodic example 
that toggles the green led (LD3 - pin 13) of the board.
Have a look into "trace.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

The task "blink" toggles the GREEN led when executed.
This is not scheduled when the program starts.

The trace documentation is set in one chapter in documentation/manual/main.pdf

Configure the application with

`
goil --target=cortex/armv7em/stm32f303 --templates=../../../../../../goil/templates/ trace.oil
`
