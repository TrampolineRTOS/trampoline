# Debug UART serial line over USB 

The lib offers a lightweight serial communication for the launchpad boards with serial over USB

The basic implementation opens the serial port (9600, 8N1) to push debug messages

At this date, it supports:
* update the baud rate parameters when there are DCO frequency updates.
* transmit  using an interrupt and a ring buffer.
* reception using an interrupt and a ring buffer.
Note that if any buffer size (defined in the OIL) file is set to 0, the corresponding interrupt is not enabled

In the OIL file, 2 parameters should be given to the lib:

```
LIBRARY = serial {
  TXBUFFER = 16;
  RXBUFFER = 16;
};
```

