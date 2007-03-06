/**
 * @file tpl_os_error.c
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
 *
 * @section descr File description
 *
 * Trampoline Errors macros, functions and datatypes header
 */

#include "tpl_os_error.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"

#ifdef WITH_ERROR_HOOK

tpl_service_call_desc tpl_service;

/**
 * Function used to call the application error hook
 *
 * @param error error code which raised the hook call
 *
 * Do not call it directly, use #PROCESS_ERROR macro
 *
 * @see #PROCESS_ERROR
 */
void tpl_call_error_hook(const tpl_status error)
{

/**
 * This flag is used to avoid error hook call recursion
 */
    static tpl_bool in_error_hook = FALSE;

    if (!in_error_hook)
    {
        in_error_hook = TRUE;
        ErrorHook(error);
        in_error_hook = FALSE;
    }
}

#endif /* WITH_ERROR_HOOK */

/* End of file tpl_os_error.c */
