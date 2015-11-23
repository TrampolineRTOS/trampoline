# Trampoline

Trampoline is a static RTOS for small embedded systems.
Its API is aligned with OSEK/VDX OS and AUTOSAR OS 4.1 standards.

5 platforms are supported by now :

* cortex: ARM Cortex-M (and others) instruction set
* ppc: PowerPC 32bits instruction set
* posix: virtual platform for POSIX systems (tested on Linux and OS X)
* avr: AVR 8 bits microcontrollers
* ARM: ARM 32 bits instruction set

And we welcome external contributors to extend this list.

Some examples have been added (check examples):

* cortex/armv7/stm32f407/stf32f4discovery
  * **blink**. Blinks a LED using an alarm and a task. 
  * **readButton**. The example polls the button to start an alarm that activates a task to blink a LED
  * **readButton_isr**. Same but the button triggers an ISR.
  * **alarms**. It is the same example than readButton_isr but we test the return value of SetRelAlarm for return parameters when in kernel (system call) mode.
  * **timer**. ISR2 trigered by timer TIM2.
* cortex/armv7/mk20dx256/teensy31
  * **blink**. Blinks the Teensy 3.1 LED using an alarm and a task. 
  * **startStopBlink**. The example polls a button connected to pin 8 to start an alarm that activates a task to blink a LED. 
  * **liquidCrystal**. startStopBlink extended. In addition the periodic task prints a value on a LCD.
  * **isr2onPIT**. Use the PIT channel 0 to trigger an ISR2.
  * **isr1onFTM**. Use the FTM0 to trigger an ISR1 and generate a variable width pulse.
* avr: 3 examples for Arduino Uno (ATMega328p chip) and Arduino Mega (ATMega2560 chip)
  * **blink**. Blinks a LED using an alarm and a task. 
  * **serial**. improve 'blink': use the standard Arduino serial API.
  * **extInterrupt**. improve 'serial': add 2 ISRs to change the alarm period.
* arm: 1 example for Olimex lpc2294 board
  * **lonely**. Blinks a led, 3 tasks, ISR category 1 or 2, counts interrupts from the push button.

More examples are coming.

## Precompiled binaries of goil, the OIL compiler

Updated to version 2.1.24

* Mac OS X: [goil-mac-os-x.zip](https://dl.dropboxusercontent.com/u/67740546/goil/goil-mac-os-x.zip)
* Mac OS X Cocoa Application with editor: [CocoaGoil.app.zip](https://dl.dropboxusercontent.com/u/67740546/goil/CocoaGoil.app.zip)
* Linux 32 bits: [goil-linux-32.zip](https://dl.dropboxusercontent.com/u/67740546/goil/goil-linux-32.zip)
* Linux 64 bits: [goil-linux-64.zip](https://dl.dropboxusercontent.com/u/67740546/goil/goil-linux-64.zip)
* Windows: [goil-windows.zip](https://dl.dropboxusercontent.com/u/67740546/goil/goil-windows.zip)

## Useful links

* [ARM development tools](https://launchpad.net/gcc-arm-embedded) compiled for various plateforms.
