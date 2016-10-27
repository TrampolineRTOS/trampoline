/**
 * @file com_internal_s6_non/com_internal_s6.c
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

#include "tpl_os.h"


TestRef COMInternalTest_seq6_t1_instance(void);

TestRef COMInternalTest_seq6_t2_instance1(void);
TestRef COMInternalTest_seq6_t2_instance2(void);
TestRef COMInternalTest_seq6_t2_instance3(void);

TestRef COMInternalTest_seq6_t3_instance1(void);
TestRef COMInternalTest_seq6_t3_instance2(void);

TestRef COMInternalTest_seq6_t4_instance(void);

TestRef COMInternalTest_seq6_t5_instance1(void);
TestRef COMInternalTest_seq6_t5_instance2(void);
TestRef COMInternalTest_seq6_t5_instance3(void);
TestRef COMInternalTest_seq6_t5_instance4(void);

TestRef COMInternalTest_seq6_t6_instance1(void);
TestRef COMInternalTest_seq6_t6_instance2(void);

TestRef COMInternalTest_seq6_t7_instance1(void);
TestRef COMInternalTest_seq6_t7_instance2(void);

TestRef COMInternalTest_seq6_t8_instance1(void);
TestRef COMInternalTest_seq6_t8_instance2(void);

TestRef COMInternalTest_seq6_t9_instance1(void);
TestRef COMInternalTest_seq6_t9_instance2(void);
TestRef COMInternalTest_seq6_t9_instance3(void);

int t2_instance = 0;
int t3_instance = 0;
int t5_instance = 0;
int t6_instance = 0;
int t7_instance = 0;
int t8_instance = 0;
int t9_instance = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(COMInternalTest_seq6_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	t2_instance++;
	switch (t2_instance)
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq6_t2_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq6_t2_instance2());
			break;
		case 3:
			TestRunner_runTest(COMInternalTest_seq6_t2_instance3());
			break;
		default:
			addFailure("instance error\n", __LINE__, __FILE__);
			break;
	}
}

TASK(t3)
{
	t3_instance++;
	switch (t3_instance)
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq6_t3_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq6_t3_instance2());
			break;
		default:
			addFailure("instance error\n", __LINE__, __FILE__);
			break;
	}
}

TASK(t4)
{	
	TestRunner_runTest(COMInternalTest_seq6_t4_instance());
}

TASK(t5)
{	
	t5_instance++;
	switch (t5_instance)
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq6_t5_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq6_t5_instance2());
			break;
		case 3:
			TestRunner_runTest(COMInternalTest_seq6_t5_instance3());
			break;
		case 4:
			TestRunner_runTest(COMInternalTest_seq6_t5_instance4());
			break;
		default:
			addFailure("instance error\n", __LINE__, __FILE__);
			break;
	}	
	
}

TASK(t6)
{
	t6_instance++;
	switch (t6_instance)
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq6_t6_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq6_t6_instance2());
			break;
		default:
			addFailure("instance error\n", __LINE__, __FILE__);
			break;
	}
	
}

TASK(t7)
{	
	t7_instance++;
	switch (t7_instance)
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq6_t7_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq6_t7_instance2());
			break;
		default:
			addFailure("instance error\n", __LINE__, __FILE__);
			break;
	}
}

TASK(t8)
{
	t8_instance++;
	switch (t8_instance)
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq6_t8_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq6_t8_instance2());
			break;
		default:
			addFailure("instance error\n", __LINE__, __FILE__);
			break;
	}
}

TASK(t9)
{
	t9_instance++;
	switch (t9_instance)
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq6_t9_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq6_t9_instance2());
			break;
		case 3:
			TestRunner_runTest(COMInternalTest_seq6_t9_instance3());
			break;
		default:
			addFailure("instance error\n", __LINE__, __FILE__);
			break;
	}
}

/* End of file com_internal_s6_non/com_internal_s6.c */
