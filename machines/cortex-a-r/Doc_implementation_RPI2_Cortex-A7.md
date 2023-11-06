<h1> Raspberry Pi 2 Bare Metal Programming </h1>

The purpose of this application is to understand the behavior of the [Raspberry Pi 2] [rpi2] for a bare metal application.
You can find useful information in the [forum] [rpi2forum] dedicated to [bare metal] [rpi2forumbaremetal] applications for Raspberry Pi boards.
The application tests the starting mode of the Raspberry Pi 2 and then switch to SYS mode.
This application will blink both leds () using an IRQ and call an exception (svc) one time inside which it will increment a variable.

*   [Overview](#overview)
*   [Approach](#how)
*   [Description of material](#material)
    *   [Cortex-A7 processor](#material_cortex-a7)
    *   [Broadcom BCM2836](#material_bcm2836)
    *   [Raspberry Pi 2](#material_rpi2)
*   [Bootloader](#bootloader)
    *   [](#)
*   [Application](#app)
    *   [](#)
*   [References](#ref)

<h2 id="overview"> Overview </h2>

<h2 id="how"> Approach </h2>

Our objective is to launch a simple bare metal application able to :

*   Run standalone,
*   Trigger interrupts,
*   Trigger exceptions such as Supervisor Call (SVC) used for calling OS services,
*   Run in User space and Supervisor space (for OS services).

We will see in the [description of the Raspberry Pi 2] (#rpi2) that this board is not so easy to use ofr bare metal programming. We will need a bootloader in order not to save a lot of time plugging and unplugging the sdcard of the board.

The bootloader will offer services for :

*   Download a software through UART,
*   Launch a software,
*   Observe memory.

<h2 id="material"> Description of material </h2>

<h3 id="material_cortex-a7"> Cortex-A7 processor </h3>

The Cortex-A7 processor implements the ARMv7-A architecture. It can have up to four processors in a single device.

<h4 id=""> Modes and PSRs </h4>

Have a look to [ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition
Issue C] [ArcRefMan], Table B1-1 ARM processor modes.

Here is a short introduction to each mode hereafter. The encoding is the CPSR.M[4:0] field of CPSR register. See B1.3.3 Program Status Registers (PSRs) of [ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition Issue C] [ArcRefMan].

The CPSR is the Current Program Status Register.
The SPSR is the Saved Program Status Register. The CPSR records the pre-exception value of CPSR.

<h5 id=""> User mode </h5>

This is a mode without privilege (PL0) for executing applications.
Access to ressources and memory is unprivileged.
Cannot change mode except by causing an exception.

*   Processor mode  : User usr
*   Encoding        : 10000
*   Privilege level : PL0
*   Implemented     : Always
*   Security state  : Both

<h5 id=""> System mode </h5>

Software in System mode executes at PL1 level. This mode uses the same registers as User mode.

*   Processor mode  : System sys
*   Encoding        : 11111
*   Privilege level : PL1
*   Implemented     : Always
*   Security state  : Both

<h5 id=""> Supervisor mode </h5>

This mode is taken when a Supervisor call (svc) arises.
This is the mode of the processor upon reset.

*   Processor mode  :
*   Encoding        :
*   Privilege level : PL1
*   Implemented     : Always
*   Security state  :

<h5 id=""> Abort mode </h5>

This is the mode when a Data Abort exception or Prefetch Abort exception is taken.

*   Processor mode  : Abort abt
*   Encoding        : 10111
*   Privilege level : PL1
*   Implemented     : Always
*   Security state  : Both

<h5 id=""> Undefined mode </h5>

This the mode for exceptions related to:

*   instruction-related exceptions,
*   UNDEFINED instruction.

*   Processor mode  : Undefined und
*   Encoding        : 11011
*   Privilege level : PL1
*   Implemented     : Always
*   Security state  : Both

<h5 id=""> FIQ mode </h5>

This is the mode when a FIQ interrupt arises.

*   Processor mode  : FIQ fiq
*   Encoding        : 10001
*   Privilege level : PL1
*   Implemented     : Always
*   Security state  : Both

<h5 id=""> IRQ mode </h5>

This is the mode when an IRQ interrupt arises.

*   Processor mode  : IRQ irq
*   Encoding        : 10010
*   Privilege level : PL1
*   Implemented     : Always
*   Security state  : Both

<h5 id="hyp_mode"> HYP mode </h5>

This is the only non-secure PL2 mode. See Virtualization Extensions.

*   Processor mode  : Hyp hyp
*   Encoding        : 11010
*   Privilege level : PL2
*   Implemented     : With Virtualization Extensions
*   Security state  : Non-secure only

See B1.3.4 ELR_hyp, [ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition Issue C] [ArcRefMan], for the description of ELR_hyp register. This register is used to store the return address when taking an exception to Hyp mode.
So the return from Hyp mode exception will be :

```
  msr ELR_hyp, lr
  eret
```

<h5 id=""> Monitor mode </h5>

This is the only non-secure PL2 mode. See Virtualization Extensions.

*   Processor mode  : Monitor mon
*   Encoding        : 10110
*   Privilege level : PL1
*   Implemented     : With Security Extensions
*   Security state  : Secure only

<h4 id=""> Security Extension </h4>

<h5 id=""> Registers </h5>

**SCR**

The SCR defines the configuration of the current security state. It specifies:

*   The security state of the processor, Secure or Non-secure.
*   What mode the processor branches to, if an IRQ, FIQ or external abort occurs.
*   Whether the CPSR.F and CPSR.A bits can be modified when SCR.NS = 1.

The SCR is:

*   A read/write register.
*   A Restricted access register that exists only in the Secure state
*   Only accessible in Secure PL1 modes.

Available in all configurations.
See the register summary in Table 4-3 on page 4-5.


Have a look to [ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition
Issue C] [ArcRefMan], Figure B1-1 Modes, privilege levels, and security states.

| Non-secure state                          | Secure state       |
|------------------------------|--------------------|
| | Non-secure PL0 |           |                    |

| Atmel ATMega328p             | 8-bit AVR          | 1     | Arduino Uno                       |




		Non-secure state				Secure state

			Non-secure PL0				Secure PL0
				User mode						User mode

			Non-secure PL1				Secure PL1
				System mode					System mode
				Supervisor mode				Supervisor mode
				FIQ mode						FIQ mode
				IRQ mode						IRQ mode
				Undef mode					Undef mode
				Abort mode					Abort mode
				
			Non-secure PL2
				Hyp mode


			Secure PL1
							Monitor mode


<h4 id=""> Core registers </h4>

Have a look to Figure B1-2 ARM core registers, PSRs, and ELR_hyp, showing register banking, [ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition Issue C] [ArcRefMan].

There are 16 ARM core registers, R0 to R12, the stack pointer (SP), the link register (LR), and the program counter (PC). There is also CPSR and SPSR and [ELR_hyp] (#hyp_mode) 
There are banked copies of some registers. Thoses banked copied registers are selected from the current execution mode.

On taking an exception, the processor changes mode unless it is already in the mode to which it must take the exception. Each mode has :

*   A banked copy of SP
*   A register that holds the preferred return address for the exception depending on the mode:
    *   PL1 mode : a banked copy of LR.
    *   PL2 mode : special [ELR_hyp] (#hyp_mode) register.
*   A saved copy of CPSR, i.e. SPSR_irq, etc.

Moreover some mode have more banked registers (FIQ mode), see A2.3 ARM core registers, [ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition Issue C] [ArcRefMan].

<h4 id=""> Coprocessor </h4>

The ARM architecture supports coprocessors:

*   cp15
*   cp14
*   cp10 and cp11
*   cp8, cp9, cp12, cp13

<h5 id=""> Coprocessor cp15 </h5>

Read a CP15 register into an ARM register

```MRC p15, Op1, Rt, CRn, CRm, Op2```

Write a CP15 register from an ARM register

```MCR p15, Op1, Rt, CRn, CRm, Op2```

Organization of CP15 registers described in [ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition Issue C, §B3.17] [ArcRefMan].

They are ordered by {CRn, opc1, CRm, opc2}

<h4 id=""> Boot sequence </h4>

The Cortex-A7 starts in Supervisor mode in the Secure state [Technical Reference Manual, §3.4.1] [TecRefMan]. 

But we'll see in paragraph [§Raspberry Pi 2] (#material_rpi2) that the Raspberry Pi 2 initializes the processor in different modes depending on the version of the firmware !

<h4 id=""> Exception handling </h4>

Exception behaviour is explained in [ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition Issue C, §B1.8.3] [ArcRefMan].
How to determine the mode in witch an exception occurs : [ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition Issue C, §B1.8.4] [ArcRefMan].

<h5 id=""> Exception entry </h5>

LR is saved on entry into exception, but the value depends on the exception type and whether it is taken from PL1 or PL2 mode. This summarized in table [ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition Issue C, Table B1-6 Exception return address and Table B1-7 Offsets applied to Link value for exceptions taken to PL1 modes] [ArcRefMan].

<h4 id=""> Interrupts </h4>


<h3 id="material_bcm2836"> Broadcom BCM2836 </h3>


<h3 id="material_rpi2"> Raspberry Pi 2 </h3>

**ADVICE** 

**The documentation for Raspberry Pi is so poor and so bad that I would not recommend using such device for bare metal programming, you should use instead a perfectly well documented and open board and the Beaglebord seems to be one of them.**

The Raspberry Pi 2 uses a [Broadcom chip BCM2836] [bcm2836] which is a SoC made of a [GPU VideoCore 4] (#videocore) and a quad-core [Cortex-A7] (#). 

The family of this chip are named BCM2709 (for the specific BCM2836) and BCM2708 (for the specific BCM2835). 

You must have a look to both BCM2836 processor and BCM2835 processor documentations for peripherals. Indeed you'll find a lot of information into the documentation of the [BCM2835] (#) for peripherals that are the same for BCM2836. The only difference is the base address for peripherals.

Elements of the SoC are organised around a system address bus ([VC CPU Bus] (#memory)) that maps GPU, CPU, Peripherals, SDRAM from 0x00000000 to 0xFFFFFFFF.

<h4 id="memory"> Memory </h4>

Describe :

*   ARM *Physical* addresses : the physical addresses for Cortex-A7 core,
*   ARM *Virtual* addresses : the MMU addresses for Cortex-A7 core,
*   VC CPU *Bus* addresses : the system bus addresses.

If the MMU is disabled then you need to address peripherals with ARM *Physical* addresses.
If the MMU is enabled then you'll use ARM *Virtual* specified addresses.

ARM I/O Peripherals are mapped at address BCM283x_PERIPH_BASE.

This address depends on the version of the chip, either BCM2835 or BCM2836.

*    ```BCM2835_PERIPH_BASE = 0x20000000```
*    ```BCM2836_PERIPH_BASE = 0x3F000000```

The real address of the designed peripheral will be ```BCM283x_PERIPH_BASE + Offset```.
Then you don't have to change offset between versions BCM283x, just use the correct ```PERIPH_BASE``` value (either ```BCM2835_PERIPH_BASE``` or ```BCM2836_PERIPH_BASE```).

<h5 id=""> Example for GPIOs </h5>

**I/O Peripherals :**

*   BCM2835
    *   VC CPU Bus Address = 0x7E000000
    *   ARM Physical Addresse = 0x20000000

*   BCM2836
    *   VC CPU Bus Address = 0x7E000000
    *   ARM Physical Address = 0x3F000000

We use a Raspberry Pi 2, so ```PERIPH_BASE = BCM2836_PERIPH_BASE```.

We want to toggle the green ACT led next to the power red led of the board. This led is connect to a GPIO, and precisely the 

We need to access GPIOs, we define ```GPIO_BASE``` and ```GPIO_OFFSET ```.
According to [BCM2835 ARM Peripherals] (#bcm2835) ```GPIO_OFFSET = 0x00020000```, but nothing appears in [Documentation for BCM2836] (#bcm2836), this is surprising !

We found this parameter into [web resources] (#web). The ACT led is accessible through ```GPIO 47``` and PWR led through ```GPIO 35```.

```GPIO_BASE = PERIPH_BASE + GPIO_OFFSET```

ACT and PWR leds are ON when output is set to LOW, and OFF when output is set to HIGH.

We must use the *Function Select Registers* ```GPFSELn``` ([BCM2835 ARM Peripherals] (#bcm2835), P 91) to select the function of the port.

Pin 47 is set to output function by positionning field ```21-23``` of register ```GPFSEL4``` to ```001```.

Then we'll use the *Pin Output Set Registers* ```GPSETn```to set the GPIO pin.

```GPIO 47``` - ```FSEL 47``` - ```GPFSEL4``` - ```GPSET1```

```GPIO 35``` - ```FSEL 35``` - ```GPFSEL3``` - ```GPSET1```

ACT led is set on and off by setting bit ```15``` of register ```GPSET1``` to ```0``` or ```1```.

The values for accessing registers are :

```
#define BCM2836_PERIPH_BASE = 0x3F000000
#define PERIPH_BASE         = BCM2836_PERIPH_BASE
#define GPIO_OFFSET         = 0x00020000

#define GPFSEL0_OFFSET      = 0x00000000
#define GPFSEL1_OFFSET      = 0x00000004
#define GPFSEL2_OFFSET      = 0x00000008
#define GPFSEL3_OFFSET      = 0x0000000C
#define GPFSEL4_OFFSET      = 0x00000010
#define GPFSEL4_OFFSET      = 0x00000014

#define GPSET0_OFFSET       = 0x0000001C
#define GPSET1_OFFSET       = 0x00000020

GPIO_BASE = PERIPH_BASE + GPIO_OFFSET;
GPFSEL4 = GPIO_BASE + GPFSEL4_OFFSET;
GPSET1 = GPIO_BASE + GPSET1_OFFSET;
```

Hence lighting on the ACT led is done with the following code:

```
GPFSEL4 &= ~(7<<21);
GPFSEL4 |= 1<<21;
GPSET1 |= 1<<15;
```

<h4 id=""> Boot sequence </h4>

As far as I know the Raspberry Pi 2 has two different boot sequences.
Depending on the version of [firmware] (#) you have you may choose the *old* or *new* boot sequence.

First of all the Raspberry Pi boots its firware and then the firware loads some executable that has been written on a SD card.

The Raspberry Pi system is configured with a file named ```config.txt``` optionnaly written on the first boot partition of the SD Card.

Boot sequence of Raspberry Pi :

*   first-stage bootloader : Mounts the FAT32 boot partition in the SDCard
*   second-stage bootloader : File ```bootcode.bin``` is loaded and executed
*   third-stage bootloader : start.elf (VideoCore OS) is loaded and executed
*   start.elf loads the settings from ```config.txt```, ```cmdline.txt```
*   start.elf loads ```kernel.img`` or ```kernel7.img``` from Raspberry Pi 2

As far as I know the firmware starts the core the *new* way with this configuration, see this [link] (#ultibo):

*   HYP mode (#) for firmware later than 10/2015, Supervisor mode for previous firmware
*   Non-secure state (#)
*   L1 Instruction cache enabled (#)
*   L1 Data cache enabled (#)
*   Branch predication disabled
*   Unaligned data access enabled
*   SMP coherence enabled
*   MMU disabled
*   FPU disabled

If one wants to start the core with the *old* configuration (versions of firmware before 10/2015) he must sets the following variable into ```config.txt``` :

```kernel_old=1```

<h4 id=""> Peripherals </h4>

<h2 id="bootloader"> Bootloader </h2>

<h3 id=""> Objective </h3>

*   Upload a binary file into Raspberry Pi's ram,
*   Launch an executable file from memory
*   Print memory areas

<h2 id="app"> Bare metal application </h2>

<h3 id=""> Objective </h3>

We want the application not to be dependent of the way the core has been started. So we will guess the initial configuration of the core and set it to our needs.

The target application is a real-time operating system (RTOS) [Trampoline] (#trampoline) that is already used in industry for secure automotive applications.

Trampoline RTOS runs in two modes :

*   User : The application that uses the RTOS is executed in a secure and unprivileged mode, the User mode,
*   Supervisor : The application may call services from the RTOS. Those services are executed in Supervisor mode.


<h3 id="vectors"> Vector tables </h3>

<h3 id="app_startup"> Startup code </h3>

This startup code provides from many web inputs, see the reference for a list of very useful informations and startup code source examples.

<h4 id=""> Starting mode test </h4>
<h4 id=""> Switching mode </h4>


<h2 id="ref"> References </h2>

<h3 id="trampoline_ref"> Trampoline </h3>

[Trampoline RTOS] [trampoline]

[trampoline]: https://github.com/TrampolineRTOS/trampoline

[Real-Time Systems Team at IRCCyN, CNRS] [str]

[str]: http://www.irccyn.ec-nantes.fr/en/research-teams/real-time

<h3 id="raspberry"> Raspberry </h3>

[Raspberry Pi 2] [rpi2]

[rpi2]: https://www.raspberrypi.org/products/raspberry-pi-2-model-b/

[Documentation for Raspberry Pi 2] [rpi2Doc]

[rpi2Doc]: https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2836/README.md

[Documentation for Raspberry Pi] [rpiDoc]

[rpiDoc]: https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2835/README.md

[Raspberry Pi forum] [rpi2forum]

[rpi2forum]: https://www.raspberrypi.org/forums/

[Raspberry Pi forum section Programming, Bare metal] [rpi2forumbaremetal]

[rpi2forumbaremetal]: https://www.raspberrypi.org/forums/viewforum.php?f=72&sid=2e207f9653147b87e307f2bc67ec8243

[Configuration of Raspberry Pi system] [config]

[config]: [https://www.raspberrypi.org/documentation/configuration/config-txt.md]

<h3 id="arm"> ARM </h3>

[Cortex™-A7 MPCore™ Technical Reference Manual
Revision: r0p5] [TecRefMan]

[TecRefMan]: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0464f/index.html

[ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition
Issue C] [ArcRefMan]

[ArcRefMan]: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0406c/index.html

<h3 id="broadcom"> Broadcom </h3>

[Documentation for BCM2836] [bcm2836]

[bcm2836]: https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2836/QA7_rev3.4.pdf

[Documentation for BCM2835] [bcm2835]

[bcm2835]: https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2835/BCM2835-ARM-Peripherals.pdf

[videocore]: https://en.wikipedia.org/wiki/VideoCore

<h3 id="web"> VERY USEFUL web resources </h3>

<h4 id="web"> Ultibo </h4>

[Ultibo project] [ultibo]

[ultibo]: https://github.com/ultibohub/Core

<h4 id="web"> D.Welch </h4>

[Raspberry Pi ARM based bare metal examples from David Welch] [dwelch67]

[dwelch67]: https://github.com/dwelch67/raspberrypi

<h4 id="web"> Valvers </h4>

[VALVERS] [valvers]

[valvers]: http://www.valvers.com

[Raspberry-pi topic] [valvers1]

[valvers1]: http://www.valvers.com/open-software/raspberry-pi/

[Baremetal programming with Raspberry-pi] [valvers2]

[valvers2]: http://www.valvers.com/open-software/raspberry-pi/step01-bare-metal-programming-in-cpt1/
