/**
 * @file tpl_as_isr.h
 *
 * @section desc File description
 *
 * Trampoline autosar extension software ISR API
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
 
#ifndef TPL_AS_ISR_H
#define TPL_AS_ISR_H

#include "tpl_os_types.h"
#include "tpl_os_custom_types.h"

/**
 * @def INVALID_ISR
 *
 * value returned by GetISRID when the currently running object
 * is not an ISR 2
 */
#define INVALID_ISR (-1)

/**
 * @typedef ISRType
 *
 * An ISR identifier.
 *
 * see paragraph 8.3.9, page 49 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
typedef tpl_isr_id  ISRType;

/**
 * Get the ID of the currently running ISR.
 *
 * @retval Identifier of the currently running ISR
 * @retval INVALID_ISR when called from outside a running ISR.
 *
 * see paragraph 8.4.2 page 51 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
ISRType GetISRID(void);

/**
 * Disables the specified ISR
 *
 * @param   DisableISR the ISR to disable
 *
 * @retval  E_OK no error
 * @retval  E_OS_ID isr_id is not a valid ISR id (only in extended error)
 *
 * see §8.4.20 of AUTOSAR/Specification of the Operating System v2.1.0
 */
StatusType DisableInterruptSource (ISRType isr_id);

/**
 * Enables the specified ISR
 *
 * @param   EnableISR the ISR to enable
 *
 * @retval  E_OK no error
 * @retval  E_OS_ID isr_id is not a valid ISR id (only in extended error)
 *
 * see §8.4.21 of AUTOSAR/Specification of the Operating System v2.1.0
 */
StatusType EnableInterruptSource (ISRType isr_id);

/* TPL_AS_ISR_H */
#endif
