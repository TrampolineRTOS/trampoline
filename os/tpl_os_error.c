/**
 * @file tpl_os_error.c
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
 * Trampoline Errors macros, functions and datatypes header
 */

#include "tpl_os_error.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"

/*
 * The function corresponding to this prototype should be provided
 * by the application
 */
extern void ErrorHook(StatusType);

#ifdef WITH_ERROR_HOOK

tpl_service_call_desc tpl_service;

/**
 * This flag is used to avoid error hook call recursion
 */
static bool in_error_hook = FALSE;

/**
 * Function used to call the application error hook
 *
 * @param error error code which raised the hook call
 *
 * Do not call it directly, use #PROCESS_ERROR macro
 *
 * @see #PROCESS_ERROR
 */
void tpl_call_error_hook(tpl_status error)
{
    if (! in_error_hook) {
        in_error_hook = TRUE;
        ErrorHook(error);
        in_error_hook = FALSE;
    }
}

#endif
