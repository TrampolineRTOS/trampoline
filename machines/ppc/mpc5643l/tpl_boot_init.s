/*
 * @file tpl_init_mmu.s
 *
 * @section desc File description
 *
 * PPC CPU Initialisation functions
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 *
 * The function 'tpl_reset_registers' is an extract from the crtsiz4.s code
 * by Cosmic Software, Copyright (c) 2010 by COSMIC Software
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_assembler.h"
#include "tpl_registers_asm.h"

#define OS_START_SEC_CODE
#include "AsMemMap.h"

TPL_GLOBAL(tpl_init_mmu)
TPL_GLOBAL_REF(tpl_init_mmu):

  //# MMU Entry First 1MB FLASH    //# MAS0 : ESEL=1
  //# MAS1 : TSIZ=1MB
  //# MAS2 : EPN=0x000000000, W=0, I=0, M=0, G=0, E=big
  //# MAS3 : RPN=0x000000000, PERMIS=all

 	e_lis     r3, 0x1000
  mtspr     spr_MAS0,    r3

  e_lis     r4, 0xC000
  e_or2i    r4, 0x0500
  mtspr     spr_MAS1,    r4

  e_lis     r5, 0x0000
  e_or2i    r5, 0x0020
  mtspr     spr_MAS2,    r5

  e_lis     r6, 0x0000
  e_or2i    r6, 0x003f
  mtspr     spr_MAS3,    r6

  msync
  tlbwe
  se_isync

	// MMU Entry Shadow Flash
	// MAS0 : ESEL=1
	// MAS1 : TSIZE=1MB
	// MAS2 : EPN=0x00F00000, I=1, guarded
	// MAS3 : RPN=0x00F00000, readonly
	e_lis     r3, 0x1001
  mtspr     spr_MAS0,    r3

  e_lis     r4, 0xC000
  e_or2i    r4, 0x0500
  mtspr     spr_MAS1,    r4

  e_lis     r5, 0x00F0
  e_or2i    r5, 0x000A
  mtspr     spr_MAS2,    r5

  e_lis     r6, 0x00F0
  e_or2i    r6, 0x002F
  mtspr     spr_MAS3,    r6

	tlbwe


  // Init MMU for DPM

  //# MMU Entry First 64K SRAM in DPM - No Translation
  //# MAS0 : ESEL=2
  //# MAS1 : TSIZ=64Kbytes
  //# MAS2 : EPN=0x400000000, W=0, I=1, M=0, G=0, E=big
  //# MAS3 : RPN=0x400000000, PERMIS=all

  e_lis     r3, 0x1002
  mtspr     spr_MAS0,    r3

  e_lis     r4, 0xC000
  e_or2i    r4, 0x0300
  mtspr     spr_MAS1,    r4

  e_lis     r5, 0x4000
  e_or2i    r5, 0x0028
  mtspr     spr_MAS2,    r5

  e_lis     r6, 0x4000
  e_or2i    r6, 0x003f
  mtspr     spr_MAS3,    r6

  tlbwe

  //# MMU Entry Second 64K SRAM in DPM Mode
  //# MAS0 : ESEL=3
  //# MAS1 : TSIZ=64Kbytes
  //# MAS2 : EPN=0x50000000, W=0, I=0, M=0, G=0, E=big
  //# MAS3 : RPN=0x50000000, PERMIS=all

  e_lis     r3, 0x1003
  mtspr     spr_MAS0,    r3

  e_lis     r4, 0xC000
  e_or2i    r4, 0x0300
  mtspr     spr_MAS1,    r4

  e_lis     r5, 0x5000
  e_or2i    r5, 0x0028
  mtspr     spr_MAS2,    r5

  e_lis     r6, 0x5000
  e_or2i    r6, 0x003f
  mtspr     spr_MAS3,    r6

  tlbwe

  //# Peripheral Space in DPM mode things start at 0x8ff0_0000
  //# will start at 0x8ff0_0000 and extend 1M
  //# MAS0 : ESEL=4
  //# MAS1 : TSIZ=1MB
  //# MAS2 : EPN=0x8ff00000, W=0, I=1, M=0, G=1, E=big
  //# MAS3 : RPN=0x8ff00000, PERMIS=all

  e_lis     r3, 0x1004
  mtspr     spr_MAS0,    r3

  e_lis     r4, 0xC000
  e_or2i    r4, 0x0500
  mtspr     spr_MAS1,    r4

  e_lis     r5, 0x8ff0
  e_or2i    r5, 0x000A
  mtspr     spr_MAS2,    r5

  e_lis     r6,0x8ff0
  e_or2i    r6, 0x003f
  mtspr     spr_MAS3,    r6

  tlbwe



  //# common to both LSM and DPM
  //# MMU Entry Peripheral A
  //# MAS0 : ESEL=5
  //# MAS1 : TSIZ=1Mbytes
  //# MAS2 : EPN=0xC3F00000, W=0, I=1, M=0, G=1, E=big
  //# MAS3 : RPN=0xC3F00000, PERMIS=all

  e_lis     r3, 0x1005
  mtspr     spr_MAS0,    r3

  e_lis     r4, 0xC000
  e_or2i    r4, 0x0500
  mtspr     spr_MAS1,    r4

  e_lis     r5, 0xC3F0
  e_or2i    r5, 0x000A
  mtspr     spr_MAS2,    r5

  e_lis     r6, 0xC3F0
  e_or2i    r6, 0x003F
  mtspr     spr_MAS3,    r6

  tlbwe

  //# MMU Entry Peripheral B
  //# MAS0 : ESEL=6
  //# MAS1 : TSIZ=1Mbytes
  //# MAS2 : EPN=0xFFE00000, W=0, I=1, M=0, G=0, E=big
  //# MAS3 : RPN=0xFFE00000, PERMIS=all

  e_lis     r3, 0x1006
  mtspr     spr_MAS0,    r3

  e_lis     r4, 0xC000
  e_or2i    r4, 0x0500
  mtspr     spr_MAS1,    r4

  e_lis     r5, 0xFFE0
  e_or2i    r5, 0x0008
  mtspr     spr_MAS2,    r5

  e_lis     r6, 0xFFE0
  e_or2i    r6, 0x003F
  mtspr     spr_MAS3,    r6

  tlbwe

  //# MMU On-Platform 0 Peripherals
  //# MAS0 : ESEL=7
  //# MAS1 : TSIZ=512 Kbytes
  //# MAS2 : EPN=0xFFF00000, W=0, I=1, M=0, G=0, E=big
  //# MAS3 : RPN=0xFFF00000, PERMIS=all

  e_lis     r3, 0x1007
  mtspr     spr_MAS0,    r3

  e_lis     r4, 0xC000
  e_or2i    r4, 0x0480
  mtspr     spr_MAS1,    r4

  e_lis     r5, 0xFFF0
  e_or2i    r5, 0x0008
  mtspr     spr_MAS2,    r5

  e_lis     r6, 0xFFF0
  e_or2i    r6, 0x003F
  mtspr     spr_MAS3,    r6

  tlbwe

  //# MMU  Off-Platform Peripherals 2
  //# MAS0 : ESEL=8
  //# MAS1 : TSIZ=64 Kbytes
  //# MAS2 : EPN=0xFFF90000, W=0, I=1, M=0, G=0, E=big
  //# MAS3 : RPN=0xFFF90000, PERMIS=all

  e_lis     r3, 0x1008
  mtspr     spr_MAS0,    r3

  e_lis     r4, 0xC000
  e_or2i    r4, 0x0300
  mtspr     spr_MAS1,    r4

  e_lis     r5, 0xFFF9
  e_or2i    r5, 0x0008
  mtspr     spr_MAS2,    r5

  e_lis     r6, 0xFFF9
  e_or2i    r6, 0x003F
  mtspr     spr_MAS3,    r6

  tlbwe

  //# MMU  Off-Platform Peripherals 2
  //# MAS0 : ESEL=8
  //# MAS1 : TSIZ=256 Kbytes
  //# MAS2 : EPN=0xFFFC0000, W=0, I=1, M=0, G=0, E=big
  //# MAS3 : RPN=0xFFFC0000, PERMIS=all

  e_lis     r3, 0x1009
  mtspr     spr_MAS0,    r3

  e_lis     r4, 0xC000
  e_or2i    r4, 0x0400
  mtspr     spr_MAS1,    r4

  e_lis     r5, 0xFFFC
  e_or2i    r5, 0x0008
  mtspr     spr_MAS2,    r5

  e_lis     r6, 0xFFFC
  e_or2i    r6, 0x003F
  mtspr     spr_MAS3,    r6

  tlbwe

  se_blr


TPL_GLOBAL(tpl_reset_registers)
TPL_GLOBAL_REF(tpl_reset_registers):
	mfmsr	r5
	lis	r6,0x0200		; MSR mask
	or	r5, r6
	mtmsr	r5
	isync

	lis	r1, 0			; Initialize the lower 32-bits of GPR1 to 0
	evmergelo r0,r1,r1		; Initialize the 64-bits of GPR0 to 0
	evmergelo r1,r0,r0		; Continue initializing the other 64-bit GPRs
	evmergelo r2,r0,r0		; ...
	evmergelo r3,r0,r0
	evmergelo r4,r0,r0
	evmergelo r5,r0,r0
	evmergelo r6,r0,r0
	evmergelo r7,r0,r0
	evmergelo r8,r0,r0
	evmergelo r9,r0,r0
	evmergelo r10,r0,r0
	evmergelo r11,r0,r0
	evmergelo r12,r0,r0
	evmergelo r13,r0,r0
	evmergelo r14,r0,r0
	evmergelo r15,r0,r0
	evmergelo r16,r0,r0
	evmergelo r17,r0,r0
	evmergelo r18,r0,r0
	evmergelo r19,r0,r0
	evmergelo r20,r0,r0
	evmergelo r21,r0,r0
	evmergelo r22,r0,r0
	evmergelo r23,r0,r0
	evmergelo r24,r0,r0
	evmergelo r25,r0,r0
	evmergelo r26,r0,r0
	evmergelo r27,r0,r0
	evmergelo r28,r0,r0
	evmergelo r29,r0,r0
	evmergelo r30,r0,r0
	evmergelo r31,r0,r0		; Initialize the 64-bit GPR31 to 0

	mtspr	61,r31			; DEAR

	mtspr	272,r31			; SPRG0-7
	mtspr	273,r31
	mtspr	274,r31
	mtspr	275,r31
	mtspr	276,r31
	mtspr	277,r31
	mtspr	278,r31
	mtspr	279,r31

	mtspr	604,r31			; SPRG8-9
	mtspr	605,r31

	mtspr	256,r31			; USPRG0

	mtspr	26,r31			; SRR0-1
	mtspr	27,r31
	mtspr	58,r31			; CSRR0-1
	mtspr	59,r31
	mtspr	570,r31			; MCSRR0-1
	mtspr	571,r31
	mtspr	574,r31			; DSSRR0-1
	mtspr	575,r31

	mtspr	63,r31			; IVPR
	mtspr	62,r31			; ESR
	mtspr	340,r31			; TCR
	mtspr	512,r31			; SPEFSCR
	mtspr	1,r31			; XER
	mtspr	256,r31			; USPRG0

	mtspr	400,r31			; IVOR0-15
	mtspr	401,r31
	mtspr	402,r31
	mtspr	403,r31
	mtspr	404,r31
	mtspr	405,r31
	mtspr	406,r31
	mtspr	407,r31
	mtspr	408,r31
	mtspr	409,r31
	mtspr	410,r31
	mtspr	411,r31
	mtspr	412,r31
	mtspr	413,r31
	mtspr	414,r31
	mtspr	415,r31

	mtspr	528,r31			; IVOR32-35
	mtspr	529,r31
	mtspr	530,r31

	mtspr	573,r31			; MCAR

	mtspr	284,r31			; TBL
	mtspr	285,r31			; TBU

	mtspr	22,r31			; DEC
	mtspr	54,r31			; DECAR

	mtspr	318,r31			; DVC1
	mtspr	319,r31			; DVC2

	mtspr	562,r31			; DBCNT

	mtspr	628,r31
	mtspr	630,r31

	mtcrf	0xFF,r31

	mtspr	9,r31			; CTR

    se_blr


#define OS_STOP_SEC_CODE
#include "AsMemMap.h"

