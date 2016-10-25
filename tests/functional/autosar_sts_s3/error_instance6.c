/**
 * @file autosar_sts_s3/error_instance6.c
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2006-2007
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
 * Foundation, Inc., 61 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

/*Instance 6 of error*/

#include "Os.h"

DeclareScheduleTable(sched_explicit);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance6(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(18,OSServiceId_StartScheduleTableSynchron, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(18,sched_explicit, OSError_StartScheduleTableSynchron_ScheduleTableID());
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTSTest_seq3_error_instance6(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance6",test_error_instance6)
	};
	EMB_UNIT_TESTCALLER(AutosarSTSTest,"AutosarSTSTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTSTest;
}

/* End of file autosar_sts_s3/error_instance6.c */
