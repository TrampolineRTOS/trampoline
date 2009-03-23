/**
 * @file tpl_os_errorhook.h
 *
 * @section descr File description
 *
 * Trampoline Error hook function header
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
 */

#ifndef TPL_OS_ERRORHOOK_H
#define TPL_OS_ERRORHOOK_H

#include "tpl_os_types.h"

/*
 * Remember (see "The design of Trampoline") :
 * NO_TASK means there is no task defined in the system
 * OS_EXTENDED means extended error checking is done
 * WITH_ERROR_HOOK means an error hook routine is called when
 * an error occurs.
 */

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

#ifdef WITH_ERROR_HOOK

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

#endif

#endif /* TPL_OS_ERRORHOOK_H */

/* End of file tpl_os_errorhook.h */
