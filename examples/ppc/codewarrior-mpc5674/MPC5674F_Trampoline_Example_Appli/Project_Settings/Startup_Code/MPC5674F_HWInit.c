/*
 * FILE : MPC567xF_HWInit.c
 *    
 * COPYRIGHT (c) 2007-2012 Freescale Semiconductor, Inc. All rights reserved.
 *     
 * DESCRIPTION: This file contains the MPC567xF derivative basic initializations,
 *  and EVB initializations. This includes setting up the MMU, SRAM, WatchDog,
 *  External Bus Interface to allow access to memory on the external bus.
 *
 *  For more on Qorivva MCUs module initializations please consult the Qorivva cookbook AN2865.  
 *  
 * VERSION: 1.2
 */

/*--------------------------------------------------------------*/
/* Includes                                                     */
/*--------------------------------------------------------------*/

#include "MPC5674F.h"       /*platform development header*/
#include "MPC5674F_HWInit.h"

#ifdef __cplusplus
extern "C" {
#endif

    
#ifndef INIT_USED_BOARD
#pragma error INIT_USED_BOARD should be defined !
#endif
    
/* This macro allows to use C defined address with the inline assembler */
#define MAKE_HLI_COMPATIBLE(hli_name, c_expr) enum { hli_name=/*lint -e30*/((int)(c_expr)) };

/*------------------------------------------------------------------*/
/* Symbol L2SRAM_LOCATION is defined in the application linker      */
/* command file (.lcf). Its value should reflect SRAM start address.*/ 
/*------------------------------------------------------------------*/
/*lint -esym(752, L2SRAM_LOCATION) */
extern unsigned long L2SRAM_LOCATION;

/*------------------------------------------------------------------*/
/* Symbol L2SRAM_CNT is defined in the application linker command   */
/* file (.lcf). It represents the how many writes with stmw         */
/* (128 bytes each) are needed to cover the whole L2SRAM.           */
/*------------------------------------------------------------------*/
extern unsigned long L2SRAM_CNT;

/* All these functions must be located in the initial 4KB memory window (.init) 
   and implemented "nofralloc" so as to not use the stack 
*/

/*-------------------------------------------------------------------*/
/* Symbol EXTERNAL_RAM is defined in the application linker          */
/* command file (.lcf). It should be set to the start of the external*/
/* memory on the EVB board.                                          */
/*-------------------------------------------------------------------*/
#if (INIT_USED_BOARD != NO_EXTERNAL_MEMORY)
extern long START_EXTERNAL_RAM[];
#define START_EXTERNAL_RAM_START 0x20000000
#endif

/* Memory initialization */
__declspec(section ".init") void INIT_Derivative(void);

/*------------------------------------------------------*/
/* Initialize the needed MMU Table entries.             */
/*------------------------------------------------------*/
__declspec(section ".init") __asm void __initMMU(void);

/* Write one MMU Table Entry */
__declspec(section ".init") __asm void WriteMMUTableEntry( void );

/* Write one MMU Table Entry with context synchronization */
__declspec(section ".init") __asm void WriteMMUTableEntryS( void );

/*------------------------------------------------------------------*/
/* Initialization of external bus to access external memory         */
/*------------------------------------------------------------------*/
/* Initializes the MMU in order to access the external memory. */
__declspec(section ".init") __asm void __initMMUExternalMemory(void);

/* Initialize a set of contiguous PCRs */
__declspec(section ".init") __asm void InitPCRs(void);

/* Initialize thes SIU External Bus Interface */
__declspec(section ".init") __asm void __initSIUExtBusInterface(void);

/* Initialize the used EBI Chip Selects */
__declspec(section ".init") __asm void __initEBIChipSelects(void);

MAKE_HLI_COMPATIBLE(SR_WSC_1, 0xc520) /*50464*/
MAKE_HLI_COMPATIBLE(SR_WSC_2, 0xd928) /*55592*/
MAKE_HLI_COMPATIBLE(MCR_VALUE, 0x8000010A)
MAKE_HLI_COMPATIBLE(SWT_SR, &SWT.SR.R) /* Address of the SWT SR */
MAKE_HLI_COMPATIBLE(SWT_MCR, &SWT.MCR.R) /* Address of the SWT MCR */
/*------------------------------------------------------------------*/
/* FUNCTION     : INIT_Derivative                                   */
/* PURPOSE      : This function initializes the derivative.         */
/* SEQUENCE:                                                        */
/* - initializes the MMU                                            */
/* - disables system WDT and Core WDT                               */
/* - initializes the internal SRAM for ROM targets                  */
/*------------------------------------------------------------------*/
__asm void INIT_Derivative(void) 
{
nofralloc

    /* Don't have a stack yet, save the return address in a register */
    mflr     r26;
    bl __initMMU;
    mtlr r26;

    /* Clear the soft lock bit SWT_CR.SLKSWT_CR: */
    /* SR --> 0x0000c520 */
    lis r4, 0
    ori r4, r4, SR_WSC_1@l
    lis r3, SWT_SR@ha
    stw r4, SWT_SR@l(r3)
    /* SR --> 0x0000d928 */
    lis r4, 0
    ori r4, r4, SR_WSC_2@l
    stw r4, SWT_SR@l(r3)

    /* Disable watchdog, SWT.CR.WEN = 0*/
    lis r4, MCR_VALUE@h
    ori r4, r4, MCR_VALUE@l
    lis r3, SWT_MCR@ha
    stw r4, SWT_MCR@l(r3)

#if defined(ROM_VERSION) && (ROM_VERSION == 1)
    /* enable SPE if the compiler isn't called with -spe_vector */

    /* SRAM initialization code*/
    lis r11,L2SRAM_LOCATION@h
    ori r11,r11,L2SRAM_LOCATION@l

    /* Loops to cover L2SRAM, stmw allows 128 bytes (32 GPRS x 4 bytes) writes */
    lis r12,L2SRAM_CNT@h
    ori r12,r12,L2SRAM_CNT@l
    mtctr r12

    init_l2sram_loop:
        stmw r0, 0(r11)        /* Write 32 GPRs to SRAM*/
        addi r11,r11,128       /* Inc the ram ptr; 32 GPRs * 4 bytes = 128B */
        bdnz init_l2sram_loop  /* Loop for L2SRAM_CNT times */
#endif
    blr
}

/*----------------------------------------------------------------------*/
/* FUNCTION:WriteMMUTableEntryS                                         */
/* PURPOSE: Creates a new TLB entry with synchronization.It ensures that*/
/*          the TLB context change doesn't affect the core by execution */
/*          before and after tlbwe a CSI. This should be called when    */
/*          creating SRAM or FLASH TLB entries.                         */
/* SEQUENCE: write GPR to MAS, execute CSI, tlbwe, CSI                  */
/*----------------------------------------------------------------------*/
__asm void WriteMMUTableEntryS( void )
{ 
nofralloc
    /* Write MMU Assist Register 0 (MAS0); SPR 624 */
    mtspr   624, r3
    /* Write MMU Assist Register 1 (MAS1); SPR 625 */
    mtspr   625, r4
    /* Write MMU Assist Register 2 (MAS2); SPR 626 */
    mtspr   626, r5
    /* Write MMU Assist Register 3 (MAS3); SPR 627 */
    mtspr   627, r6
    /* Write the table entry */

    /* All instruction will complete here in current context. */
    msync
    tlbwe
    /* synchronize instruction fetches and data accesses in respect
     with the new created TLB entry. */
    msync
    isync
    blr
}

/*--------------------------------------------------*/
/* FUNCTION:WriteMMUTableEntry                      */
/* PURPOSE: Creates a new TLB entry with            */
/* SEQUENCE: write GPR to MAS, execute tlbwe        */
/*--------------------------------------------------*/
__asm void WriteMMUTableEntry( void )
{ 
nofralloc
    /* Write MMU Assist Register 0 (MAS0); SPR 624 */
    mtspr   624, r3
    /* Write MMU Assist Register 1 (MAS1); SPR 625 */
    mtspr   625, r4
    /* Write MMU Assist Register 2 (MAS2); SPR 626 */
    mtspr   626, r5
    /* Write MMU Assist Register 3 (MAS3); SPR 627 */
    mtspr   627, r6
    /* Write the table entry */
    tlbwe
    blr
}

/*
   Device MMU table:
   ---------------------------------------------------------
   Name:            TLB entry  Start            Length
   ---------------------------------------------------------
   FLASH            0         0x0000_0000       4MB
   SRAM             1         0x4000_0000       256KB
   SHADOW           2         0x00FF_C000       16KB
   EBI              3         0x2000_0000       512KB
   PBRIDGEA         4         0xC3F0_0000       1MB
   PBRIDGEB + BAM   5         0xFFE0_0000       2MB
   ---------------------------------------------------------
 */

/* Run MMU init:TLB 15, 0x0000_0000, 4GB, TS=1, not guarded, big endian, cache inhibited, all access, VLE/BOOKE */
MAKE_HLI_COMPATIBLE(TLB_Entry_15_MAS0, MAS0_VALUE(15))
MAKE_HLI_COMPATIBLE(TLB_Entry_15_MAS1, MAS1_VALUE(V_VALID, IPROT_NOTPROTECTED, TID_GLOBAL, TS_ON, TSIZE_4GB))
MAKE_HLI_COMPATIBLE(TLB_Entry_15_MAS1_INVALID, MAS1_VALUE(V_INVALID, IPROT_NOTPROTECTED, TID_GLOBAL, TS_ON, TSIZE_4GB))
#if __option(vle)
MAKE_HLI_COMPATIBLE(TLB_Entry_15_MAS2, MAS2_VALUE(0, VLE_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN))
#else
MAKE_HLI_COMPATIBLE(TLB_Entry_15_MAS2, MAS2_VALUE(0, BOOK_E_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN))
#endif
MAKE_HLI_COMPATIBLE(TLB_Entry_15_MAS3, MAS3_VALUE(0, READ_WRITE_EXECUTE))

/* FLASH: TLB 0, 0x0000_0000, 4MB, not guarded, protected, cachable, all access */
MAKE_HLI_COMPATIBLE(TLB_Entry_0_MAS0, MAS0_VALUE(0))
MAKE_HLI_COMPATIBLE(TLB_Entry_0_MAS1, MAS1_VALUE(V_VALID, IPROT_PROTECTED, TID_GLOBAL, TS_OFF, TSIZE_4MB))
#if __option(vle)
MAKE_HLI_COMPATIBLE(TLB_Entry_0_MAS2, MAS2_VALUE(0x0, VLE_MODE, WRITE_BACK, CACHEABLE, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN))
#else
MAKE_HLI_COMPATIBLE(TLB_Entry_0_MAS2, MAS2_VALUE(0x0, BOOK_E_MODE, WRITE_BACK, CACHEABLE, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN))
#endif
MAKE_HLI_COMPATIBLE(TLB_Entry_0_MAS3, MAS3_VALUE(0x0, READ_WRITE_EXECUTE))

/* SRAM: TLB 1, 0x4000_0000, 256KB, not protected, not guarded, cache off, big-endian, all access */
MAKE_HLI_COMPATIBLE(TLB_Entry_1_MAS0, MAS0_VALUE(1))
MAKE_HLI_COMPATIBLE(TLB_Entry_1_MAS1, MAS1_VALUE(V_VALID, IPROT_NOTPROTECTED, TID_GLOBAL, TS_OFF, TSIZE_256KB))
#if __option(vle)
MAKE_HLI_COMPATIBLE(TLB_Entry_1_MAS2, MAS2_VALUE(0x40000000, VLE_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN))
#else
MAKE_HLI_COMPATIBLE(TLB_Entry_1_MAS2, MAS2_VALUE(0x40000000, BOOK_E_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN))
#endif
MAKE_HLI_COMPATIBLE(TLB_Entry_1_MAS3, MAS3_VALUE(0x40000000, READ_WRITE_EXECUTE))

/* SHADOW FLASH: TLB 2, 0x00FF_C000, 16KB, not guarded, protected, cachable, all access */
MAKE_HLI_COMPATIBLE(TLB_Entry_2_MAS0, MAS0_VALUE(2))
MAKE_HLI_COMPATIBLE(TLB_Entry_2_MAS1, MAS1_VALUE(V_VALID, IPROT_PROTECTED, TID_GLOBAL, TS_OFF, TSIZE_16KB))
MAKE_HLI_COMPATIBLE(TLB_Entry_2_MAS2, MAS2_VALUE(0x00FFC000, BOOK_E_MODE, WRITE_BACK, CACHEABLE, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN))
MAKE_HLI_COMPATIBLE(TLB_Entry_2_MAS3, MAS3_VALUE(0x00FFC000, READ_WRITE))

#if (INIT_USED_BOARD != NO_EXTERNAL_MEMORY)
/* EBI: TLB 3, 0x2000_0000, 512KB, not protected, not guarded, cache off, big-endian, all access */
MAKE_HLI_COMPATIBLE(TLB_Entry_3_MAS0, MAS0_VALUE(3))
MAKE_HLI_COMPATIBLE(TLB_Entry_3_MAS1, MAS1_VALUE(V_VALID, IPROT_NOTPROTECTED, TID_GLOBAL, TS_OFF, TSIZE_512KB))
#if __option(vle) 
MAKE_HLI_COMPATIBLE(TLB_Entry_3_MAS2, MAS2_VALUE(START_EXTERNAL_RAM_START, VLE_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN))
#else
MAKE_HLI_COMPATIBLE(TLB_Entry_3_MAS2, MAS2_VALUE(START_EXTERNAL_RAM_START, BOOK_E_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN))
#endif
MAKE_HLI_COMPATIBLE(TLB_Entry_3_MAS3, MAS3_VALUE(START_EXTERNAL_RAM_START, READ_WRITE_EXECUTE))
#endif

/* PBRIDGEA: TLB 4, 0xC3F0_0000, 1MB, not protected, not guarded, cache off, big-endian, all access */
MAKE_HLI_COMPATIBLE(TLB_Entry_4_MAS0, MAS0_VALUE(4))
MAKE_HLI_COMPATIBLE(TLB_Entry_4_MAS1, MAS1_VALUE(V_VALID, IPROT_NOTPROTECTED, TID_GLOBAL, TS_OFF, TSIZE_1MB))
MAKE_HLI_COMPATIBLE(TLB_Entry_4_MAS2, MAS2_VALUE(0xC3F00000, BOOK_E_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN))
MAKE_HLI_COMPATIBLE(TLB_Entry_4_MAS3, MAS3_VALUE(0xC3F00000, READ_WRITE))

/* PBRIDGEB + BAM: TLB 5, 0xFFE0_0000, 2MB, not protected, guarded, cache off, big-endian, all access, VLE */
MAKE_HLI_COMPATIBLE(TLB_Entry_5_MAS0, MAS0_VALUE(5))
MAKE_HLI_COMPATIBLE(TLB_Entry_5_MAS1, MAS1_VALUE(V_VALID, IPROT_NOTPROTECTED, TID_GLOBAL, TS_OFF, TSIZE_2MB))
MAKE_HLI_COMPATIBLE(TLB_Entry_5_MAS2, MAS2_VALUE(0xFFE00000, VLE_MODE, WRITE_BACK, CACHE_INHIBIT, MEM_COHERENCE_NREQ, GUARDED, BIG_ENDIAN))
MAKE_HLI_COMPATIBLE(TLB_Entry_5_MAS3, MAS3_VALUE(0xFFE00000, READ_WRITE_EXECUTE))

__asm void __initMMU(void)
{
nofralloc
    /* Use a translation address space page in order to run the MMU initialization
        regardless of the current executing env. and MMU setup. */
    lis r3, TLB_Entry_15_MAS0@h
    ori r3, r3, TLB_Entry_15_MAS0@l
    mtspr 624, r3
    lis r4, TLB_Entry_15_MAS1@h
    ori r4, r4, TLB_Entry_15_MAS1@l
    mtspr 625, r4
    xor r5, r5, r5
    mr r6, r5
    ori r5, r5, TLB_Entry_15_MAS2@l
    ori r6, r6, TLB_Entry_15_MAS3@l
    mtspr 626, r5
    mtspr 627, r6
    tlbwe

    /* force this TLB entry to be used for translation */
    mfmsr r10
    /* save state */
    mr r3, r10
    /* set IS=1, DS=1 */
    ori r3, r3, 0x20

    msync
    /* mtmsr does execution synchronization.*/
    mtmsr r3
    /* Required after changing MSR.IS, and MSR.DS so the prefetched instructions
       will be discarded and all subsequent instructions will use the TLB 15 context.*/
    isync
    msync

     /* FLASH,TLB0,0x0000_0000,4MB */
     lis r3, TLB_Entry_0_MAS0@h
     ori r3, r3, TLB_Entry_0_MAS0@l
     lis r4, TLB_Entry_0_MAS1@h
     ori r4, r4, TLB_Entry_0_MAS1@l
     lis r5, TLB_Entry_0_MAS2@h
     ori r5, r5, TLB_Entry_0_MAS2@l
     lis r6, TLB_Entry_0_MAS3@h
     ori r6, r6, TLB_Entry_0_MAS3@l
     /* Synchronize in case running from FLASH */
     mflr r28
     bl WriteMMUTableEntryS
     mtlr r28

     /* SRAM,TLB1,0x4000_0000,256KB */
     lis r3, TLB_Entry_1_MAS0@h
     ori r3, r3, TLB_Entry_1_MAS0@l
     lis r4, TLB_Entry_1_MAS1@h
     ori r4, r4, TLB_Entry_1_MAS1@l
     lis r5, TLB_Entry_1_MAS2@h
     ori r5, r5, TLB_Entry_1_MAS2@l
     lis r6, TLB_Entry_1_MAS3@h
     ori r6, r6, TLB_Entry_1_MAS3@l
     /* Synchronize in case running from SRAM */
     mflr r28
     bl WriteMMUTableEntryS
     mtlr r28

     /* SHADOW,TLB2,0x00FF_C000,16KB */
     lis r3, TLB_Entry_2_MAS0@h
     ori r3, r3, TLB_Entry_2_MAS0@l
     lis r4, TLB_Entry_2_MAS1@h
     ori r4, r4, TLB_Entry_2_MAS1@l
     lis r5, TLB_Entry_2_MAS2@h
     ori r5, r5, TLB_Entry_2_MAS2@l
     lis r6, TLB_Entry_2_MAS3@h
     ori r6, r6, TLB_Entry_2_MAS3@l
     mflr r28
     bl WriteMMUTableEntry
     mtlr r28

     /* PBRIDGEA,TLB4,0xC3F0_0000,1MB */
     lis r3, TLB_Entry_4_MAS0@h
     ori r3, r3, TLB_Entry_4_MAS0@l
     lis r4, TLB_Entry_4_MAS1@h
     ori r4, r4, TLB_Entry_4_MAS1@l
     lis r5, TLB_Entry_4_MAS2@h
     ori r5, r5, TLB_Entry_4_MAS2@l
     lis r6, TLB_Entry_4_MAS3@h
     ori r6, r6, TLB_Entry_4_MAS3@l
     mflr r28
     bl WriteMMUTableEntry
     mtlr r28

     /* PBRIDGEB + BAM,TLB5,0xFFE0_0000,2MB */
     lis r3, TLB_Entry_5_MAS0@h
     ori r3, r3, TLB_Entry_5_MAS0@l
     lis r4, TLB_Entry_5_MAS1@h
     ori r4, r4, TLB_Entry_5_MAS1@l
     lis r5, TLB_Entry_5_MAS2@h
     ori r5, r5, TLB_Entry_5_MAS2@l
     lis r6, TLB_Entry_5_MAS3@h
     ori r6, r6, TLB_Entry_5_MAS3@l
     mflr r28
     bl WriteMMUTableEntry
     mtlr r28

     /* restore msr */
     mtmsr r10
     /* dicard instruction & data prefetch */
     msync

     /* invalidated initialization TLB entry 15 */
     lis r3, TLB_Entry_15_MAS0@h
     ori r3, r3, TLB_Entry_15_MAS0@l
     lis r4, TLB_Entry_15_MAS1_INVALID@h
     ori r4, r4, TLB_Entry_15_MAS1_INVALID@l
     mtspr 624, r3
     mtspr 625, r4
     tlbwe
     /* make sure isntructions and data are fetched from the new context. */
     isync
     msync

     blr
}

/*----------------------------------------------------------------------------*/
/* SIU External Bus Interface                                                 */
/*----------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* FUNCTION     : INIT_ExternalBusAndMemory                                 */
/* PURPOSE      : This function configures EBI for the external memory      */
/* SEQUENCE:                                                                */
/*  - init external bus interface                                           */
/*  - init EBI chip selects                                                 */
/*  - init a TLB entry for the external memory bus                          */
/*--------------------------------------------------------------------------*/
__asm void INIT_ExternalBusAndMemory(void) 
{
nofralloc

    /* Initialize the SIU External Bus Interface */
    mflr r28
    bl __initSIUExtBusInterface
    mtlr r28

    /* Initialize the used EBI Chip Selects */
    mflr r28
    bl __initEBIChipSelects
    mtlr r28

    /* Initialize the needed MMU Table entry */
    mflr r28
    bl __initMMUExternalMemory
    mtlr r28

    blr
}

/*------------------------------------------------------------------*/
/* FUNCTION     : InitPCRs                                          */
/* PURPOSE      : Initialize a set of contiguous PCRs:              */
/*                  r3: the first PCR to initialize                 */
/*                  r4: the value to write in the PCRs              */ 
/*                  r5: the number of PCRs to initialize            */
/*------------------------------------------------------------------*/
__asm void InitPCRs(void) 
{
nofralloc

    mtctr r5                   /* initialize ctr with the number of PCRs to initialize */
    pcr_init_loop:
        sth r4,0(r3)           /* Write r4 to current PCR address */
        addi r3,r3, 2          /* Inc the memory ptr by 2 to point to the next PCR */
        bdnz pcr_init_loop     /* Loop for ctr PCRs */

    blr
}


/* PCR_FLAGS(pa, obe, ibe, dsc, ode, hys, src, wpe, wps) */
#if INIT_USED_BOARD==ADAT516_AXM_0472
/*------------------------------------------------------------*/
/* The following pin assignments work only for AXM-0472 REV C.*/
/* Note the RM revision 3/2010 starts counting PCR from 75    */
/*------------------------------------------------------------*/

/* Default jumper set is chip select 0 */
/* PCR no. 256, offset 0x240, D_CS0 181*/
MAKE_HLI_COMPATIBLE(SIU_PCR_256,&SIU.PCR[256].R)
MAKE_HLI_COMPATIBLE(SIU_PCR_256_VAL,PCR_FLAGS(PA_Primary,OBE_DISABLE,IBE_DISABLE,DSC_20PF,ODE_DISABLE,HYS_DISABLE,SRC_MIN,WPE_ENABLE,WPS_ENABLE))

/* Data and address PCRs */

/* Note AXM-0472 REV C. multiplexes the address with data lines */
/* PCR no. 257, offset 0x242, alternate function D_ADD_DAT31 182*/
MAKE_HLI_COMPATIBLE(SIU_PCR_257,&SIU.PCR[257].R)
MAKE_HLI_COMPATIBLE(SIU_PCR_257_VAL, PCR_FLAGS(PA_Alt1,OBE_DISABLE,IBE_DISABLE,DSC_20PF,ODE_DISABLE,HYS_DISABLE,SRC_MIN,WPE_DISABLE,WPS_DISABLE))

/* PCR no. 263 - 277, offset 0x24E, alternate function D_ADD_DAT16 - 30 188*/
MAKE_HLI_COMPATIBLE(SIU_PCR_263_277,&SIU.PCR[263].R)
MAKE_HLI_COMPATIBLE(SIU_PCR_263_277_VAL, PCR_FLAGS(PA_Alt1,OBE_DISABLE,IBE_DISABLE,DSC_20PF,ODE_DISABLE,HYS_DISABLE,SRC_MIN,WPE_DISABLE,WPS_DISABLE))

/* PCR no. 278 - 293, offset 0x26C, primary function D_ADD_DAT0 - 15 203*/
MAKE_HLI_COMPATIBLE(SIU_PCR_278_293,&SIU.PCR[278].R)
MAKE_HLI_COMPATIBLE(SIU_PCR_278_293_VAL, PCR_FLAGS(PA_Primary,OBE_DISABLE,IBE_DISABLE,DSC_20PF,ODE_DISABLE,HYS_DISABLE,SRC_MIN,WPE_DISABLE,WPS_DISABLE))

/* Control PCRs */
/* PCR no. 294 - 305, offset 0x28C, primary functions D_RD_WR, D_WE0, D_WE1, D_OE, D_TS, D_ALE,D_TA, D_CS1, D_BDIP, D_WE2, D_WE3, D_ADD9 219*/
MAKE_HLI_COMPATIBLE(SIU_PCR_294_305,&SIU.PCR[294].R)
MAKE_HLI_COMPATIBLE(SIU_PCR_294_305_VAL, PCR_FLAGS(PA_Primary,OBE_DISABLE,IBE_DISABLE,DSC_20PF,ODE_DISABLE,HYS_DISABLE,SRC_MIN,WPE_ENABLE,WPS_ENABLE))
#endif 

/*------------------------------------------------------------------*/
/* FUNCTION     : __initSIUExtBusInterface                          */
/* PURPOSE      : Initialize the SIU EBI for the selected board.    */
/*------------------------------------------------------------------*/
__asm void __initSIUExtBusInterface(void)
{
nofralloc

#if INIT_USED_BOARD==ADAT516_AXM_0472    
    /* Configure address and data bus pins.*/

    /* PCR no. 257, offset 0x242, alternate function D_ADD_DAT31 */
    lis r3,SIU_PCR_257@h
    ori r3,r3,SIU_PCR_257@l
    lis r4,SIU_PCR_257_VAL@h
    ori r4,r4,SIU_PCR_257_VAL@l
    li r5,1

    mflr r29
    bl InitPCRs
    mtlr r29

    /* PCR no. 263 - 277, offset 0x24E, alternate function D_ADD_DAT16 - 30 */
    lis r3,SIU_PCR_263_277@h
    ori r3,r3,SIU_PCR_263_277@l
    lis r4,SIU_PCR_263_277_VAL@h
    ori r4,r4,SIU_PCR_263_277_VAL@l
    li r5,15

    mflr r29
    bl InitPCRs
    mtlr r29

    /* PCR no. 278 - 293, offset 0x26C, primary function D_ADD_DAT0 - 15 */
    lis r3,SIU_PCR_278_293@h
    ori r3,r3,SIU_PCR_278_293@l
    lis r4,SIU_PCR_278_293_VAL@h
    ori r4,r4,SIU_PCR_278_293_VAL@l
    li r5,16

    mflr r29
    bl InitPCRs
    mtlr r29

    /* Configure control lines */
    /* PCR no. 256, offset 0x240, D_CS0 */
    lis r3,SIU_PCR_256@h
    ori r3,r3,SIU_PCR_256@l
    lis r4,SIU_PCR_256_VAL@h
    ori r4,r4,SIU_PCR_256_VAL@l
    li r5,1

    mflr r29
    bl InitPCRs
    mtlr r29

    /*    PCR no. 294 - 305, offset 0x28C, 
        primary functions D_RD_WR, D_WE0, D_WE1, D_OE, D_TS,
        D_ALE,D_TA, D_CS1, D_BDIP, D_WE2, D_WE3, D_ADD9
    */
    lis r3,SIU_PCR_294_305@h
    ori r3,r3,SIU_PCR_294_305@l
    lis r4,SIU_PCR_294_305_VAL@h
    ori r4,r4,SIU_PCR_294_305_VAL@l
    li r5,11

    mflr r29
    bl InitPCRs 
    mtlr r29
#endif

    blr
}


#if INIT_USED_BOARD==ADAT516_AXM_0472
MAKE_HLI_COMPATIBLE(EBI_CS0_CAL_BR0,&EBI.CS[0].BR.R)
MAKE_HLI_COMPATIBLE(EBI_CS0_CAL_OR0,&EBI.CS[0].OR.R)
#endif

/*------------------------------------------------------------------*/
/* FUNCTION     : __initEBIChipSelects                              */
/* PURPOSE      : Initialize the EBI chip selects                   */
/*------------------------------------------------------------------*/
__asm void __initEBIChipSelects(void)
{
nofralloc

#if INIT_USED_BOARD==ADAT516_AXM_0472
    /*  CY7C1338 512K External SRAM - burst inhibit, 0 wait, multiplexed AD
        Set up Memory Controller CS0 @ ADAT516_AXM_0472
    */
    /* EBI.CS[0].BR.R = (unsigned long) START_EXTERNAL_RAM | 0x83UL; */
    /* Sets the base address to START_EXTERNAL_RAM - defined in LCF file*/    
    lis r3, START_EXTERNAL_RAM@h
    addi r0, r3, START_EXTERNAL_RAM@l

    /* 32-bit wide bus, Address/Data multiplexed mode, burst inhibit*/
    ori  r0, r0, 0x83 
    lis  r3, EBI_CS0_CAL_BR0@h
    ori  r3, r3, EBI_CS0_CAL_BR0@l
    stw  r0, 0(r3)

    /*     Set address mask for 512KB range,
        0-clock cycle wait states, 0 - cycle length in clocks
    */
    /*  EBI.CS[0].OR.R = 0xfff80000; */
    lis r0, 0xFFF8
    lis r3, EBI_CS0_CAL_OR0@h
    ori r3, r3, EBI_CS0_CAL_OR0@l
    stw r0, 0(r3)
#endif

    blr
}

/*--------------------------------------------------------------------------*/
/* FUNCTION     : __initMMUExternalMemory                                   */
/* PURPOSE      : Initialize the needed MMU table entry for external memory.*/
/*--------------------------------------------------------------------------*/
__asm void __initMMUExternalMemory(void)
{
/* Set up MMU for External Memory for the external memory module. */
nofralloc

#if (INIT_USED_BOARD != NO_EXTERNAL_MEMORY)
    /* EBI, TLB3, START_EXTERNAL_RAM(0x2000_0000), 512KB */
    lis r3, TLB_Entry_3_MAS0@h
    ori r3, r3, TLB_Entry_3_MAS0@l
    lis r4, TLB_Entry_3_MAS1@h
    ori r4, r4, TLB_Entry_3_MAS1@l
    lis r5, TLB_Entry_3_MAS2@h
    ori r5, r5, TLB_Entry_3_MAS2@l
    lis r6, TLB_Entry_3_MAS3@h
    ori r6, r6, TLB_Entry_3_MAS3@l
    mflr r29
    bl WriteMMUTableEntry
    mtlr r29
#endif

    blr
}


#ifdef __cplusplus
}
#endif
