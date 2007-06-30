/**
 * @file tpl_os_hooks.h
 *
 * @section descr File description
 *
 * Trampoline Hooks related macros, functions prototypes and datatypes
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
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

#ifndef TPL_OS_HOOKS_H
#define TPL_OS_HOOKS_H

#include "tpl_os_types.h"

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
 * Generates a call to #PostTaskHook only if WITH_POST_TASK_HOOK
 * (or WITH_TASK_HOOK) is defined
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
 * Generates a call to #PreTaskHook only if WITH_PRE_TASK_HOOK
 * (or WITH_TASK_HOOK) is defined
 */
#ifdef WITH_PRE_TASK_HOOK
#   define CALL_PRE_TASK_HOOK()         \
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
#   define CALL_STARTUP_HOOK()          \
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
#   define CALL_SHUTDOWN_HOOK(error)    \
    ShutdownHook(error);
#else
#   define CALL_SHUTDOWN_HOOK(error)
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#ifdef WITH_PRE_TASK_HOOK
/**
 * Prototype of the pre-task hook routine
 */
extern void PreTaskHook(void);
#endif

#ifdef WITH_POST_TASK_HOOK
/**
 * Prototype of the post-task hook routine
 */
extern void PostTaskHook(void);
#endif

#ifdef WITH_STARTUP_HOOK
/**
 * Prototype of the startup hook routine
 */
void StartupHook(void);
#endif

#ifdef WITH_SHUTDOWN_HOOK
/**
 * Prototype of the shutdown hook routine
 */
void ShutdownHook(StatusType);
#endif

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_HOOKS_H */

/* End of file tpl_os_hooks.h */
