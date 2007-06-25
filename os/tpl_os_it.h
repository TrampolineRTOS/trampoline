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
#define OS_START_SEC_CODE
#include "Memmap.h"
void EnableAllInterrupts(void);     
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/**
 * Disable all interrupts
 *
 * see paragraph 13.3.2.2 page 55 of OSEK/VDX 2.2.2 spec
 *
 * @see #EnableAllInterrupts
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
void DisableAllInterrupts(void);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/** 
 * Resume all interrupts
 *
 * see paragraph 13.3.2.3 page 55 of OSEK/VDX 2.2.2 spec
 *
 * @see #SuspendAllInterrupts
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
void ResumeAllInterrupts(void);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/**
 * Suspend all interrupts
 *
 * see paragraph 13.3.2.4 page 56 of OSEK/VDX 2.2.2 spec
 *
 * @see #ResumeAllInterrupts
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
void SuspendAllInterrupts(void);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/** 
 * Resume category 2 interrupts
 *
 * see paragraph 13.3.2.5 page 56 of OSEK/VDX 2.2.2 spec
 * 
 * @see #SuspendOSInterrupts
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
void ResumeOSInterrupts(void);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/**
 * Suspend category 2 interrupts
 *
 * see paragraph 13.3.2.6 page 57 of OSEK/VDX 2.2.2 spec
 *
 * @see #ResumeOSInterrupts
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
void SuspendOSInterrupts(void);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/**
 * Additional non-standard system service to terminate a category 2 interrupt
 * routine.
 *
 * This service is equivalent to TerminateTask but for ISR2
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
StatusType TerminateISR2(void);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

#endif /* TPL_OS_IT_H */

/* End of file tpl_os_it.h */
