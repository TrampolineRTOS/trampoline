/**
 * @file hook_s6_full/hook_s6.c
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

TestRef HookTest_seq6_t1_instance(void);
TestRef HookTest_seq6_isr1_instance(void);
TestRef HookTest_seq6_isr2_instance(void);
TestRef HookTest_seq6_error_instance(void);
TestRef HookTest_seq6_posttask_instance3(void);

int posttask_instance = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void StartupHook(void)
{ 
	TestRunner_start();
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

void ErrorHook(void)
{
	TestRunner_runTest(HookTest_seq6_error_instance());
}


void PostTaskHook(void)
{ 
	posttask_instance++;
	switch (posttask_instance)
	{
		case 3:
		{
			TestRunner_runTest(HookTest_seq6_posttask_instance3());
			break;
		}
		default:
		{

			break;
		}
	}
}

TASK(t1)
{
	TestRunner_runTest(HookTest_seq6_t1_instance());
}

ISR(softwareInterruptHandler0)
{
	TestRunner_runTest(HookTest_seq6_isr1_instance());
}

ISR(softwareInterruptHandler1)
{
	TestRunner_runTest(HookTest_seq6_isr2_instance());
	ShutdownOS(E_OK);
}
UNUSED_ISR(softwareInterruptHandler2)

/* End of file hook_s6_full/hook_s6.c */
