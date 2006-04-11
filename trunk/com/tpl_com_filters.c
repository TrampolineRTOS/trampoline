/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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

bool tpl_filter_always(
    tpl_filter_param * /*fp*/,
    tpl_com_value /*old_value*/,
    tpl_com_value /*new_value*/)
{
    return TRUE;
}

bool tpl_filter_never(
    tpl_filter_param * /*fp*/,
    tpl_com_value /*old_value*/,
    tpl_com_value /*new_value*/)
{
    return FALSE;
}

bool tpl_filter_masked_new_equals_x(
    tpl_filter_param *fp,
    tpl_com_value /*old_value*/,
    tpl_com_value new_value)
{
    return ((new_value & fp->masked.mask) == fp->masked.x);
}

bool tpl_filter_masked_new_differs_x(
    tpl_filter_param *fp,
    tpl_com_value /*old_value*/,
    tpl_com_value new_value)
{
    return ((new_value & fp->masked.mask) != fp->masked.x);
}

bool tpl_filter_new_is_equal(
    tpl_filter_param * /*fp*/,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value == old_value);
}

bool tpl_filter_new_is_different(
    tpl_filter_param * /*fp*/,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value != old_value);
}

bool tpl_filter_masked_new_equals_masked_old(
    tpl_filter_param *fp,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return ((new_value & fp->masked.mask) == (old_value & fp->masked.mask));
}

bool tpl_filter_masked_new_differs_masked_old(
    tpl_filter_param *fp,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return ((new_value & fp->masked.mask) != (old_value & fp->masked.mask));
}

bool tpl_filter_new_is_within(
    tpl_filter_param *fp,
    tpl_com_value /*old_value*/,
    tpl_com_value new_value)
{
    return ((new_value >= fp->interval.min) && (new_value <= fp->interval.max));
}

bool tpl_filter_new_is_outside(
    tpl_filter_param *fp,
    tpl_com_value /*old_value*/,
    tpl_com_value new_value)
{
    return ((new_value < fp->interval.min) || (new_value > fp->interval.max));
}

bool tpl_filter_new_is_greater(
    tpl_filter_param * /*fp*/,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value > old_value);
}

bool tpl_filter_new_is_less_or_equal(
    tpl_filter_param * /*fp*/,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value <= old_value);
}

bool tpl_filter_new_is_less(
    tpl_filter_param * /*fp*/,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value < old_value);
}

bool tpl_filter_new_is_greater_or_equal(
    tpl_filter_param * /*fp*/,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    return (new_value >= old_value);
}

bool tpl_filter_one_every_n(
    tpl_filter_param *fp,
    tpl_com_value old_value,
    tpl_com_value new_value)
{
    if (fp->every.occurence == fp->every.period) {
        fp->every.occurence = 0;
        return TRUE;
    }
    else {
        ++(fp->every.occurence);
        return FALSE;
    }
}