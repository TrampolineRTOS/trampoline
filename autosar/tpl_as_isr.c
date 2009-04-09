/**
 * @file tpl_as_isr.c
 *
 * @internal
 *
 * @section desc File description
 *
 * Trampoline autosar extension software ISR implementation
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

#include "tpl_as_isr.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_kernel.h"
#include "tpl_as_error.h"
#include "tpl_os_definitions.h"
#include "tpl_as_isr_kernel.h"
#include "tpl_machine_interface.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Get the ID of the currently running ISR.
 *
 * It returns the identifier of the currently running ISR
 * or INVALID_ISR when called from outside a running ISR.
 *
 * see paragraph 8.4.2 page 51 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
FUNC(ISRType, OS_CODE) GetISRID(void)
{
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_get_isr_id_service();
#endif
}

/**
 * Disables the specified ISR
 *
 * see §8.4.20 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) DisableInterruptSource (VAR(ISRType, AUTOMATIC) isr_id)
{
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_disable_interrupt_source_service(isr_id);
#endif
}

/**
 * Enables the specified ISR
 *
 * see §8.4.21 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) EnableInterruptSource (VAR(ISRType, AUTOMATIC) isr_id)
{
#ifdef WITH_SYSTEM_CALL
#else
    return tpl_enable_interrupt_source_service(isr_id);
#endif
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_isr.c */
