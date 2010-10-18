/*
 * @file tpl_call_trusted_fct.s
 *
 * @section desc File description
 *
 * Trampoline tpl_call_trusted_function_service implementation
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
#include "tpl_os_process_stack.h"
#include "tpl_assembler.h"
#include "tpl_os_definitions.h"

TPL_EXTERN  ExitTrustedFunction
TPL_EXTERN  tpl_trusted_fct_table

  .global tpl_call_trusted_function_service
  .global tpl_exit_trusted_function_service
  
  .text
  .section .osCode CODE_ACCESS_RIGHT

tpl_call_trusted_function_service:
  /*
   * Check the function index is within the allowed range
   */
  mr    r11,r3
  cmpw  r3,TRUSTED_FCT_COUNT
  ori   r3,r0,E_OS_SERVICEID
  bge   invalid_trusted_fct_id
  mr    r3,r11
  /*
   * Increment the trusted counter of the process
   */
  lwz   r11,KS_KERN_PTR(r1)   /* get the ptr to tpl_kern */
  lwz   r11,12(r11)           /* get the prt to the runnning process desc */
  lwz   r12,4(r11)            /* get trusted_count member */
  addi  r12,r12,1             /* increment it */
  stw   r12,4(r11)            /* put it back in the process desc */
  /*
   * Save the current return address in process stack
   *
   * First get back the process stack pointer
   */
  lwz   r11,KS_SP(r1)
  /*
   * Make room to prepare the call of the trusted function
   */
  subi  r11,r11,PS_TRUSTED_FOOTPRINT_IN
  /*
   * store ExitTrustedFunction as the return address
   */
  lis   r12,TPL_HIG(ExitTrustedFunction)
  ori   r12,r12,TPL_LOW(ExitTrustedFunction)
  stw   r12,PS_LR(r11)
  /*
   * Update the stack pointer
   */
  stw   r11,KS_SP(r1)
  /*
   * second get back SRR0 and SRR1 and save them to the process stack
   */
  lwz   r12,KS_SRR0(r1)
  stw   r12,PS_SRR0_IN(r11)
  lwz   r12,KS_SRR1(r1)
  stw   r12,PS_SRR1_IN(r11)
  /*
   * get the trusted function pointer from the table
   * the index is in r3 and is converted to an offset by shifting it
   * left by 2.
   * the fonction pointer is put in the return location and
   * a pointer to ExitTrustedFunction() service is put in the saved lr
   */
  lis   r11,TPL_HIG(tpl_trusted_fct_table)
  ori   r11,r11,TPL_LOW(tpl_trusted_fct_table)
  slwi  r0,r3,2
  lwzx  r12,r11,r0
  stw   r12,KS_SRR0(r1)
  /*
   * go back
   */
invalid_trusted_fct_id:  
  blr
  .type tpl_call_trusted_function_service,@function
  .size tpl_call_trusted_function_service,$-tpl_call_trusted_function_service
  
tpl_exit_trusted_function_service:
  /*
   * Decrement the trusted counter of the process
   */
  lwz   r11,KS_KERN_PTR(r1)   /* get the ptr to tpl_kern */
  lwz   r11,12(r11)           /* get the ptr to the runnning process desc */
  lwz   r12,4(r11)            /* get trusted_count member */
  /*
   * Warning, the trusted counter has to be check (compared to 0) to
   * avoid to decrement it if it is already 0. Without that a process
   * could build an had-hoc stack an call explicitly ExitTrustedFunction
   * to get access to all the memory.
   */
  cmpwi r12,0                 /* check it is not already at 0 */
  beq   cracker_in_action     /* uh uh */
  subi  r12,r12,1             /* decrement it */
  stw   r12,4(r11)            /* put it back in the process desc */

cracker_in_action:
  
  /*
   * get the process stack pointer
   */
  lwz   r11,KS_SP(r1)
  
  /*
   * get back the SRR0 and SRR1
   */
  lwz   r12,PS_SRR0_OUT(r11)
  stw   r12,KS_SRR0(r1)
  lwz   r12,PS_SRR1_OUT(r11)
  stw   r12,KS_SRR1(r1)
  
  /*
   * free the process stack and update it in the kernel stack
   */
  addi  r11,r11,PS_TRUSTED_FOOTPRINT_OUT
  stw   r11,KS_SP(r1)
  
  /*
   * that's all
   */
  blr
  .type tpl_exit_trusted_function_service,@function
  .size tpl_exit_trusted_function_service,$-tpl_exit_trusted_function_service
