/**
 * @file Os.h
 *
 * @section desc File description
 *
 * Trampoline AUTOSAR standard API. This file should be included in every
 * AUTOSAR application. This file includes all necessary into AUTOSAR, so
 * any other AUTOSAR/OSEK include is superfluous.
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
#ifndef OS_H
#define OS_H

/* OSEK includes */
/*#include "tpl_os_application_def.h"*/
#include "tpl_os.h"
/*#include "tpl_os_types.h"
#include "tpl_os_task.h"
#include "tpl_os_alarm.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_os_event.h"
#include "tpl_os_it.h"
#include "tpl_os_rez.h"
#include "tpl_os_it_kernel.h"*/

/* AUTOSAR includes */
/*#if WITH_AUTOSAR == YES
#include "tpl_as_error.h"
#include "tpl_as_isr.h"
#include "tpl_as_protec_hook.h"
#include "tpl_as_schedtable.h"
#include "tpl_as_stack_monitor.h"
#include "tpl_as_timing_protec.h"

#if AUTOSAR_SC == 3 || AUTOSAR_SC == 4
#include "tpl_as_application.h"
#include "tpl_as_trusted_fct.h"
#endif
*/
#if WITH_IOC == YES
#include "tpl_ioc.h"
#include "tpl_ioc_api_config.h"
#endif

/*#endif*/

/* Configuration includes */
/*#include "tpl_os_generated_configuration.h"*/

/* Common Published Information */
#define OS_VENDOR_ID         48
#define OS_MODULE_ID         1
#define OS_AR_MAJOR_VERSION  3
#define OS_AR_MINOR_VERSION  0
#define OS_AR_PATCH_VERSION  0
#define OS_SW_MAJOR_VERSION  1
#define OS_SW_MINOR_VERSION  0
#define OS_SW_PATCH_VERSION  0

#endif /*OS_H_*/
