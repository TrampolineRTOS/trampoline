/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Hooks macros, functions and datatypes header
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
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

#ifdef WITH_POST_TASK_HOOK
#   define CALL_POST_TASK_HOOK()    \
    PostTaskHook();
#else
#   define CALL_POST_TASK_HOOK()
#endif

#ifdef WITH_PRE_TASK_HOOK
#   define CALL_PRE_TASK_HOOK()    \
    PreTaskHook();
#else
#   define CALL_PRE_TASK_HOOK()
#endif

#ifdef WITH_STARTUP_HOOK
#   define CALL_STARTUP_HOOK()  \
    StartupHook();
#else
#   define CALL_STARTUP_HOOK()
#endif

#ifdef WITH_SHUTDOWN_HOOK
#   define CALL_SHUTDOWN_HOOK(error)  \
    ShutdownHook(error);
#else
#   define CALL_SHUTDOWN_HOOK(error)
#endif

#endif
