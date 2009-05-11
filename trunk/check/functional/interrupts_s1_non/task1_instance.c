/**
 * @file interrupts_s1_non/task1_instance.c
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

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it1(void);
void tpl_send_it2(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{	
	
	SCHEDULING_CHECK_STEP(1);
	
	EnableAllInterrupts();
	DisableAllInterrupts();
	DisableAllInterrupts();
	DisableAllInterrupts();
	tpl_send_it2();
	tpl_send_it2();
	tpl_send_it2();
	
	EnableAllInterrupts();
	EnableAllInterrupts();
	EnableAllInterrupts();
	
	SCHEDULING_CHECK_STEP(3);
	
	tpl_send_it2();
	
	SCHEDULING_CHECK_STEP(5);
	
	SuspendAllInterrupts();
	ResumeAllInterrupts();
	SuspendAllInterrupts();
	SuspendAllInterrupts();
	SuspendAllInterrupts();
	tpl_send_it2();
	
	ResumeAllInterrupts();
	ResumeAllInterrupts();
	ResumeAllInterrupts();
	
	SCHEDULING_CHECK_STEP(7);
	
	tpl_send_it2();
	
	SCHEDULING_CHECK_STEP(9);	
	
	SuspendOSInterrupts();
	ResumeOSInterrupts();
	SuspendOSInterrupts();
	SuspendOSInterrupts();
	SuspendOSInterrupts();
	tpl_send_it2();
	
	ResumeOSInterrupts();
	ResumeOSInterrupts();
	ResumeOSInterrupts();
	
	SCHEDULING_CHECK_STEP(11);
	
	tpl_send_it1();
	
	SCHEDULING_CHECK_STEP(27);
	
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&InterruptProcessingTest;
}

/* End of file interrupts_s1_non/task1_instance.c */
