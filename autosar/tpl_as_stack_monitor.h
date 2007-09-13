/**
 * @file tpl_as_stack_monitor.h
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
#ifndef TPL_AS_STACK_MONITOR_H
#define TPL_AS_STACK_MONITOR_H_

#include "tpl_machine_interface.h"
#include "tpl_as_protec_hook.h"

/**
 * @def SCALABILITY_CLASS
 * 
 * @todo to be defined by GOIL
 */
#define SCALABILITY_CLASS 2

void tpl_check_stack (tpl_exec_common *this_exec_obj);

#endif /* TPL_AS_STACK_MONITOR_H */
