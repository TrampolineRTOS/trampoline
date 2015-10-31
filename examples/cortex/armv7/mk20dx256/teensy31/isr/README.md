# isr example

The basis of this application is the same as the blink example.
A periodic task  toggles the built in led of the teensy the board.
This runs at start.

An ISR is programmed on the PIT0 channel

Have a look into "isr.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

Configure the application with:

`goil --target=cortex/armv7/mk20dx256/teensy31 --templates=../../../../../../goil/templates isr.oil`

Then compile the application:

`./make.py`

If everything went well, program the board (teensy-loader-cli location should be in your path):

`./make.py burn`
