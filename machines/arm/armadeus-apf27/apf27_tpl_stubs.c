/**
 * @file apf27_tpl_stubs.c
 *
 * @section descr File description
 *
 * ARMADEUS platform specific routines and variables
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */
#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_definitions.h"
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"
#endif /* WITH_AUTOSAR */

#ifdef WITH_MEMORY_PROTECTION
#include "apf27_mem_prot.h"
#endif /* WITH_MEMORY_PROTECTION */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

struct ARM_CONTEXT idle_task_context;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern int main (void);

FUNC(void, OS_CODE) tpl_shutdown ()
{
	/* FIXME: this is does not conform to AUTOSAR OS specifications,
	 * should return to main with initial context */
	DISABLE_FIQ ();
	DISABLE_IRQ ();

	/* fall into very low consumption mode : all
	 * internal CPU clocks are disabled.
	 */
	/* TODO armadeus_system_standby (); */

	while (1);
}

extern void tpl_init_machine_generic (void);

FUNC(void, OS_CODE) tpl_init_machine()
{
	/* TODO armadeus_int_ctrl_setup_defaults ();*/

	/* TODO armadeus_disable_all_devices ();*/

	/* TODO armadeus_setup_heartbeat_timer_1ms ();*/

	tpl_init_mp();

	tpl_init_machine_generic ();

	/* TODO armadeus_heartbeat_timer_start ();*/
}

FUNC(void, OS_CODE) tpl_arm_subarch_irq_handler ()
{
	/* TODO */
//	u32 interrupt_source;
//	u16 isr_id;

//	interrupt_source = armadeus_get_interrupt_source ();
//	switch (interrupt_source)
//	{
//		case SYSTEM_TIMER_INT_SOURCE:
//		armadeus_heartbeat_timer_ack ();
//		/* TODO: call counter heartbeat */
//		/* TODO: increment local time (watchdogs) */
//		break;
//#ifndef NO_ISR
//		default:
//		isr_id = armadeus_isr_by_src[interrupt_source];
//		tpl_central_interrupt_handler(isr_id);
//#endif /* !defined NO_ISR */
//	}

	/* acknoledge interrupt */
//	armadeus_acknoledge_current_irq_level ();
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#ifdef WITH_AUTOSAR

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_bool, OS_VAR) tpl_user_task_lock = FALSE;
VAR(u32, OS_VAR) tpl_cpt_user_task_lock = 0;
//STATIC VAR(u32, OS_VAR) tpl_cpt_os_task_lock = 0;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(tpl_bool, OS_CODE) tpl_get_interrupt_lock_status(void)
{
    /* FIXME: to be implemented */
    VAR(tpl_bool, AUTOMATIC) result;

    /*if( (TRUE == tpl_user_task_lock) || (tpl_cpt_user_task_lock > 0) )
    {
        result = TRUE;
    }
    else
    {*/
        result = FALSE;
    //}

    return result;
}


FUNC(void, OS_CODE) tpl_reset_interrupt_lock_status(void)
{
    /* FIXME: to be implemented */
  /*tpl_user_task_lock = FALSE;

  tpl_cpt_user_task_lock = 0;

  tpl_locking_depth = tpl_cpt_os_task_lock;*/
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
#endif /* defined WITH_AUTOSAR */

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_set_watchdog (
	VAR(tpl_time, AUTOMATIC) delay)
{
	/* TODO */
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_cancel_watchdog ()
{
	/* TODO */
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(tpl_time, OS_CODE) tpl_get_local_current_date ()
{
	/* TODO delete these lines there are juste for debbug */
	VAR(tpl_time, OS_VAR) current_date;
	current_date = 0;
	return current_date;
	/* TODO */
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* defined WITH_AUTOSAR_TIMING_PROTECTION */

#ifdef WITH_AUTOSAR_STACK_MONITORING
/* FIXME : needs update (tpl_proc_static) */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 *  Check if one stack overflow have occured.
 *
 *  @param    this_exec_obj    The executable object to monitor
 *
 *  @retval    tmp    If set at one, a stack overflow is detected
 */

/* FIXME : needs update (tpl_proc_static) */

FUNC(tpl_bool, OS_CODE) tpl_check_stack_pointer (
  	CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
	VAR(tpl_bool, OS_VAR) tmp;
	/* FIXME : needs update (tpl_proc_static)
	if(this_exec_obj->static_desc->context.core_context->r[sp]<
		&(this_exec_obj->static_desc->stack))*/
	tmp=1; /*no overflow detected*/
	//else tmp=0; /*there is an overflow*/
	return tmp;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_AUTOSAR_STACK_MONITORING */

