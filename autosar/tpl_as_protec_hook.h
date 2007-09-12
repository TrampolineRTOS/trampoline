/**
 * @file tpl_as_protec_hook.h
 *
 * @section desc File description
 *
 * @todo: finish documentation
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

/**
 * @def E_OS_PROTECTION_TIME
 * 
 * A task exeeded its execution budget or an ISR2 exeeded its
 * exection time.
 * 
 * see §7.10 of autosar OS SWS 2.1
 */
#define E_OS_PROTECTION_TIME 32 /* FIXME: how values are allocated ? */

/**
 * @def E_OS_PROTECTION_LOCKED
 * 
 * A Task/Category 2 ISR blocks for too long
 * 
 * see §7.10 of autosar OS SWS 2.1 
 */
#define E_OS_PROTECTION_LOCKED 33 /* FIXME: how values are allocated ? */

typedef enum 
{
  PRO_KILLTASKISR,
  PRO_KILLAPPL,
  PRO_KILLAPPL_RESTART,
  PRO_SHUTDOWN
} ProtectionReturnType;

#ifdef WITH_PROTECTION_HOOK
/**
 * User protection hook callback function.
 * 
 * @todo finish documentation
 * 
 * see §8.5.1 of AUTOSAR OS SWS 2.1.0
 */
extern ProtectionReturnType ProtectionHook (tpl_status FatalError);
#endif /* WITH_PROTECTION_HOOK */

/**
 * @todo
 */
extern void tpl_call_protection_hook (tpl_status error);

#endif /* TPL_AS_PROTEC_HOOK_H */
