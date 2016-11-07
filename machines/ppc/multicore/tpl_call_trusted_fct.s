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

#if TRUSTED_FCT_COUNT > 0

#include "tpl_os_kernel_stack.h"
#include "tpl_os_process_stack.h"
#include "tpl_assembler.h"
#include "tpl_os_definitions.h"
#include "tpl_app_define.h"


TPL_EXTERN(ExitTrustedFunction)
TPL_EXTERN(tpl_trusted_fct_table)

TPL_GLOBAL(tpl_call_trusted_function_service)
TPL_GLOBAL(tpl_exit_trusted_function_service)

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

TPL_GLOBAL_REF(tpl_call_trusted_function_service):
#if (WITH_VLE == YES)
/* ------------ VLE ---------------------------------------------------------*/
  /*
   * Check the function index is within the allowed range
   */
  mr        r11,r3
  e_cmp16i  r3,TRUSTED_FCT_COUNT
  e_lis     r3,0
  e_or2i    r3,E_OS_SERVICEID
  se_bge    invalid_trusted_fct_params
  mr        r3,r11

  /*
   * Check the pointer param is not NULL
   */
  mr        r11,r3
  e_cmp16i  r4,0
  e_lis     r3,0
  e_or2i    r3,E_OS_ILLEGAL_ADDRESS
  e_beq     invalid_trusted_fct_params
  mr        r3,r11

  /*
   * Increment the trusted counter of the process
   */
  e_lwz     r11,KS_KERN_PTR(r1)   /* get the ptr to tpl_kern */
  e_lwz     r11,12(r11)           /* get the prt to the runnning process desc */
  e_lwz     r12,4(r11)            /* get trusted_count member */
  e_addi    r12,r12,1             /* increment it */
  e_stw     r12,4(r11)            /* put it back in the process desc */
  /*
   * Save the current return address in process stack
   *
   * First get back the process stack pointer
   */
  e_lwz     r11,KS_SP(r1)
  /*
   * Make room to prepare the call of the trusted function
   */
  e_subi    r11,r11,PS_TRUSTED_FOOTPRINT
  /*
   * store ExitTrustedFunction as the return address
   */
  e_lis     r12,TPL_HIG(TPL_EXTERN_REF(ExitTrustedFunction))
  e_add16i  r12,TPL_LOW(TPL_EXTERN_REF(ExitTrustedFunction))
  e_stw     r12,PS_LR(r11)
  /*
   * Update the stack pointer
   */
  e_stw     r11,KS_SP(r1)
  /*
   * second get back SRR0 and SRR1 and save them to the process stack
   */
  e_lwz     r12,KS_SRR0(r1)
  e_stw     r12,PS_SRR0(r11)
  e_lwz     r12,KS_SRR1(r1)
  e_stw     r12,PS_SRR1(r11)
  /*
   * get the trusted function pointer from the table
   * the index is in r3 and is converted to an offset by shifting it
   * left by 2.
   * the fonction pointer is put in the return location and
   * a pointer to ExitTrustedFunction() service is put in the saved lr
   */
  e_lis     r11,TPL_HIG(TPL_EXTERN_REF(tpl_trusted_fct_table))
  e_add16i  r11,TPL_LOW(TPL_EXTERN_REF(tpl_trusted_fct_table))
  e_slwi    r0,r3,2
  lwzx      r12,r11,r0
  e_stw     r12,KS_SRR0(r1)
  /*
   * go back
   */
invalid_trusted_fct_params:
  se_blr
#else
/* ------------ NO VLE ------------------------------------------------------*/
  /*
   * Check the function index is within the allowed range
   */
  mr    r11,r3
  cmpw  r3,TRUSTED_FCT_COUNT
  ori   r3,r0,E_OS_SERVICEID
  bge   invalid_trusted_fct_params
  mr    r3,r11

  /*
   * Check the pointer param is not NULL
   */
  mr    r11,r3
  cmpw  r4,0
  ori   r3,r0,E_OS_ILLEGAL_ADDRESS
  beq   invalid_trusted_fct_params
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
  subi  r11,r11,PS_TRUSTED_FOOTPRINT
  /*
   * store ExitTrustedFunction as the return address
   */
  lis   r12,TPL_HIG(TPL_EXTERN_REF(ExitTrustedFunction))
  ori   r12,r12,TPL_LOW(TPL_EXTERN_REF(ExitTrustedFunction))
  stw   r12,PS_LR(r11)
  /*
   * Update the stack pointer
   */
  stw   r11,KS_SP(r1)
  /*
   * second get back SRR0 and SRR1 and save them to the process stack
   */
  lwz   r12,KS_SRR0(r1)
  stw   r12,PS_SRR0(r11)
  lwz   r12,KS_SRR1(r1)
  stw   r12,PS_SRR1(r11)
  /*
   * get the trusted function pointer from the table
   * the index is in r3 and is converted to an offset by shifting it
   * left by 2.
   * the fonction pointer is put in the return location and
   * a pointer to ExitTrustedFunction() service is put in the saved lr
   */
  lis   r11,TPL_HIG(TPL_EXTERN_REF(tpl_trusted_fct_table))
  ori   r11,r11,TPL_LOW(TPL_EXTERN_REF(tpl_trusted_fct_table))
  slwi  r0,r3,2
  lwzx  r12,r11,r0
  stw   r12,KS_SRR0(r1)
  /*
   * go back
   */
invalid_trusted_fct_params:
  blr
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_call_trusted_function_service))
TPL_TYPE(TPL_GLOBAL_REF(tpl_call_trusted_function_service),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_call_trusted_function_service),$-TPL_GLOBAL_REF(tpl_call_trusted_function_service))

TPL_GLOBAL_REF(tpl_exit_trusted_function_service):
#if (WITH_VLE == YES)
/* ------------ VLE ---------------------------------------------------------*/
  /*
   * Decrement the trusted counter of the process
   */
  e_lwz     r11,KS_KERN_PTR(r1)   /* get the ptr to tpl_kern */
  e_lwz     r11,12(r11)           /* get the ptr to the runnning process desc */
  e_lwz     r12,4(r11)            /* get trusted_count member */
  /*
   * Warning, the trusted counter has to be check (compared to 0) to
   * avoid to decrement it if it is already 0. Without that a process
   * could build an had-hoc stack an call explicitly ExitTrustedFunction
   * to get access to all the memory.
   */
  e_cmp16i  r12,0                 /* check it is not already at 0 */
  e_beq     cracker_in_action     /* uh uh */
  e_subi    r12,r12,1                 /* decrement it */
  e_stw     r12,4(r11)            /* put it back in the process desc */

cracker_in_action:

  /*
   * get the process stack pointer
   */
  e_lwz     r11,KS_SP(r1)

  /*
   * get back the SRR0 and SRR1
   */
  e_lwz     r12,PS_SRR0(r11)
  e_stw     r12,KS_SRR0(r1)
  e_lwz     r12,PS_SRR1(r11)
  e_stw     r12,KS_SRR1(r1)

  /*
   * free the process stack and update it in the kernel stack
   */
  e_addi    r11,r11,PS_TRUSTED_FOOTPRINT
  e_stw     r11,KS_SP(r1)

  /*
   * set the return value of CallTrustedFunction to E_OK
   * TODO : use E_OK define
   */
  e_lis     r3,0
  e_or2i    r3,0

  /*
   * that's all
   */
  se_blr
#else
/* ------------ NO VLE ------------------------------------------------------*/
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
  lwz   r12,PS_SRR0(r11)
  stw   r12,KS_SRR0(r1)
  lwz   r12,PS_SRR1(r11)
  stw   r12,KS_SRR1(r1)

  /*
   * free the process stack and update it in the kernel stack
   */
  addi  r11,r11,PS_TRUSTED_FOOTPRINT
  stw   r11,KS_SP(r1)

  /*
   * set the return value of CallTrustedFunction to E_OK
   * TODO : use E_OK define
   */
  lis   r3,0
  ori   r3,r3,0

  /*
   * that's all
   */
  blr
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_exit_trusted_function_service))
TPL_TYPE(TPL_GLOBAL_REF(tpl_exit_trusted_function_service),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_exit_trusted_function_service),$-TPL_GLOBAL_REF(tpl_exit_trusted_function_service))

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#endif /* End if TRUSTED_FCT_COUNT > 0 */

