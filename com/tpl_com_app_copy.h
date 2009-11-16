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
#include "tpl_com_base_mo.h"

FUNC(tpl_status, OS_CODE) tpl_copy_from_unqueued(
  P2VAR(tpl_com_data, AUTOMATIC, OS_APPL_DATA)  data,
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       rmo);

tpl_status tpl_copy_from_queued(
  P2VAR(tpl_com_data, AUTOMATIC, OS_APPL_DATA)  data,
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       rmo);

#endif
/*  __TPL_COM_APP_COPY_H__   */
