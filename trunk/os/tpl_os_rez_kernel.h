/**
 * @file tpl_os_rez_kernel.h
 *
 * @section desc File description
 *
 * This header file provides internal function
 * for resource management.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
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

#ifndef TPL_OS_REZ_KERNEL_H
#define TPL_OS_REZ_KERNEL_H

#include "tpl_os_internal_types.h"

/*
 * Getting a resource.
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
extern void tpl_get_resource(tpl_resource *res);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/*
 * Releasing a resource
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
extern void tpl_release_resource(tpl_resource *res);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

#endif /* tpl_os_rez_kernel.h */

/* End of file tpl_os_rez_kernel.h */
