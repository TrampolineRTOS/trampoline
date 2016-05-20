/**
 * @file tpl_start.S
 *
 * @section desc File description
 *
 * A default _start for PowerPC port
 *
 * @section copyright Copyright
 *
 * Trampoline OpenSource project
 * http://trampoline.rts-software.org
 *
 * Trampoline is copyright (c) IRCCyN 2005+ except for the following parts
 * Copyright ESEO for ARM7 port, function and data structures documentation
 * Copyright Geensys for hcs12 port and v8500 port
 * MPC5674F port - copyright(c) 2016 propriété de l'IRT Saint Exupery, tous droits reservés
 *
 * Trampoline is protected by the French intellectual property law.
 *
 * Trampoline/OS and Trampoline/COM are distributed under one of the
 * following license:
 * - the BSD license
 * - the LGPL V2 license.
 *
 * Goil and Viper are distributed under the GPL v2 license.
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
#include "tpl_app_define.h" /* MPC5674F_Porting_Modif :  Add include to access to WITH_VLE define */

TPL_EXTERN main
TPL_EXTERN tpl_kernel_stack

  .text
  .global _start


  .section .osCode CODE_ACCESS_RIGHT
_start:
/* MPC5674F_Porting_Modif :  Add the VLE section since this project is create with the support of VLE instruction */
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  /* set up the stack */
  e_lis   r1,TPL_HIG(tpl_kernel_stack)
  /* MPC5674F_Porting_Modif :  Delete the second parameter in the instructions below to respect VLE syntax */
  /*e_or2i   r1,r1,TPL_LOW(tpl_kernel_stack) */
  e_or2i   r1,TPL_LOW(tpl_kernel_stack)
  e_add16i  r1,r1,KERNEL_STACK_SIZE - KS_FOOTPRINT
  /* set up the MSR   */
  mfmsr r0
  e_li    r3,64
  not   r3,r3
  and   r0,r0,r3
  mtmsr r0
  
  e_bl    main

_never_get_here:
  e_b     _never_get_here
/* ------------ NO VLE ------------------------------------------------------*/
#else
  /* set up the stack */
  lis   r1,TPL_HIG(tpl_kernel_stack)
  ori   r1,r1,TPL_LOW(tpl_kernel_stack)
  addi  r1,r1,KERNEL_STACK_SIZE - KS_FOOTPRINT
  /* set up the MSR   */
  mfmsr r0
  li    r3,64
  not   r3,r3
  and   r0,r0,r3
  mtmsr r0
  
  bl    main

_never_get_here:
  b     _never_get_here
 #endif
  
  .type _start,@function
  .size _start,$-_start

  
