/**
 * @file tpl_as_protec_hook.h
 *
 * @section desc File description
 *
 * Trampoline AUTOSAR's protection hook module
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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
#ifndef TPL_AS_PROTEC_HOOK_H
#define TPL_AS_PROTEC_HOOK_H

#include "tpl_os_application_def.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_types.h"
#include "tpl_as_definitions.h"

/**
 * @typedef ProtectionReturnType
 *
 * Defines what to do after returning from ProtectionHook.
 *
 * See paragraph 8.3.15 of AUTOSAR OS SWS 2.1
 */
typedef enum
{
  PRO_IGNORE,                 /**< do nothing */
  PRO_TERMINATETASKISR,       /**< terminate the faulty task or ISR2 */
  PRO_TERMINATEAPPL,          /**< terminate the faulty application */
  PRO_TERMINATEAPPL_RESTART,  /**< terminate and restart the faulty application */
  PRO_SHUTDOWN                /**< shutdown the OS */
} ProtectionReturnType;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#if WITH_PROTECTION_HOOK == YES
/**
 * User protection hook callback function.
 *
 * @param FatalError the kind of error
 *
 * @return what to do after this error
 *
 * see paragraph 8.5.1 of AUTOSAR OS SWS 2.1.0
 */
extern FUNC(ProtectionReturnType, OS_CODE) ProtectionHook (
    VAR(StatusType, AUTOMATIC) FatalError);
#endif /* WITH_PROTECTION_HOOK */

/**
 * @internal
 *
 * This function wraps the call to the protection hook (if it exists). Also,
 * it does what is required to do according to what the ProtectionHook
 * returns.
 *
 * If no ProtectionHook function is defined, the default action is to kill
 * the current task or ISR2
 *
 * @param error the error to send to the ProtectionHook function
 *
 * @see #ProtectionHook
 */
extern FUNC(void, OS_CODE) tpl_call_protection_hook (
    VAR(tpl_status, AUTOMATIC) error);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_AS_PROTEC_HOOK_H */
