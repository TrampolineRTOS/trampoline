/*
 * @file tpl_ctx_switch.s
 *
 * @section desc File description
 *
 * Trampoline context switch
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

#include "tpl_os_kernel_stack.h"
#include "tpl_assembler.h"

  .global tpl_save_context
  .global tpl_load_context

#define INT_CONTEXT 0
#define FP_CONTEXT  4

/*
 * Mapping in the context structures
 */
/* #define GPR0    0 */
#define GPR1    4
#define GPR2    8
#define GPR3    12
#define GPR4    16
#define GPR5    20
#define GPR6    24
#define GPR7    28
#define GPR8    32
#define GPR9    36
#define GPR10   40
/* #define GPR11   44
#define GPR12   48 */
#define GPR13   52
#define GPR14   56
#define GPR15   60
#define GPR16   64
#define GPR17   68
#define GPR18   72
#define GPR19   76
#define GPR20   80
#define GPR21   84
#define GPR22   88
#define GPR23   92
#define GPR24   96
#define GPR25   100
#define GPR26   104
#define GPR27   108
#define GPR28   112
#define GPR29   116
#define GPR30   120
#define GPR31   124
/* #define CR      128 */
#define XER     132
/* #define LR      136 */
#define CTR     140
#define SRR0    144
#define SRR1    148
#define FRESH   152

#define FPR0    0
#define FPR1    8
#define FPR2    16
#define FPR3    24
#define FPR4    32
#define FPR5    40
#define FPR6    48
#define FPR7    56
#define FPR8    64
#define FPR9    72
#define FPR10   80
#define FPR11   88
#define FPR12   96
#define FPR13   104
#define FPR14   112
#define FPR15   120
#define FPR16   128
#define FPR17   136
#define FPR18   144
#define FPR19   152
#define FPR20   160
#define FPR21   168
#define FPR22   176
#define FPR23   184
#define FPR24   192
#define FPR25   200
#define FPR26   208
#define FPR27   216
#define FPR28   224
#define FPR29   232
#define FPR30   240
#define FPR31   248
#define FPSCR   256

  .text
  .section .osCode CODE_ACCESS_RIGHT
/**
 * tpl_save_context saves the context in the context passed in r3
 * this function is called from tpl_sc_handler and we are running
 * on the kernel stack so the actual value of some registers to save
 * are saved on the kernel stack.
 */
tpl_save_context:
    lwz     r11,INT_CONTEXT(r3) /* Get the pointer to the integer context  */
    stw     r2,GPR2(r11)        /* save registers          */
    stw     r4,GPR4(r11)
    stw     r5,GPR5(r11)
    stw     r6,GPR6(r11)
    stw     r7,GPR7(r11)
    stw     r8,GPR8(r11)
    stw     r9,GPR9(r11)
    stw     r10,GPR10(r11)
    stw     r13,GPR13(r11)
    stw     r14,GPR14(r11)
    stw     r15,GPR15(r11)
    stw     r16,GPR16(r11)
    stw     r17,GPR17(r11)
    stw     r18,GPR18(r11)
    stw     r19,GPR19(r11)
    stw     r20,GPR20(r11)
    stw     r21,GPR21(r11)
    stw     r22,GPR22(r11)
    stw     r23,GPR23(r11)
    stw     r24,GPR24(r11)
    stw     r25,GPR25(r11)
    stw     r26,GPR26(r11)
    stw     r27,GPR27(r11)
    stw     r28,GPR28(r11)
    stw     r29,GPR29(r11)
    stw     r30,GPR30(r11)
    stw     r31,GPR31(r11)
        
    lwz     r0,KS_SP(r1)                /* get back sp and save it  */
    stw     r0,GPR1(r11)
    
    lwz     r0,KS_RETURN_CODE(r1)       /* get back r3 and save it  */
    stw     r0,GPR3(r11)
    
    mfxer   r0                          /* save the xer             */
    stw     r0,XER(r11)
    mfctr   r0                          /* save the ctr             */
    stw     r0,CTR(r11)
  
    lwz     r0,KS_SRR0(r1)              /* save SRR0 and SRR1       */
    stw     r0,SRR0(r11)
    lwz     r0,KS_SRR1(r1)
    stw     r0,SRR1(r11)
  
#ifdef WITH_FLOAT
#endif
    
    blr   /* returns */

  .type tpl_save_context,@function
  .size tpl_save_context,$-tpl_save_context

/**
 * tpl_load_context loads a context from a tpl_context
 * to the registers and to the kernel stack
 * This function is run on the kernel stack
 *
 * @param   r3 contains the pointer to the context pointers
 */
tpl_load_context:
  
#ifdef WITH_FLOAT
#endif

    lwz r11,INT_CONTEXT(r3)   /* Get the pointer to the integer context   */

/*  setup the kernel stack stuff  */
    lwz     r0,GPR1(r11)      /* load sp and put it in the kernel stack   */
    stw     r0,KS_SP(r1)
    lwz     r0,GPR3(r11)      /* load r3 and put it in the kernel stack   */
    stw     r0,KS_RETURN_CODE(r1)

/*  setup the registers */
    lwz     r0,SRR0(r11)    /* load SRR0 and SRR1                         */
    stw     r0,KS_SRR0(1)
    lwz     r0,SRR1(r11)
    stw     r0,KS_SRR1(r1)

    lwz     r0,CTR(r11)     /* load the ctr                               */
    mtctr   r0
    lwz     r0,XER(r11)     /* load the xer                               */
    mtxer   r0

    lwz     r31,GPR31(r11)
    lwz     r30,GPR30(r11)
    lwz     r29,GPR29(r11)
    lwz     r28,GPR28(r11)
    lwz     r27,GPR27(r11)
    lwz     r26,GPR26(r11)
    lwz     r25,GPR25(r11)
    lwz     r24,GPR24(r11)
    lwz     r23,GPR23(r11)
    lwz     r22,GPR22(r11)
    lwz     r21,GPR21(r11)
    lwz     r20,GPR20(r11)
    lwz     r19,GPR19(r11)
    lwz     r18,GPR18(r11)
    lwz     r17,GPR17(r11)
    lwz     r16,GPR16(r11)
    lwz     r15,GPR15(r11)
    lwz     r14,GPR14(r11)
    lwz     r13,GPR13(r11)
    lwz     r10,GPR10(r11)
    lwz     r9,GPR9(r11)
    lwz     r8,GPR8(r11)
    lwz     r7,GPR7(r11)
    lwz     r6,GPR6(r11)
    lwz     r5,GPR5(r11)
    lwz     r4,GPR4(r11)
    lwz     r2,GPR2(r11)

    blr   /* returns */

  .type tpl_load_context,@function
  .size tpl_load_context,$-tpl_load_context
