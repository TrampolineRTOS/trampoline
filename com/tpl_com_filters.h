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

#ifndef __TPL_COM_FILTERS_H__
#define __TPL_COM_FILTERS_H__

#include "tpl_com_filtering.h"

tpl_bool tpl_filter_always(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_never(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_masked_new_equals_x(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_masked_new_differs_x(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_new_is_equal(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_new_is_different(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_masked_new_equals_masked_old(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_masked_new_differs_masked_old(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_new_is_within(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_new_is_outside(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_new_is_greater(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_new_is_less_or_equal(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_new_is_less(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_new_is_greater_or_equal(tpl_filter_desc *, tpl_com_value, tpl_com_value);
tpl_bool tpl_filter_one_every_n(tpl_filter_desc *, tpl_com_value, tpl_com_value);

#endif
