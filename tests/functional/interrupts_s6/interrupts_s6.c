/**
 * @file interrupts_s6/interrupts_s6.c
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

TestRef InterruptProcessingTest_seq6_t1_instance(void);
TestRef InterruptProcessingTest_seq6_isr1_instance(void);
TestRef InterruptProcessingTest_seq6_error_instance1(void);
TestRef InterruptProcessingTest_seq6_error_instance2(void);
TestRef InterruptProcessingTest_seq6_error_instance3(void);
TestRef InterruptProcessingTest_seq6_error_instance4(void);
TestRef InterruptProcessingTest_seq6_error_instance5(void);
TestRef InterruptProcessingTest_seq6_error_instance6(void);
TestRef InterruptProcessingTest_seq6_error_instance7(void);
TestRef InterruptProcessingTest_seq6_error_instance8(void);
TestRef InterruptProcessingTest_seq6_error_instance9(void);
TestRef InterruptProcessingTest_seq6_error_instance10(void);
TestRef InterruptProcessingTest_seq6_error_instance11(void);
TestRef InterruptProcessingTest_seq6_error_instance12(void);
TestRef InterruptProcessingTest_seq6_error_instance13(void);
TestRef InterruptProcessingTest_seq6_error_instance14(void);
TestRef InterruptProcessingTest_seq6_error_instance15(void);
TestRef InterruptProcessingTest_seq6_error_instance16(void);
TestRef InterruptProcessingTest_seq6_error_instance17(void);
TestRef InterruptProcessingTest_seq6_error_instance18(void);

StatusType instance_error = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

void ErrorHook(StatusType error)
{
	instance_error++;
	switch (instance_error)
	{
		case 1 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance1());	
			break;
		}	
		case 2 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance2());	
			break;
		}
		case 3 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance3());	
			break;
		}
		case 4 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance4());	
			break;
		}
		case 5 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance5());	
			break;
		}
		case 6 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance6());	
			break;
		}
		case 7 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance7());	
			break;
		}
		case 8 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance8());	
			break;
		}
		case 9 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance9());	
			break;
		}
		case 10 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance10());	
			break;
		}
		case 11 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance11());	
			break;
		}
		case 12 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance12());	
			break;
		}
		case 13 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance13());	
			break;
		}
		case 14 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance14());	
			break;
		}
		case 15 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance15());	
			break;
		}
		case 16 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance16());	
			break;
		}		
		case 17 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance17());	
			break;
		}
		case 18 :
		{
			TestRunner_runTest(InterruptProcessingTest_seq6_error_instance18());	
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
	TestRunner_start();
	TestRunner_runTest(InterruptProcessingTest_seq6_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	addFailure("instance error", __LINE__, __FILE__);
}

TASK(t3)
{
	addFailure("instance error", __LINE__, __FILE__);
}

/* End of file interrupts_s6/interrupts_s6.c */
