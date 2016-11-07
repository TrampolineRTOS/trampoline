/**
 * @file interrupts_s6/error_instance4.c
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

/*Instance 4 of error*/

#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance4(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT(10,OSServiceId_Schedule, result_inst_1);
		
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq6_error_instance4(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance4",test_error_instance4)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&InterruptProcessingTest;
}

/* End of file interrupts_s6/error_instance4.c */
