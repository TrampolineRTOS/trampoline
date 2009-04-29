/**
 * @file tpl_as_trusted_fct.c
 *
 * @section desc File description
 *
 * Trampoline AUTOSAR's trusted fonction API implementation
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

#ifndef WITH_SYSTEM_CALL

#include "tpl_as_trusted_fct.h"
#include "tpl_as_trusted_fct_kernel.h"
#include "tpl_as_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Call a Trusted Function
 *
 * @param   fct_idx     the trusted function id
 * @param   fct_param   the pointer to the parameters of trusted function
 *
 * @retval  E_OK            the trusted function exists and has been called
 *                          successfully.
 * @retval  E_OS_SERVICEID  the trusted function does not exists
 */
FUNC(StatusType, OS_CODE) CallTrustedFunction(
  CONST(TrustedFunctionIndexType, AUTOMATIC)        fct_idx,
  CONST(TrustedFunctionParameterRefType, AUTOMATIC) fct_param)
{
  return tpl_call_trusted_function_service(fct_idx, fct_param);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#else
#error "This file should not be part of your project since WITH_SYSTEM_CALL is defined"
#endif /* WITH_SYSTEM_CALL */

/* End of file tpl_as_trusted_fct.c */
