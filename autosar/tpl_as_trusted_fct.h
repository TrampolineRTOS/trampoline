/**
 * @file tpl_as_trusted_fct.h
 *
 * @section desc File description
 *
 * Trampoline AUTOSAR's trusted fonction API header
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

#ifndef TPL_AS_TRUSTED_FCT_H
#define TPL_AS_TRUSTED_FCT_H

#include "tpl_os_types.h"

/**
 * @def DeclareTrustedFunction
 *
 * This is used to declare a trusted function
 *
 * @param trusted_fct_id the trusted function identifier
 *        (provide a C identifier here)
 */
#define DeclareTrustedFunction(trusted_fct_id) \
  extern CONST(TrustedFunctionIndexType, AUTOMATIC) trusted_fct_id

/**
 * @typedef TrustedFunctionIndexType
 *
 * The identifier of a trusted function
 */
typedef tpl_tf_id TrustedFunctionIndexType;

/**
 * @typedef TrustedFunctionParameterRefType
 *
 * The pointer to the parameter a trusted function
 */
typedef void *TrustedFunctionParameterRefType;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
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
  CONST(TrustedFunctionParameterRefType, AUTOMATIC) fct_param);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif
/* End of file tpl_as_trusted_fct.h */
