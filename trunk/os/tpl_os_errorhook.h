/**
 * @file tpl_os_errorhook.h
 *
 * @section descr File description
 *
 * Trampoline Error hook function header
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

#ifndef TPL_OS_ERRORHOOK_H
#define TPL_OS_ERRORHOOK_H

#include "tpl_os_types.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * this function is used to call the ErrorHook callback
 *
 * @param tpl_status The error code which causes the call back
 */
FUNC(void, OS_CODE) tpl_call_error_hook(
    CONST(tpl_status, AUTOMATIC) error);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#if WITH_ERROR_HOOK == YES

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * The function corresponding to this prototype should be provided
 * by the application
 */
extern FUNC(void, OS_CODE) ErrorHook(
    VAR(StatusType, AUTOMATIC) error);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_ERROR_HOOK */

#endif /* TPL_OS_ERRORHOOK_H */

/* End of file tpl_os_errorhook.h */
