/**
 * @file tpl_os_error.c
 *
 * @section descr File description
 *
 * Trampoline Errors macros, functions and datatypes header
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
 *
 */

#include "tpl_os_errorhook.h"
#include "tpl_os_error.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"
#include "tpl_os_multicore_macros.h"
#include "tpl_os_kernel.h"


#if WITH_ORTI == YES

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

# if NUMBER_OF_CORES > 1
VAR(tpl_status, OS_VAR) tpl_last_error[NUMBER_OF_CORES];
# else
VAR(tpl_status, OS_VAR) tpl_last_error = 0;
# endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#endif

#if WITH_ERROR_HOOK == YES

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_service_call_desc, OS_VAR) tpl_service;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * Function used to call the application error hook
 *
 * @param error error code which raised the hook call
 *
 * Do not call it directly, use #PROCESS_ERROR macro
 *
 * @see #PROCESS_ERROR
 */
FUNC(void, OS_CODE) tpl_call_error_hook(
    CONST(tpl_status, AUTOMATIC) error)
{
    GET_CURRENT_CORE_ID(core_id)
    GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
/**
 * This flag is used to avoid error hook call recursion
 */
    STATIC VAR(tpl_bool, AUTOMATIC) in_error_hook = FALSE;

    if (!in_error_hook)
    {
#if WITH_MEMORY_PROTECTION == YES
        TPL_KERN_REF(kern).running_trusted = 1;
#endif /* WITH_MEMORY_PROTECTION == YES */
        in_error_hook = TRUE;
        ErrorHook(error);
#if WITH_MEMORY_PROTECTION == YES
        TPL_KERN_REF(kern).running_trusted = 0;
#endif /* WITH_MEMORY_PROTECTION == YES */
        in_error_hook = FALSE;
    }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_ERROR_HOOK */

/* End of file tpl_os_error.c */
