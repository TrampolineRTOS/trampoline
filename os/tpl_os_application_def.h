/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline wrapper to user application header
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#ifndef __TPL_OS_APPLICATION_DEF_H__
#define __TPL_OS_APPLICATION_DEF_H__

#include "tpl_os_generated_configuration.h"

#ifndef TASK_COUNT
#define NO_TASK
#else
	#if TASK_COUNT == 0
		#define NO_TASK
	#endif
#endif

#ifndef RES_COUNT
#define NO_RESOURCE
#else
	#if RES_COUNT == 0
		#define NO_RESOURCE
	#endif
#endif

#ifndef ALARM_COUNT
#define NO_ALARM
#else
	#if ALARM_COUNT == 0
		#define NO_ALARM
	#endif
#endif

#ifndef ISR_COUNT
#define NO_ISR
#else
	#if ISR_COUNT == 0
		#define NO_ISR
	#endif
#endif

#endif
