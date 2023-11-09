/**
 * @file tpl_os_interrupts.h
 *
 * @section desc File description
 *
 * Trampoline interrupt service routines management
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de
 * Nantes Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_IT_KERNEL_H
#define TPL_OS_IT_KERNEL_H

#include "tpl_machine.h"
#include "tpl_os_kernel.h"

/**
 * An ISR helper is a function which should return true
 * if the related ISR decides to handle the interrupt
 *
 * This type is not intended to be used alone.
 *
 * @see #TPL_ISR_STATIC
 */
typedef P2FUNC(tpl_bool, OS_APPL_CODE, tpl_isr_helper)(void);

typedef P2FUNC(void, OS_APPL_CODE,
               tpl_it_handler)(P2CONST(void, OS_APPL_DATA, AUTOMATIC));

/**
 * Function pointer type for enable/disable interrupts functions
 */
typedef P2FUNC(void, OS_APPL_CODE, tpl_enable_disable_func)(void);

/**
 * @struct TPL_IT_VECTOR_ENTRY
 *
 * Entry of the tpl interrupt vector
 */
struct TPL_IT_VECTOR_ENTRY
{
  CONST(tpl_it_handler, AUTOMATIC)
  func; /**< pointer to the request
              handling function for
              this interrupt
          */
  P2VAR(void, OS_APPL_DATA, AUTOMATIC)
  args; /**< pointer to the
            arguments the function
          */
};

/**
 * @typedef tpl_it_vector_entry
 *
 * This is an alias for #TPL_IT_VECTOR_ENTRY structure
 *
 * @see #TPL_IT_VECTOR_ENTRY
 */
typedef struct TPL_IT_VECTOR_ENTRY tpl_it_vector_entry;

/**
 * @struct TPL_ISR_STATIC
 *
 * Static descriptor of a category 2 interrupt service routine
 */
struct TPL_ISR_STATIC
{
  CONST(tpl_isr_helper, AUTOMATIC)
  helper; /**<  pointer to a helper function used
                to search for hardware that
                launched the interrupt
          */
  struct P2VAR(TPL_ISR_STATIC, OS_APPL_DATA,
               AUTOMATIC) next; /**<  when there is several handler for
                                      the same interrupt priority, the
                                      tpl_isr are chained. In this case.
                                      Trampoline uses the helper to check
                                      what handler will be called for the
                                      interrupt.
                                */
  CONST(tpl_isr_id, AUTOMATIC)
  isr_id; /**<  The id of the ISR
           */
};

/**
 * @typedef tpl_isr_static
 *
 * This is an alias for #TPL_ISR_STATIC structure
 *
 * @see #TPL_ISR_STATIC
 */
typedef struct TPL_ISR_STATIC tpl_isr_static;

#if ISR_COUNT > 0

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

extern CONSTP2CONST(tpl_isr_static, AUTOMATIC,
                    OS_APPL_DATA) tpl_isr_stat_table[ISR_COUNT];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#endif /* ISR_COUNT */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * Check if interrupts are disabled or not by the user
 *
 * @retval  TRUE        interrupts disabled
 * @retval  FALSE       interrupts enabled
 */
FUNC(tpl_bool, OS_CODE) tpl_get_interrupt_lock_status(void);

/**
 * Check if interrupts are disabled or not by the user
 */
FUNC(void, OS_CODE) tpl_reset_interrupt_lock_status(void);

/**
 * Additional non-standard system service to terminate a category 2 interrupt
 * routine.
 *
 * This service is equivalent to TerminateTask but for ISR2
 */
FUNC(tpl_status, OS_CODE) tpl_terminate_isr2_service(void);

/**
 * This is the dispatcher of interrupts. It should be called by
 * the root interrupt handler with an ISR identifier
 *
 * @param interrupt service routine identifier
 */
FUNC(void, OS_CODE) tpl_central_interrupt_handler(CONST(uint16, AUTOMATIC) id);

/**
 * This is the fast dispatcher of interrupts. It should be called by
 * the root interrupt handler with an ISR identifier
 * This dispatcher does not look for many isr connected to the id.
 * It activates only one isr.
 *
 * @param interrupt service routine identifier
 */
FUNC(void, OS_CODE)
tpl_fast_central_interrupt_handler(CONST(uint16, AUTOMATIC) id);

/**
 * This is the dispatcher of interrupts. It should be called by
 * the root interrupt handler with an ISR identifier. VP2 version.
 *
 * @param interrupt service routine identifier
 */
FUNC(void, OS_CODE)
tpl_central_interrupt_handler_2(P2CONST(void, OS_APPL_DATA, AUTOMATIC) id);

/**
 * This function is called when an unknown interrupt is raised.
 * It is empty. It is only present to attach a breakpoint for
 * debugging purposes. VP2 version.
 */
FUNC(void, OS_CODE) tpl_null_it(P2CONST(void, OS_APPL_DATA, AUTOMATIC));

/**
 * Enable all interrupts service
 *
 * @see #EnableAllInterrupts
 */
FUNC(void, OS_CODE) tpl_enable_all_interrupts_service(void);

/**
 * Disable all interrupts
 *
 * @see #DisableAllInterrupts
 */
FUNC(void, OS_CODE) tpl_disable_all_interrupts_service(void);

/**
 * Resume all interrupts
 *
 * @see #ResumeAllInterrupts
 */
FUNC(void, OS_CODE) tpl_resume_all_interrupts_service(void);

/**
 * Suspend all interrupts
 *
 * @see #SuspendAllInterrupts
 */
FUNC(void, OS_CODE) tpl_suspend_all_interrupts_service(void);

/**
 * Resume category 2 interrupts
 *
 * @see #ResumeOSInterrupts
 */
FUNC(void, OS_CODE) tpl_resume_os_interrupts_service(void);

/**
 * Suspend category 2 interrupts
 *
 * @see #SuspendOSInterrupts
 */
FUNC(void, OS_CODE) tpl_suspend_os_interrupts_service(void);

#if WITH_ISR2_PRIORITY_MASKING == YES && ISR_COUNT > 0
/**
 * @internal
 *
 * tpl_mask_isr2_priority masks ISR2s which have a lower priority than
 * the ISR2 id given in argument
 *
 * @param isr isr for which interrupts have to be masked
 */
extern FUNC(void, OS_CODE)
    tpl_mask_isr2_priority(CONST(tpl_proc_id, AUTOMATIC) proc_id);

/**
 * @internal
 *
 * tpl_unmask_isr2_priority unmask ISR2s which have a lower priority than
 * the ISR2 id given in argument
 *
 * @param isr isr for which interrupts have to be unmasked
 */
extern FUNC(void, OS_CODE)
    tpl_unmask_isr2_priority(CONST(tpl_proc_id, AUTOMATIC) proc_id);

#endif /* WITH_ISR2_PRIORITY_MASKING */

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_IT_KERNEL_H */

/* End of file tpl_os_it_kernel.h */
