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

TPL_EXTERN main
TPL_EXTERN tpl_kernel_stack

  .text
  .global _start

  .section ".osCode","ax"
_start:

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
  
  .type _start,@function
  .size _start,$-_start

  