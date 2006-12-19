/**
 * @file tpl_os_application_def.h
 *
 * @section Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 * @section File description
 *
 * This file wraps user application configuration header. This wrapped file is typically
 * generated from an OIL source.
 *
 */

#ifndef __TPL_OS_APPLICATION_DEF_H__
#define __TPL_OS_APPLICATION_DEF_H__

#include "tpl_os_generated_configuration.h"

#ifndef TASK_COUNT
/**
 * @def NO_TASK
 *
 * When this flag is defined, this means there is no task defined in the system.
 */
#define NO_TASK
#else
	#if TASK_COUNT == 0
		#define NO_TASK
	#endif
#endif

#ifndef RES_COUNT
/**
 * @def NO_RESOURCE
 *
 * When this flag is defined, this means there is no resource defined in the system.
 */
#define NO_RESOURCE
#else
	#if RES_COUNT == 0
		#define NO_RESOURCE
	#endif
#endif

#ifndef ALARM_COUNT
/**
 * @def NO_ALARM
 *
 * When this flag is defined, this means there is no alarm defined in the system.
 */
#define NO_ALARM
#else
	#if ALARM_COUNT == 0
		#define NO_ALARM
	#endif
#endif

#ifndef ISR_COUNT
/**
 * @def NO_ISR
 *
 * When this flag is defined, this means there is no Interrupt Service Routine defined in the system.
 */
#define NO_ISR
#else
	#if ISR_COUNT == 0
		#define NO_ISR
	#endif
#endif

#endif
