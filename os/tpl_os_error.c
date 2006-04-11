/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Errors macros, functions and datatypes header
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#include "tpl_os_error.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"

/*
 * The function corresponding to this prototype is provided
 * by the application
 */
void ErrorHook(StatusType);

#ifdef WITH_ERROR_HOOK

tpl_service_call_desc tpl_service;

static bool in_error_hook = FALSE;

void tpl_call_error_hook(tpl_status error)
{
    /*  Since error hook should not be called when an error occurs
        in a service called by the hook routine, the flag in_error_hook
        is checked before calling the hook routine
    */
    if (! in_error_hook) {
        in_error_hook = TRUE;
        ErrorHook(error);
        in_error_hook = FALSE;
    }
}

#endif
