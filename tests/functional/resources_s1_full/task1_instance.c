/**
 * @file resources_s1_full/task1_instance.c
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

DeclareResource(source1);
DeclareResource(Resource2);
DeclareResource(Resource3);
DeclareResource(Resource4);
DeclareResource(Resource5);
DeclareResource(Resource6);
DeclareResource(ResourceA);
DeclareResource(INVALID_RESOURCE);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{	
	StatusType result_inst_1, result_inst_1_5, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17, result_inst_18, result_inst_19, result_inst_20;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetResource(ResourceA);
	SCHEDULING_CHECK_AND_EQUAL_INT(1 , E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1_5 = ReleaseResource(ResourceA);
	SCHEDULING_CHECK_AND_EQUAL_INT(2 , E_OK, result_inst_1_5);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = GetResource(INVALID_RESOURCE);
	SCHEDULING_CHECK_AND_EQUAL_INT(3 , E_OS_ID, result_inst_2);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_3 = GetResource(source1);
	SCHEDULING_CHECK_AND_EQUAL_INT(4 , E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_4 = GetResource(Resource2);
	SCHEDULING_CHECK_AND_EQUAL_INT(5 , E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_5 = GetResource(Resource3);
	SCHEDULING_CHECK_AND_EQUAL_INT(6 , E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_6 = GetResource(Resource4);
	SCHEDULING_CHECK_AND_EQUAL_INT(7 , E_OK, result_inst_6);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_7 = GetResource(Resource5);
	SCHEDULING_CHECK_AND_EQUAL_INT(8 , E_OK, result_inst_7);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_8 = GetResource(Resource6);
	SCHEDULING_CHECK_AND_EQUAL_INT(9 , E_OK, result_inst_8);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_9 = ReleaseResource(Resource6);
	SCHEDULING_CHECK_AND_EQUAL_INT(10 , E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_10 = ReleaseResource(Resource5);
	SCHEDULING_CHECK_AND_EQUAL_INT(11 , E_OK, result_inst_10);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_11 = ReleaseResource(Resource4);
	SCHEDULING_CHECK_AND_EQUAL_INT(12 , E_OK, result_inst_11);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_12 = ReleaseResource(Resource3);
	SCHEDULING_CHECK_AND_EQUAL_INT(13 , E_OK, result_inst_12);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_13 = ReleaseResource(source1);
	SCHEDULING_CHECK_AND_EQUAL_INT(14 , E_OS_NOFUNC, result_inst_13);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_14 = ReleaseResource(Resource2);
	SCHEDULING_CHECK_AND_EQUAL_INT(15 , E_OK, result_inst_14);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_15 = GetResource(source1);
	SCHEDULING_CHECK_AND_EQUAL_INT(16 , E_OS_ACCESS, result_inst_15);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_17 = ReleaseResource(source1);
	SCHEDULING_CHECK_AND_EQUAL_INT(17 , E_OK, result_inst_17);
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_16 = ActivateTask(t2);
	/*force scheduling*/
	SCHEDULING_CHECK_AND_EQUAL_INT(21 , E_OK, result_inst_16);
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_18 = ReleaseResource(INVALID_RESOURCE);
	SCHEDULING_CHECK_AND_EQUAL_INT(22 , E_OS_ID, result_inst_18);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_19 = ReleaseResource(source1);
	SCHEDULING_CHECK_AND_EQUAL_INT(23 , E_OS_NOFUNC, result_inst_19);
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_20 = ReleaseResource(RES_SCHEDULER);
	SCHEDULING_CHECK_AND_EQUAL_INT(24 , E_OS_NOFUNC, result_inst_20);
	
	
}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&ResourceManagementTest;
}

/* End of file resources_s1_full/task1_instance.c */
