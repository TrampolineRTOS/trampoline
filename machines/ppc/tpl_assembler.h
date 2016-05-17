/*
 * @file tpl_assembler.h
 *
 * @section desc File description
 *
 * Cooking to have a portable assembly source
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

#ifndef TPL_ASSEMBLER_H
#define TPL_ASSEMBLER_H

/*
 * According to the assembler used (currently, Metrowerks and Green Hills are
 * supported, whe define some macro that correspond to keywords that are
 * not portable
 */
#ifdef __MWERKS__
  #define TPL_HIG(sym)  sym@h
  #define TPL_LOW(sym)  sym@l
  #define TPL_EXTERN    .extern
  #define CODE_ACCESS_RIGHT
  #define VAR_ACCESS_RIGHT
#else
  #ifdef __ghs_asm
    #define TPL_HIG(sym)  %hi(sym)
    #define TPL_LOW(sym)  %lo(sym)
    #define TPL_EXTERN    .extern
    #define CODE_ACCESS_RIGHT ,"ax"
    #define VAR_ACCESS_RIGHT ,"aw"
  #else
    #ifdef __GNUC__
      #define r0 0
      #define r1 1
      #define r2 2
      #define r3 3
      #define r4 4
      #define r5 5
      #define r6 6
      #define r7 7
      #define r8 8
      #define r9 9
      #define r10 10
      #define r11 11
      #define r12 12
      #define r13 13
      #define r14 14
      #define r15 15
      #define r16 16
      #define r17 17
      #define r18 18
      #define r19 19
      #define r20 20
      #define r21 21
      #define r22 22
      #define r23 23
      #define r24 24
      #define r25 25
      #define r26 26
      #define r27 27
      #define r28 28
      #define r29 29
      #define r30 30
      #define r31 31
      #define TPL_HIG(sym)  sym@h
      #define TPL_LOW(sym)  sym@l
      #define TPL_EXTERN    .extern
      #define CODE_ACCESS_RIGHT ,"ax"
      #define VAR_ACCESS_RIGHT ,"aw"
    #else
      #error "Unknown compiler"
    #endif
  #endif
#endif

/*
 * register number for special purpose registers
 */
#define spr_SRR0    26
#define spr_SRR1    27

/*
 * External interrupt bit mask in MSR
 */
#define EE_BIT_1  0x8000
#define RI_BIT_1  0x0002

#endif /*  TPL_ASSEMBLER_H  */

/* End of file tpl_assembler.h */
