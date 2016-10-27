/**
 * @file interrupts_s1_non/interrupts_s1.c
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

TestRef InterruptProcessingTest_seq1_t1_instance(void);
TestRef InterruptProcessingTest_seq1_isr1_instance(void);
TestRef InterruptProcessingTest_seq1_isr2_instance1(void);
TestRef InterruptProcessingTest_seq1_isr2_instance2(void);
TestRef InterruptProcessingTest_seq1_isr2_instance3(void);
TestRef InterruptProcessingTest_seq1_isr2_instance4(void);
TestRef InterruptProcessingTest_seq1_isr2_instance5(void);
TestRef InterruptProcessingTest_seq1_isr2_instance6(void);
TestRef InterruptProcessingTest_seq1_isr2_instance7(void);
TestRef InterruptProcessingTest_seq1_isr2_instance8(void);
TestRef InterruptProcessingTest_seq1_isr2_instance9(void);
TestRef InterruptProcessingTest_seq1_isr2_instance10(void);
TestRef InterruptProcessingTest_seq1_isr2_instance11(void);
TestRef InterruptProcessingTest_seq1_isr3_instance(void);

unsigned char instance_isr2 = 0;

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
	TestRunner_runTest(InterruptProcessingTest_seq1_t1_instance());
	ShutdownOS(E_OK);
}

ISR(softwareInterruptHandler0)
{
	TestRunner_runTest(InterruptProcessingTest_seq1_isr1_instance());
}

ISR(softwareInterruptHandler1)
{
	
	instance_isr2 ++;
	switch(instance_isr2)
	{ 
		case 1:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance2());
			break;
		}
		case 3:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance3());
			break;
		}
		case 4:
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance4());
			break;
		}
		case 5:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance5());
			break;
		}
		case 6:
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance6());
			break;
		}
		case 7:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance7());
			break;
		}
		case 8:
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance8());
			break;
		}
		case 9:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance9());
			break;
		}
		case 10:
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance10());
			break;
		}
		case 11:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance11());
			break;
		}
		default:
		{
			addFailure("Instance error \n", __LINE__, __FILE__);
			break;
		}
	}
	
	
	
}

ISR(softwareInterruptHandler2)
{
	TestRunner_runTest(InterruptProcessingTest_seq1_isr3_instance());
}

/* End of file interrupts_s1_non/interrupts_s1.c */
