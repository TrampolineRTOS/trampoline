/**
 * @file tpl_as_isr.c
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
/* disabled to be compilable / Jonathan ILIAS - 11 sept 2007 */
#if 0
    tpl_exec_object_type    type;
    tpl_isr_id              isr_id = INVALID_ISR;
    
    /* critical section */
    tpl_get_task_lock();
    
    type = tpl_running_obj->static_desc->type;
    
    if (type != IS_ROUTINE)
    {
        isr_id = tpl_running_obj->static_desc->id;
    }
    
    tpl_release_task_lock();
    
    return isr_id;
#else
  return 0;
#endif
}

/* End of file tpl_as_isr.c */
