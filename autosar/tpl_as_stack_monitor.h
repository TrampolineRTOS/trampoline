/**
 * @file tpl_as_stack_monitor.h
 *
 * @section desc File description
 *
 * Trampoline stack monitoring. This is an AUTOSAR specific module.
 * See paragraph 7.4 of AUTOSAR OS Specifications v2.1.
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
#ifndef TPL_AS_STACK_MONITOR_H
#define TPL_AS_STACK_MONITOR_H_

#include "tpl_as_protec_hook.h"
#include "tpl_machine_interface.h"

/**
 * @def SCALABILITY_CLASS
 *
 * @todo to be defined by GOIL
 */
#ifndef SCALABILITY_CLASS
#define SCALABILITY_CLASS 2
#endif /* !defined SCALABILITY_CLASS */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * Do the stack monitoring checkings for the specified executable object and
 * call the #ProtectionHook if required.
 *
 * @param tpl_proc_id the id of the executable object to monitor
 *
 * @see #ProtectionHook
 */
FUNC(void, OS_CODE) tpl_check_stack(CONST(tpl_proc_id, AUTOMATIC) proc_id);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_AS_STACK_MONITOR_H */
