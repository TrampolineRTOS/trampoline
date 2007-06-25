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

#ifdef WITH_ERROR_HOOK

#include "tpl_os_definitions.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"
tpl_service_call_desc tpl_service;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

/**
 * Function used to call the application error hook
 *
 * @param error error code which raised the hook call
 *
 * Do not call it directly, use #PROCESS_ERROR macro
 *
 * @see #PROCESS_ERROR
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
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
#define OS_STOP_SEC_CODE
#include "Memmap.h"

#endif /* WITH_ERROR_HOOK */

/* End of file tpl_os_error.c */
