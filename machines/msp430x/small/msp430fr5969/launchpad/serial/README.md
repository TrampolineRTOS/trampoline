# Serial over USB support

The lib offers a lightweight serial communication for the launchpad boards with serial over USB

The basic implementation opens the serial port (9600, 8N1) to push debug messages

At this date, it supports:
* update the baud rate parameters when there are DCO frequency updates.

At this date, it does **not** support:
* transmit using an interrupt (and a ring buffer)
* receive msgs
