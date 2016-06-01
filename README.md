# Trampoline

Trampoline is a static RTOS for small embedded systems.
Its API is aligned with OSEK/VDX OS and AUTOSAR OS 4.1 standards.

5 platforms are supported by now :

* cortex
  * Cortex-M (M0+ and M4 for now) instruction set
  * Cortex-A (A7) instruction set. This port is under heavy development.
* ppc: PowerPC 32bits instruction set
* posix: virtual platform for POSIX systems (tested on Linux and OS X)
* avr: AVR 8 bits microcontrollers
* ARM: ARM 32 bits instruction set

And we welcome external contributors to extend this list.

Trampoline runs on the following boards :
* ST Discovery   - https://www.element14.com/community/docs/DOC-48699/l/discovery-kit-for-stm32-f4-series-with-stm32f407vg-mcu
* Teensy         - https://www.pjrc.com/store/teensy.html
* Raspberry Pi 2 - https://www.raspberrypi.org/products/raspberry-pi-2-model-b
* Arduino Uno    - https://www.arduino.cc/en/Main/ArduinoBoardUno
* Arduino Mega   - https://www.arduino.cc/en/Main/ArduinoBoardMega2560
* LPC-L2294-1MB  - https://www.olimex.com/Products/ARM/NXP/LPC-L2294-1MB/

Some examples have been added (check examples):

* Cortex M4 with µC stm32f407: `cortex/armv7em/stm32f407/stf32f4discovery`
  * **blink**. Blinks a LED using an alarm and a task. 
  * **readButton**. The example polls the button to start an alarm that activates a task to blink a LED
  * **readButton_isr**. Same but the button triggers an ISR.
  * **alarms**. It is the same example than readButton_isr but we test the return value of SetRelAlarm for return parameters when in kernel (system call) mode.
  * **timer**. ISR2 trigered by timer TIM2.
* Cortex M4 with µC mk20dx256 : `cortex/armv7em/mk20dx256/teensy31`
  * **blink**. Blinks the Teensy 3.1 LED using an alarm and a task. 
  * **startStopBlink**. The example polls a button connected to pin 8 to start an alarm that activates a task to blink a LED. 
  * **liquidCrystal**. startStopBlink extended. In addition the periodic task prints a value on a LCD.
  * **isr2onPIT**. Use the PIT channel 0 to trigger an ISR2.
  * **isr1onFTM**. Use the FTM0 to trigger an ISR1 and generate a variable width pulse.
* Cortex M0+ with µC samd21: `cortex/armv6m/samd21/XPlainedPro`.
  * **blink**. Blinks a LED using an alarm and a task. 
  * **readButton**. The example polls the button to start an alarm that activates a task to blink a LED
  * **readButton_isr**. Same but the button triggers an ISR.
* Cortex A7 with bcm2836 - Raspberry Pi 2 : `cortex-a/armv7/bcm2836/rpi2`.
  * **blink**. A first runable blink example is available. We need a bootloader and and a console. This stuff will be soon available as well.
* avr: 3 examples for Arduino Uno (ATMega328p chip) and Arduino Mega (ATMega2560 chip)
  * **blink**. Blinks a LED using an alarm and a task. 
  * **serial**. improve 'blink': use the standard Arduino serial API.
  * **extInterrupt**. improve 'serial': add 2 ISRs to change the alarm period.
* arm: 1 example for Olimex lpc2294 board
  * **lonely**. Blinks a led, 3 tasks, ISR category 1 or 2, counts interrupts from the push button.

More examples are coming.

## Precompiled binaries of goil, the OIL compiler

Updated to version 2.1.27

* Mac OS X: [goil-mac-os-x.zip](http://trampoline.rts-software.org/bin/goil-mac-os-x.zip)
* Mac OS X Cocoa Application with editor: [CocoaGoil.app.zip](http://trampoline.rts-software.org/bin/CocoaGoil.app.zip) (version 2.1.24)
* Linux 32 bits: [goil-linux-32.zip](http://trampoline.rts-software.org/bin/goil-linux-32.zip)
* Linux 64 bits: [goil-linux-64.zip](http://trampoline.rts-software.org/bin/goil-linux-64.zip)
* Windows: [goil-windows.zip](http://trampoline.rts-software.org/bin/goil-windows.zip)

## Useful links

* [ARM development tools](https://launchpad.net/gcc-arm-embedded) compiled for various plateforms.
