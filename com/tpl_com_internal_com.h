/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline internal communication functions declarations.
 * These functions are attached to the message object.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */
 
#ifndef __TPL_COM_INTERNAL_COM__
#define __TPL_COM_INTERNAL_COM__

#include "tpl_com_mo.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_status, OS_CODE) tpl_send_static_internal_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       smo,
  CONSTP2CONST(tpl_com_data, AUTOMATIC, OS_VAR) data);

FUNC(tpl_status, OS_CODE) tpl_send_zero_internal_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       smo,
  CONSTP2CONST(tpl_com_data, AUTOMATIC, OS_VAR) data);

FUNC(tpl_status, OS_CODE) tpl_receive_static_internal_unqueued_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       rmo,
  CONSTP2CONST(tpl_com_data, AUTOMATIC, OS_VAR) data);

FUNC(tpl_status, OS_CODE) tpl_receive_static_internal_queued_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       rmo,
  CONSTP2CONST(tpl_com_data, AUTOMATIC, OS_VAR) data);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif
/* __TPL_COM_INTERNAL_COM__ */
