/**
 * @file tpl_com_message_kernel.h
 *
 * @section descr File description
 *
 * Communication services
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date:$
 * $Rev:$
 * $Author:$
 * $URL:$
 */

#ifndef TPL_COM_MESSAGE_KERNEL_H
#define TPL_COM_MESSAGE_KERNEL_H

#include "tpl_com_types.h"
#include "tpl_compiler.h"
#include "tpl_os_internal_types.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
extern void tpl_get_task_lock(void);
extern void tpl_release_task_lock(void);

FUNC(tpl_status, OS_CODE) tpl_get_message_status_service(
  CONST(tpl_message_id, AUTOMATIC) mess_id);

FUNC(tpl_status, OS_CODE) tpl_send_message_service(
  CONST(tpl_message_id, AUTOMATIC)   mess_id,
  CONSTP2CONST(void, AUTOMATIC, OS_APPL_DATA)  data);

FUNC(tpl_status, OS_CODE) tpl_receive_message_service(
  CONST(tpl_message_id, AUTOMATIC)  mess_id,
  CONSTP2VAR(void, AUTOMATIC, OS_APPL_DATA) data);

FUNC(tpl_status, OS_CODE) tpl_send_zero_message_service(
  CONST(tpl_message_id, AUTOMATIC) mess_id);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_COM_MESSAGE_KERNEL_H */
#endif

/* End of file tpl_com_message_kernel.h */
