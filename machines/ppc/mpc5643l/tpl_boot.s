/*
 * @file tpl_init_mmu.s
 *
 * @section desc File description
 *
 * Trampoline MPC5643L cores boot
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

#include "tpl_assembler.h"
#include "tpl_registers_asm.h"

TPL_EXTERN(main)
TPL_EXTERN(_sdata)
TPL_EXTERN(_bss_start)
TPL_EXTERN(_bss_end)
TPL_EXTERN(_stack_addr)
TPL_EXTERN(_idesc__)    /* Cosmic Software's linker initialised data descriptor 
                         * address
                         */

TPL_EXTERN(tpl_reset_registers)
TPL_EXTERN(tpl_init_mmu)
TPL_EXTERN(tpl_copy_init_data)
TPL_EXTERN(tpl_clear_bss)
TPL_EXTERN(tpl_init_kernel_stack)
TPL_EXTERN(tpl_init_interrupts)

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif

#define OS_START_SEC_BOOT
#include "tpl_as_memmap.h"

/* ============================================================================
 * Master core boot
 */

TPL_GLOBAL(tpl_master_core_startup)
TPL_GLOBAL_REF(tpl_master_core_startup) :
#if WITH_DEBUG == YES
    /* Set MSR's debug interrupt flag */
    mfmsr   r5
    e_lis   r6, DE_BIT_1
    se_or   r5, r6
    mtmsr   r5
    se_isync
#endif

    /* Initialization of the MMU */
    e_bl      TPL_EXTERN_REF(tpl_init_mmu)

    /* Clear registers */
    e_bl      TPL_EXTERN_REF(tpl_reset_registers)

    /* Set stack pointer */
    e_lis     r1,TPL_HIG(TPL_EXTERN_REF(_stack_addr))
    e_add16i  r1,TPL_LOW(TPL_EXTERN_REF(_stack_addr))

    /* Set data pointer */
    e_lis     r13,TPL_HIG(TPL_EXTERN_REF(_sdata))
    e_add16i  r13,TPL_LOW(TPL_EXTERN_REF(_sdata))

    /* Clear Ram call */
    e_lis     r3,TPL_HIG(TPL_EXTERN_REF(_bss_start))
    e_add16i  r3,TPL_LOW(TPL_EXTERN_REF(_bss_start))
    e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_bss_end))
    e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_bss_end))
    e_bl      TPL_EXTERN_REF(tpl_clear_bss)

    /* Copy initialized datas call */
    e_lis     r3,TPL_HIG(TPL_EXTERN_REF(_idesc__))
    e_add16i  r3,TPL_LOW(TPL_EXTERN_REF(_idesc__))
    e_bl      TPL_EXTERN_REF(tpl_copy_init_data)

   /**
    * [SWS_Os_00625] : Some syscalls may be called before StartOS (at least
    *                  GetCoreID and StartCore). However, we need to initialize
    *                  the kernel stack and the ivor vector before being able
    *                  to handle a system call
    */
    e_bl      TPL_EXTERN_REF(tpl_init_kernel_stack)
    e_bl      TPL_EXTERN_REF(tpl_init_interrupts)

    /* Go to main */
    e_bl      TPL_EXTERN_REF(main)           ; execute main

tpl_master_core_startup_loop:
    se_b      tpl_master_core_startup_loop


#if NUMBER_OF_CORES > 1
TPL_EXTERN(_stack_addr_p1)

/* =============================================================================
 *  Slave core boot
 */
ALIGN(4) /* Must be aligned to at least 4bytes */
TPL_GLOBAL(tpl_slave_core_startup)
TPL_GLOBAL_REF(tpl_slave_core_startup):
#if WITH_DEBUG == YES
    /* Set MSR's debug interrupt flag */
    mfmsr   r5
    e_lis   r6, DE_BIT_1
    se_or   r5, r6
    mtmsr   r5
    se_isync
#endif

    /* Initialization of the MMU */
    e_bl      TPL_EXTERN_REF(tpl_init_mmu)

    /* Clear registers */
    e_bl      TPL_EXTERN_REF(tpl_reset_registers)

    /* Set stack pointer */
    e_lis     r1,TPL_HIG(TPL_EXTERN_REF(_stack_addr_p1))
    e_add16i  r1,TPL_LOW(TPL_EXTERN_REF(_stack_addr_p1))

    /* Set data pointer */
    e_lis     r13,TPL_HIG(TPL_EXTERN_REF(_sdata))
    e_add16i  r13,TPL_LOW(TPL_EXTERN_REF(_sdata))

   /**
    * [SWS_Os_00606] : Some syscalls may be called before StartOS (at least
    *                  GetCoreID and StartCore). However, we need to initialize
    *                  the kernel stack and the ivor vector before being able
    *                  to handle a system call
    */
    e_bl      TPL_EXTERN_REF(tpl_init_kernel_stack)
    e_bl      TPL_EXTERN_REF(tpl_init_interrupts)

    /* Go to main */
    e_bl      TPL_EXTERN_REF(main)           ; execute main

tpl_slave_core_startup_loop:
  se_b      tpl_slave_core_startup_loop
#endif

/* =============================================================================
 *  Utils
 */

TPL_GLOBAL(tpl_init_mmu)
TPL_GLOBAL_REF(tpl_init_mmu):

  /*
   * MMU Entry First 1MB FLASH    //# MAS0 : ESEL=1
   * MAS1 : TSIZ=1MB
   * MAS2 : EPN=0x000000000, W=0, I=0, M=0, G=0, E=big
   * MAS3 : RPN=0x000000000, PERMIS=all
   */

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

  /*
   * MMU Entry Shadow Flash
   * MAS0 : ESEL=1
   * MAS1 : TSIZE=1MB
   * MAS2 : EPN=0x00F00000, I=1, guarded
   * MAS3 : RPN=0x00F00000, readonly
   */
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


  /* Init MMU for DPM */

  /*
   * MMU Entry First 64K SRAM in DPM - No Translation
   * MAS0 : ESEL=2
   * MAS1 : TSIZ=64Kbytes
   * MAS2 : EPN=0x400000000, W=0, I=1, M=0, G=0, E=big
   * MAS3 : RPN=0x400000000, PERMIS=all
   */
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

  /*
   * MMU Entry Second 64K SRAM in DPM Mode
   * MAS0 : ESEL=3
   * MAS1 : TSIZ=64Kbytes
   * MAS2 : EPN=0x50000000, W=0, I=0, M=0, G=0, E=big
   * MAS3 : RPN=0x50000000, PERMIS=all
   */
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

  /*
   * Peripheral Space in DPM mode things start at 0x8ff0_0000
   * will start at 0x8ff0_0000 and extend 1M
   * MAS0 : ESEL=4
   * MAS1 : TSIZ=1MB
   * MAS2 : EPN=0x8ff00000, W=0, I=1, M=0, G=1, E=big
   * MAS3 : RPN=0x8ff00000, PERMIS=all
   */
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


  /*
   * common to both LSM and DPM
   * MMU Entry Peripheral A
   * MAS0 : ESEL=5
   * MAS1 : TSIZ=1Mbytes
   * MAS2 : EPN=0xC3F00000, W=0, I=1, M=0, G=1, E=big
   * MAS3 : RPN=0xC3F00000, PERMIS=all
   */
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

  /*
   * MMU Entry Peripheral B
   * MAS0 : ESEL=6
   * MAS1 : TSIZ=1Mbytes
   * MAS2 : EPN=0xFFE00000, W=0, I=1, M=0, G=0, E=big
   * MAS3 : RPN=0xFFE00000, PERMIS=all
   */
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

  /*
   * MMU On-Platform 0 Peripherals
   * MAS0 : ESEL=7
   * MAS1 : TSIZ=512 Kbytes
   * MAS2 : EPN=0xFFF00000, W=0, I=1, M=0, G=0, E=big
   * MAS3 : RPN=0xFFF00000, PERMIS=all
   */
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

  /*
   * MMU  Off-Platform Peripherals 2
   * MAS0 : ESEL=8
   * MAS1 : TSIZ=64 Kbytes
   * MAS2 : EPN=0xFFF90000, W=0, I=1, M=0, G=0, E=big
   * MAS3 : RPN=0xFFF90000, PERMIS=all
   */
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

  /*
   * MMU  Off-Platform Peripherals 2
   * MAS0 : ESEL=8
   * MAS1 : TSIZ=256 Kbytes
   * MAS2 : EPN=0xFFFC0000, W=0, I=1, M=0, G=0, E=big
   * MAS3 : RPN=0xFFFC0000, PERMIS=all
   */
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


; The following MPC5643L e200z4 core registers require software initialization
; General Registers — CR, CTR, LR, GPR0-GPR31, ACC
; Debug Registers — DBCNT, DVC1-DVC2
; Exception Handling — SPRG0-SPRG7, SPRG8-SPRG9, USPRG0, SRR0-SRR1, CSRR0-CSRR1,
; DSRR0-DSRR1, MCSRR0-MCSRR1, IVPR, IVOR0-IVOR15, IVOR32-IVOR34, MCAR, DEAR
; Timers — DEC, DECAR, TBL, TBU
; Memory Management Registers — MAS0-MAS4, MAS6

TPL_GLOBAL(tpl_reset_registers)
TPL_GLOBAL_REF(tpl_reset_registers):
    /* General Registers */
    se_andi r0,0
    se_andi r1,0
    se_andi r2,0
    se_andi r3,0
    se_andi r4,0
    se_andi r5,0
    se_andi r6,0
    se_andi r7,0
    e_and2i r8,0
    e_and2i r9,0
    e_and2i r10,0
    e_and2i r11,0
    e_and2i r12,0
    e_and2i r13,0
    e_and2i r14,0
    e_and2i r15,0
    e_and2i r16,0
    e_and2i r17,0
    e_and2i r18,0
    e_and2i r19,0
    e_and2i r20,0
    e_and2i r21,0
    e_and2i r22,0
    e_and2i r23,0
    e_and2i r24,0
    e_and2i r25,0
    e_and2i r26,0
    e_and2i r27,0
    e_and2i r28,0
    e_and2i r29,0
    e_and2i r30,0
    e_and2i r31,0

    mtspr spr_CTR,r31
    mtspr spr_XER,r31

    /* Debug Registers */
    mtspr spr_DBCNT,r31
    mtspr spr_DVC1,r31
    mtspr spr_DVC2,r31

    /* Exception Handling */
    mtspr spr_SPRG0,r31
    mtspr spr_SPRG1,r31
    mtspr spr_SPRG2,r31
    mtspr spr_SPRG3,r31
    mtspr spr_SPRG4,r31
    mtspr spr_SPRG5,r31
    mtspr spr_SPRG6,r31
    mtspr spr_SPRG7,r31
    mtspr spr_SPRG8,r31
    mtspr spr_SPRG9,r31
    mtspr spr_USPRG0,r31
    mtspr spr_SRR0,r31
    mtspr spr_SRR1,r31
    mtspr spr_CSRR0,r31
    mtspr spr_CSRR1,r31
    mtspr spr_DSRR0,r31
    mtspr spr_DSRR1,r31
    mtspr spr_MCSRR0,r31
    mtspr spr_MCSRR1,r31
    mtspr spr_IVPR,r31
    mtspr spr_IVOR0,r31
    mtspr spr_IVOR1,r31
    mtspr spr_IVOR2,r31
    mtspr spr_IVOR3,r31
    mtspr spr_IVOR4,r31
    mtspr spr_IVOR5,r31
    mtspr spr_IVOR6,r31
    mtspr spr_IVOR7,r31
    mtspr spr_IVOR8,r31
    mtspr spr_IVOR9,r31
    mtspr spr_IVOR10,r31
    mtspr spr_IVOR11,r31
    mtspr spr_IVOR12,r31
    mtspr spr_IVOR13,r31
    mtspr spr_IVOR14,r31
    mtspr spr_IVOR15,r31
    mtspr spr_IVOR32,r31
    mtspr spr_IVOR33,r31
    mtspr spr_IVOR34,r31
    mtspr spr_MCAR,r31
    mtspr spr_DEAR,r31

    /* Timers */
    mtspr spr_DEC,r31
    mtspr spr_DECAR,r31
    mtspr spr_TBL,r31
    mtspr spr_TBU,r31
    mtspr spr_TSR,r31
    mtspr spr_TCR,r31

    /* Memory Management Registers */
    mtspr spr_MAS0,r31
    mtspr spr_MAS1,r31
    mtspr spr_MAS2,r31
    mtspr spr_MAS3,r31
    mtspr spr_MAS4,r31
    mtspr spr_MAS6,r31

    se_blr

#define OS_STOP_SEC_BOOT
#include "tpl_as_memmap.h"


