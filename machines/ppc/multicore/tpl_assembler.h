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
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
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
#if defined (__MWERKS__)
  #define TPL_VLE_ON
  #define TPL_VLE_OFF
  #define TPL_HIG(sym)  sym@ha
  #define TPL_LOW(sym)  sym@l
  #define TPL_EXTERN(var)    .extern var
  #define TPL_GLOBAL(var)    .global var
  #define TPL_EXTERN_REF(var) var
  #define TPL_GLOBAL_REF(var) var
  #define TPL_ALIGN(byte)     .align byte
  #define TPL_SPACE(bytes)    .space bytes
  #define TPL_LONG(expr)    .long expr
  #define TPL_FILL(bytes)   .fill bytes
  #define TPL_EQU(sym,val)  .equ sym, val
  #define TPL_TYPE(sym,val) .type sym,val
  #define TPL_SIZE(sym,val) .size sym,val
  #define TPL_MACRO         .macro
  #define TPL_END_MACRO     .endm
  #define TPL_MACRO_ARG(sym)    sym
  #define TPL_SECTION(name, rights) .section .name rights
  #define TPL_TEXT_SECTION          .text
  #define TPL_DATA_SECTION          .data
  #define CODE_ACCESS_RIGHT ,text_vle
  #define VAR_ACCESS_RIGHT
  #define FUNCTION(name)  .function "##name", ##name, $-##name
  #define TYPE(name)      .type ##name,@function
  #define SIZE(name)      .size ##name,$-##name
#elif defined (__ghs_asm)
  #define TPL_VLE_ON    .vle
  #define TPL_VLE_OFF
  #define TPL_HIG(sym)  %hi(sym)
  #define TPL_LOW(sym)  %lo(sym)
  #define TPL_EXTERN(var)    .extern var
  #define TPL_GLOBAL(var)    .global var
  #define TPL_EXTERN_REF(var) var
  #define TPL_GLOBAL_REF(var) var
  #define TPL_ALIGN(byte)     .align byte
  #define TPL_SPACE(bytes)    .space bytes
  #define TPL_LONG(expr)    .long expr
  #define TPL_FILL(bytes)   .fill bytes
  #define TPL_EQU(sym,val)  .equ sym, val
  #define TPL_TYPE(sym,val) .type sym,val
  #define TPL_SIZE(sym,val) .size sym,val
  #define TPL_MACRO         .macro
  #define TPL_END_MACRO     .endm
  #define TPL_MACRO_ARG(sym)    sym
  #define TPL_SECTION(name, rights) .section .name rights
  #define TPL_TEXT_SECTION          .text
  #define TPL_DATA_SECTION          .data
  #define CODE_ACCESS_RIGHT ,"ax"
  #define VAR_ACCESS_RIGHT ,"aw"
  #define FUNCTION(name)  .function "##name", ##name, $-##name
  #define TYPE(name)      .type ##name,@function
  #define SIZE(name)      .size ##name,$-##name
#elif defined(__DIABDATA__)
  #define TPL_VLE_ON
  #define TPL_VLE_OFF
  #define TPL_HIG(sym)  sym@ha
  #define TPL_LOW(sym)  sym@l
  #define TPL_EXTERN    .extern
  #define TPL_GLOBAL(var)    .global var
  #define TPL_EXTERN_REF(var) var
  #define TPL_GLOBAL_REF(var) var
  #define TPL_ALIGN(byte)     .align byte
  #define TPL_SPACE(bytes)    .space bytes
  #define TPL_LONG(expr)    .long expr
  #define TPL_FILL(bytes)   .fill bytes
  #define TPL_EQU(sym,val)  .equ sym, val
  #define TPL_TYPE(sym,val) .type sym,val
  #define TPL_SIZE(sym,val) .size sym,val
  #define TPL_MACRO         .macro
  #define TPL_END_MACRO     .endm
  #define TPL_MACRO_ARG(sym)    sym
  #define TPL_SECTION(name, rights) .section .name rights
  #define TPL_TEXT_SECTION          .text
  #define TPL_DATA_SECTION          .data
  #define CODE_ACCESS_RIGHT
  #define VAR_ACCESS_RIGHT
  #define FUNCTION(name)
  #define TYPE(name)      .type ##name,@function
  #define SIZE(name)      .size ##name,$-##name
#elif defined (__GNUC__)
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
  #define TPL_VLE_ON
  #define TPL_VLE_OFF
  #define TPL_HIG(sym)  sym@ha
  #define TPL_LOW(sym)  sym@l
  #define TPL_EXTERN(var)    .extern var
  #define TPL_GLOBAL(var)    .global var
  #define TPL_EXTERN_REF(var) var
  #define TPL_GLOBAL_REF(var) var
  #define TPL_ALIGN(byte)     .align byte
  #define TPL_SPACE(bytes)    .space bytes
  #define TPL_LONG(expr)    .long expr
  #define TPL_FILL(bytes)   .fill bytes
  #define TPL_EQU(sym,val)  .equ sym, val
  #define TPL_TYPE(sym,val)         .type sym,val
  #define TPL_SIZE(sym,val)         .size sym,val
  #define TPL_MACRO         .macro
  #define TPL_END_MACRO     .endm
  #define TPL_MACRO_ARG(sym)    sym
  #define TPL_SECTION(name, rights) .section .name rights
  #define TPL_TEXT_SECTION          .text
  #define TPL_DATA_SECTION          .data
  #define CODE_ACCESS_RIGHT ,"ax"
  #define VAR_ACCESS_RIGHT ,"aw"
  #define FUNCTION(name)
  #define TYPE(name)
  #define SIZE(name)
#elif defined (__CSMC__)
  #define TPL_VLE_ON    vle on
  #define TPL_VLE_OFF   vle off
  #define TPL_HIG(sym)  sym@ha
  #define TPL_LOW(sym)  sym@l
  #define TPL_EXTERN(var)    xref _ ## var
  #define TPL_GLOBAL(var)    xdef _ ## var
  #define TPL_EXTERN_REF(var) _ ## var
  #define TPL_GLOBAL_REF(var) _ ## var
  #define TPL_ALIGN(byte)    align byte
  #define TPL_SPACE(bytes)   dcb.b bytes,0 /* Initializes bytes with value 0 */
  #define TPL_LONG(expr)     dc.b  expr
  #define TPL_FILL(bytes)    dcb.b bytes,0
  #define TPL_EQU(sym,val)   sym : equ val
  #define TPL_TYPE(sym,val)
  #define TPL_SIZE(sym,val)
  #define TPL_MACRO         macro
  #define TPL_END_MACRO     endm
  #define TPL_MACRO_ARG(sym)    \ ## sym
  #define TPL_SECTION(name, rights) .name: section rights
  #define TPL_TEXT_SECTION          switch .text
  #define TPL_DATA_SECTION          switch .data
  #define CODE_ACCESS_RIGHT .text
  #define VAR_ACCESS_RIGHT  .data
  #define FUNCTION(name)
  #define TYPE(name)
  #define SIZE(name)
#else
  #error "Unknown compiler"
#endif

#endif /*  TPL_ASSEMBLER_H  */

/* End of file tpl_assembler.h */
