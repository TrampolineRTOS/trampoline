/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline notification implementation.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_application_def.h"
#include "tpl_os_action.h"
#include "tpl_os_kernel.h"
#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_com_base_mo.h"
#include "tpl_com_definitions.h"
#include "tpl_com_notification.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 *  action function for action set flag
 */
FUNC(void, OS_CODE) tpl_action_setflag(
  CONSTP2CONST(tpl_action, AUTOMATIC, OS_CONST) action)
{
    /*
     * A tpl_action * is cast to a tpl_callback_action *
     * This violate MISRA rule 45. However, since the
     * first member of tpl_flag_action * is a tpl_action *
     * This cast behaves correctly.
     */
    ((const tpl_flag_action *)action)->setflag();
}

/*!
 *  \brief
 *
 *
 */
FUNC(void, OS_CODE) tpl_notify_receiving_mos(
  CONST(uint8, AUTOMATIC) from)
{
  GET_CURRENT_CORE_ID(core_id)
	
#if NUMBER_OF_CORES > 1
  tpl_multi_schedule();
  tpl_dispatch_context_switch();
#endif
  if (TPL_KERN(core_id).need_schedule)
  {
    tpl_schedule_from_running(CORE_ID_OR_NOTHING(a_core_id));
#if WITH_SYSTEM_CALL == NO
    if (TPL_KERN(core_id).need_switch != NO_NEED_SWITCH)
    {
      if (from == FROM_IT_LEVEL)
      {
      SWITCH_CONTEXT(CORE_ID_OR_NOTHING(proc_core_id))
        /*tpl_switch_context_from_it(*/
          /*&(TPL_KERN(core_id).s_running->context),*/
          /*&(TPL_KERN(core_id).s_elected->context)*/
        /*);*/
      }
      else
      {
      SWITCH_CONTEXT(CORE_ID_OR_NOTHING(proc_core_id))
        /*tpl_switch_context(*/
          /*&(TPL_KERN(core_id).s_running->context),*/
          /*&(TPL_KERN(core_id).s_elected->context)*/
        /*);*/
      }
    }
#endif
  }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_com_notification.c */
