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
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_never(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_masked_new_equals_x(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_masked_new_differs_x(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_equal(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_different(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_masked_new_equals_masked_old(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_masked_new_differs_masked_old(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_within(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_outside(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_greater(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_less_or_equal(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_less(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_greater_or_equal(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

FUNC(tpl_bool, OS_CODE) tpl_filter_one_every_n(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif
