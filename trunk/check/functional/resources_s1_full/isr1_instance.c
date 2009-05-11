/**
 * @file resources_s1_full/isr1_instance.c
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

/*Instance of interruption isr1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareResource(Resource1);

void tpl_send_it2(void);
void tpl_send_it3(void);

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_4, result_inst_5, result_inst_6;
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_1 = GetResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(21 , E_OK, result_inst_1);
	
	tpl_send_it2();
	
	tpl_send_it3();
	/*it3 trigged*/
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_2 = ReleaseResource(Resource1);
	/*it2 trigged*/
	SCHEDULING_CHECK_AND_EQUAL_INT(25 , E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_4 = GetResource(RES_SCHEDULER);
	SCHEDULING_CHECK_AND_EQUAL_INT(26 , E_OS_ACCESS, result_inst_4);
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_5 = ReleaseResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(27 , E_OS_NOFUNC, result_inst_5);
	
	SCHEDULING_CHECK_INIT(28);
	result_inst_6 = ReleaseResource(RES_SCHEDULER);
	SCHEDULING_CHECK_AND_EQUAL_INT(28 , E_OS_NOFUNC, result_inst_6);
	
	/*t2 trigged after isr1 instance*/
}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq1_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&ResourceManagementTest;
}

/* End of file resources_s1_full/isr1_instance.c */
