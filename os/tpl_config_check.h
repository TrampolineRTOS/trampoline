/**
 * @file tpl_config_check.h
 *
 * @section descr File description
 *
 * Here are macro checking used to control the configuration of Trampoline.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
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

#ifndef TPL_CONFIG_CHECK_H
#define TPL_CONFIG_CHECK_H

/*
 * Check the macros configuring the OS behavior are Ok
 */
#ifndef WITH_OS_EXTENDED
#error "Misconfiguration of the OS. WITH_OS_EXTENDED is not defined"
#elif WITH_OS_EXTENDED != YES && WITH_OS_EXTENDED != NO
#error "Misconfiguration of the OS. WITH_OS_EXTENDED is not set to YES or NO"
#endif

#ifndef WITH_STARTUP_HOOK
#error "Misconfiguration of the OS. WITH_STARTUP_HOOK is not defined"
#elif WITH_STARTUP_HOOK != YES && WITH_STARTUP_HOOK != NO
#error "Misconfiguration of the OS. WITH_STARTUP_HOOK is not set to YES or NO"
#endif

#ifndef WITH_SHUTDOWN_HOOK
#error "Misconfiguration of the OS. WITH_SHUTDOWN_HOOK is not defined"
#elif WITH_SHUTDOWN_HOOK != YES && WITH_SHUTDOWN_HOOK != NO
#error "Misconfiguration of the OS. WITH_SHUTDOWN_HOOK is not set to YES or NO"
#endif

#ifndef WITH_ERROR_HOOK
#error "Misconfiguration of the OS. WITH_ERROR_HOOK is not defined"
#elif WITH_ERROR_HOOK != YES && WITH_ERROR_HOOK != NO
#error "Misconfiguration of the OS. WITH_ERROR_HOOK is not set to YES or NO"
#endif

#ifndef WITH_PRE_TASK_HOOK
#error "Misconfiguration of the OS. WITH_PRE_TASK_HOOK is not defined"
#elif WITH_PRE_TASK_HOOK != YES && WITH_PRE_TASK_HOOK != NO
#error "Misconfiguration of the OS. WITH_PRE_TASK_HOOK is not set to YES or NO"
#endif

#ifndef WITH_POST_TASK_HOOK
#error "Misconfiguration of the OS. WITH_POST_TASK_HOOK is not defined"
#elif WITH_POST_TASK_HOOK != YES && WITH_POST_TASK_HOOK != NO
#error "Misconfiguration of the OS. WITH_POST_TASK_HOOK is not set to YES or NO"
#endif

#ifndef WITH_USEGETSERVICEID
#error "Misconfiguration of the OS. WITH_USEGETSERVICEID is not defined"
#elif WITH_USEGETSERVICEID != YES && WITH_USEGETSERVICEID != NO
#error "Misconfiguration of the OS. WITH_USEGETSERVICEID is not set to YES or NO"
#endif

#ifndef WITH_USEPARAMETERACCESS
#error "Misconfiguration of the OS. WITH_USEPARAMETERACCESS is not defined"
#elif WITH_USEPARAMETERACCESS != YES && WITH_USEPARAMETERACCESS != NO
#error "Misconfiguration of the OS. WITH_USEPARAMETERACCESS is not set to YES or NO"
#endif

#ifndef WITH_USERESSCHEDULER
#error "Misconfiguration of the OS. WITH_USERESSCHEDULER is not defined"
#elif WITH_USERESSCHEDULER != YES && WITH_USERESSCHEDULER != NO
#error "Misconfiguration of the OS. WITH_USERESSCHEDULER is not set to YES or NO"
#endif

#ifndef WITH_SYSTEM_CALL
#error "Misconfiguration of the OS. WITH_SYSTEM_CALL is not defined"
#elif WITH_SYSTEM_CALL != YES && WITH_SYSTEM_CALL != NO
#error "Misconfiguration of the OS. WITH_SYSTEM_CALL is not set to YES or NO"
#endif

#ifndef WITH_MEMORY_PROTECTION
#error "Misconfiguration of the OS. WITH_MEMORY_PROTECTION is not defined"
#elif WITH_MEMORY_PROTECTION != YES && WITH_MEMORY_PROTECTION != NO
#error "Misconfiguration of the OS. WITH_MEMORY_PROTECTION is not set to YES or NO"
#endif

#ifndef WITH_MEMMAP
#error "Misconfiguration of the OS. WITH_MEMMAP is not defined"
#elif WITH_MEMMAP != YES && WITH_MEMMAP != NO
#error "Misconfiguration of the OS. WITH_MEMMAP is not set to YES or NO"
#endif

#ifndef WITH_COMPILER_SETTINGS
#error "Misconfiguration of the OS. WITH_COMPILER_SETTINGS is not defined"
#elif WITH_COMPILER_SETTINGS != YES && WITH_COMPILER_SETTINGS != NO
#error "Misconfiguration of the OS. WITH_COMPILER_SETTINGS is not set to YES or NO"
#endif

#ifndef WITH_AUTOSAR
#error "Misconfiguration of the OS. WITH_AUTOSAR is not defined"
#elif WITH_AUTOSAR != YES && WITH_AUTOSAR != NO
#error "Misconfiguration of the OS. WITH_AUTOSAR is not set to YES or NO"
#endif

#ifndef AUTOSAR_SC
#error "Misconfiguration of the OS. AUTOSAR_SC is not defined"
#elif AUTOSAR_SC != 0 && AUTOSAR_SC != 1 && AUTOSAR_SC != 2 && AUTOSAR_SC != 3 && AUTOSAR_SC != 4
#error "Misconfiguration of the OS. AUTOSAR_SC is not set to 0, 1, 2 or 4"
#endif

#ifndef WITH_OSAPPLICATION
#error "Misconfiguration of the OS. WITH_OSAPPLICATION is not defined"
#elif WITH_OSAPPLICATION != YES && WITH_OSAPPLICATION != NO
#error "Misconfiguration of the OS. WITH_OSAPPLICATION is not set to YES or NO"
#endif

#ifndef WITH_PROTECTION_HOOK
#error "Misconfiguration of the OS. WITH_PROTECTION_HOOK is not defined"
#elif WITH_PROTECTION_HOOK != YES && WITH_PROTECTION_HOOK != NO
#error "Misconfiguration of the OS. WITH_PROTECTION_HOOK is not set to YES or NO"
#endif

#ifndef WITH_STACK_MONITORING
#error "Misconfiguration of the OS. WITH_STACK_MONITORING is not defined"
#elif WITH_STACK_MONITORING != YES && WITH_STACK_MONITORING != NO
#error "Misconfiguration of the OS. WITH_STACK_MONITORING is not set to YES or NO"
#endif
/*
#ifndef WITH_AUTOSAR_TIMING_PROTECTION
#error "Misconfiguration of the OS. WITH_AUTOSAR_TIMING_PROTECTION is not defined"
#elif WITH_AUTOSAR_TIMING_PROTECTION != YES && WITH_AUTOSAR_TIMING_PROTECTION != NO
#error "Misconfiguration of the OS. WITH_AUTOSAR_TIMING_PROTECTION is not set to YES or NO"
#endif
*/
#ifndef WITH_TRACE
#error "Misconfiguration of the OS. WITH_TRACE is not defined"
#elif WITH_TRACE != YES && WITH_TRACE != NO
#error "Misconfiguration of the OS. WITH_TRACE is not set to YES or NO"
#endif

#ifndef WITH_IT_TABLE
#error "Misconfiguration of the OS. WITH_IT_TABLE is not defined"
#elif WITH_IT_TABLE != YES && WITH_IT_TABLE != NO
#error "Misconfiguration of the OS. WITH_IT_TABLE is not set to YES or NO"
#endif

#ifndef WITH_COM
#error "Misconfiguration of the OS. WITH_COM is not defined"
#elif WITH_COM != YES && WITH_COM != NO
#error "Misconfiguration of the OS. WITH_COM is not set to YES or NO"
#endif

#if WITH_COM == YES

#ifndef WITH_COM_ERROR_HOOK
#error "Misconfiguration of the OS. WITH_COM_ERROR_HOOK is not defined"
#elif WITH_COM_ERROR_HOOK != YES && WITH_COM_ERROR_HOOK != NO
#error "Misconfiguration of the OS. WITH_COM_ERROR_HOOK is not set to YES or NO"
#endif

#ifndef WITH_COM_USEGETSERVICEID
#error "Misconfiguration of the OS. WITH_COM_USEGETSERVICEID is not defined"
#elif WITH_COM_USEGETSERVICEID != YES && WITH_COM_USEGETSERVICEID != NO
#error "Misconfiguration of the OS. WITH_COM_USEGETSERVICEID is not set to YES or NO"
#endif

#ifndef WITH_COM_USEPARAMETERACCESS
#error "Misconfiguration of the OS. WITH_COM_USEPARAMETERACCESS is not defined"
#elif WITH_COM_USEPARAMETERACCESS != YES && WITH_COM_USEPARAMETERACCESS != NO
#error "Misconfiguration of the OS. WITH_COM_USEPARAMETERACCESS is not set to YES or NO"
#endif

#ifndef WITH_COM_STARTCOMEXTENSION
#error "Misconfiguration of the OS. WITH_COM_STARTCOMEXTENSION is not defined"
#elif WITH_COM_STARTCOMEXTENSION != YES && WITH_COM_STARTCOMEXTENSION != NO
#error "Misconfiguration of the OS. WITH_COM_STARTCOMEXTENSION is not set to YES or NO"
#endif

#ifndef WITH_COM_EXTENDED
#error "Misconfiguration of the OS. WITH_COM_EXTENDED is not defined"
#elif WITH_COM_EXTENDED != YES && WITH_COM_EXTENDED != NO
#error "Misconfiguration of the OS. WITH_COM_EXTENDED is not set to YES or NO"
#endif

#endif /* WITH_COM */

/*
 * Check the macros defining the number of objects of each kind are set
 */
#ifndef TASK_COUNT
#error "Misconfiguration of the OS. TASK_COUNT is not defined"
#elif TASK_COUNT < 0
#error "Misconfiguration of the OS. TASK_COUNT should not be negative"
#endif

#ifndef EXTENDED_TASK_COUNT
#error "Misconfiguration of the OS. EXTENDED_TASK_COUNT is not defined"
#elif EXTENDED_TASK_COUNT < 0
#error "Misconfiguration of the OS. EXTENDED_TASK_COUNT should not be negative"
#endif

#ifndef RESOURCE_COUNT
#error "Misconfiguration of the OS. RESOURCE_COUNT is not defined"
#elif RESOURCE_COUNT < 0
#error "Misconfiguration of the OS. RESOURCE_COUNT should not be negative"
#endif

#ifndef ALARM_COUNT
#error "Misconfiguration of the OS. ALARM_COUNT is not defined"
#elif ALARM_COUNT < 0
#error "Misconfiguration of the OS. ALARM_COUNT should not be negative"
#endif

#ifndef ISR_COUNT
#error "Misconfiguration of the OS. ISR_COUNT is not defined"
#elif ISR_COUNT < 0
#error "Misconfiguration of the OS. ISR_COUNT should not be negative"
#endif

#if WITH_AUTOSAR == YES

#ifndef SCHEDTABLE_COUNT
#error "Misconfiguration of the OS. SCHEDTABLE_COUNT is not defined"
#elif SCHEDTABLE_COUNT < 0
#error "Misconfiguration of the OS. SCHEDTABLE_COUNT should not be negative"
#endif

#ifndef COUNTER_COUNT
#error "Misconfiguration of the OS. COUNTER_COUNT is not defined"
#elif COUNTER_COUNT < 0
#error "Misconfiguration of the OS. COUNTER_COUNT should not be negative"
#endif

#ifndef APP_COUNT
#error "Misconfiguration of the OS. APP_COUNT is not defined"
#elif APP_COUNT < 0
#error "Misconfiguration of the OS. APP_COUNT should not be negative"
#endif

#ifndef TRUSTED_FCT_COUNT
#error "Misconfiguration of the OS. TRUSTED_FCT_COUNT is not defined"
#elif TRUSTED_FCT_COUNT < 0
#error "Misconfiguration of the OS. TRUSTED_FCT_COUNT should not be negative"
#endif

#ifndef SPINLOCK_COUNT
#error "Misconfiguration of the OS. SPINLOCK_COUNT is not defined"
#elif SPINLOCK_COUNT < 0
#error "Misconfiguration of the OS. SPINLOCK_COUNT should not be negative"
#elif ((SPINLOCK_COUNT > 0) && (NUMBER_OF_CORES <= 1))
#error "Misconfiguration of the OS. SPINLOCKS can only be present in multicore"
#endif

#endif

#endif /* TPL_CONFIG_CHECK_H */
