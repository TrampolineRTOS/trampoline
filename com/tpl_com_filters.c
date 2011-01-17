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
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) old_value,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) new_value)
{
  return TRUE;
}

FUNC(tpl_bool, OS_CODE) tpl_filter_never(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) old_value,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) new_value)
{
  return FALSE;
}

FUNC(tpl_bool, OS_CODE) tpl_filter_one_every_n(
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CODE) fd,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) old_value,
  CONSTP2CONST(void, AUTOMATIC, OS_VAR) new_value)
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
