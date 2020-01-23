# Blink example

This application is a simple example using the serial communication over the USB

The SystemCounter is at 1ms.

The serial library should be declared in the .oil file, with the size (in bytes) of the 2 buffers (TX and RX). If any buffers is set to 0, no buffer is used and the related interrupt is not enabled.

```
      LIBRARY = serial {
        TXBUFFER = 16;
        RXBUFFER = 16;
      };
```

There are 2 tasks:
* serial_TX is autostart (and run once) and just send a text string on startup.
* serial_RX is periodic (200ms) and check if there are some bytes availables on the rx buffer.  The bytes are written back to the serial line if the buffer has more than 10 bytes.

The serial configuration is 9600, 8N1, with the serial line connected to the debugger (/dev/ttyACM1 on Linux).

`
goil --target=msp430x/small/msp430fr5969/launchpad --templates=../../../../../../goil/templates/ serial.oil
`
