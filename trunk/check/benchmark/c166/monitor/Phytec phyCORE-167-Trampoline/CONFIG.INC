;------------------------------------------------------------------------------
;  This file defines the Monitor Configuration Parameters
;  Copyright KEIL ELEKTRONIK GmbH 1993 - 1999
;  Version 4.00
;------------------------------------------------------------------------------
;
; Definitions of Monitor Parameters
; ---------------------------------
;
; DATA_START: Defines the Start Address for the Monitor Data Area
;             Monitor uses 512 Bytes RAM starting at this location.
%DEFINE (DATA_START) (0FEA00H) ; set to 0FEA00H for Target "Bootstrap" 
;                              ; set to 0FFE00H for Targets "UART ASC0" and "Simulated Serial"
;
; CODE_START: Defines the Start Address for the Monitor Code Area
;             Monitor requires 6KB for program code starting at this location.
%DEFINE (CODE_START) (0FEC00H) ; set to 0FEC00H for Target "Bootstrap" 
;                              ; set to 0200000H for Targets "UART ASC0" and "Simulated Serial"
;
; VECTAB: Defines the Interrupt Vector Address relocation 
; Notes: This setting is ONLY relevant, if CODE_START is 0.  Locate interrupts
;        in your target application to the same address with uVision2
;        Project-Options for Target-L166 Misc-Interrupt Vector Table Address
;        (generates the L166 VECTAB directive).
%DEFINE (VECTAB) (08000H)         ; default Address 0x8000
;
; BAUDRATE: Defines the communication Baudrate for NON-BOOTSTRAP Mode.
; Notes: For SIMULATED SERIAL MODE the max. Baudrate is 38400bps @20MHz Clock.
;        Use the default baudrate first, before you check higher baudrates.
;        This setting is not relevant when you are using BOOTSTRAP Mode.
;        You may set BAUDRATE to 0 to enable automatic baudrate detection.
;        Automatic baudrate detection does not work for the SIMULATED SERIAL MODE.
BAUDRATE     EQU   19200     ; default Baudrate is 9600 bps.
;
; CPU_CLOCK: Defines the internal CPU Clock frequency
; Notes: The internal Clock might be different from the XTAL frequency, due
;        to on-chip PLL.  This setting is not relevant for BOOTSTRAP Mode.
CPU_CLOCK    EQU   20000000 ; default clock for most chips is 20MHz
;
;------------------------------------------------------------------------------
;
; Definitions for SYSCON and BUSCON0 Register:
; --------------------------------------------
;
; MCTC0: Memory Cycle Time (BUSCON0.0 .. BUSCON0.3):
; Note: if RDYEN0 == 1 a maximum number of 7 waitstates can be selected
_MCTC0	 EQU	1	; Memory wait states is 1 (MCTC0 field = 0EH).
;			; (Reset Value = 15 additional state times)
;
; RWDC0: Read/Write Signal Delay (BUSCON0.4):
_RWDC0	 EQU	0	; 0 = Delay Time     0.5 States (Reset Value)  
;			; 1 = No Delay Time  0   States
;
; MTTC0: Memory Tri-state Time (BUSCON0.5):
_MTTC0	 EQU	1	; 0 = Delay Time     0.5 States (Reset Value)
;			; 1 = No Delay Time  0   States
;
$SET (BTYP_ENABLE = 0)  ; 0 = BTYP0 and BUSACT0 is set according to the level
                        ;     at pins P0L.6 and P0L.7 during reset.
			; 1 = the following _BTYP0 and _BUSACT0 values are
			;     written to BTYP0 and BUSACT0

; BTYP0: External Bus Configuration Control (BUSCON0.6 .. BUSCON0.7):
_BTYP0	 EQU	2	; 0 = 8 Bit Non Multiplexed
;			; 1 = 8 Bit Multiplexed
;			; 2 = 16 Bit Non Multiplexed
;			; 3 = 16 Bit Multiplexed
;
; ALECTL0: ALE Lengthening Control Bit (BUSCON0.9):
_ALECTL0 EQU	0	; see data sheet for description
;
; BUSACT0: Bus Active Control Bit (BUSCON0.10):
_BUSACT0 EQU	1	; = 0 external bus disabled
			; = 1 external bus enabled
;
; RDYEN0: READY# Input Enable control bit (BUSCON0.12):
_RDYEN0  EQU	0	; 0 = READY# function disabled  (Reset Value)
;			; 1 = READY# function enabled
;
; RDY_AS0: Synchronous / Asynchronous READY# Input (BUSCON0.3):
; Note: This bit is only valid if _RDYEN0 == 1.
_RDY_AS0 EQU	0	; 0 = synchronous READY# input
;			; 1 = asynchronous READY# input
;
; CSREN0: Read Chip Select Enable bit (BUSCON0.14, only in some devices):
_CSREN0  EQU	0	; 0 = CS0# is independent of read command (RD#)
;			; 1 = CS0# is generated for the duration of read
;
; CSWEN0: Write Chip Select Enable bit (BUSCON0.15, only in some devices):
_CSWEN0  EQU	0	; 0 = CS0# is independent of write command (WR#)
;			; 1 = CS0# is generated for the duration of write
;
; XPERSHARE: XBUS Peripheral Share Mode Control (SYSCON.0)
_XPERSHARE EQU 0        ; 0 = External accesses to XBUS peripherals disabled
;                       ; 1 = XBUS accessible via external BUS in hold mode
;
; VISIBLE: Visible Mode Control (SYSCON.1)
_VISIBLE EQU 0          ; 0 = Accesses to XBUS are done internally
;                       ; 1 = XBUS accesses are made visible on external pins
;
; XPEN: XRAM & XBUS Peripheral Enable Control Bit (SYSCON.2)
_XPEN	EQU	1	; 0 = access to on-chip XRAM & XBUS disable => EXT.BUS
;                       ; 1 = on-chip XRAM & XBUS is accessed
;
; BDRSTEN: Bidirectional Reset Enable Bit (SYSCON.3, only in some devices)
_BDRSTEN EQU    0       ; 0 = Pin RSTIN# is an input only
;                       ; 1 = RSTIN# is pulled low during internal reset
;
$SET (OWDDIS_ENABLE = 0); 0 = OWDDIS is set according to the inverted level
;                       ;     at pin RD\ duirng reset.
;                       ; 1 = the following _OWDDIS value is
;                       ;     written to OWDDIS in the SYSCON register
; OWDDIS: Oscillator Watchdog Disable Bit (SYSCON.4, only in some devices)
_OWDDIS EQU     0       ; 0 = the on-chip oscillator watchdog is enabled 
;                       ; 1 = the on-chip oscillator watchdog is disabled
;
; PWDCFG: Power Down Mode Configuration Bit (SYSCON.5, only in some devices)
_PWDCFG EQU     0       ; 0 = Power Down mode can be left via reset
;                       ; 1 = Power Down mode left via ext. or RTC interrupt
;
; CSCFG: Chip Select Configuration Control (SYSCON.6, only in some devices)
_CSCFG  EQU     0       ; 0 = Latched CS mode; CS signals are latch internally
;                       ; 1 = Unlatched CS mode
; 
$SET (WRCFG_ENABLE = 0) ; 0 = WRCFG is set according to the level at
;                       ;     pin P0H.0 during reset.
;                       ; 1 = the following _WRCFG value is
;                       ;     written to WRCFG in the SYSCON register
; WRCFG: Write Configuration Control Bit (SYSCON.7):
_WRCFG	 EQU	1	; 0 = Normal configuration of WR# and BHE#
;			; 1 = WR# pin acts as WRL#, BHE# pin acts as WRH#
;
; CLKEN: System Clock Output Enable bit (SYSCON.8):
_CLKEN	EQU	0	; 0 = disabled    (Reset Value)
;			; 1 = enabled
;
; BYTDIS: Byte High Enable pin control bit (SYSCON.9):
_BYTDIS	EQU	0	; 0 = enabled     (Reset Value)
;			; 1 = disabled
;
; ROMEN: Internal ROM Access Enable is read only (SYSCON.10):
_ROMEN	EQU	0	; 0 = Internal ROM disabled
			; 1 = Internal ROM enabled
;
; SGTDIS: Segmentation Disable control bit (SYSCON.11):
_SGTDIS	EQU	0	; 0 = Segmentation enabled (Reset Value)
			; 1 = Segmentation disabled
;
; ROMS1: ROM Segment Mapping Control Bit (SYSCON.12):
_ROMS1  EQU	0	; _ROMS1 = 0 Internal ROM mapped to segment 0
;			; _ROMS1 = 1 Internal ROM mapped to segment 1
;
; STKSZ: Maximum System Stack Size selection  (SYSCON.13 .. SYSCON.15)
;  Defines the system stack space which is used by CALL/RET and PUSH/POP
;  instructions.  This system stack selectino must be identical with
;  the selection in your START167.A66 file.
$SET (STK_SIZE = 7)
;     System stack sizes:
;       0 = 256 words (Reset Value)
;       1 = 128 words
;       2 =  64 words
;       3 =  32 words
;       4 = 512 words
;       5 = not implemented
;       6 = not implemented
;       7 = no wrapping (entire internal RAM use as STACK)
;-----------------------------------------------------------------------------
; Initialization for XPERCON register (available on some derivatives only)
;
; INIT_XPERCON: Init XPERCON register available on some devices
; --- Set INIT_XPERCON = 1 to initilize the XPERCON register
$SET (INIT_XPERCON = 0)
;
; --- XPERCON values
;
; V_CAN1: make CAN1 address range 0xEF00 .. 0xEFFF visible (XPERCON.0)
_V_CAN1    EQU     1       ; 0 = CAN1 is not visible on the XBUS
;                          ; 1 = CAN1 is visible on the XBUS (default)
;
; V_CAN2: make CAN2 address range 0xEE00 .. 0xEEFF visible (XPERCON.1)
_V_CAN2    EQU     0       ; 0 = CAN2 is not visible on the XBUS (default)
;                          ; 1 = CAN2 is visible on the XBUS
;
; V_XRAM2: make 2KB XRAM address range 0xE000 .. 0xE7FF visible (XPERCON.10)
_V_XRAM2   EQU     1       ; 0 = 2KB XRAM is not visible on the XBUS
;                          ; 1 = 2KB XRAM is visible on the XBUS (default)
;
; V_XRAM6: make 6KB XRAM address range 0xC000 .. 0xD7FF visible (XPERCON.11)
_V_XRAM6   EQU     0       ; 0 = 6KB XRAM is not visible on the XBUS (default)
;                          ; 1 = 6KB XRAM is visible on the XBUS
;
; V_XFLASH: make 4KB XFLASH address range 0x8000 .. 0x8FFF visible (XPERCON.14)
_V_XFLASH  EQU     0       ; 0 = 4KB XFLASH is not visible on the XBUS (default)
;                          ; 1 = 4KB XFLASH is visible on the XBUS
;
;------------------------------------------------------------------------------
;
; Initialization for SYSCON2 and SYSCON3 (available on some derivatives only)
; Note: The SYSCON2 and SYSCON3 bits may be different in some derivatives.
;       Check the values carefully!
;
; ADVANCED_SYSCON: Init SYSCON2 and SYSCON3 register available on some devices
; --- Set ADVANCE_SYSCON = 1 to initilize SYSCON2 and SYSCON3
$SET (ADVANCED_SYSCON = 0)
;
; --- SYSCON2 values
;
; PDCON: Power Down Control (during power down mode) (SYSCON2.4 .. SYSCON2.5)
_PDCON  EQU     0       ; 0 = RTC On,  Ports On  (default after Reset)
;                       ; 1 = RTC On,  Ports Off
;                       ; 2 = RTC Off, Ports On
;                       ; 3 = RTC Off, Ports Off
;
; RTS: RTC Clock Source (not affected by a reset) (SYSCON2.6)
_RTS    EQU     0	; 0 = Main oscillator
;                       ; 1 = Auxiliary oscillator (if available)
;
; SCS: SDD Clock Source (not affected by a reset) (SYSCON2.7)
_SCS    EQU     0	; 0 = Main oscillator
;                       ; 1 = Auxiliary oscillator (if available)
;
; CLKCON: Clock State Control (SYSCON2.8 .. SYSCON2.9)
_CLKCON EQU     0	; 0 = Running on configured basic frequency
;                       ; 1 = Running on slow down frequency, PLL ON
;                       ; 2 = Running on slow down frequency, PLL OFF
;                       ; 3 = reserved
;
; CLKREL: Reload Counter Value for Slowdown Devider (SYSCON2.10 .. SYSCON2.14)
_CLKREL EQU     0       ; possible values are 0 .. 31
;
;
; --- SYSCON3 values: disable on-chip peripherals
;
_ADCDIS  EQU    0       ; 1 = disable Analog/Digital Converter    (SYSCON3.0)
_ASC0DIS EQU	0	; 1 = disable UART ASC0                   (SYSCON3.1)
_SSCDIS	 EQU	0	; 1 = disable Synchronus Serial Cnl SSC   (SYSCON3.2)
_GPTDIS	 EQU	0	; 1 = disable Timer Block GPT             (SYSCON3.3)
             		; reserved                                (SYSCON3.4)
_FMDIS   EQU	0	; 1 = disable on-chip Flash Memory Module (SYSCON3.5)
_CC1DIS	 EQU	0	; 1 = disable CAPCOM Unit 1               (SYSCON3.6)
_CC2DIS	 EQU	0	; 1 = disable CAPCOM Unit 2               (SYSCON3.7)
_CC6DIS	 EQU	0	; 1 = disable CAPCOM Unit 6               (SYSCON3.8)
_PWMDIS	 EQU	0	; 1 = disable Pulse Width Modulation Unit (SYSCON3.9)
_ASC1DIS EQU	0	; 1 = disable UART ASC1                   (SYSCON3.10)
_I2CDIS  EQU    0       ; 1 = disable I2C Bus Module              (SYSCON3.11)
;                       ; reserved                                (SYSCON3.12)
_CAN1DIS EQU    0       ; 1 = disable on-chip CAN Module 1        (SYSCON3.13)
_CAN2DIS EQU    0       ; 1 = disable on-chip CAN Module 2        (SYSCON3.14)
_PCDDIS  EQU    0       ; 1 = disable Peripheral Clock Driver     (SYSCON3.15)
;
;------------------------------------------------------------------------------
;
; BUSCON1/ADDRSEL1 .. BUSCON4/ADDRSEL4 Initialization
; ===================================================
;
;
; BUSCON1/ADDRSEL1
; --- Set BUSCON1 = 1 to initialize the BUSCON1/ADDRSEL1 registers
$SET (BUSCON1 = 1)
;
; Define the start address and the address range of Chip Select 1 (CS1#) 
; This values are used to set the ADDRSEL1 register
%DEFINE (ADDRESS1) (0000H)     ; Set CS1# Start Address (default 100000H)
%DEFINE (RANGE1)   (1024K)       ; Set CS1# Range (default 1024K = 1MB)
;  
; MCTC1: Memory Cycle Time (BUSCON1.0 .. BUSCON1.3):
; Note: if RDYEN1 == 1 a maximum number of 7 waitstates can be selected
_MCTC1	 EQU	1	; Memory wait states is 1 (MCTC1 field = 0EH).
;
; RWDC1: Read/Write Signal Delay (BUSCON1.4):
_RWDC1	 EQU	0	; 0 = Delay Time     0.5 States
;			; 1 = No Delay Time  0   States
;
; MTTC1: Memory Tri-state Time (BUSCON1.5):
_MTTC1	 EQU	1	; 0 = Delay Time     0.5 States
;			; 1 = No Delay Time  0   States
;
; BTYP1: External Bus Configuration Control (BUSCON1.6 .. BUSCON1.7):
_BTYP1	 EQU	2	; 0 = 8 Bit Non Multiplexed
;			; 1 = 8 Bit Multiplexed
;			; 2 = 16 Bit Non Multiplexed
;			; 3 = 16 Bit Multiplexed
;
; ALECTL1: ALE Lengthening Control Bit (BUSCON1.9):
_ALECTL1 EQU	0	; see data sheet for description
;
; BUSACT1: Bus Active Control Bit (BUSCON1.10):
_BUSACT1 EQU	1	; = 0 external (ADDRSEL1) bus disabled
			; = 1 external (ADDRSEL1) bus enabled
;
; RDYEN1: READY# Input Enable control bit (BUSCON1.12):
_RDYEN1  EQU	0	; 0 = READY# function disabled
;			; 1 = READY# function enabled
;
; RDY_AS1: Synchronous / Asynchronous READY# Input (BUSCON1.3):
; Note: This bit is only valid if _RDYEN1 == 1.
_RDY_AS1 EQU	0	; 0 = synchronous READY# input
;			; 1 = asynchronous READY# input
;
; CSREN1: Read Chip Select Enable bit (BUSCON1.14):
_CSREN1  EQU	0	; 0 = CS1# is independent of read command (RD#)
;			; 1 = CS1# is generated for the duration of read
;
; CSWEN1: Write Chip Select Enable bit (BUSCON1.15):
_CSWEN1  EQU	0	; 0 = CS1# is independent of write command (WR#)
;			; 1 = CS1# is generated for the duration of write
;
;
; BUSCON2/ADDRSEL2
; --- Set BUSCON2 = 1 to initialize the BUSCON2/ADDRSEL2 registers
$SET (BUSCON2 = 1)
;
; Define the start address and the address range of Chip Select 2 (CS2#) 
; This values are used to set the ADDRSEL2 register
%DEFINE (ADDRESS2) (200000H)     ; Set CS2# Start Address (default 200000H)
%DEFINE (RANGE2)   (1024K)       ; Set CS2# Range (default 1024K = 1MB)
;  
; MCTC2: Memory Cycle Time (BUSCON2.0 .. BUSCON2.3):
; Note: if RDYEN2 == 1 a maximum number of 7 waitstates can be selected
_MCTC2	 EQU	1	; Memory wait states is 1 (MCTC2 field = 0EH).
;
; RWDC2: Read/Write Signal Delay (BUSCON2.4):
_RWDC2	 EQU	0	; 0 = Delay Time     0.5 States
;			; 1 = No Delay Time  0   States
;
; MTTC2: Memory Tri-state Time (BUSCON2.5):
_MTTC2	 EQU	1	; 0 = Delay Time     0.5 States
;			; 1 = No Delay Time  0   States
;
; BTYP2: External Bus Configuration Control (BUSCON2.6 .. BUSCON2.7):
_BTYP2	 EQU	0	; 0 = 8 Bit Non Multiplexed			;Achtung !!! war auf 2
;			; 1 = 8 Bit Multiplexed
;			; 2 = 16 Bit Non Multiplexed
;			; 3 = 16 Bit Multiplexed
;
; ALECTL2: ALE Lengthening Control Bit (BUSCON2.9):
_ALECTL2 EQU	0	; see data sheet for description
;
; BUSACT2: Bus Active Control Bit (BUSCON2.10):
_BUSACT2 EQU	1	; = 0 external (ADDRSEL2) bus disabled
			; = 1 external (ADDRSEL2) bus enabled
;
; RDYEN2: READY# Input Enable control bit (BUSCON2.12):
_RDYEN2  EQU	0	; 0 = READY# function disabled
;			; 1 = READY# function enabled
;
; RDY_AS2: Synchronous / Asynchronous READY# Input (BUSCON2.3):
; Note: This bit is only valid if _RDYEN2 == 1.
_RDY_AS2 EQU	0	; 0 = synchronous READY# input
;			; 1 = asynchronous READY# input
;
; CSREN2: Read Chip Select Enable bit (BUSCON2.14):
_CSREN2  EQU	0	; 0 = CS2# is independent of read command (RD#)
;			; 1 = CS2# is generated for the duration of read
;
; CSWEN2: Write Chip Select Enable bit (BUSCON2.15):
_CSWEN2  EQU	0	; 0 = CS2# is independent of write command (WR#)
;			; 1 = CS2# is generated for the duration of write
;
;
; BUSCON3/ADDRSEL3
; --- Set BUSCON3 = 1 to initialize the BUSCON3/ADDRSEL3 registers
$SET (BUSCON3 = 0)
;
; Define the start address and the address range of Chip Select 3 (CS3#) 
; This values are used to set the ADDRSEL3 register
%DEFINE (ADDRESS3) (300000H)     ; Set CS3# Start Address (default 300000H)
%DEFINE (RANGE3)   (1024K)       ; Set CS3# Range (default 1024K = 1MB)
;  
; MCTC3: Memory Cycle Time (BUSCON3.0 .. BUSCON3.3):
; Note: if RDYEN3 == 1 a maximum number of 7 waitstates can be selected
_MCTC3	 EQU	1	; Memory wait states is 1 (MCTC3 field = 0EH).
;
; RWDC3: Read/Write Signal Delay (BUSCON3.4):
_RWDC3	 EQU	0	; 0 = Delay Time     0.5 States
;			; 1 = No Delay Time  0   States
;
; MTTC3: Memory Tri-state Time (BUSCON3.5):
_MTTC3	 EQU	1	; 0 = Delay Time     0.5 States
;			; 1 = No Delay Time  0   States
;
; BTYP3: External Bus Configuration Control (BUSCON3.6 .. BUSCON3.7):
_BTYP3	 EQU	2	; 0 = 8 Bit Non Multiplexed
;			; 1 = 8 Bit Multiplexed
;			; 2 = 16 Bit Non Multiplexed
;			; 3 = 16 Bit Multiplexed
;
; ALECTL3: ALE Lengthening Control Bit (BUSCON3.9):
_ALECTL3 EQU	0	; see data sheet for description
;
; BUSACT3: Bus Active Control Bit (BUSCON3.10):
_BUSACT3 EQU	1	; = 0 external (ADDRSEL3) bus disabled
			; = 1 external (ADDRSEL3) bus enabled
;
; RDYEN3: READY# Input Enable control bit (BUSCON3.12):
_RDYEN3  EQU	0	; 0 = READY# function disabled
;			; 1 = READY# function enabled
;
; RDY_AS3: Synchronous / Asynchronous READY# Input (BUSCON3.3):
; Note: This bit is only valid if _RDYEN3 == 1.
_RDY_AS3 EQU	0	; 0 = synchronous READY# input
;			; 1 = asynchronous READY# input
;
; CSREN3: Read Chip Select Enable bit (BUSCON3.14):
_CSREN3  EQU	0	; 0 = CS3# is independent of read command (RD#)
;			; 1 = CS3# is generated for the duration of read
;
; CSWEN3: Write Chip Select Enable bit (BUSCON3.15):
_CSWEN3  EQU	0	; 0 = CS3# is independent of write command (WR#)
;			; 1 = CS3# is generated for the duration of write
;
;
; BUSCON4/ADDRSEL4
; --- Set BUSCON4 = 1 to initialize the BUSCON4/ADDRSEL4 registers
$SET (BUSCON4 = 0)
;
; Define the start address and the address range of Chip Select 4 (CS4#) 
; This values are used to set the ADDRSEL4 register
%DEFINE (ADDRESS4) (400000H)     ; Set CS4# Start Address (default 400000H)
%DEFINE (RANGE4)   (1024K)       ; Set CS4# Range (default 1024K = 1MB)
;  
; MCTC4: Memory Cycle Time (BUSCON4.0 .. BUSCON4.3):
; Note: if RDYEN4 == 1 a maximum number of 7 waitstates can be selected
_MCTC4	 EQU	1	; Memory wait states is 1 (MCTC4 field = 0EH).
;
; RWDC4: Read/Write Signal Delay (BUSCON4.4):
_RWDC4	 EQU	0	; 0 = Delay Time     0.5 States
;			; 1 = No Delay Time  0   States
;
; MTTC4: Memory Tri-state Time (BUSCON4.5):
_MTTC4	 EQU	1	; 0 = Delay Time     0.5 States
;			; 1 = No Delay Time  0   States
;
; BTYP4: External Bus Configuration Control (BUSCON4.6 .. BUSCON4.7):
_BTYP4	 EQU	2	; 0 = 8 Bit Non Multiplexed
;			; 1 = 8 Bit Multiplexed
;			; 2 = 16 Bit Non Multiplexed
;			; 3 = 16 Bit Multiplexed
;
; ALECTL4: ALE Lengthening Control Bit (BUSCON4.9):
_ALECTL4 EQU	0	; see data sheet for description
;
; BUSACT4: Bus Active Control Bit (BUSCON4.10):
_BUSACT4 EQU	1	; = 0 external (ADDRSEL4) bus disabled
			; = 1 external (ADDRSEL4) bus enabled
;
; RDYEN4: READY# Input Enable control bit (BUSCON4.12):
_RDYEN4  EQU	0	; 0 = READY# function disabled
;			; 1 = READY# function enabled
;
; RDY_AS4: Synchronous / Asynchronous READY# Input (BUSCON4.3):
; Note: This bit is only valid if _RDYEN4 == 1.
_RDY_AS4 EQU	0	; 0 = synchronous READY# input
;			; 1 = asynchronous READY# input
;
; CSREN4: Read Chip Select Enable bit (BUSCON4.14):
_CSREN4  EQU	0	; 0 = CS4# is independent of read command (RD#)
;			; 1 = CS4# is generated for the duration of read
;
; CSWEN4: Write Chip Select Enable bit (BUSCON4.15):
_CSWEN4  EQU	0	; 0 = CS4# is independent of write command (WR#)
;			; 1 = CS4# is generated for the duration of write
;
;------------------------------------------------------------------------------

