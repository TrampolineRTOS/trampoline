/**
 * @file autosar_st_s6/task1_instance.c
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

DeclareCounter(Software_Counter);
DeclareScheduleTable(sched_abs_more_1);
DeclareScheduleTable(sched_abs_more_2);
DeclareScheduleTable(sched_abs_more_3);
DeclareScheduleTable(sched_abs_less_1);
DeclareScheduleTable(sched_abs_less_2);
DeclareScheduleTable(sched_abs_less_3);
DeclareScheduleTable(sched_abs_less_4);
DeclareScheduleTable(sched_rel);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14;
	StatusType result_inst_15, result_inst_16, result_inst_17, result_inst_18, result_inst_19, result_inst_20, result_inst_21, result_inst_22, result_inst_23, result_inst_24;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = IncrementCounter(Software_Counter);
	/*offset = 1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
		
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = IncrementCounter(Software_Counter);
	/*offset = 2 */
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_3 = IncrementCounter(Software_Counter);
	/*offset = 3 */
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_3);
	
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_4 = StartScheduleTableAbs(sched_abs_more_1, 5);
	/* obj in 5+0= 5(1st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_5 = StartScheduleTableAbs(sched_abs_more_2, 5);
	/* obj in 5+5=10= 3 */
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_6 = StartScheduleTableAbs(sched_abs_more_3, 6);
	/* obj in 6+6=12= 5 */
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_6);
	
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_7 = StartScheduleTableAbs(sched_abs_less_1, 1);
	/* obj in 1+0= 1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_7);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_8 = StartScheduleTableAbs(sched_abs_less_2, 1);
	/* obj in 1+2= 3 */
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_8);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_9 = StartScheduleTableAbs(sched_abs_less_3, 1);
	/* obj in 1+5= 6(1st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_10 = StartScheduleTableAbs(sched_abs_less_4, 2);
	/* obj in 2+5= 0 */
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_10);

	SCHEDULING_CHECK_INIT(11);
	result_inst_11 = StartScheduleTableRel(sched_rel, 2);
	/* obj in 3+2+1= 6(1st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_11);

	SCHEDULING_CHECK_INIT(12);
	result_inst_12 = IncrementCounter(Software_Counter);
	/*offset = 4 */
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_12);

	SCHEDULING_CHECK_INIT(13);
	result_inst_13 = IncrementCounter(Software_Counter);
	/*offset = 5 */
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_13);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_14 = IncrementCounter(Software_Counter);
	/*offset = 6 */
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OK, result_inst_14);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_15 = IncrementCounter(Software_Counter);
	/*offset = 0 */
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK, result_inst_15);
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_16 = IncrementCounter(Software_Counter);
	/*offset = 1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OK, result_inst_16);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_17 = IncrementCounter(Software_Counter);
	/*offset = 2 */
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK, result_inst_17);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_18 = IncrementCounter(Software_Counter);
	/*offset = 3 */
	SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OK, result_inst_18);
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_19 = IncrementCounter(Software_Counter);
	/*offset = 4 */
	SCHEDULING_CHECK_AND_EQUAL_INT(24,E_OK, result_inst_19);
		
	SCHEDULING_CHECK_INIT(25);
	result_inst_20 = IncrementCounter(Software_Counter);
	/*offset = 5 */
	SCHEDULING_CHECK_AND_EQUAL_INT(26 ,E_OK, result_inst_20);
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_21 = IncrementCounter(Software_Counter);
	/*offset = 6 */
	SCHEDULING_CHECK_AND_EQUAL_INT(28,E_OK, result_inst_21);
	
	SCHEDULING_CHECK_INIT(29);
	result_inst_22 = IncrementCounter(Software_Counter);
	/*offset = 0 */
	SCHEDULING_CHECK_AND_EQUAL_INT(30,E_OK, result_inst_22);
	
	SCHEDULING_CHECK_INIT(31);
	result_inst_23 = IncrementCounter(Software_Counter);
	/*offset = 1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(31,E_OK, result_inst_23);
	
	SCHEDULING_CHECK_INIT(32);
	result_inst_24 = IncrementCounter(Software_Counter);
	/*offset = 2 */
	SCHEDULING_CHECK_AND_EQUAL_INT(32,E_OK, result_inst_24);

}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq6_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}

/* End of file autosar_st_s6/task1_instance.c */
