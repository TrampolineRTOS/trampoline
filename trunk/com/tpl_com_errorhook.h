/**
 * @file tpl_com_errorhook.h
 *
 * @section descr File description
 *
 * Trampoline COM Error hook function header
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
 * $Date: 2009-02-18 14:14:39 +0100 (Mer, 18 fév 2009) $
 * $Rev: 577 $
 * $Author: jlb $
 * $URL: https://trampoline.rts-software.org/svn/trunk/os/tpl_com_errorhook.h $
 */

#ifndef TPL_COM_ERRORHOOK_H
#define TPL_COM_ERRORHOOK_H

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
FUNC(void, OS_CODE) tpl_call_com_error_hook(
	CONST(tpl_status, AUTOMATIC) error);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#if WITH_COM_ERROR_HOOK == YES

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * The function corresponding to this prototype should be provided
 * by the application
 */
extern FUNC(void, OS_CODE) COMErrorHook(VAR(StatusType, AUTOMATIC) error);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif

#endif /* TPL_COM_ERRORHOOK_H */

/* End of file tpl_os_errorhook.h */
