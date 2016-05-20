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
 * $Date: 2010-04-02 15:58:24 -0500 (ven. 02 avril 2010) $
 * $Rev: 1123 $
 * $Author: jlb $
 * $URL: https://trampoline.rts-software.org/svn/trunk/os/tpl_os_errorhook.h $
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
