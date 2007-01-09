/**
 * @file tpl_os_hooks.h
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 * @section descr File description
 *
 * Trampoline Hooks related macros, functions and datatypes
 */

#ifndef __TPL_OS_HOOKS_H__
#define __TPL_OS_HOOKS_H__

#ifdef WITH_TASK_HOOK
#   ifndef WITH_POST_TASK_HOOK
#       define WITH_POST_TASK_HOOK
#   endif
#   ifndef WITH_PRE_TASK_HOOK
#       define WITH_PRE_TASK_HOOK
#   endif
#endif

/**
 * @def CALL_POST_TASK_HOOK
 *
 * Generates a call to #PostTaskHook only if WITH_POST_TASK_HOOK (or WITH_TASK_HOOK) is defined
 */
#ifdef WITH_POST_TASK_HOOK
#   define CALL_POST_TASK_HOOK()    \
    PostTaskHook();
#else
#   define CALL_POST_TASK_HOOK()
#endif

/**
 * @def CALL_PRE_TASK_HOOK
 *
 * Generates a call to #PreTaskHook only if WITH_PRE_TASK_HOOK (or WITH_TASK_HOOK) is defined
 */
#ifdef WITH_PRE_TASK_HOOK
#   define CALL_PRE_TASK_HOOK()    \
    PreTaskHook();
#else
#   define CALL_PRE_TASK_HOOK()
#endif

/**
 * @def CALL_STARTUP_HOOK
 *
 * Generates a call to #StartupHook only if WITH_STARTUP_HOOK is defined 
 */
#ifdef WITH_STARTUP_HOOK
#   define CALL_STARTUP_HOOK()  \
    StartupHook();
#else
#   define CALL_STARTUP_HOOK()
#endif

/**
 * @def CALL_SHUTDOWN_HOOK
 *
 * Generates a call to #ShutdownHook only if WITH_SHUTDOWN_HOOK is defined
 *
 * @param error error code (#StatusType) to send to shutdown hook
 */
#ifdef WITH_SHUTDOWN_HOOK
#   define CALL_SHUTDOWN_HOOK(error)  \
    ShutdownHook(error);
#else
#   define CALL_SHUTDOWN_HOOK(error)
#endif

#endif
