# Trampoline

Trampoline is a static RTOS for small embedded systems.
Its API is aligned with OSEK/VDX OS and AUTOSAR OS 4.2 standards.

8 platforms are supported by now :

* cortex
  * Cortex-M (M0+, M3 and M4 for now) instruction set
  * Cortex-A (A7) instruction set. This port is under heavy development.
  * Cortex-R (R52) instruction set.
* riscv
  * PULPino microprocessor with 32bits RISC-V instruction set.
* ppc: PowerPC 32bits instruction set
* posix: virtual platform for POSIX systems (tested on Linux and OS X)
* avr: AVR 8 bits microcontrollers
* ARM: ARM 32 bits instruction set
* virt-v7
  * Cortex-A9 - Cortex-A7 virtualized instruction set. This port is used with the hypervisor XVisor
* MSP430/CPUX which has been developed on MSP430FR5969 and MSP430FR5994 microcontrollers.
* rh850
  * Renesas G4MH instruction set.

And we welcome external contributors to extend this list.

Trampoline runs on the following platforms :

| MCU                          | Architecture       | Cores | Evaluation Board                                       |
|------------------------------|--------------------|:-----:|--------------------------------------------------------|
| Atmel ATMega328p             | 8-bit AVR          | 1     | Arduino Uno                                            |
| Atmel ATMega2560             | 8-bit AVR          | 1     | Arduino Mega                                           |
| Atmel SAM D21                | Cortex-M0+         | 1     | XPlainedPro                                            |
| Broadcom BCM2836             | Cortex-A7          | 4     | Raspberry Pi 2 Model B                                 |
| NXP LPC2294                  | ARM7               | 1     | Olimex LPC-L2294-1MB                                   |
| NXP / Freescale MK20DX256    | Cortex-M4          | 1     | Teensy31                                               |
| NXP / Freescale MPC564xL     | Power Architecture | 2     | XPC56XX EVB + XPC56XL MINI-MODULE                      |
| PULPino                      | RISC-V             | 1     | ZedBoard                                               |
| Renesas Spider CR52          | Cortex-R52         | 1     | Renesas R-Car S4 Spider                                |
| Renesas Spider G4MH          | RH850              | 1     | Renesas R-Car S4 Spider                                |
| STMicroelectronics STM32F4xx | Cortex-M4          | 1     | STM32F4DISCOVERY with STM32F407VG                      |
| STMicroelectronics STM32F30x | Cortex-M4          | 1     | Nucleo-32 STM32F303K8                                  |
| STMicroelectronics STM32L432 | Cortex-M4          | 1     | Nucleo-32 STM32L432KC                                  |
| MicroSemi SmartFusion2       | Cortex-M3          | 1     | starterKit                                             |
| MSP430FR5969, MSP430FR5994   | CPUX               | 1     | Launchpad MSP-EXP430FR5969, Launchpad MSP-EXP430FR5994 |

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

Updated to version 3.1.16 on 2023, December 4.

* Mac OS X (Universal): [goil-mac-os-x-universal.zip](https://uncloud.univ-nantes.fr/index.php/s/gXN6za6qBGSSqby)
* Mac OS X (Apple Silicon): [goil-mac-os-x-silicon.zip](https://uncloud.univ-nantes.fr/index.php/s/DHxMzm47XRyatm2)
* Mac OS X (Intel)  : [goil-mac-os-x.zip](https://uncloud.univ-nantes.fr/index.php/s/xsrTrwk8bm5x4Kz)
* Linux 32 bits: [goil-linux-32.zip](https://uncloud.univ-nantes.fr/index.php/s/9kzNTz3KK6aogbX)
* Linux 64 bits: [goil-linux-64.zip](https://uncloud.univ-nantes.fr/index.php/s/n2bHana8SLo2CrG)
* Windows: [goil-windows.zip](https://uncloud.univ-nantes.fr/index.php/s/ZAyZ4ngSqCaa4wD)  (you may be warned of the presence of a virus)

Note: goil binaries for Mac OS X are not signed. You can either recompile goil from sources (script in `goil/makefile-macosx`) or self sign the binary (information [here](https://stackoverflow.com/questions/58356844/what-are-the-ways-or-technologies-to-sign-an-executable-application-file-in-mac))

* MD5 (goil-mac-os-x-universal.zip) = 68b8cad78cecd39b273728c1d4a99ea2
* MD5 (goil-mac-os-x-silicon.zip) = 9d7422f3cead9b40e37c062bc646e53c
* MD5 (goil-mac-os-x.zip) = 411a1c5999288c955e275619c8443261
* MD5 (goil-linux-32.zip) = 581a56202e35ae5551a3f9dce600179d
* MD5 (goil-linux-64.zip) = fe06a628abd5ea954048c26a3a2cbda7
* MD5 (goil-windows.zip) = 3bc9be1b6c053aa58437c957d5d174f9

## Useful links

* [ARM development tools](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm) compiled for various platforms.

The OSEK-VDX portal is down since at least june 2017 because the working group has been disbanded in favor of AUTOSAR. Here are copies of a part of the documents that were available for download:

* [OIL specification](https://uncloud.univ-nantes.fr/index.php/s/zXE6YHjrXcysrE4)
* [OS specification](https://uncloud.univ-nantes.fr/index.php/s/KG6LYzra2paHNbS)
* [COM specification](https://uncloud.univ-nantes.fr/index.php/s/CppiWPmfyF3eKGS)
* [ORTI A](https://uncloud.univ-nantes.fr/index.php/s/x3w56pyGHoExnBp) and [ORTI B](https://uncloud.univ-nantes.fr/index.php/s/7QMCDeQLKgJQ8Xx) specifications
* [OS Test Plan](https://uncloud.univ-nantes.fr/index.php/s/cax2N6XSCex7fXx)
* [OS Test Procedure](https://uncloud.univ-nantes.fr/index.php/s/nWm9EqAdq3gkSr6)
* [COM Test Plan](https://uncloud.univ-nantes.fr/index.php/s/PTXAnj5L58aiWS9)
* [COM Test Procedure](https://uncloud.univ-nantes.fr/index.php/s/jqZEq7NByTczX5o)
