/**
 * @file tpl_os_multicore_error.h
 *
 * @section descr File description
 *
 * Trampoline multicore error handling macros.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2013
 * Part of Autosar extension is copyright (c) IRCCyN and ESEO 2007
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
 *
 */

#ifndef TPL_OS_MULTICORE_ERROR_H
#define TPL_OS_MULTICORE_ERROR_H

#include "tpl_os_error.h"

/**
 * STORE_CODE_ID macro
 */
#if (NUMBER_OF_CORES > 1) && \
    (WITH_OS_EXTENDED == YES) && \
    (WITH_ERROR_HOOK == YES) && \
    (WITH_USEPARAMETERACCESS == YES)
#  define STORE_CORE_ID(core_id) \
  tpl_service.parameters.id.core_id = (core_id);
#else
#  define STORE_CORE_ID(core_id)
#endif

/**
 * CHECK_CORE_ID_ERROR macro
 */
#if (NUMBER_OF_CORES > 1) && \
    (WITH_OS_EXTENDED == YES)
#  define CHECK_CORE_ID_ERROR(core_id, result) \
  if ((result == E_OK) && !(core_id < NUMBER_OF_CORES)) { result = E_OS_ID; }
#else
#  define CHECK_CORE_ID_ERROR(core_id, result)
#endif

/**
 * CHECK_START_CORE_ERROR macro
 */
#if (NUMBER_OF_CORES > 1) && \
    (WITH_OS_EXTENDED == YES)
#  define CHECK_START_CORE_ERROR(core_id, result) \
  if ((result == E_OK) && (tpl_core_status[core_id] != STOPPED_CORE)) { \
    result = E_OS_STATE; \
  }
#else
#  define CHECK_START_CORE_ERROR(core_id, result)
#endif


/* TPL_OS_MULTICORE_ERROR_H */
#endif

/* End of file tpl_os_multicore_error.h */
