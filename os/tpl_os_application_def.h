/**
 * @file tpl_os_application_def.h
 *
 * @section File description
 *
 * This file wraps user application configuration header. This wrapped file is
 * typically generated from an OIL source.
 *
 * @section Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_APPLICATION_DEF_H
#define TPL_OS_APPLICATION_DEF_H

#include "tpl_app_define.h"
#include "tpl_config_check.h"

#ifndef TASK_COUNT
#define TASK_COUNT 0
#endif
#if TASK_COUNT == 0
/**
 * @def NO_TASK
 *
 * When this flag is defined, this means there is no task defined in the
 * system.
 */
#define NO_TASK
#endif

#ifndef EXTENDED_TASK_COUNT
#define EXTENDED_TASK_COUNT 0
#endif
#if EXTENDED_TASK_COUNT == 0
/**
 * @def NO_EXTENDED_TASK
 *
 * When this flag is defined, this means there is no extended task
 * defined in the system.
 */
#define NO_EXTENDED_TASK
#endif

#ifndef RESOURCE_COUNT
#define RESOURCE_COUNT 0
#endif
#if RESOURCE_COUNT == 0
/**
 * @def NO_RESOURCE
 *
 * When this flag is defined, this means there is no resource defined in the
 * system.
 */
#define NO_RESOURCE
#endif

#ifndef ALARM_COUNT
#define ALARM_COUNT 0
#endif
#if ALARM_COUNT == 0
/**
 * @def NO_ALARM
 *
 * When this flag is defined, this means there is no alarm defined in the
 * system.
 */
#define NO_ALARM
#endif

#ifndef ISR_COUNT
#define ISR_COUNT 0
#endif
#if ISR_COUNT == 0
/**
 * @def NO_ISR
 *
 * When this flag is defined, this means there is no Interrupt Service
 * Routine defined in the system.
 */
#define NO_ISR
#endif

#ifdef WITH_AUTOSAR

#ifndef SCHEDTABLE_COUNT
#define SCHEDTABLE_COUNT 0
#endif
#if SCHEDTABLE_COUNT == 0
/**
 * @def NO_SCHEDTABLE
 *
 * When this flag is defined, this means there is no schedule table defined
 * in the system
 */
#define NO_SCHEDTABLE
#endif

#ifndef COUNTER_COUNT
#define COUNTER_COUNT 0
#endif
#if COUNTER_COUNT == 0
/**
 * @def NO_COUNTER
 *
 * When this flag is defined, this means there is no software counter defined
 * in the system
 */
#define NO_COUNTER
#endif

/* WITH_AUTOSAR */
#endif


/**
 * @def ASM
 *
 * When using system calls, API functions are written in assembly code
 * ASM expands in the appropriate keyword for the target platform or
 * to an empty string
 */
#ifdef WITH_SYSTEM_CALL
#define ASM TC_ASM
#else
#define ASM
#endif

#ifdef WITH_AUTOSAR
/**
 * @def WITH_OSAPPLICATION
 *
 * @internal
 *
 * This compilation is set if WITH_AUTOSAR is defined and AUTOSAR_SC is
 * equal to 3 or 4. But if WITH_NO_OSAPPLICATION is set, it is unset.
 */
#if APP_COUNT > 0
#if (AUTOSAR_SC == 3) || (AUTOSAR_SC == 4)
#ifndef WITH_NO_OSAPPLICATION
#define WITH_OSAPPLICATION
#endif
#endif
#endif

#endif /* defined WITH_AUTOSAR */

#endif /* TPL_OS_APPLICATION_DEF_H */

/* End of file tpl_os_application_def.h */
