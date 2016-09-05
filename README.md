# Trampoline

Trampoline is a static RTOS for small embedded systems.
Its API is aligned with OSEK/VDX OS and AUTOSAR OS 4.1 standards.

5 platforms are supported by now :

* cortex
  * Cortex-M (M0+, M3 and M4 for now) instruction set
  * Cortex-A (A7) instruction set. This port is under heavy development.
* ppc: PowerPC 32bits instruction set
* posix: virtual platform for POSIX systems (tested on Linux and OS X)
* avr: AVR 8 bits microcontrollers
* ARM: ARM 32 bits instruction set

And we welcome external contributors to extend this list.

Trampoline runs on the following plateforms :

| MCU                          | Architecture       | Cores | Evaluation Board                  |
|------------------------------|--------------------|:-----:|-----------------------------------|
| Atmel ATMega328p             | 8-bit AVR          | 1     | Arduino Uno                       |
| Atmel ATMega2560             | 8-bit AVR          | 1     | Arduino Mega                      |
| Atmel SAM D21                | Cortex-M0+         | 1     | XPlainedPro                       |
| Broadcom BCM2836             | Cortex-A7          | 4     | Raspberry Pi 2 Model B            |
| NXP LPC2294                  | ARM7               | 1     | Olimex LPC-L2294-1MB              |
| NXP / Freescale MK20DX256    | Cortex-M4          | 1     | Teensy31                          |
| NXP / Freescale MPC564xL     | Power Architecture | 2     | XPC56XX EVB + XPC56XL MINI-MODULE |
| STMicroelectronics STM32F4xx | Cortex-M4          | 1     | STM32F4DISCOVERY                  |
| MicroSemi SmartFusion2       | Cortex-M3          | 1     | starterKit                        |

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
* Cortex M3 with µC SmartFusion2: `cortex/armv7m/SmartFusion2`.
  * **blink**. a simple periodic example which toggles the two green leds (DS3, DS4) of the board
  * **fpgaInterrupt** an interrupt from the FPGA fabriq toggles the green led DS4 of the board (and a periodic task blinks another Led).
* Cortex M0+ with µC samd21: `cortex/armv6m/samd21/XPlainedPro`.
  * **blink**. Blinks a LED using an alarm and a task. 
  * **readButton**. The example polls the button to start an alarm that activates a task to blink a LED
  * **readButton_isr**. Same but the button triggers an ISR.
* Cortex A7 with bcm2836 - Raspberry Pi 2 : `cortex-a/armv7/bcm2836/rpi2`.
  * **blink**. A first runable blink example is available. We need a bootloader and and a console. This stuff will be soon available as well. Single core for the moment.
* avr: 3 examples for Arduino Uno (ATMega328p chip) and Arduino Mega (ATMega2560 chip)
  * **blink**. Blinks a LED using an alarm and a task. 
  * **serial**. improve 'blink': use the standard Arduino serial API.
  * **extInterrupt**. improve 'serial': add 2 ISRs to change the alarm period.
* arm: 1 example for Olimex lpc2294 board
  * **lonely**. Blinks a led, 3 tasks, ISR category 1 or 2, counts interrupts from the push button.
* ppc: 2 examples for MPC5643L
  * **blink_1c**. Blinks a LED using an alarm and a task.
  * **blink_2c**. Blinks two leds using two synchronized cores with one task and one alarm per core.
  * **button_2c**. Waits for a button input to light a led. Switch it off using Timing Protection watchdog. Multicore example.

More examples are coming.

## Precompiled binaries of goil, the OIL compiler

Updated to version 3.0.6

* Mac OS X: [goil-mac-os-x.zip](http://trampoline.rts-software.org/bin/goil-mac-os-x.zip)
* Mac OS X Cocoa Application with editor: [CocoaGoil.app.zip](http://trampoline.rts-software.org/bin/CocoaGoil.app.zip)
* Linux 32 bits: [goil-linux-32.zip](http://trampoline.rts-software.org/bin/goil-linux-32.zip)
* Linux 64 bits: [goil-linux-64.zip](http://trampoline.rts-software.org/bin/goil-linux-64.zip)
* Windows: [goil-windows.zip](http://trampoline.rts-software.org/bin/goil-windows.zip)

## Useful links

* [ARM development tools](https://launchpad.net/gcc-arm-embedded) compiled for various plateforms.
