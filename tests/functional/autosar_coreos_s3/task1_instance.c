/**
 * @file autosar_coreos_s3/task1_instance.c
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

#include "Os.h"

DeclareTask(t1);


/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	ISRType ISRType_inst_1;
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_STEP(1);
	sendSoftwareIt(0, SOFT_IRQ0);
	
	SCHEDULING_CHECK_INIT(6);
	ISRType_inst_1 = GetISRID();
	SCHEDULING_CHECK_AND_EQUAL_INT(6, INVALID_ISR, ISRType_inst_1);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_1 = ActivateTask(t1);
	SCHEDULING_CHECK_AND_EQUAL_INT(9, E_OS_LIMIT, result_inst_1);
}

/*create the test suite with all the test cases*/
TestRef AutosarCOREOSTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarCOREOSTest,"AutosarCOREOSTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarCOREOSTest;
}

/* End of file autosar_alarm_s1/task1_instance.c */
