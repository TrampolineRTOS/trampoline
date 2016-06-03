/*
 * @file tpl_exceptions.S
 *
 * @section desc File description
 *
 * Trampoline default exception functions for MPC551x
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

#include "tpl_assembler.h"
#include "tpl_app_define.h"

#define TPL_EXCEPTION_CRITICAL_INPUT        0
#define TPL_EXCEPTION_MACHINE_CHECK         1
#define TPL_EXCEPTION_DATA_STORAGE          2
#define TPL_EXCEPTION_INSTRUCTION_STORAGE   3
#define TPL_EXCEPTION_ALIGNMENT             5
#define TPL_EXCEPTION_PROGRAM               6
#define TPL_EXCEPTION_FLOATING_POINT        7
#define TPL_EXCEPTION_FIXED_INTERVAL_TIMER  11
#define TPL_EXCEPTION_WATCHDOG_TIMER        12
#define TPL_EXCEPTION_DATA_TLB_ERROR        13
#define TPL_EXCEPTION_INSTRUCTION_TLB_ERROR 14

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"
#if (WITH_EXCEPTION_HOOK == YES)
tpl_exception_mngt:
  /* prolog, save all volatile registers, r3 has already been saved */
  e_subi    r1,r1,44
  e_stw     r0,0(r1)
  se_mflr   r0
  e_stw     r0,4(r1)
  e_stw     r4,8(r1)
  e_stw     r5,12(r1)
  e_stw     r6,16(r1)
  e_stw     r7,20(r1)
  e_stw     r8,24(r1)
  e_stw     r9,28(r1)
  e_stw     r10,32(r1)
  e_stw     r11,36(r1)
  e_stw     r12,40(r1)

  /* call ExceptionHook, parameter has already been set in r3 */
  e_bl      TPL_EXTERN_REF(ExceptionHook)

  /* epilog */
  e_lwz     r12,40(r1)
  e_lwz     r11,36(r1)
  e_lwz     r10,32(r1)
  e_lwz     r9 ,28(r1)
  e_lwz     r8 ,24(r1)
  e_lwz     r7 ,20(r1)
  e_lwz     r6 ,16(r1)
  e_lwz     r5 ,12(r1)
  e_lwz     r4 , 8(r1)
  e_lwz     r0 , 4(r1)
  se_mtlr   r0
  e_lwz     r0 ,0(r1)
  e_addi    r1,r1,44
  se_lwz    r3 ,0(r1)
  se_addi   r1,4
  se_rfi
  FUNCTION(tpl_exception_mngt)
TPL_TYPE(tpl_exception_mngt,@function)
TPL_SIZE(tpl_exception_mngt,$-tpl_exception_mngt  )

tpl_exception_mngt_with_wrapper:
  /* prolog, save all volatile registers, r3 has already been saved */
  e_subi    r1,r1,44
  e_stw     r0,0(r1)
  se_mflr   r0
  e_stw     r0,4(r1)
  e_stw     r4,8(r1)
  e_stw     r5,12(r1)
  e_stw     r6,16(r1)
  e_stw     r7,20(r1)
  e_stw     r8,24(r1)
  e_stw     r9,28(r1)
  e_stw     r10,32(r1)
  e_stw     r11,36(r1)
  e_stw     r12,40(r1)

  /* call ExceptionHook, parameter has already been set in r3 */
  e_bl      TPL_EXTERN_REF(tpl_protection_hook_wrapper)
  e_bl      TPL_EXTERN_REF(ExceptionHook)

  /* epilog */
  e_lwz     r12,40(r1)
  e_lwz     r11,36(r1)
  e_lwz     r10,32(r1)
  e_lwz     r9 ,28(r1)
  e_lwz     r8 ,24(r1)
  e_lwz     r7 ,20(r1)
  e_lwz     r6 ,16(r1)
  e_lwz     r5 ,12(r1)
  e_lwz     r4 , 8(r1)
  e_lwz     r0 , 4(r1)
  se_mtlr   r0
  e_lwz     r0 ,0(r1)
  e_addi    r1,r1,44
  se_lwz    r3 ,0(r1)
  se_addi   r1,4
  se_rfi
  FUNCTION(tpl_exception_mngt_with_wrapper)
TPL_TYPE(tpl_exception_mngt_with_wrapper,@function)
TPL_SIZE(tpl_exception_mngt_with_wrapper,$-tpl_exception_mngt_with_wrapper  )

tpl_exception_mngt_with_wrapper_mc:
  /* prolog, save all volatile registers, r3 has already been saved */
  e_subi    r1,r1,44
  e_stw     r0,0(r1)
  se_mflr   r0
  e_stw     r0,4(r1)
  e_stw     r4,8(r1)
  e_stw     r5,12(r1)
  e_stw     r6,16(r1)
  e_stw     r7,20(r1)
  e_stw     r8,24(r1)
  e_stw     r9,28(r1)
  e_stw     r10,32(r1)
  e_stw     r11,36(r1)
  e_stw     r12,40(r1)

  /* call ExceptionHook, parameter has already been set in r3 */
  e_bl      TPL_EXTERN_REF(tpl_protection_hook_wrapper)
  e_bl      TPL_EXTERN_REF(ExceptionHook)

  /* epilog */
  e_lwz     r12,40(r1)
  e_lwz     r11,36(r1)
  e_lwz     r10,32(r1)
  e_lwz     r9 ,28(r1)
  e_lwz     r8 ,24(r1)
  e_lwz     r7 ,20(r1)
  e_lwz     r6 ,16(r1)
  e_lwz     r5 ,12(r1)
  e_lwz     r4 , 8(r1)
  e_lwz     r0 , 4(r1)
  se_mtlr   r0
  e_lwz     r0 ,0(r1)
  e_addi    r1,r1,44
  se_lwz    r3 ,0(r1)
  se_addi   r1,4
  se_rfmci
  FUNCTION(tpl_exception_mngt_with_wrapper_mc)
TPL_TYPE(tpl_exception_mngt_with_wrapper_mc,@function)
TPL_SIZE(tpl_exception_mngt_with_wrapper_mc,$-tpl_exception_mngt_with_wrapper_mc   )
#endif


#if (WITH_EXCEPTION_HOOK == YES)
TPL_CALL_EXCEPTION_MNGT: TPL_MACRO TPL_MACRO_ARG(exception)
  se_subi   r1,4
  se_stw    r3,0(r1)
  se_li     r3,TPL_MACRO_ARG(exception)
  e_b       tpl_exception_mngt
TPL_END_MACRO

TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER: TPL_MACRO TPL_MACRO_ARG(exception)
  se_subi   r1,4
  se_stw    r3,0(r1)
  se_li     r3,TPL_MACRO_ARG(exception)
  e_b       tpl_exception_mngt_with_wrapper
TPL_END_MACRO

TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER_MC: TPL_MACRO TPL_MACRO_ARG(exception)
  se_subi   r1,4
  se_stw    r3,0(r1)
  se_li     r3,TPL_MACRO_ARG(exception)
  e_b       tpl_exception_mngt_with_wrapper_mc
TPL_END_MACRO
#else
TPL_CALL_EXCEPTION_MNGT: TPL_MACRO TPL_MACRO_ARG(exception)
TPL_END_MACRO

TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER: TPL_MACRO TPL_MACRO_ARG(exception)
  e_bl      TPL_EXTERN_REF(tpl_protection_hook_wrapper)
TPL_END_MACRO

TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER_MC: TPL_MACRO TPL_MACRO_ARG(exception)
  e_bl      TPL_EXTERN_REF(tpl_protection_hook_wrapper)
TPL_END_MACRO
#endif


#if (WITH_EXCEPTION_HOOK == YES)
TPL_EXTERN(ExceptionHook)
#endif
TPL_EXTERN(tpl_protection_hook_wrapper)

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"
#define OS_START_SEC_EXCRITICALINPUT
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_critical_input)
TPL_GLOBAL_REF(tpl_critical_input):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_CRITICAL_INPUT
  e_b TPL_GLOBAL_REF(tpl_critical_input)
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b   TPL_GLOBAL_REF(tpl_critical_input)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_critical_input))
TPL_TYPE(TPL_GLOBAL_REF(tpl_critical_input),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_critical_input),$-TPL_GLOBAL_REF(tpl_critical_input))
#define OS_STOP_SEC_EXCRITICALINPUT
#include "tpl_as_memmap.h"





#define OS_START_SEC_EXMACHINECHECK
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_machine_check)
TPL_GLOBAL_REF(tpl_machine_check):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER_MC TPL_EXCEPTION_MACHINE_CHECK
  e_b TPL_GLOBAL_REF(tpl_machine_check)
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b TPL_EXTERN_REF(tpl_protection_hook_wrapper)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_machine_check))
TPL_TYPE(TPL_GLOBAL_REF(tpl_machine_check),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_machine_check),$-TPL_GLOBAL_REF(tpl_machine_check))
#define OS_STOP_SEC_EXMACHINECHECK
#include "tpl_as_memmap.h"





#define OS_START_SEC_EXDATASTORAGE
#include "tpl_as_memmap.h"
/*
 * tpl_data_storage and tpl_instruction_storage exception handler
 * are called when a memory protection exception occurs
 */
TPL_GLOBAL(tpl_data_storage)
TPL_GLOBAL_REF(tpl_data_storage):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER TPL_EXCEPTION_DATA_STORAGE
  e_b TPL_GLOBAL_REF(tpl_data_storage)
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b TPL_EXTERN_REF(tpl_protection_hook_wrapper)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_data_storage))
TPL_TYPE(TPL_GLOBAL_REF(tpl_data_storage),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_data_storage),$-TPL_GLOBAL_REF(tpl_data_storage))
#define OS_STOP_SEC_EXDATASTORAGE
#include "tpl_as_memmap.h"





#define OS_START_SEC_EXINSTRUCTIONSTORAGE
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_instruction_storage)
TPL_GLOBAL_REF(tpl_instruction_storage):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER TPL_EXCEPTION_INSTRUCTION_STORAGE
  e_b TPL_GLOBAL_REF(tpl_instruction_storage)
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b TPL_EXTERN_REF(tpl_protection_hook_wrapper)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_instruction_storage))
TPL_TYPE(TPL_GLOBAL_REF(tpl_instruction_storage),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_instruction_storage),$-TPL_GLOBAL_REF(tpl_instruction_storage))
#define OS_STOP_SEC_EXINSTRUCTIONSTORAGE
#include "tpl_as_memmap.h"





#define OS_START_SEC_EXALIGNMENT
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_alignment)
TPL_GLOBAL_REF(tpl_alignment):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_ALIGNMENT
  e_b TPL_GLOBAL_REF(tpl_alignment)
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b TPL_GLOBAL_REF(tpl_alignment)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_alignment))
TPL_TYPE(TPL_GLOBAL_REF(tpl_alignment),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_alignment),$-TPL_GLOBAL_REF(tpl_alignment))
#define OS_STOP_SEC_EXALIGNMENT
#include "tpl_as_memmap.h"





#define OS_START_SEC_EXPROGRAM
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_program)
TPL_GLOBAL_REF(tpl_program):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_PROGRAM
  /*e_b TPL_GLOBAL_REF(tpl_program)*/
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b TPL_GLOBAL_REF(tpl_program)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_program))
TPL_TYPE(TPL_GLOBAL_REF(tpl_program),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_program),$-TPL_GLOBAL_REF(tpl_program))
#define OS_STOP_SEC_EXPROGRAM
#include "tpl_as_memmap.h"





#define OS_START_SEC_EXFLOATINGPOINTUNAVAILABLE
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_floating_point_unavailable)
TPL_GLOBAL_REF(tpl_floating_point_unavailable):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_FLOATING_POINT
  e_b TPL_GLOBAL_REF(tpl_floating_point_unavailable)
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b TPL_GLOBAL_REF(tpl_floating_point_unavailable)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_floating_point_unavailable))
TPL_TYPE(TPL_GLOBAL_REF(tpl_floating_point_unavailable),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_floating_point_unavailable),$-TPL_GLOBAL_REF(tpl_floating_point_unavailable))
#define OS_STOP_SEC_EXFLOATINGPOINTUNAVAILABLE
#include "tpl_as_memmap.h"





#define OS_START_SEC_EXFIXEDINTERVALTIMER
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_fi_timer)
TPL_GLOBAL_REF(tpl_fi_timer):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_FIXED_INTERVAL_TIMER
  e_b TPL_GLOBAL_REF(tpl_fi_timer)
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b TPL_GLOBAL_REF(tpl_fi_timer)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_fi_timer))
TPL_TYPE(TPL_GLOBAL_REF(tpl_fi_timer),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_fi_timer),$-TPL_GLOBAL_REF(tpl_fi_timer))
#define OS_STOP_SEC_EXFIXEDINTERVALTIMER
#include "tpl_as_memmap.h"





#define OS_START_SEC_EXWATCHDOGTIMER
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_wdg_timer)
TPL_GLOBAL_REF(tpl_wdg_timer):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_WATCHDOG_TIMER
  e_b TPL_GLOBAL_REF(tpl_wdg_timer)
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b TPL_GLOBAL_REF(tpl_wdg_timer)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_wdg_timer))
TPL_TYPE(TPL_GLOBAL_REF(tpl_wdg_timer),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_wdg_timer),$-TPL_GLOBAL_REF(tpl_wdg_timer))
#define OS_STOP_SEC_EXWATCHDOGTIMER
#include "tpl_as_memmap.h"



#define OS_START_SEC_EXDATATLBERROR
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_data_tlb)
TPL_GLOBAL_REF(tpl_data_tlb):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_DATA_TLB_ERROR
  e_b TPL_GLOBAL_REF(tpl_data_tlb)
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b TPL_GLOBAL_REF(tpl_data_tlb)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_data_tlb))
TPL_TYPE(TPL_GLOBAL_REF(tpl_data_tlb),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_data_tlb),$-TPL_GLOBAL_REF(tpl_data_tlb))
#define OS_STOP_SEC_EXDATATLBERROR
#include "tpl_as_memmap.h"




#define OS_START_SEC_EXINSTRUCTIONTLBERROR
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_inst_tlb)
TPL_GLOBAL_REF(tpl_inst_tlb):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_INSTRUCTION_TLB_ERROR
  e_b TPL_GLOBAL_REF(tpl_inst_tlb)
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b TPL_GLOBAL_REF(tpl_inst_tlb)
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_inst_tlb))
TPL_TYPE(TPL_GLOBAL_REF(tpl_inst_tlb),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_inst_tlb),$-TPL_GLOBAL_REF(tpl_inst_tlb))
#define OS_STOP_SEC_EXINSTRUCTIONTLBERROR
#include "tpl_as_memmap.h"




