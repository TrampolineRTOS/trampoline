/**
 * @file tpl_os_it.c
 *
 * @section desc File description
 *
 * This implementation file provides standard OSEK-VDX API
 * for interrupts management.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
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

#include "tpl_os_it.h"
#include "tpl_os_it_kernel.h"

#ifdef WITH_SYSTEM_CALL
#include "tpl_os_service_ids.h"
#include "tpl_dispatch.h"
#endif

#ifdef WITH_AUTOSAR
#include "tpl_as_isr.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * TerminateISR
 *
 * While this function is not part of the OSEK API, it is used
 * to terminate an ISR2 routine
 */
ASM FUNC(StatusType, OS_CODE) TerminateISR2(void)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_TerminateISR)
#else
    return tpl_terminate_isr2_service();
#endif
}

/*
 * Enable all interrupts
 *
 * see paragraph 13.3.2.1 page 54 of OSEK/VDX 2.2.2 spec
 *
 * @see #DisableAllInterrupts
 */
ASM FUNC(void, OS_CODE) EnableAllInterrupts(void)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_EnableAllInterrupts)
#else
    tpl_enable_all_interrupts_service();
#endif
}


/*
 * Disable all interrupts
 *
 * see paragraph 13.3.2.2 page 55 of OSEK/VDX 2.2.2 spec
 *
 * @see #EnableAllInterrupts
 */
ASM FUNC(void, OS_CODE) DisableAllInterrupts(void)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_DisableAllInterrupts)
#else
    tpl_disable_all_interrupts_service();
#endif
}


/*
 * Resume all interrupts
 *
 * see paragraph 13.3.2.3 page 55 of OSEK/VDX 2.2.2 spec
 *
 * @see #SuspendAllInterrupts
 */
ASM FUNC(void, OS_CODE) ResumeAllInterrupts(void)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_ResumeAllInterrupts)
#else
    tpl_resume_all_interrupts_service();
#endif
}


/*
 * Suspend all interrupts
 *
 * see paragraph 13.3.2.4 page 56 of OSEK/VDX 2.2.2 spec
 *
 * @see #ResumeAllInterrupts
 */
ASM FUNC(void, OS_CODE) SuspendAllInterrupts(void)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_SuspendAllInterrupts)
#else
    tpl_suspend_all_interrupts_service();
#endif
}


/*
 * Resume category 2 interrupts
 *
 * see paragraph 13.3.2.5 page 56 of OSEK/VDX 2.2.2 spec
 *
 * @see #SuspendOSInterrupts
 */
ASM FUNC(void, OS_CODE) ResumeOSInterrupts(void)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_ResumeOSInterrupts)
#else
    tpl_resume_os_interrupts_service();
#endif
}


/*
 * Suspend category 2 interrupts
 *
 * see paragraph 13.3.2.6 page 57 of OSEK/VDX 2.2.2 spec
 *
 * @see #ResumeOSInterrupts
 */
ASM FUNC(void, OS_CODE) SuspendOSInterrupts(void)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_SuspendOSInterrupts)
#else
    tpl_suspend_os_interrupts_service();
#endif
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_it.h */
