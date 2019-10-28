# Blink example

This application is a simple periodic example 

The SystemCounter is at 1ms.

The task "blink" prints "hello world" to the serial line 115200, 8N1 of the launchpad, that is connected to the USB (through the embbeded debugger).

`
goil --target=msp430x/small/msp430fr5969/launchpad --templates=../../../../../../goil/templates/ serial.oil
`
