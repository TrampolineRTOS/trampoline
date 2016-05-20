/**
 * @file tpl_os_os_kernel.h
 *
 * @section descr File description
 *
 * Trampoline os services header.
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
 *
 */

#ifndef TPL_OS_OS_KERNEL_H
#define TPL_OS_OS_KERNEL_H

#include "tpl_os_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_application_mode, OS_CODE) tpl_get_active_application_mode_service(
  void);

FUNC(void, OS_CODE) tpl_start_os_service(
  CONST(tpl_application_mode, AUTOMATIC) mode);

FUNC(void, OS_CODE) tpl_shutdown_os_service(
    CONST(tpl_status, AUTOMATIC) error);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_OS_OS_KERNEL_H */
#endif
/* End of file tpl_os_os_kernel.h */
