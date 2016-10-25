/**
 * @file tasks_s1_full/task2_instance.c
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

/*Instance of task t2*/

#include "ioc_types.h"
/*#include "test_hal.h"*/
#include "Os.h"

DeclareTask(t1);
DeclareTask(t2);

#define APP_Task_t2_START_SEC_CODE
#include "tpl_memmap.h"
static void test_t2_instance1(void)
{
  Std_ReturnType result_inst_1, result_inst_2, result_inst_3;

  TestType1 data1 = 0x00;
  TestType2 data2 = {0x00, 0x00};
	
  SCHEDULING_CHECK_INIT(1);
  result_inst_1 = IocRead_ioc1(&data1);
  SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(1,IOC_E_OK, result_inst_1);
  SCHEDULING_CHECK_AND_EQUAL_INT(1,0xFF, data1);
	
  SCHEDULING_CHECK_INIT(2);
  result_inst_2 = IocRead_ioc2(&data2);
  SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(2,IOC_E_OK, result_inst_2);
  SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(2,0xFF, data2.a);
  SCHEDULING_CHECK_AND_EQUAL_INT(2,0xFF, data2.b);
	
  SCHEDULING_CHECK_INIT(3);
  result_inst_3 = IocRead_ioc3(&data2);
  SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(3,IOC_E_OK, result_inst_3);
  SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(3,0xFA, data2.a);
  SCHEDULING_CHECK_AND_EQUAL_INT(3,0xFA, data2.b);

  SCHEDULING_CHECK_STEP(4);

  TerminateTask();

}


static void test_t2_instance2(void)
{
  Std_ReturnType result_inst_1, result_inst_2, result_inst_3;

  TestType1 data1 = 0x00;
  TestType2 data2;
  data2.a=0x00;
  data2.b=0x00;

  SCHEDULING_CHECK_INIT(9);
  result_inst_1 = IocRead_ioc1(&data1);
  SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(9,IOC_E_OK, result_inst_1);
  SCHEDULING_CHECK_AND_EQUAL_INT(9,0x01, data1);
	
  SCHEDULING_CHECK_INIT(10);
  result_inst_2 = IocRead_ioc2(&data2);
  SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(10,IOC_E_OK, result_inst_2);
  SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(10,0x01, data2.a);
  SCHEDULING_CHECK_AND_EQUAL_INT(10,0x02, data2.b);
	
  SCHEDULING_CHECK_INIT(11);
  result_inst_3 = IocRead_ioc3(&data2);
  SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(11,IOC_E_OK, result_inst_3);
  SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(11,0x0A, data2.a);
  SCHEDULING_CHECK_AND_EQUAL_INT(11,0x0B, data2.b);

  SCHEDULING_CHECK_STEP(12);

  TerminateTask();

}
#define APP_Task_t2_STOP_SEC_CODE
#include "tpl_memmap.h"


#define TEST_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
  EMB_UNIT_TESTFIXTURES(fixtures1) {
    new_TestFixture(NULL,test_t2_instance1)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest1,NULL,NULL,NULL,fixtures1);

  EMB_UNIT_TESTFIXTURES(fixtures2) {
    new_TestFixture(NULL,test_t2_instance2)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest2,NULL,NULL,NULL,fixtures2);
#define TEST_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define APP_Task_t2_START_SEC_CODE
#include "tpl_memmap.h"
/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq2_t2_instance1(void)
{
/*
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t2_instance1",test_t2_instance1)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence2",NULL,NULL,fixtures);
*/
  return (TestRef)&TaskManagementTest1;
}

TestRef TaskManagementTest_seq2_t2_instance2(void)
{
/*
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t2_instance2",test_t2_instance2)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence2",NULL,NULL,fixtures);
*/
  return (TestRef)&TaskManagementTest2;
}
#define APP_Task_t2_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file ioc_s2/task2_instance.c */
