/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Communication Filters
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_com_filters.h"
#include "tpl_os_definitions.h"
#include <stdio.h>

tpl_bool tpl_filter_always(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return TRUE;
}

tpl_bool tpl_filter_never(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return FALSE;
}

tpl_bool tpl_filter_masked_new_equals_x(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return ((new_value &
            ((tpl_mask_x_filter_desc *)fd)->mask)
            == ((tpl_mask_x_filter_desc *)fd)->x);
}

tpl_bool tpl_filter_masked_new_differs_x(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return ((new_value &
            ((tpl_mask_x_filter_desc *)fd)->mask)
            != ((tpl_mask_x_filter_desc *)fd)->x);
}

tpl_bool tpl_filter_new_is_equal(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value == old_value);
}

tpl_bool tpl_filter_new_is_different(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value != old_value);
}

tpl_bool tpl_filter_masked_new_equals_masked_old(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return ((new_value & ((tpl_mask_filter_desc *)fd)->mask)
            == (old_value & ((tpl_mask_filter_desc *)fd)->mask));
}

tpl_bool tpl_filter_masked_new_differs_masked_old(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return ((new_value & ((tpl_mask_filter_desc *)fd)->mask)
            != (old_value & ((tpl_mask_filter_desc *)fd)->mask));
}

tpl_bool tpl_filter_new_is_within(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
	//printf("filter_within : min = %d - max = %d - oldvalue = %d - newvalue = %d\n",(((tpl_interval_filter_desc *)fd)->min),(((tpl_interval_filter_desc *)fd)->max),old_value,new_value);
	return ((new_value >= ((tpl_interval_filter_desc *)fd)->min) &&
            (new_value <= ((tpl_interval_filter_desc *)fd)->max));
}

tpl_bool tpl_filter_new_is_outside(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    
	//printf("filter_outside : min = %d - max = %d - oldvalue = %d - newvalue = %d\n",(((tpl_interval_filter_desc *)fd)->min),(((tpl_interval_filter_desc *)fd)->max),old_value,new_value);
	return ((new_value < ((tpl_interval_filter_desc *)fd)->min) ||
            (new_value > ((tpl_interval_filter_desc *)fd)->max));
}

tpl_bool tpl_filter_new_is_greater(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value > old_value);
}

tpl_bool tpl_filter_new_is_less_or_equal(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value <= old_value);
}

tpl_bool tpl_filter_new_is_less(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value < old_value);
}

tpl_bool tpl_filter_new_is_greater_or_equal(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value >= old_value);
}

tpl_bool tpl_filter_one_every_n(
    tpl_filter_desc *fd,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    tpl_com_count *occ = ((tpl_occurence_filter_desc *)fd)->occurence;
    if (*occ == ((tpl_occurence_filter_desc *)fd)->period) {
        *occ = 0;
        return TRUE;
    }
    else {
        ++(*occ);
        return FALSE;
    }
}
