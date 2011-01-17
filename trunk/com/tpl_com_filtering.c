/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline filtering machinery implementation.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_com_filtering.h"
#include "tpl_os_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * tpl_filtering handles the filtering of messages.
 * It takes two data pointers (new_data and old_data),
 * If the check failed, tpl_filtering returns TRUE
 */
tpl_bool tpl_filtering(
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR)            old_data,
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR)            new_data,
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CONST)  filter_desc)
{
  
  /*  Checks there is a filter set */
  if ((filter_desc != NULL) && (filter_desc->filter != NULL)) {
    /*  Checks the data is compatible with filter. Size have
        to be less or equal than the tpl_com_value data size    */
    /*  Call the filter */
    return filter_desc->filter(filter_desc, old_data, new_data);
  }
  return TRUE;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

