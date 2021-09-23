# Blink example

This application is a simple example using the serial communication over the USB

The SystemCounter is at 1ms.

The serial library should be declared in the .oil file, with the size (in bytes) of the 2 buffers (TX and RX). If any buffers is set to 0, no buffer is used and the related interrupt is not enabled.

```
      LIBRARY = serial {
        TXBUFFER = 16;
      };
```

The serial configuration is 115200, 8N1, with the serial line connected to the debugger (/dev/ttyACM0 on Linux).

`
goil --target=cortex/armv7em/stm32f303 --templates=../../../../../../goil/templates/ serial.oil
`
