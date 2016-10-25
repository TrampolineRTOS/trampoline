/**
 * @file autosar_st_s2/error_instance8.c
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

/*Instance 8 of error*/

#include "Os.h"

DeclareScheduleTable(sched3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance8(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(30);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(30,OSServiceId_StartScheduleTableRel , result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(30, sched3 , OSError_StartScheduleTableRel_ScheduleTableID());
	SCHEDULING_CHECK_AND_EQUAL_INT(30, 1, OSError_StartScheduleTableRel_offset());
	
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq2_error_instance8(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance8",test_error_instance8)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}

/* End of file autosar_st_s2/error_instance8.c */
