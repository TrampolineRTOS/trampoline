/**
 * @file interrupts_s5/task1_instance.c
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

/*Instance of task t1*/

#include "tpl_os.h"

DeclareTask(t2);


/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
		
	SCHEDULING_CHECK_STEP(1);
	SuspendAllInterrupts();
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_STEP(3);
	sendSoftwareIt(0, SOFT_IRQ0);
	
	SCHEDULING_CHECK_STEP(4);
	ResumeOSInterrupts();
	
	SCHEDULING_CHECK_STEP(5);
	EnableAllInterrupts();
	
	SCHEDULING_CHECK_STEP(6);
	ResumeAllInterrupts();
		
	
	
	SCHEDULING_CHECK_STEP(8);
	SuspendOSInterrupts();
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_2 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OS_DISABLEDINT, result_inst_2);
	
	SCHEDULING_CHECK_STEP(10);
	sendSoftwareIt(0, SOFT_IRQ0);
	
	SCHEDULING_CHECK_STEP(11);
	ResumeAllInterrupts();
	
	SCHEDULING_CHECK_STEP(12);
	EnableAllInterrupts();
	
	SCHEDULING_CHECK_STEP(13);
	DisableAllInterrupts();
	
	SCHEDULING_CHECK_STEP(14);
	EnableAllInterrupts();
	
	SCHEDULING_CHECK_STEP(15);
	ResumeOSInterrupts();
	
	
	
	SCHEDULING_CHECK_STEP(17);
	DisableAllInterrupts();
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_3 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OS_DISABLEDINT, result_inst_3);
	
	SCHEDULING_CHECK_STEP(19);
	sendSoftwareIt(0, SOFT_IRQ0);
	
	SCHEDULING_CHECK_STEP(20);
	ResumeAllInterrupts();
	
	SCHEDULING_CHECK_STEP(21);
	ResumeOSInterrupts();
	
	SCHEDULING_CHECK_STEP(22);
	EnableAllInterrupts();
	
	SCHEDULING_CHECK_STEP(24);

}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq5_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence5",NULL,NULL,fixtures);

	return (TestRef)&InterruptProcessingTest;
}

/* End of file interrupts_s5/task1_instance.c */
