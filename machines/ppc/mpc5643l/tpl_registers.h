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
#include "Compiler.h"

/*=============================================================================
 * External interrupt bit mask in MSR
 */
#define EE_BIT_1  0x8000    /* Interrupt enabled        */
#define PR_BIT_1  0x4000    /* Processor can only execute user-level inst */
#define FP_BIT_1  0x2000    /* Floating point instructions enabled */
#define RI_BIT_1  0x0002    /* Interrupt is recoverable */

/*=============================================================================
 * SEMA4 registers
 */

#define TPL_GATE_KERNEL 0
#define TPL_GATE_LOCK   1
#define TPL_GATE_SPIN   2

#define TPL_GATE_CPU0_LOCK 0x1
#define TPL_GATE_CPU1_LOCK 0x2
#define TPL_GATE_UNLOCK    0x0

struct _tpl_sema4 {
	uint8 GATE[16];
	uint32 reserved_1[12];
	uint32 CP0INE;
	uint32 reserved_2[1];
	uint32 CP1INE;
	uint32 reserved_3[13];
	uint32 CP0NTF;
	uint32 reserved_4;
	uint32 CP1NTF;
	uint32 reserved_5[29];
	uint32 RSTGT;
	uint32 RSTNTF;
	};

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
extern CONSTP2CONST(struct _tpl_sema4, OS_CONST, OS_CONST) tpl_sem[NUMBER_OF_CORES];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/* Base address of the SEMA4, these are stored in tpl_sem[] array defined in
 * tpl_app_config.c indexed by the core id
 */
#define SEMA4_BASE      0xFFF24000
#define TPL_SEMA40_Base SEMA4_BASE
#define TPL_SEMA41_Base 0x8FF24000

/* Simplify accesses to the structure. i=core_id */
#define TPL_SEMA4(i)           (*(volatile struct _tpl_sema4 *) tpl_sem[i])

/*=============================================================================
 * Interrupts registers
 */

#define INTC_SSCIR_CORE0_SW_ISR    TPL_INTERCORE_IT_CORE0_0
#define INTC_SSCIR_CORE1_SW_ISR    TPL_INTERCORE_IT_CORE1_0
#define INTC_SSCIR_SET       (uint8)(0x1 << 1)
#define INTC_SSCIR_CLR       (uint8)(0x1 << 0)

struct _tpl_intc {
    uint32 BCR;             /* Block Configuration Register             0x00 */
    uint32 reserved_1;      /*                                          0x04 */
    uint32 CPR;             /* Current Priority Register                0x08 */
    uint32 reserved_2;      /*                                          0x0C */
    uint32 IACKR;           /* Interrupt Acknowledge Register           0x10 */
    uint32 reserved_3;      /*                                          0x14 */
    uint32 EOIR;            /* End Of Interrupt Register                0x18 */
    uint32 reserved_4;      /*                                          0x1C */
    uint8  SSCIR[8];        /* Software Set/Clear Interrupt Register    0x20 */
    uint32 reserved_5[6];   /*                                          0x28 */
    uint8  PSR[256];        /* Priority Select Register                 0x40 */
};

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
extern CONSTP2CONST(struct _tpl_intc, OS_CONST, OS_CONST) tpl_intc[NUMBER_OF_CORES];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/* Base address of the INTC, these are stored in tpl_intc[] array defined in
 * tpl_app_config.c indexed by the core id
 */
#define TPL_INTC_Base         0xFFF48000
#define TPL_INTC0_Base        TPL_INTC_Base
#define TPL_INTC1_Base        0x8FF48000

/* Simplify accesses to the structure. i=core_id */
#if WITH_MULTICORE == YES
#  define TPL_INTC(i)           (*(volatile struct _tpl_intc *) tpl_intc[i])
#else
#  define TPL_INTC(i)           (*(volatile struct _tpl_intc *) TPL_INTC_Base)
#endif

/*=============================================================================
 * PIT registers
 */
#define PIT_MCR_FRZ     ((uint32)0x1<<0U)
#define PIT_MCR_MDIS    ((uint32)0x1<<1U)
#define PIT_CR_TEN      ((uint32)0x1<<0U)
#define PIT_CR_TIE      ((uint32)0x1<<1U)
#define PIT_FR_TIF      ((uint32)0x1<<0U)

/* Simplify accesses to the channels registers */
#define PIT_LVR(chan)   TPL_PIT.CHANNEL[chan].LVR
#define PIT_CVR(chan)   TPL_PIT.CHANNEL[chan].CVR
#define PIT_CR(chan)    TPL_PIT.CHANNEL[chan].CR
#define PIT_FR(chan)    TPL_PIT.CHANNEL[chan].FR

struct _tpl_timer_channel {
    uint32 LVR;                 /* Load Value Register                 0x0   */
    uint32 CVR;                 /* Current Value Register              0x4   */
    uint32 CR;                  /* Control Register                    0x8   */
    uint32 FR;                  /* Flag Register                       0xC   */
};

struct _tpl_pit {
    uint32 MCR;                 /* Module Control Register     0x000 - 0x004 */
    uint32 reserved_1[63];      /*                             0x004 - 0x100 */
    struct _tpl_timer_channel CHANNEL[4];   /* Pit Channels    0x100 - 0x140 */
};

#define TPL_PIT (*(volatile struct _tpl_pit *) 0xC3FF0000)

/*=============================================================================
 * SSCM registers
 */
#define SSCM_DPMBOOT_VLE    0x1UL << 1
#define SSCM_DPMKEY_KEY1    (uint16) 0x5AF0
#define SSCM_DPMKEY_KEY2    (uint16) ~SSCM_DPMKEY_KEY1

struct _tpl_sscm {
    uint16 STATUS;          /* System Status                           0x00  */
    uint16 MEMCONFIG;       /* System Memory and ID                    0x02  */
    uint16 reserved_1;      /*                                         0x04  */
    uint16 ERROR;           /* Error Configuration                     0x06  */
    uint16 DEBUGPORT;       /* Debug Status Port                       0x08  */
    uint16 reserved_2;      /*                                         0x0A  */
    uint32 PWCRH;           /* Password Comparison Register High       0x0C  */
    uint32 PWCRL;           /* Password Comparison Register Low        0x10  */
    uint32 reserved_3;      /*                                         0x14  */
    uint32 DPMBOOT;         /* DPM Boot Register                       0x18  */
    uint32 DPMKEY;          /* DPM Boot Key Register                   0x1C  */
    uint32 UOSR;            /* User Option Status Register             0x20  */
    uint32 CR;              /* Control Register                        0x24  */
    };

#define TPL_SSCM (*(volatile struct _tpl_sscm *) 0xC3FD8000UL)


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
#define ME_MCTL_KEY1        (uint16) 0x5AF0
#define ME_MCTL_KEY2        (uint16) ~ME_MCTL_KEY1
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

struct _tpl_me {
    uint32 GS;              /* Global Status                            0x00 */
    uint32 MCTL;            /* Mode Control                             0x04 */
    uint32 ME;              /* Mode Enable                              0x08 */
    uint32 IS;              /* Interrupt Status                         0x0C */
    uint32 IM;              /* Interrupt Mask                           0x10 */
    uint32 IMTS;            /* Invalid Mode Transition Status           0x14 */
    uint32 DMTS;            /* Debug Mode Transition Status             0x18 */
    uint32 reserved_0;      /*                                          0x1C */
    uint32 RESET_MC;        /* Reset Mode Configuration                 0x20 */
    uint32 TEST_MC;         /* Test Mode Configuration                  0x24 */
    uint32 SAFE_MC;         /* Safe Mode Configuration                  0x28 */
    uint32 DRUN_MC;         /* DRUN Mode Configuration                  0x2C */
    uint32 RUN_MC[4];       /* RUN Mode Configuration                   0x30 */
    uint32 HALT0_MC;        /* HALT0 Mode Configuration                 0x40 */
    uint32 reserved_1;      /*                                          0x44 */
    uint32 STOP0_MC;        /* STOP0 Mode Configuration                 0x48 */
    uint32 reserved_2[5];   /*                                          0x4C */
    uint32 PS[3];           /* Peripheral Status                        0x60 */
    uint32 reserved_3[5];   /*                                          0x6C */
    uint32 RUN_PC[8];       /* Run Peripheral Configuration             0x80 */
    uint32 LP_PC[8];        /* Low-Power Peripheral Configuration       0xA0 */
    uint8  PCTL[92];        /* Peripheral Control                       0xC0 */
    };

#define TPL_ME (*(volatile struct _tpl_me *) 0xC3FDC000UL)

/*=============================================================================
 * RGM : Reset Generation Module
 */

struct _tpl_rgm {
    uint16 FES;             /* Functional Event Status                  0x00 */
    uint16 DES;             /* Destructive Event Status                 0x02 */
    uint16 FERD;            /* Functional Event Reset Disable           0x04 */
    uint16 DERD;            /* Destructive Event Reset Disable          0x06 */
    uint16 reserved_0[4];   /*                                          0x08 */
    uint16 FEAR;            /* Functional Event Alternate Request       0x10 */
    uint16 reserved_1[3];   /*                                          0x12 */
    uint16 FESS;            /* Functional Event Short Sequence          0x18 */
    uint16 reserved_2;      /*                                          0x1A */
    uint16 FBRE;            /* Functional Bidirectional Reset Enable    0x1C */
    };

#define TPL_RGM (*(volatile struct _tpl_rgm *) 0xC3FE4000UL)

/*=============================================================================
 * SWT : Software watchdog timer
 */

#define SWT_CR_KEY 0x00000200

struct _tpl_swt {
    uint32 CR;             /*  0x00 */
    uint32 IR;             /*  0x04 */
    uint32 TO;             /*  0x08 */
    uint32 WN;             /*  0x0c */
    uint32 SR;             /*  0x10 */
    uint32 CO;             /*  0x14 */
    uint32 SK;             /*  0x18 */
    };

#define TPL_SWT (*(volatile struct _tpl_swt *) 0xFFF38000UL)

/*=============================================================================
 *  System Integration Unit (SIUL) section
 */
struct __siul__ {
    uint32 reserved_0;
    uint32 MIDR1;         /* MCU ID Register 1 */
    uint32 MIDR2;         /* MCU ID Register 2 */
    uint32 reserved_1[2];
    uint32 ISR;           /* Interrupt Status Register */
    uint32 IRER;          /* Interrupt Request Enable Register */
    uint32 reserved_2[3];
    uint32 IREER;         /* Interrupt Rising-Edge Event Enable Register */
    uint32 IFEER;         /* Interrupt Falling-Edge Event Enable Register */
    uint32 IFER;          /* Interrupt Filter Enable Register */
    uint32 reserved_3[3];
    uint16 PCR[108];      /* Pad Configuration Registers */
    uint32 reserved_4[250];
    uint8  PSMI[36];      /* Pad Selection for Multiplexed Input */
    uint32 reserved_5[55];
    uint8  GPDO[108];     /* GPIO Pin Data Output Registers */
    uint32 reserved_6[101];
    uint8  GPDI[108];     /* GPIO Pin Data Input Registers */
    uint32 reserved_7[229];
    uint32 PGPDO[4];      /* Parallel GPIO Pin Data Output Registers */
    uint32 reserved_8[12];
    uint32 PGPDI[4];      /* Parallel GPIO Pin Data Input Registers */
    uint32 reserved_9[12];
    uint32 MPGPDO[4];     /* Masked Parallel GPIO Pin Data Output */
    uint32 reserved_10[217];
    uint32 IFMC[32];      /* Interrupt Filter Maximum Counter Register */
    uint32 IFCPR;         /* Interrupt Filter Clock Prescaler Register */
    };

#define SIUL (* (volatile struct __siul__*) 0xC3F90000UL)

#endif

