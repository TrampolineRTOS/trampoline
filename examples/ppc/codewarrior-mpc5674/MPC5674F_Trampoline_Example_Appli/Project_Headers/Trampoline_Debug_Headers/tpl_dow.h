/**
 * @file tpl_dow.h
 *
 * @section descr File description
 *
 * Various macros for Debugging on Workstation (DoW) purpose.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
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
 *
 */

#ifndef TPL_DOW_H
#define TPL_DOW_H

#include "tpl_app_define.h"

#if defined(__unix__) || defined(__APPLE__)

#if WITH_DEBUG == YES
#include <stdio.h>
#include <assert.h>
#endif

#if WITH_DEBUG == YES
#define DOW_ASSERT(cond)    assert(cond);
#define DOW_DO(action)      action
#define WITH_DOW
#else
#define DOW_ASSERT(cond)
#define DOW_DO(action)
#endif

/* __unix__ */
#else
#define DOW_ASSERT(cond)
#define DOW_DO(action)

/* __unix__ */
#endif

/* TPL_DOW_H */
#endif
