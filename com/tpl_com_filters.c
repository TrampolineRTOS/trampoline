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

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_bool, OS_CODE) tpl_filter_always(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return TRUE;
}

FUNC(tpl_bool, OS_CODE) tpl_filter_never(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return FALSE;
}

FUNC(tpl_bool, OS_CODE) tpl_filter_masked_new_equals_x(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return (tpl_bool)((new_value &
          ((tpl_mask_x_filter_desc *)fd)->mask)
          == ((tpl_mask_x_filter_desc *)fd)->x);
}

FUNC(tpl_bool, OS_CODE) tpl_filter_masked_new_differs_x(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return (tpl_bool)((new_value &
          ((tpl_mask_x_filter_desc *)fd)->mask)
          != ((tpl_mask_x_filter_desc *)fd)->x);
}

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_equal(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return (tpl_bool)(new_value == old_value);
}

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_different(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return (tpl_bool)(new_value != old_value);
}

FUNC(tpl_bool, OS_CODE) tpl_filter_masked_new_equals_masked_old(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return (tpl_bool)((new_value & ((tpl_mask_filter_desc *)fd)->mask)
          == (old_value & ((tpl_mask_filter_desc *)fd)->mask));
}

FUNC(tpl_bool, OS_CODE) tpl_filter_masked_new_differs_masked_old(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return (tpl_bool)((new_value & ((tpl_mask_filter_desc *)fd)->mask)
          != (old_value & ((tpl_mask_filter_desc *)fd)->mask));
}

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_within(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
	return (tpl_bool)((new_value >= ((tpl_interval_filter_desc *)fd)->min) &&
            (new_value <= ((tpl_interval_filter_desc *)fd)->max));
}

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_outside(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
    
	return (tpl_bool)((new_value < ((tpl_interval_filter_desc *)fd)->min) ||
            (new_value > ((tpl_interval_filter_desc *)fd)->max));
}

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_greater(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return (tpl_bool)(new_value > old_value);
}

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_less_or_equal(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return (tpl_bool)(new_value <= old_value);
}

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_less(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return (tpl_bool)(new_value < old_value);
}

FUNC(tpl_bool, OS_CODE) tpl_filter_new_is_greater_or_equal(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
  return (tpl_bool)(new_value >= old_value);
}

FUNC(tpl_bool, OS_CODE) tpl_filter_one_every_n(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONST(tpl_com_value, AUTOMATIC) old_value,
  CONST(tpl_com_value, AUTOMATIC) new_value)
{
	VAR(tpl_bool, AUTOMATIC) b_temp = FALSE;
	CONSTP2VAR(tpl_com_count, AUTOMATIC, OS_VAR)
  occ = ((tpl_occurence_filter_desc *)fd)->occurence;

	if (*occ < ( ((tpl_occurence_filter_desc *)fd)->period + ((tpl_occurence_filter_desc *)fd)->offset ) )
	{
		++(*occ);
		b_temp = FALSE;
	}
	else {
		if (*occ == ( ((tpl_occurence_filter_desc *)fd)->period + ((tpl_occurence_filter_desc *)fd)->offset) )
		{
			b_temp = TRUE;
		}
		else
		{
			b_temp = FALSE;
		}
		*occ = ((tpl_occurence_filter_desc *)fd)->offset;
	}
	return b_temp;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_com_filters.h */
