/**
 * @file hook_s6_full/error_instance.c
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

/*Instance of error*/

#include "tpl_os.h"


extern int posttask_instance;

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_error_instance(void)
{
  int err_instance = posttask_instance/2;
  int test_start = err_instance * 4;
	
	SCHEDULING_CHECK_STEP(test_start + 2);
	
	sendSoftwareIt(0, SOFT_IRQ0);
	SuspendAllInterrupts();
	sendSoftwareIt(0, SOFT_IRQ0);
	ResumeAllInterrupts();
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq6_error_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance",test_error_instance)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence6",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}

/* End of file hook_s6_full/error_instance.c */
