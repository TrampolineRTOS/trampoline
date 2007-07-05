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

#ifdef __unix__

#ifdef WITH_DEBUG
#include <stdio.h>
#include <assert.h>
#endif

#ifdef WITH_DEBUG
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
