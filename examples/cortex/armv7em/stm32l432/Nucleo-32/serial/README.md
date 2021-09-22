# Serial example

This application is a simple periodic example wich toggles the green led (LD3 - pin 13) of the board and sends a charcter string on the serial line. Have a look into "serial.oil" file.

Configure the application with

`
goil --target=cortex/armv7em/stm32l432 --templates=../../../../../../goil/templates/ serial.oil
`
