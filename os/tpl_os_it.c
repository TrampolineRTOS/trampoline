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
FUNC(StatusType, OS_CODE) TerminateISR2(void)
{
    return tpl_terminate_isr2_service();
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_it.h */
