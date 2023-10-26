# Serial example

This application is a simple periodic example wich toggles the green led (LD3 - pin 13) of the board and sends a charcter string on the serial line. Have a look into "serial.oil" file.

The SystemCounter is at 1ms.

The serial library should be declared in the .oil file, with the size (in bytes) of the TX buffer (should not be set to 0!)

```
      LIBRARY = serial {
        TXBUFFER = 16;
      };
```

The serial configuration is 115200, 8N1, with the serial line connected to the debugger (/dev/ttyACM0 on Linux).

`
goil --target=cortex-m/armv7em/stm32l432 --templates=../../../../../../goil/templates/ serial.oil
`
