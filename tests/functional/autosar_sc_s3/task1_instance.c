/**
 * @file autosar_sc_s3/task1_instance.c
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

DeclareCounter(Hardware_Counter);
DeclareCounterConstants(Hardware_Counter);
DeclareCounter(Software_Counter);
DeclareCounterConstants(Software_Counter);
DeclareCounter(INVALID_COUNTER);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	TickType TickType_inst_5, TickType_inst_6, TickType_inst_7;
	TickType TickType_inst_1 = OSMAXALLOWEDVALUE_Software_Counter + 1;
	TickType TickType_inst_2 = OSMAXALLOWEDVALUE_Software_Counter + 1;
	TickType TickType_inst_3 = OSMAXALLOWEDVALUE_Software_Counter + 1;
	TickType TickType_inst_4 = OSMAXALLOWEDVALUE_Hardware_Counter + 1;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = IncrementCounter(Hardware_Counter);	
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OS_ID, result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = IncrementCounter(INVALID_COUNTER);	
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OS_ID, result_inst_2);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_3 = GetCounterValue(INVALID_COUNTER, &TickType_inst_1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_ID, result_inst_3);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_4 = GetElapsedCounterValue(Software_Counter, &TickType_inst_2, &TickType_inst_3);	
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OS_VALUE, result_inst_4);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_5 = GetElapsedCounterValue(Hardware_Counter, &TickType_inst_4, &TickType_inst_5);	
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OS_VALUE, result_inst_5);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_6 = GetElapsedCounterValue(INVALID_COUNTER, &TickType_inst_6, &TickType_inst_7);	
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OS_ID, result_inst_6);
}

/*create the test suite with all the test cases*/
TestRef AutosarSCTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSCTest,"AutosarSCTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSCTest;
}

/* End of file autosar_sc_s3/task1_instance.c */
