/*
 * @file tpl_registers_asm.h
 *
 * @section desc File description
 *
 * Trampoline register and address enumerations for asm files
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

#ifndef TPL_REGISTERS_ASM_H
#define TPL_REGISTERS_ASM_H

/*=============================================================================
 * Register number for special purpose registers
 */
/* General Registers */
#define spr_CTR     9
#define spr_LR      8
#define spr_XER     1

/* Debug Registers */
#define spr_DBCNT   562
#define spr_DVC1    318
#define spr_DVC2    319

/* Exception Handling */
#define spr_SPRG0   272
#define spr_SPRG1   273
#define spr_SPRG2   274
#define spr_SPRG3   275
#define spr_SPRG4   276
#define spr_SPRG5   277
#define spr_SPRG6   278
#define spr_SPRG7   279
#define spr_SPRG8   604
#define spr_SPRG9   605
#define spr_USPRG0  256
#define spr_SRR0    26
#define spr_SRR1    27
#define spr_CSRR0   58
#define spr_CSRR1   59
#define spr_DSRR0   574
#define spr_DSRR1   575
#define spr_MCSRR0  570
#define spr_MCSRR1  571
#define spr_IVPR    63
#define spr_IVOR0   400
#define spr_IVOR1   401
#define spr_IVOR2   402
#define spr_IVOR3   403
#define spr_IVOR4   404
#define spr_IVOR5   405
#define spr_IVOR6   406
#define spr_IVOR7   407
#define spr_IVOR8   408
#define spr_IVOR9   409
#define spr_IVOR10  410
#define spr_IVOR11  411
#define spr_IVOR12  412
#define spr_IVOR13  413
#define spr_IVOR14  414
#define spr_IVOR15  415
#define spr_IVOR32  528
#define spr_IVOR33  529
#define spr_IVOR34  530
#define spr_MCAR    573
#define spr_DEAR    61

/* Timers */
#define spr_DEC     22
#define spr_DECAR   54
#define spr_TBL     284
#define spr_TBU     285
#define spr_TSR     336
#define spr_TCR     340

/* Memory Management Registers */
#define spr_MAS0    624
#define spr_MAS1    625
#define spr_MAS2    626
#define spr_MAS3    627
#define spr_MAS4    628
#define spr_MAS6    630

/* Processor Control Registers */
#define spr_PIR     286
#define spr_HID0    1008

/*
 * External interrupt bit mask in MSR
 */
#define EE_BIT_1  0x8000
#define DE_BIT_1  0x0200
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

/*
 * MPU Region descriptor 10
 */
#define MPU_RGD11_start  0x4B0
#define MPU_RGD11_end    0x4B4
#define MPU_RGD11_access 0x4B8
#define MPU_RGD11_pid    0x4BC

/*
 * MPU Region descriptor 10
 */
#define MPU_RGD12_start  0x4C0
#define MPU_RGD12_end    0x4C4
#define MPU_RGD12_access 0x4C8
#define MPU_RGD12_pid    0x4CC

/*
 * MPU Region descriptor 10
 */
#define MPU_RGD13_start  0x4D0
#define MPU_RGD13_end    0x4D4
#define MPU_RGD13_access 0x4D8
#define MPU_RGD13_pid    0x4DC

/*
 * MPU Region descriptor 10
 */
#define MPU_RGD14_start  0x4E0
#define MPU_RGD14_end    0x4E4
#define MPU_RGD14_access 0x4E8
#define MPU_RGD14_pid    0x4EC

/*
 * MPU Region descriptor 10
 */
#define MPU_RGD15_start  0x4F0
#define MPU_RGD15_end    0x4F4
#define MPU_RGD15_access 0x4F8
#define MPU_RGD15_pid    0x4FC

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
 * Sema4 registers
 */

/* We're using the Gate 0 of the sema4_0 to get the kernel lock */
#define TPL_SEMA4_BASE  0xFFF24000
#define TPL_GATE_KERNEL 0

/*=============================================================================
 *  System Integration Unit Lite (SIUL) section
 */
#define SIU_BASE 0xC3F90000
#define SIU_END  0xC3F94000

#endif

