/**
 * @file hook_s2_full/hook_s2.c
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

TestRef HookTest_seq2_error_instance1(void);
TestRef HookTest_seq2_error_instance2(void);
TestRef HookTest_seq2_error_instance3(void);
TestRef HookTest_seq2_error_instance4(void);
TestRef HookTest_seq2_error_instance5(void);
TestRef HookTest_seq2_error_instance6(void);
TestRef HookTest_seq2_pretask_instance1(void);
TestRef HookTest_seq2_pretask_instance2(void);
TestRef HookTest_seq2_pretask_instance3(void);
TestRef HookTest_seq2_pretask_instance4(void);
TestRef HookTest_seq2_posttask_instance1(void);
TestRef HookTest_seq2_posttask_instance2(void);
TestRef HookTest_seq2_posttask_instance3(void);
TestRef HookTest_seq2_t1_instance(void);
TestRef HookTest_seq2_t2_instance(void);

unsigned char instance_post = 0;
unsigned char instance_pre = 0;
unsigned char instance_error = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

void ErrorHook(void)
{ 
	instance_error++;
	switch (instance_error)
	{
		case 1 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance2());
			break;
		}
		case 3 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance3());
			break;
		}
		case 4 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance4());
			break;
		}
		case 5 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance5());
			break;
		}
		case 6 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance6());
			break;
		}
		default:
		{
			addFailure("Instance error", __LINE__, __FILE__);
			break;
		}
	}
	
}

void PreTaskHook(void)
{ 
	instance_pre++;
	switch (instance_pre)
	{
		case 1 :
		{
			TestRunner_start();
			TestRunner_runTest(HookTest_seq2_pretask_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(HookTest_seq2_pretask_instance2());
			break;
		}
		case 3 :
		{
			TestRunner_runTest(HookTest_seq2_pretask_instance3());
			break;
		}
		case 4 :
		{
			TestRunner_runTest(HookTest_seq2_pretask_instance4());
			break;
		}
		default:
		{
			addFailure("Instance error", __LINE__, __FILE__);
			break;
		}
	}
}

void PostTaskHook(void)
{ 	
	instance_post++;
	switch (instance_post)
	{
		case 1 :
		{
			TestRunner_runTest(HookTest_seq2_posttask_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(HookTest_seq2_posttask_instance2());
			break;
		}
		case 3 :
		{
			TestRunner_runTest(HookTest_seq2_posttask_instance3());
			break;
		}
		default:
		{
			addFailure("Instance error", __LINE__, __FILE__);
			break;
		}
	}

	
}

TASK(t1)
{
	TestRunner_runTest(HookTest_seq2_t1_instance());
}

TASK(t2)
{		
	TestRunner_runTest(HookTest_seq2_t2_instance());
	ShutdownOS(E_OK);
}

/* End of file hook_s2_full/hook_s2.c */
