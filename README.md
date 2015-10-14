# Trampoline

Trampoline is a static RTOS for small embedded systems.
Its API is aligned with OSEK/VDX OS and AUTOSAR OS 4.1 standards.

5 platforms are supported by now :

* thumb2: ARM Cortex-M (and others) instruction set
* ppc: PowerPC 32bits instruction set
* posix: virtual platform for POSIX systems (tested on Linux and OS X)
* avr: AVR 8 bits microcontrollers
* ARM (currently not working, updated soon): ARM 32 bits instruction set

And we welcome external contributors to extend this list.

Some examples have been added (check examples):

* thumb2 (aka Cortex-M)/cortex-m4/stf32f4-discovery
  * blink. Blinks a LED using an alarm and a task
  * readButton. The example polls the button to start an alarm that activates a task to blink a LED
  * readButton_isr. Same but the button triggers an ISR.
* avr: 3 examples for Arduino Uno (ATMega328p chip) and Arduino Mega (ATMega2560 chip)
  * blink. Blinks a LED using an alarm and a task
  * serial. improve 'blink': use the standard Arduino serial API.
  * extInterrupt. improve 'serial': add 2 ISRs to change the alarm period.

More examples are coming.

## Precompiled binaries of goil, the OIL compiler

* Mac OS X: [goil-mac-os-x.zip](https://dl.dropboxusercontent.com/u/67740546/goil/goil-mac-os-x.zip)
* Mac OS X Cocoa Application with editor: [CocoaGoil.app.zip](https://dl.dropboxusercontent.com/u/67740546/goil/CocoaGoil.app.zip)
* Linux 32 bits: [goil-linux-32.zip](https://dl.dropboxusercontent.com/u/67740546/goil/goil-linux-32.zip)
* Linux 64 bits: [goil-linux-64.zip](https://dl.dropboxusercontent.com/u/67740546/goil/goil-linux-64.zip)
* Windows: [goil-windows.zip](https://dl.dropboxusercontent.com/u/67740546/goil/goil-windows.zip)
