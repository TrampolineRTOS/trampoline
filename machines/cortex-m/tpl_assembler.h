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
#else
  #ifdef __ghs_asm
  #else
    #ifdef __GNUC__
      #define r0 r0
      #define r1 r1
      #define r2 r2
      #define r3 r3
      #define r4 r4
      #define r5 r5
      #define r6 r6
      #define r7 r7
      #define r8 r8
      #define r9 r9
      #define r10 r10
      #define r11 r11
      #define r12 r12
      #define r13 r13
      #define r14 r14
      #define r15 r15
      #define TPL_EXTERN    .extern
      #define CODE_ACCESS_RIGHT ,"ax"
      #define CAR_ACCESS_RIGHT ,"aw"
    #else
      #error "Unknown compiler"
    #endif
  #endif
#endif

#endif /*  TPL_ASSEMBLER_H  */

/* End of file tpl_assembler.h */
