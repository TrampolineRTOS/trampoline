/*
 * @file SchedulingCheck.h
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef __SCHEDULING_CHECK_H__
#define __SCHEDULING_CHECK_H__

#include "config.h"
#include "AssertImpl.h"

void assertImplementationInt(int expected,int actual, long line, const char *file); /*AssertImpl.c*/

/**
 * @def SCHEDULING_CHECK_INIT
 *
 * This macro initialise a local variable incrementing the global variable test_number.
 *
 *	@param number step number
 *
 */
#define SCHEDULING_CHECK_INIT(number)												\
	{																	\
		extern unsigned char test_number;								\
		if ((number) != (++test_number)){								\
			assertImplementationInt((number),(test_number),__LINE__,__FILE__); \
		}	

/**
 * @def SCHEDULING_CHECK_AND_EQUAL_INT
 *
 * This macro serves to check the sequence order of the tests (if the global variable test_number has the right value).
 * It compares global variable test_number with parameter number and tell the user if the two variables are different.
 * This test should be tested after the service call otherwise, the last service call of a test sequence can't be tested.
 * It is not useful to check the step after TerminateTask() because the macro shouldn't be called.
 *
 * If the two variables has the same value, TEST_ASSERT_EQUAL_INIT from EmbUnit is called otherwise,
 * an error displays the two variables and let the user check the difference.
 *
 * @param number step number
 * @param expected same value in TEST_ASSERT_EQUAL_INT in Embedded Unit
 * @param actual same value in TEST_ASSERT_EQUAL_INT in Embedded Unit
 *
 */
#define SCHEDULING_CHECK_AND_EQUAL_INT(number, expected, actual)							\
		if ((number) == (test_number)){									\
			TEST_ASSERT_EQUAL_INT((expected),(actual))					\
		}else{															\
			assertImplementationInt((number),(test_number),__LINE__,__FILE__); \
		}																\
	}

/**
 * @def SCHEDULING_CHECK_AND_EQUAL_INT_FIRST
 *
 * When severals tests are needed, it's impossible to call several times TEST_CHECK because it closes the local bracket.
 * This Macro is used for the first tests to check and TEST_CHECK is the final test.
 *
 * @param number step number
 * @param expected same value in TEST_ASSERT_EQUAL_INT in Embedded Unit
 * @param actual same value in TEST_ASSERT_EQUAL_INT in Embedded Unit
 * 
 */
#define SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(number, expected, actual)						\
		if ((number) == (test_number)){							\
			TEST_ASSERT_EQUAL_INT((expected),(actual))					\
		}else{															\
			assertImplementationInt((number),(test_number),__LINE__,__FILE__); \
		}

/**
 * @def SCHEDULING_CHECK_FINAL
 *
 * This macro check the return of any ISR2 in the final task juste before shutdowning "Trampoline".
 *
 *	@param number step number
 *
 */
#define SCHEDULING_CHECK_STEP(number)									\
	{																	\
		extern unsigned char test_number;								\
		if ((number) != (++test_number)){								\
			assertImplementationInt((number),(test_number),__LINE__,__FILE__); \
		}																\
	}

/*	__SCHEDULING_CHECK_H__	*/
#endif

/* End of file SchedulingCheck.h */
