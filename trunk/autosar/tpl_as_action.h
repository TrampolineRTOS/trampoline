/**
 * @file tpl_as_action.h
 *
 * @section descr File description
 *
 * Trampoline autosar extension. extra action to increment
 * a counter. Header
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
 *
 */

#ifndef TPL_AS_ACTION_H
#define TPL_AS_ACTION_H

#include "tpl_os_internal_types.h"

/*!
 *  \brief  Increment counter action structure
 *
 *  This structure add a pointer to a counter to the base action
 *  structure.
 */
struct TPL_INCREMENT_COUNTER_ACTION {
    /*  base action           */
    tpl_action          b_desc;
    /*  callback function pointer   */
    tpl_counter         *counter;
};

typedef struct TPL_INCREMENT_COUNTER_ACTION
tpl_increment_counter_action;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Notification function prototype
 */
tpl_status tpl_action_increment_counter(const tpl_action *action);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_AS_ACTION_H */
#endif

/* End of file tpl_as_action.h */
