/*
 *  @file tpl_os_dispatch_table.c
 *
 * @section desc File description
 *
 * Trampoline dispatch table implementation for system call version
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
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

#include "tpl_os_dispatch_table.h"

/* task services */
#include "tpl_os_task_kernel.h"
/* interrupt services */
#include "tpl_os_it_kernel.h"
/* resources services */
#include "tpl_os_rez_kernel.h"
/* event services */
#include "tpl_os_event_kernel.h"
/* alarm services */
#include "tpl_os_alarm_kernel.h"
/* os services */
#include "tpl_os_kernel.h"
/* isr services */
#include "tpl_os_it_kernel.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONST(tpl_system_call, OS_CONST) tpl_dispatch_table[OS_SYSCALL_COUNT] = {
/* task services */
    (tpl_system_call) tpl_activate_task_service,
    (tpl_system_call) tpl_terminate_task_service,
    (tpl_system_call) tpl_chain_task_service,
    (tpl_system_call) tpl_schedule_service,
    (tpl_system_call) tpl_get_task_id_service,
    (tpl_system_call) tpl_get_task_state_service,
/* interrupt services */
    (tpl_system_call) tpl_enable_all_interrupts_service,
    (tpl_system_call) tpl_disable_all_interrupts_service,
    (tpl_system_call) tpl_resume_all_interrupts_service,
    (tpl_system_call) tpl_suspend_all_interrupts_service,
    (tpl_system_call) tpl_resume_os_interrupts_service,
    (tpl_system_call) tpl_suspend_os_interrupts_service,
/* resources services */
    (tpl_system_call) tpl_get_resource_service,
    (tpl_system_call) tpl_release_resource_service,
/* event services */
    (tpl_system_call) tpl_set_event_service,
    (tpl_system_call) tpl_clear_event_service,
    (tpl_system_call) tpl_get_event_service,
    (tpl_system_call) tpl_wait_event_service,
/* alarm services */
    (tpl_system_call) tpl_get_alarm_base_service,
    (tpl_system_call) tpl_get_alarm_service,
    (tpl_system_call) tpl_set_rel_alarm_service,
    (tpl_system_call) tpl_set_abs_alarm_service,
    (tpl_system_call) tpl_cancel_alarm_service,
/* os services */
    (tpl_system_call) tpl_get_active_application_mode_service,
    (tpl_system_call) tpl_start_os_service,
    (tpl_system_call) tpl_shutdown_os_service,
/* isr services */
    (tpl_system_call) tpl_terminate_isr2_service
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/* End of file tpl_os_dispatch_table.c */
