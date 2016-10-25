/**
 * @file tasks_s14_non/tasks_s14.c
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

TestRef TaskManagementTest_seq14_t1_instance(void);
TestRef TaskManagementTest_seq14_t2_instance(void);
TestRef TaskManagementTest_seq14_t3_instance(void);
TestRef TaskManagementTest_seq14_t4_instance(void);
TestRef TaskManagementTest_seq14_t5_instance(void);
TestRef TaskManagementTest_seq14_t6_instance(void);
TestRef TaskManagementTest_seq14_t7_instance(void);
TestRef TaskManagementTest_seq14_t8_instance(void);
TestRef TaskManagementTest_seq14_t9_instance(void);
TestRef TaskManagementTest_seq14_t10_instance(void);
TestRef TaskManagementTest_seq14_t11_instance(void);
TestRef TaskManagementTest_seq14_t12_instance(void);
TestRef TaskManagementTest_seq14_t13_instance(void);
TestRef TaskManagementTest_seq14_t14_instance(void);
TestRef TaskManagementTest_seq14_t15_instance(void);
TestRef TaskManagementTest_seq14_t16_instance(void);

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
	TestRunner_runTest(TaskManagementTest_seq14_t1_instance());
}

TASK(t2)
{
	TestRunner_runTest(TaskManagementTest_seq14_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(TaskManagementTest_seq14_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(TaskManagementTest_seq14_t4_instance());
}

TASK(t5)
{
	TestRunner_runTest(TaskManagementTest_seq14_t5_instance());
}

TASK(t6)
{
	TestRunner_runTest(TaskManagementTest_seq14_t6_instance());
}

TASK(t7)
{
	TestRunner_runTest(TaskManagementTest_seq14_t7_instance());
}

TASK(t8)
{
	TestRunner_runTest(TaskManagementTest_seq14_t8_instance());
}

TASK(t9)
{
	TestRunner_runTest(TaskManagementTest_seq14_t9_instance());
}

TASK(t10)
{
	TestRunner_runTest(TaskManagementTest_seq14_t10_instance());
}

TASK(t11)
{
	TestRunner_runTest(TaskManagementTest_seq14_t11_instance());
}

TASK(t12)
{
	TestRunner_runTest(TaskManagementTest_seq14_t12_instance());
}

TASK(t13)
{
	TestRunner_runTest(TaskManagementTest_seq14_t13_instance());
}

TASK(t14)
{
	TestRunner_runTest(TaskManagementTest_seq14_t14_instance());
}

TASK(t15)
{
	TestRunner_runTest(TaskManagementTest_seq14_t15_instance());
}

TASK(t16)
{
	TestRunner_runTest(TaskManagementTest_seq14_t16_instance());
	ShutdownOS(E_OK);
}

/* End of file tasks_s14_non/tasks_s14.c */
