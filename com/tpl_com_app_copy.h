/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline application receiving functions header
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_APP_COPY_H__
#define __TPL_COM_APP_COPY_H__

#include "tpl_os_types.h"
#include "tpl_com_mo.h"

tpl_status tpl_copy_from_unqueued( tpl_com_data *, tpl_base_receiving_mo *);

tpl_status tpl_copy_from_queued(tpl_com_data *, tpl_base_receiving_mo *);

#endif
/*  __TPL_COM_APP_COPY_H__   */
