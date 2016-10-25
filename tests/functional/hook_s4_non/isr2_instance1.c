/**
 * @file hook_s4_non/isr2_instance1.c
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

/*Instance 1 of interruption isr2*/

#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr2_instance1(void)
{
  /*
   * (jlb) previous version was plainly wrong. GetActiveApplicationMode
   * does not return a StatusType but the application mode. By
   * chance both E_OK and OSDEFAULTAPPMODE was O. So the comparison
   * was true. This has changed since Trampoline allows more than one
   * application mode. OSDEFAULTAPPMODE has no longer the zero value.
   */
	AppModeType result_inst_1;
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_1 = GetActiveApplicationMode();
	SCHEDULING_CHECK_AND_EQUAL_INT(5, OSDEFAULTAPPMODE, result_inst_1);	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq4_isr2_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr2_instance1",test_isr2_instance1)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}

/* End of file hook_s4_non/isr2_instance1.c */
