# Trampoline

Trampoline is a static RTOS for small embedded systems.
Its API is aligned with OSEK/VDX OS and AUTOSAR OS 4.2 standards.

8 platforms are supported by now :

* cortex
  * Cortex-M (M0+, M3 and M4 for now) instruction set
  * Cortex-A (A7) instruction set. This port is under heavy development.
* riscv
  * PULPino microprocessor with 32bits RISC-V instruction set.
* ppc: PowerPC 32bits instruction set
* posix: virtual platform for POSIX systems (tested on Linux and OS X)
* avr: AVR 8 bits microcontrollers
* ARM: ARM 32 bits instruction set
* virt-v7
  * Cortex-A9 - Cortex-A7 virtualized instruction set. This port is used with the hypervisor XVisor
* MSP430/CPUX which has been developed on MSP430FR5969 and MSP430FR5994 microcontrollers.

And we welcome external contributors to extend this list.

Trampoline runs on the following platforms :

| MCU                          | Architecture       | Cores | Evaluation Board                  |
|------------------------------|--------------------|:-----:|-----------------------------------|
| Atmel ATMega328p             | 8-bit AVR          | 1     | Arduino Uno                       |
| Atmel ATMega2560             | 8-bit AVR          | 1     | Arduino Mega                      |
| Atmel SAM D21                | Cortex-M0+         | 1     | XPlainedPro                       |
| Broadcom BCM2836             | Cortex-A7          | 4     | Raspberry Pi 2 Model B            |
| NXP LPC2294                  | ARM7               | 1     | Olimex LPC-L2294-1MB              |
| NXP / Freescale MK20DX256    | Cortex-M4          | 1     | Teensy31                          |
| NXP / Freescale MPC564xL     | Power Architecture | 2     | XPC56XX EVB + XPC56XL MINI-MODULE |
| PULPino                      | RISC-V             | 1     | ZedBoard                          |
| STMicroelectronics STM32F4xx | Cortex-M4          | 1     | STM32F4DISCOVERY with STM32F407VG |
| STMicroelectronics STM32F30x | Cortex-M4          | 1     | Nucleo-32 STM32F303K8             |
| STMicroelectronics STM32L432 | Cortex-M4          | 1     | Nucleo-32 STM32L432KC             |
| MicroSemi SmartFusion2       | Cortex-M3          | 1     | starterKit                        |
| MSP430FR5969, MSP430FR5994   | CPUX               | 1     | Launchpad MSP-EXP430FR5969, Launchpad MSP-EXP430FR5994                       |

Some examples are available (check examples):

* Cortex M4 with µC stm32f407: `cortex-m/armv7em/stm32f407/stf32f4discovery`
  * **blink**. Blinks a LED using an alarm and a task.
  * **readButton**. The example polls the button to start an alarm that activates a task to blink a LED
  * **readButton_isr**. Same but the button triggers an ISR.
  * **alarms**. It is the same example than readButton_isr but we test the return value of SetRelAlarm for return parameters when in kernel (system call) mode.
  * **timer**. ISR2 trigered by timer TIM2.
* Cortex M4 with MCU stm32f303K8: `cortex-m/armv7em/stm32f303/Nucleo-32`. There are few differences from the `stm32f407` target, and examples should be easily imported.
  * **blink**. Blinks a LED using an alarm and a task.
* Cortex M4 with MCU stm32L432KC: `cortex-m/armv7em/stm32l432/Nucleo-32`.
  * **blink**. Blinks a LED using an alarm and a task.
  * **readButton**. The example polls the button to start an alarm that activates a task to blink a LED
  * **readButton_isr**. Same but the button triggers an ISR.
* Cortex M4 with µC mk20dx256 : `cortex-m/armv7em/mk20dx256/teensy31`
  * **blink**. Blinks the Teensy 3.1 LED using an alarm and a task.
  * **startStopBlink**. The example polls a button connected to pin 8 to start an alarm that activates a task to blink a LED.
  * **liquidCrystal**. startStopBlink extended. In addition the periodic task prints a value on a LCD.
  * **isr2onPIT**. Use the PIT channel 0 to trigger an ISR2.
  * **isr1onFTM**. Use the FTM0 to trigger an ISR1 and generate a variable width pulse.
* Cortex M3 with µC SmartFusion2: `cortex-m/armv7m/SmartFusion2`.
  * **blink**. a simple periodic example which toggles the two green leds (DS3, DS4) of the board
  * **fpgaInterrupt** an interrupt from the FPGA fabriq toggles the green led DS4 of the board (and a periodic task blinks another Led).
* Cortex M0+ with µC samd21: `cortex-m/armv6m/samd21/XPlainedPro`.
  * **blink**. Blinks a LED using an alarm and a task.
  * **readButton**. The example polls the button to start an alarm that activates a task to blink a LED
  * **readButton_isr**. Same but the button triggers an ISR.
* Cortex A7 with bcm2836 - Raspberry Pi 2 : `cortex-a-r/armv7/bcm2836/rpi2`.
  * **blink**. A first runable blink example is available. We need a bootloader and and a console. This stuff will be soon available as well. Single core for the moment.
* avr: 3 examples for Arduino Uno (ATMega328p chip) and Arduino Mega (ATMega2560 chip)
  * **blink**. Blinks a LED using an alarm and a task.
  * **serial**. improve 'blink': use the standard Arduino serial API.
  * **extInterrupt**. improve 'serial': add 2 ISRs to change the alarm period.
* arm: 1 example for Olimex lpc2294 board
  * **lonely**. Blinks a led, 3 tasks, ISR category 1 or 2, counts interrupts from the push button.
* ppc: 5 examples for MPC5643L
  * **blink_1c**. Blinks a LED using an alarm and a task.
  * **blink_1c_withOrti**. Blinks a LED using an alarm and a task. Creates an orti file.
  * **blink_2c**. Blinks two leds using two synchronized cores with one task and one alarm per core.
  * **blink_2c_arxml**. Same as the two cores blink example but uses an arxml config file.
  * **blink_2c_opticks**. Same as the two cores blink example but optimizes ticks.
  * **button_2c**. Waits for a button input to light a led. Switch it off using Timing Protection watchdog. Multicore example.
  * **spinlocks**. Producer/Consumer example.
* PULPino: `riscv/pulpino`
  * **blink**. Has two tasks who alternate outputting on UART interface.
* virt-v7:
  * **firmware**. Builds a firmware that can be used as a guest on XVisor.
* MSP430 CPUX, 4 examples for Launchpad MSP-EXP430FR5969 and for MSP-EXP430FR5994:
  * **blink**. blink LED2 with a 100ms period.
  * **readbutton**. blink LED2 with a 200ms period. Button S1 allows to start and stop the blinking.
  * **readbutton_isr1**.  blink LED2 with a 200ms period. Button S1 triggers an ISR1 that swtches LED1.
  * **readbutton_isr2**.  blink LED2 with a 200ms period. Button S1 triggers an ISR2 that swtches LED1.

More examples are coming.

## Precompiled binaries of goil, the OIL and ARXML compiler

Updated to version 3.1.12 on 2020, November 2.


* Linux 32 bits: [goil-linux-32.zip](http://osek.triskell.org/goil-linux-32.zip)
* Linux 64 bits: [goil-linux-64.zip](http://osek.triskell.org/goil-linux-64.zip)
* Windows: [goil-windows.zip](http://osek.triskell.org/goil-windows.zip)
* Mac OS X (Intel)  : [goil-mac-os-x.zip](http://osek.triskell.org/goil-mac-os-x.zip)
* Mac OS X (Silicon): [goil-mac-os-x-silicon.zip](http://osek.triskell.org/goil-mac-os-x-silicon.zip)
* Mac OS X Cocoa Application with editor (Intel)  : [CocoaGoil.app.zip](http://osek.triskell.org/CocoaGoil.app.zip)
* Mac OS X Cocoa Application with editor (Silicon): [CocoaGoil-silicon.app.zip](http://osek.triskell.org/CocoaGoil-silicon.app.zip)

Note: goil binaries for Mac OS X are not signed. You can either recompile goil rom sources (script in `goil/makefile-macosx`) or self sign the binary (information [here](https://stackoverflow.com/questions/58356844/what-are-the-ways-or-technologies-to-sign-an-executable-application-file-in-mac))

## Useful links

* [ARM development tools](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm) compiled for various platforms.

The OSEK-VDX portal is down since at least june 2017 because the working group has been disbanded in favor of AUTOSAR. Here are copies of a part of the documents that were available for download:

* [OIL specification](http://osek.triskell.org/oil25.pdf)
* [OS specification](http://osek.triskell.org/os223.pdf)
* [COM specification](http://osek.triskell.org/OSEKCOM303.pdf)
* [ORTI A](http://osek.triskell.org/orti-a-22.pdf) and [ORTI B](http://osek.triskell.org/orti-b-22.pdf) specifications
* [OS Test Plan](http://osek.triskell.org/ostestplan20.pdf)
* [OS Test Procedure](http://osek.triskell.org/ostestproc20.pdf)
* [COM Test Plan](http://osek.triskell.org/comtestplan20.pdf)
* [COM Test Procedure](http://osek.triskell.org/comtestproc20.pdf)
