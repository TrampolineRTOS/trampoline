/**
 * @file tpl_as_trusted_fct_kernel.h
 *
 * @section desc File description
 *
 * Trampoline AUTOSAR's trusted fonction header
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_AS_TRUSTED_FCT_KERNEL_H
#define TPL_AS_TRUSTED_FCT_KERNEL_H

#include "tpl_os_internal_types.h" 

typedef P2FUNC(void, OS_APPL_CODE, tpl_trusted_fct)(
  CONST(tpl_tf_id, AUTOMATIC)               fct_idx,
  CONSTP2VAR(void, AUTOMATIC, OS_APPL_DATA) fct_param);

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_status, OS_CODE) tpl_call_trusted_function_service(
  CONST(tpl_tf_id, AUTOMATIC)               fct_idx,
  CONSTP2VAR(void, AUTOMATIC, OS_APPL_DATA) fct_param);

FUNC(void, OS_CODE) tpl_exit_trusted_function_service(void);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#endif
/* End of file tpl_as_trusted_fct_kernel.h */
