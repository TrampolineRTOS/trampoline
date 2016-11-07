/**
 * @file hook_s4_non/hook_s4.c
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

TestRef HookTest_seq4_t1_instance(void);
TestRef HookTest_seq4_t2_instance(void);
TestRef HookTest_seq4_isr1_instance1(void);
TestRef HookTest_seq4_isr1_instance2(void);
TestRef HookTest_seq4_isr2_instance1(void);
TestRef HookTest_seq4_isr2_instance2(void);
TestRef HookTest_seq4_pretask_instance2(void);
TestRef HookTest_seq4_pretask_instance3(void);
TestRef HookTest_seq4_pretask_instance6(void);
TestRef HookTest_seq4_pretask_instance7(void);
TestRef HookTest_seq4_posttask_instance2(void);
TestRef HookTest_seq4_posttask_instance5(void);

unsigned char instance_pre = 0;
unsigned char instance_post = 0;
unsigned char instance_isr2 = 0;
unsigned char instance_isr1 = 0;

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

void PreTaskHook(void)
{ 
	instance_pre++;
	switch (instance_pre)
	{
		case 2:
		{
			TestRunner_runTest(HookTest_seq4_pretask_instance2());
			break;
		}
		case 3:
		{
			TestRunner_runTest(HookTest_seq4_pretask_instance3());
			break;
		}
		case 6: 
		{
			TestRunner_runTest(HookTest_seq4_pretask_instance6());
			break;
		}
		default: 
		{
			break;
		}
	}
	
}

void PostTaskHook(void)
{ 
	instance_post++;
	switch (instance_post) 
	{
		case 2:
		{
			TestRunner_runTest(HookTest_seq4_posttask_instance2());
			break;
		}
		case 5:
		{
			TestRunner_runTest(HookTest_seq4_posttask_instance5());
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
	TestRunner_runTest(HookTest_seq4_t1_instance());
}


TASK(t2)
{
	TestRunner_runTest(HookTest_seq4_t2_instance());
	ShutdownOS(E_OK);
}


ISR(softwareInterruptHandler0)
{
	instance_isr1++;
	switch (instance_isr1)
	{
		case 1:
		{
			TestRunner_runTest(HookTest_seq4_isr1_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(HookTest_seq4_isr1_instance2());
			break;
		}
		default: 
		{
			addFailure("instance error", __LINE__, __FILE__);
			break;
		}
	}
	
}

ISR(softwareInterruptHandler1)
{
	instance_isr2++;
	switch (instance_isr2)
	{
		case 1:
		{
			TestRunner_runTest(HookTest_seq4_isr2_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(HookTest_seq4_isr2_instance2());
			break;
		}
		default: 
		{
			addFailure("instance error", __LINE__, __FILE__);
			break;
		}
	}
}
UNUSED_ISR(softwareInterruptHandler2)

/* End of file hook_s4_non/hook_s4.c */
