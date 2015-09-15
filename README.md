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

Some examples have been added :

* thumb2: 2 examples
*   - blink
*   - readbutton
* avr: 3 examples
*   - blink
*   - extInterrupt
*   - serial

More examples are coming.
