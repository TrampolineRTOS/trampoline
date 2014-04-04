/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline notification header.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_NOTIFICATION_H
#define TPL_OS_NOTIFICATION_H

#include "tpl_com_base_mo.h"

/**
 * @typedef tpl_setflag_func
 *
 * This type is used for various
 * setflag function type in Trampoline/COM.
 */
typedef void (*tpl_setflag_func)(void);

/*!
 *  \brief  flag action structure
 *
 *  The action function pointer is directly used to store the
 *  flag setting function.
 */
struct TPL_FLAG_ACTION {
    /*  base action           */
    tpl_action          b_desc;
    /*  set flag function pointer   */
    tpl_setflag_func    setflag;
};

typedef struct TPL_FLAG_ACTION
tpl_flag_action;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_action_setflag(
  CONSTP2CONST(tpl_action, AUTOMATIC, OS_CONST) action);

FUNC(void, OS_CODE) tpl_notify_receiving_mos(CONST(uint8, AUTOMATIC) from);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /*  TPL_OS_NOTIFICATION_H  */

/* End of file tpl_os_notification.h */
