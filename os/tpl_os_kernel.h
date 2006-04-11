/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline kernel structures header file
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#ifndef __TPL_OS_KERNEL_H__
#define __TPL_OS_KERNEL_H__

#include "tpl_os_internal_types.h"
#include "tpl_os_interrupts.h"
#include "tpl_os_application_def.h"

#define INVALID_TASK    (-1)

/*
 * State of the OS
 */
#define OS_INIT 0
#define OS_TASK 1
#define OS_IDLE 2
#define OS_ISR2 3

/*
 * Globals of the OS
 */
/*extern tpl_status       tpl_last_result; */
extern tpl_exec_common  *tpl_running_obj;
extern tpl_exec_common  *tpl_exec_obj_list_head;

#ifndef NO_TASK
/*
 * While it would be less time consuming to
 * refer a task by a pointer to its descriptor
 * the OSEK API requires a task to have an
 * identifier. So a table of pointer
 * is used. The size of this table is static
 * and known at compile time
 */
extern tpl_task         *tpl_task_table[TASK_COUNT];
#endif

#ifndef NO_RESOURCE
/*
 * the same remark is true for resources
 * so a resource table is used to store
 * them.
 */
extern tpl_resource     *tpl_resource_table[RES_COUNT];
#endif

#ifndef NO_ALARM
/*
 * same for alarms
 */
extern tpl_alarm        *tpl_alarm_table[ALARM_COUNT];
#endif

#ifndef NO_ISR
/*
 * and for ISR2
 */
extern tpl_isr			*tpl_isr_table[ISR_COUNT];
#endif

extern unsigned char    tpl_os_state;

/*
 * Locking the kernel
 * unused
 */
extern tpl_lock         *TASK_LOCK;

#endif
