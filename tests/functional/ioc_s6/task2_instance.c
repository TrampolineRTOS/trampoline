/**
 * @file ioc_s3/task2_instance.c
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
#include "tpl_os.h"

DeclareTask(t1);
DeclareTask(t2);

#define TEST_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
char strTestFixtureNameInst1[]="test_t2_instance1";
char strTestCallerNameInst1[]="TaskManagementTest_sequence3";

char strTestFixtureNameInst2[]="test_t2_instance2";
char strTestCallerNameInst2[]="TaskManagementTest_sequence3";

char strTestFixtureNameInst3[]="test_t2_instance3";
char strTestCallerNameInst3[]="TaskManagementTest_sequence3";
#define TEST_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define APP_Task_t2_START_SEC_CODE
#include "tpl_memmap.h"

static void test_t2_instance1(void)
{
  Std_ReturnType result_inst_1, result_inst_2, result_inst_3, result_inst_4;

  TestType1 data1 = 0x00;
  TestType2 data2;
  data2.a=0x00;
  data2.b=0x00;


  SCHEDULING_CHECK_INIT(4);
  result_inst_1 = IocSendGroup_ioc1(data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(4,IOC_E_NOT_OK, result_inst_1);
	
  SCHEDULING_CHECK_INIT(5);
  result_inst_2 = IocReceiveGroup_ioc1(&data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(5,IOC_E_OK, result_inst_2);	
	
  SCHEDULING_CHECK_INIT(6);
  result_inst_3 = IocSendGroup_ioc2(data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(6,IOC_E_OK, result_inst_3);
	
  SCHEDULING_CHECK_INIT(7);
  result_inst_4 = IocReceiveGroup_ioc2(&data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(7,IOC_E_NOT_OK, result_inst_4);

  SCHEDULING_CHECK_STEP(8);

}


static void test_t2_instance2(void)
{
  Std_ReturnType result_inst_1, result_inst_2;

  TestType1 data1 = 0x00;
  TestType2 data2 = {0x00, 0x00};

}



static void test_t2_instance3(void)
{
  Std_ReturnType result_inst_1;

  TestType1 data1 = 0x00;
  TestType2 data2 = {0x00, 0x00};

}

#define APP_Task_t2_STOP_SEC_CODE
#include "tpl_memmap.h"



#define TEST_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
  EMB_UNIT_TESTFIXTURES(fixtures1) {
    new_TestFixture(strTestFixtureNameInst1,test_t2_instance1)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest1,strTestCallerNameInst1,NULL,NULL,fixtures1);

  EMB_UNIT_TESTFIXTURES(fixtures2) {
    new_TestFixture(strTestFixtureNameInst2,test_t2_instance2)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest2,strTestCallerNameInst2,NULL,NULL,fixtures2);

  EMB_UNIT_TESTFIXTURES(fixtures3) {
    new_TestFixture(strTestFixtureNameInst3,test_t2_instance3)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest3,strTestCallerNameInst3,NULL,NULL,fixtures3);

#define TEST_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define APP_Task_t2_START_SEC_CODE
#include "tpl_memmap.h"

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq3_t2_instance1(void)
{
/*
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture(strTestFixtureNameInst1,test_t2_instance1)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,strTestCallerNameInst1,NULL,NULL,fixtures);
*/
  return (TestRef)&TaskManagementTest1;
}

TestRef TaskManagementTest_seq3_t2_instance2(void)
{
/*
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture(strTestFixtureNameInst2,test_t2_instance2)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,strTestCallerNameInst2,NULL,NULL,fixtures);
*/
  return (TestRef)&TaskManagementTest2;
}

TestRef TaskManagementTest_seq3_t2_instance3(void)
{
/*
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture(strTestFixtureNameInst3,test_t2_instance3)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,strTestCallerNameInst3,NULL,NULL,fixtures);
*/
  return (TestRef)&TaskManagementTest3;
}

#define APP_Task_t2_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file ioc_s3/task2_instance.c */
