/**
 * @file tpl_os_it.h
 *
 * @section desc File description
 *
 * This header file provides standard OSEK-VDX API for interrupts management.
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

#ifndef TPL_OS_IT_H
#define TPL_OS_IT_H

#include "tpl_os_types.h"


#define OS_START_SEC_CODE
#include "Memmap.h"

/*
 * Interrupt handling
 * see paragraph 13.3,
 * pages 54+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Enable all interrupts
 *
 * see paragraph 13.3.2.1 page 54 of OSEK/VDX 2.2.2 spec
 *
 * @see #DisableAllInterrupts
 */
void EnableAllInterrupts(void);     


/**
 * Disable all interrupts
 *
 * see paragraph 13.3.2.2 page 55 of OSEK/VDX 2.2.2 spec
 *
 * @see #EnableAllInterrupts
 */
void DisableAllInterrupts(void);


/** 
 * Resume all interrupts
 *
 * see paragraph 13.3.2.3 page 55 of OSEK/VDX 2.2.2 spec
 *
 * @see #SuspendAllInterrupts
 */
void ResumeAllInterrupts(void);


/**
 * Suspend all interrupts
 *
 * see paragraph 13.3.2.4 page 56 of OSEK/VDX 2.2.2 spec
 *
 * @see #ResumeAllInterrupts
 */
void SuspendAllInterrupts(void);


/** 
 * Resume category 2 interrupts
 *
 * see paragraph 13.3.2.5 page 56 of OSEK/VDX 2.2.2 spec
 * 
 * @see #SuspendOSInterrupts
 */
void ResumeOSInterrupts(void);


/**
 * Suspend category 2 interrupts
 *
 * see paragraph 13.3.2.6 page 57 of OSEK/VDX 2.2.2 spec
 *
 * @see #ResumeOSInterrupts
 */
void SuspendOSInterrupts(void);


/**
 * Additional non-standard system service to terminate a category 2 interrupt
 * routine.
 *
 * This service is equivalent to TerminateTask but for ISR2
 */
StatusType TerminateISR2(void);


#define OS_STOP_SEC_CODE
#include "Memmap.h"

#endif /* TPL_OS_IT_H */

/* End of file tpl_os_it.h */
