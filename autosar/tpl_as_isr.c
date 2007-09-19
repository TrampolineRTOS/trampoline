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
ISRType GetISRID(void)
{
    tpl_exec_common     *ro = tpl_running_obj;
    tpl_isr_id          isr_id = (tpl_isr_id)INVALID_ISR;
        
    if (tpl_running_obj->static_desc->type != IS_ROUTINE)
    {
        isr_id = ro->static_desc->id;
    }
    
    return isr_id;
}

/**
 * Disables the specified ISR
 *
 * see §8.4.20 of AUTOSAR/Specification of the Operating System v2.1.0
 */
StatusType DisableInterruptSource (ISRType isr_id)
{
    StatusType  result = E_OK;

#ifndef NO_ISR
    tpl_isr *isr;
#endif

    CHECK_ISR_ID_ERROR(isr_id,result)

#ifndef NO_ISR
    IF_NO_EXTENDED_ERROR(result)
        /* get the isr */
        isr = tpl_isr_table[isr_id];
        tpl_disable_isr2_by_user (isr);
    IF_NO_EXTENDED_ERROR_END()
#endif    

    return result;
}

/**
 * Enables the specified ISR
 *
 * see §8.4.21 of AUTOSAR/Specification of the Operating System v2.1.0
 */
StatusType EnableInterruptSource (ISRType isr_id)
{
    StatusType  result = E_OK;

#ifndef NO_ISR
    tpl_isr *isr;
#endif

    CHECK_ISR_ID_ERROR(isr_id,result)

#ifndef NO_ISR
    IF_NO_EXTENDED_ERROR(result)
        /* get the isr */
        isr = tpl_isr_table[isr_id];
        tpl_enable_isr2_by_user (isr);
    IF_NO_EXTENDED_ERROR_END()
#endif    

    return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_isr.c */
