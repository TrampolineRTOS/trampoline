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

/**
 * @def E_OS_PROTECTION_TIME
 * 
 * A task exeeded its execution budget or an ISR2 exeeded its
 * exection time.
 * 
 * see §7.10 of autosar OS SWS 2.1
 *
 * @see #ProtectionHook
 */
#define E_OS_PROTECTION_TIME 32

/**
 * @def E_OS_PROTECTION_LOCKED
 * 
 * A Task/Category 2 ISR blocks for too long
 * 
 * see §7.10 of autosar OS SWS 2.1 
 *
 * @see #ProtectionHook
 */
#define E_OS_PROTECTION_LOCKED 33

/**
 * @def E_OS_STACKFAULT
 * 
 * A stackfault occurred (see §7.4 of AUTOSAR OS SWS 2.1)
 *
 * @see #ProtectionHook
 */
#define E_OS_STACKFAULT 34

/**
 * @typedef ProtectionReturnType
 *
 * Defines what to do after returning from ProtectionHook.
 *
 * See paragraph 8.3.15 of AUTOSAR OS SWS 2.1
 */
typedef enum 
{
  PRO_KILLTASKISR,      /**< kill the faulty task or ISR2 */
  PRO_KILLAPPL,         /**< kill the faulty application */
  PRO_KILLAPPL_RESTART, /**< kill and restart the faulty application */
  PRO_SHUTDOWN          /**< shutdown the OS */
} ProtectionReturnType;

#ifdef WITH_PROTECTION_HOOK
/**
 * User protection hook callback function.
 *
 * @param FatalError the kind of error
 *
 * @return what to do after this error
 *
 * see §8.5.1 of AUTOSAR OS SWS 2.1.0
 */
extern ProtectionReturnType ProtectionHook (StatusType FatalError);
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
extern void tpl_call_protection_hook (tpl_status error);

#endif /* TPL_AS_PROTEC_HOOK_H */
