/**
 * @file tpl_as_counter.h
 *
 * @section desc File description
 *
 * Trampoline autosar extension software counters API
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
#ifndef TPL_AS_COUNTER_H
#define TPL_AS_COUNTER_H

#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_types.h"

/**
 * @typedef CounterType
 *
 * A counter identifier.
 *
 * see paragraph 8.3.13, page 50 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
typedef tpl_counter_id  CounterType;

/**
 * @def Declare a counter
 *
 * Defines a counter
 *
 */
#define DeclareCounter(counter_id)  \
  extern CONST(CounterType, AUTOMATIC) counter_id

/* TPL_AS_COUNTER_H */
#endif

/* End of file tpl_as_counter.h */
