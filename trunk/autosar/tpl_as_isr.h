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
#include "tpl_as_isr_definitions.h"
/*#include "tpl_as_protec_hook.h"*/

/**
 * @typedef ISRType
 *
 * An ISR identifier.
 *
 * see paragraph 8.3.9, page 49 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
typedef tpl_isr_id  ISRType;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @def DeclareISR
 *
 * Defines an ISR
 *
 * @param isr_id ISR's C identifier
 *
 */
#define DeclareISR(isr_id)  \
extern CONST(ISRType, AUTOMATIC) isr_id

/**
 * Get the ID of the currently running ISR.
 *
 * @retval Identifier of the currently running ISR
 * @retval INVALID_ISR when called from outside a running ISR.
 *
 * see paragraph 8.4.2 page 51 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
FUNC(ISRType, OS_CODE) GetISRID(void);

/**
 * Disables the specified ISR
 *
 * @param   DisableISR the ISR to disable
 *
 * @retval  E_OK no error
 * @retval  E_OS_ID isr_id is not a valid ISR id (only in extended error)
 *
 * see ß8.4.20 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) DisableInterruptSource (VAR(ISRType, AUTOMATIC) isr_id);

/**
 * Enables the specified ISR
 *
 * @param   EnableISR the ISR to enable
 *
 * @retval  E_OK no error
 * @retval  E_OS_ID isr_id is not a valid ISR id (only in extended error)
 *
 * see ß8.4.21 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) EnableInterruptSource (VAR(ISRType, AUTOMATIC) isr_id);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_AS_ISR_H */
#endif

/* End of file tpl_as_isr.h */
