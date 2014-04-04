/**
 * @file tpl_com_errorhook.c
 *
 * @section desc File description
 *
 * Trampoline COM Error
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date: 2009-03-04 09:55:20 +0100 (Mer, 04 mar 2009) $
 * $Rev: 620 $
 * $Author: fp $
 * $URL: https://trampoline.rts-software.org/svn/trunk/os/tpl_com_errorhook.c $
 */

#include "tpl_com_errorhook.h"
#include "tpl_com_error.h"

#include "tpl_os_internal_types.h"

#include "tpl_os_definitions.h"
#include "tpl_com.h"

#if WITH_COM_ERROR_HOOK == YES

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_com_service_call_descriptor, OS_VAR) tpl_com_service;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * Function used to call the COM application error hook
 *
 * @param error error code which raised the hook call
 *
 * Do not call it directly, use #PROCESS_ERROR macro
 *
 * @see #PROCESS_ERROR
 */
FUNC(void, OS_CODE) tpl_call_com_error_hook(
	CONST(tpl_status, AUTOMATIC) error)
{
	
	/**
	 * This flag is used to avoid error hook call recursion
	 */
    tpl_bool in_com_error_hook = FALSE;
	
    if (!in_com_error_hook)
    {
        in_com_error_hook = TRUE;
        COMErrorHook(error);
        in_com_error_hook = FALSE;
    }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_COM_ERROR_HOOK */

/* End of file tpl_com_errorhook.c */
