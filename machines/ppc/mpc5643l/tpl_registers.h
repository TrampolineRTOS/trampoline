/*
 * @file tpl_registers.h
 *
 * @section desc File description
 *
 * Trampoline register and address enumerations for C files
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
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_REGISTERS_H
#define TPL_REGISTERS_H

#include "tpl_os_std_types.h"

/* FIXME Clean this */
/*=============================================================================
 * Register number for special purpose registers
 */
#define spr_IVPR   63
#define spr_IVOR0  400
#define spr_IVOR1  401
#define spr_IVOR2  402
#define spr_IVOR3  403
#define spr_IVOR4  404
#define spr_IVOR5  405
#define spr_IVOR6  406
#define spr_IVOR7  407
#define spr_IVOR8  408
#define spr_IVOR10  410
#define spr_IVOR11  411
#define spr_IVOR12  412
#define spr_IVOR13  413
#define spr_IVOR14  414
#define spr_IVOR15  415
#define spr_IVOR32  528
#define spr_IVOR33  529
#define spr_IVOR34  530
#define spr_SRR0    26
#define spr_SRR1    27
#define spr_PIR     286
#define spr_TBU     284
#define spr_TBL     285
#define spr_DEC     22
#define spr_DECAR     54
#define spr_TSR     336
#define spr_TCR     340
#define spr_HID0    1008
#define spr_MAS0    624
#define spr_MAS1    625
#define spr_MAS2    626
#define spr_MAS3    627

/*
 * External interrupt bit mask in MSR
 */
#define EE_BIT_1  0x8000
#define RI_BIT_1  0x0002




/*=============================================================================
 * MPU registers
 */
/* Base address of the MPU */

#define MPUBase 0xFFF10000
#define TPL_MPU0_Base   MPUBase
#define TPL_MPU1_Base   0x8FF10000


/* MPU control/error status register */
#define MPU_CESR  0x00
#define MPU_CESR_SPERR_MASK 0xE0000000

/* MPU error address register, slave port 0 */
#define MPU_EAR0  0x10

/* MPU error detail register, slave port 0 */
#define MPU_EDR0  0x14

/* MPU error address register, slave port 1 */
#define MPU_EAR1  0x18

/* MPU error detail register, slave port 1 */
#define MPU_EDR1  0x1C

/* MPU error address register, slave port 2 */
#define MPU_EAR2  0x20

/* MPU error detail register, slave port 2 */
#define MPU_EDR2  0x24

/*
 * MPU Region descriptor 0
 */
#define MPU_RGD0_start  0x400
#define MPU_RGD0_end    0x404
#define MPU_RGD0_access 0x408
#define MPU_RGD0_pid    0x40C
/*
 * MPU Region descriptor 1
 */
#define MPU_RGD1_start  0x410
#define MPU_RGD1_end    0x414
#define MPU_RGD1_access 0x418
#define MPU_RGD1_pid    0x41C
/*
 * MPU Region descriptor 2
 */
#define MPU_RGD2_start  0x420
#define MPU_RGD2_end    0x424
#define MPU_RGD2_access 0x428
#define MPU_RGD2_pid    0x42C
/*
 * MPU Region descriptor 3
 */
#define MPU_RGD3_start  0x430
#define MPU_RGD3_end    0x434
#define MPU_RGD3_access 0x438
#define MPU_RGD3_pid    0x43C

/*
 * MPU Region descriptor 4
 */
#define MPU_RGD4_start  0x440
#define MPU_RGD4_end    0x444
#define MPU_RGD4_access 0x448
#define MPU_RGD4_pid    0x44C

/*
 * MPU Region descriptor 5
 */
#define MPU_RGD5_start  0x450
#define MPU_RGD5_end    0x454
#define MPU_RGD5_access 0x458
#define MPU_RGD5_pid    0x45C

/*
 * MPU Region descriptor 6
 */
#define MPU_RGD6_start  0x460
#define MPU_RGD6_end    0x464
#define MPU_RGD6_access 0x468
#define MPU_RGD6_pid    0x46C

/*
 * MPU Region descriptor 7
 */
#define MPU_RGD7_start  0x470
#define MPU_RGD7_end    0x474
#define MPU_RGD7_access 0x478
#define MPU_RGD7_pid    0x47C

/*
 * MPU Region descriptor 8
 */
#define MPU_RGD8_start  0x480
#define MPU_RGD8_end    0x484
#define MPU_RGD8_access 0x488
#define MPU_RGD8_pid    0x48C

/*
 * MPU Region descriptor 9
 */
#define MPU_RGD9_start  0x490
#define MPU_RGD9_end    0x494
#define MPU_RGD9_access 0x498
#define MPU_RGD9_pid    0x49C

/*
 * MPU Region descriptor 10
 */
#define MPU_RGD10_start  0x4A0
#define MPU_RGD10_end    0x4A4
#define MPU_RGD10_access 0x4A8
#define MPU_RGD10_pid    0x4AC



/*=============================================================================
 * Interrupts registers
 */
/* Base address of the INTC */
#define TPL_INTC_Base         0xFFF48000
#define TPL_INTC0_Base        TPL_INTC_Base
#define TPL_INTC1_Base        0x8FF48000


/*
 * INTC current priority register
 */
#define TPL_INTC_CPR_PRC0    0x08
#define TPL_INTC_CPR_PRC1    0x0C


/*
 * INTC interrupt acknowledge register
 */
#define TPL_INTC_IACKR_PRC0  0x10
#define TPL_INTC_IACKR_PRC1  0x14


/*
 * INTC end of interrupt register
 */
#define TPL_INTC_EOIR_PRC0   0x18
#define TPL_INTC_EOIR_PRC1   0x1C


/*
 * INTC priority select register
 */
#define TPL_INTC_PSR         0x40


/*
 * INTC software set/clear interrupt request register
 */
#define TPL_INTC_SSCIR03     0x20
#define TPL_INTC_SSCIR47     0x24


#define TPL_INTC_SET_7       (0x1<<1)
#define TPL_INTC_CLR_7       (0x1<<0)
#define TPL_INTC_SET_6       (0x1<<9)
#define TPL_INTC_CLR_6       (0x1<<8)
#define TPL_INTC_SET_5       (0x1<<17)
#define TPL_INTC_CLR_5       (0x1<<16)
#define TPL_INTC_SET_4       (0x1<<25)
#define TPL_INTC_CLR_4       (0x1<<24)
#define TPL_INTC_SET_3       (0x1<<1)
#define TPL_INTC_CLR_3       (0x1<<0)
#define TPL_INTC_SET_2       (0x1<<9)
#define TPL_INTC_CLR_2       (0x1<<8)
#define TPL_INTC_SET_1       (0x1<<17)
#define TPL_INTC_CLR_1       (0x1<<16)
#define TPL_INTC_SET_0       (0x1<<25)
#define TPL_INTC_CLR_0       (0x1<<24)



/*=============================================================================
 * PIT registers
 */
#define PIT_BASE_ADDR   0xC3FF0000
#define PIT_MCR_ADDR    0x0000
#define PIT_LDVAL_ADDR  0x0100
#define PIT_CVAL_ADDR   0x0104
#define PIT_TCTRL_ADDR  0x0108
#define PIT_TFLG_ADDR   0x010C


/*=============================================================================
 * SEMA4 registers
 */
/* Base address of the SEMA4 */
#define SEMA4_BASE      0xFFF24000
#define TPL_SEMA40_Base SEMA4_BASE
#define TPL_SEMA41_Base 0x8FF24000

#define SEMA4_GATES     0x0000

#define TPL_GATE_KERNEL 0
#define TPL_GATE_LOCK   1
#define TPL_GATE_SPIN   2

#define TPL_GATE_CPU0_LOCK 0x1
#define TPL_GATE_CPU1_LOCK 0x2
#define TPL_GATE_UNLOCK    0x0

/*=============================================================================
 * SSCM registers
 */
#define SSCM_BASE       0xC3FD8000
#define SSCM_GPIO_ADDR  0x0600
#define SSCM_PCR_ADDR   0x040
#define SSCM_DPM_BOOT        0x18
#define SSCM_DPM_BOOT_KEY    0x1C

#define TPL_BOOT_KEY_1  0x5AF0
#define TPL_BOOT_KEY_2  0xA50F
/* END FIXME */

/*=============================================================================
 * MC_ME : Mode Entry Module
 */

#define ME_RUNPC_RUN0   (0x1 << 4)
#define ME_RUNPC_RUN1   (0x1 << 5)
#define ME_RUNPC_RUN2   (0x1 << 6)
#define ME_RUNPC_RUN3   (0x1 << 7)
#define ME_MCTL_TGT_OFFSET  28
#define ME_MCTL_TGT_TEST    (((uint32) 1) << ME_MCTL_TGT_OFFSET)
#define ME_MCTL_TGT_SAFE    (((uint32) 2) << ME_MCTL_TGT_OFFSET)
#define ME_MCTL_TGT_DRUN    (((uint32) 3) << ME_MCTL_TGT_OFFSET)
#define ME_MCTL_TGT_RUN0    (((uint32) 4) << ME_MCTL_TGT_OFFSET)
#define ME_MCTL_TGT_RUN1    (((uint32) 5) << ME_MCTL_TGT_OFFSET)
#define ME_MCTL_TGT_RUN2    (((uint32) 6) << ME_MCTL_TGT_OFFSET)
#define ME_MCTL_TGT_RUN3    (((uint32) 7) << ME_MCTL_TGT_OFFSET)
#define ME_MCTL_TGT_HALT    (((uint32) 8) << ME_MCTL_TGT_OFFSET)
#define ME_MCTL_TGT_STOP    (((uint32) 10) << ME_MCTL_TGT_OFFSET)
#define ME_MCTL_KEY1        0x5AF0
#define ME_MCTL_KEY2        0xA50F
#define ME_PCTL_PIT         92
#define ME_PCTL_
#define ME_PC0_CONFIGURATION 0
#define ME_PC1_CONFIGURATION 1
#define ME_PC2_CONFIGURATION 2
#define ME_PC3_CONFIGURATION 3
#define ME_PC4_CONFIGURATION 4
#define ME_PC5_CONFIGURATION 5
#define ME_PC6_CONFIGURATION 6
#define ME_PC7_CONFIGURATION 7
#define ME_IS_IMTC      0x1     /* Mode transition complete interrupt */

struct __me__ {
	uint32 GS;			/* Global Status */
	uint32 MCTL;			/* Mode Control */
	uint32 ME;			/* Mode Enable Register */
	uint32 IS;			/* Interrupt Status Register */
	uint32 IM;			/* Interrupt Mask Register */
	uint32 IMTS;			/* Invalid Mode Transition Status Reg */
	uint32 DMTS;			/* Debug Mode Transition Status Reg */
	uint32 reserved_0;
	uint32 RESET;			/* Reset Mode Configuration Register */
	uint32 TEST;			/* Test Mode Configuration Register */
	uint32 SAFE;			/* Safe Mode Configuration Register */
	uint32 DRUN;			/* DRUN Mode Configuration Register */
	uint32 RUN[4];		/* RUN Mode Configuration Reg 0-4 */
	uint32 HALT0;			/* HALT0 Mode Configuration Register */
	uint32 reserved_1;
	uint32 STOP0;			/* STOP0 Mode Configuration Register */
	uint32 reserved_2[5];
	uint32 PS[3];			/* Peripheral Status Register 0-3 */
	uint32 reserved_3[5];
	uint32 RUNPC[8];		/* Peripheral Configuration Reg 0-7 */
	uint32 LPPC[8];		/* Low Power Periph Config Reg 0-7 */
	uint8  PCTL[93];		/* Peripheral Control Register */
	};

#define ME (*(volatile struct __me__ *) 0xC3FDC000UL)

/*=============================================================================
 * RGM : Reset Generation Module
 */

struct __rgm__ {
	uint16 FES;			/* Functional Event Status */
	uint16 DES;			/* Destructive Event Status */
	uint16 FERD;			/* Functional Event Reset Disable */
	uint16 DERD;			/* Destructive Event Reset Disable */
	uint16 reserved_0[4];
	uint16 FEAR;			/* Functional Event Alternate Req */
	uint16 reserved_1[3];
	uint16 FESS;			/* Functional Event Short Sequence */
	uint16 reserved_2;
	uint16 FBRE;			/* Functional Bidirect Reset Enable */
	};

#define RGM (*(volatile struct __rgm__ *) 0xC3FE4000UL)

#endif


