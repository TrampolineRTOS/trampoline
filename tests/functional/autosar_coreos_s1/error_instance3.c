/**
 * @file autosar_coreos_s1/error_instance3.c
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

/*Instance 3 of error*/

#include "Os.h"

DeclareAlarm(Alarm_ActivateTask);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance3(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(16,OSServiceId_SetRelAlarm , result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(16, 0 , OSError_SetRelAlarm_increment());
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(16, 0 , OSError_SetRelAlarm_cycle());
	SCHEDULING_CHECK_AND_EQUAL_INT(16, Alarm_ActivateTask , OSError_SetRelAlarm_AlarmID());
		
}

/*create the test suite with all the test cases*/
TestRef AutosarCOREOSTest_seq1_error_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance3",test_error_instance3)
	};
	EMB_UNIT_TESTCALLER(AutosarCOREOSTest,"AutosarCOREOSTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarCOREOSTest;
}

/* End of file autosar_coreos_s1/error_instance3.c */
