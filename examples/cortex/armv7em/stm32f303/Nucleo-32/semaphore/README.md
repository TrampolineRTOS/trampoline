# Serial protection with Mutex example

This application is a simple periodic example that uses semaphores. Semaphores are not part of OSEK/VDX nor AUTOSAR standard, but are widely used.

The Semaphores uses to additionnal System Calls
* SemWait (wait for a semaphore, i.e. P())
* SemPost (give back the semaphore, i.e V())

The example just show an mutex example to protect the serial line. Without any mutex, a higher priority task will interrupt the transmission of a long char string on serial.

The serial configuration is 115200, 8N1, with the serial line connected to the debugger (/dev/ttyACM0 on Linux).

`
goil --target=cortex/armv7em/stm32f303 --templates=../../../../../../goil/templates/ semaphore.oil
`
