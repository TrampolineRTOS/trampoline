/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Communication Filters header
 *
 * $Date: 2005-04-07 15:20:19 +0200 (Thu, 07 Apr 2005) $
 * $Rev$
 * $Author: jlb $
 * $URL: http://localhost:8888/Trampoline/svn/tpl_com_filters.h $
 */

#ifndef TPL_COM_FILTERS_H
#define TPL_COM_FILTERS_H

#include "tpl_com_filtering.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_bool, OS_CODE) tpl_filter_always(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) old_value,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_never(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) old_value,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_one_every_n(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) old_value,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) new_value);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif
