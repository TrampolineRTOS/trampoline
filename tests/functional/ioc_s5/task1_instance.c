/**
 * @file ioc_s5/task1_instance.c
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

#include "ioc_types.h"
/*#include "test_hal.h"*/
#include "Os.h"

DeclareTask(t2);
DeclareTask(t3);
DeclareTask(INVALID_TASK);

#define TEST_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
char strTestFixtureNamet1[]="test_t1_instance";
char strTestCallerNamet1[]="TaskManagementTest_sequence5";
#define TEST_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define APP_Task_t1_START_SEC_CODE
#include "tpl_memmap.h"

static void test_t1_instance(void)
{
  Std_ReturnType  result_inst_1, result_inst_2;
  StatusType result_inst_3, result_inst_4;

  TestType1 data1 = 0x01;
  TestType2 data2;
  data2.a=0x01;
  data2.b=0x02;

  /* test Send */
  SCHEDULING_CHECK_INIT(1);
  result_inst_1 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(1,IOC_E_OK, result_inst_1);

  SCHEDULING_CHECK_INIT(2);
  result_inst_2 = IocWrite_ioc2(&data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(2,IOC_E_OK, result_inst_2);

  SCHEDULING_CHECK_INIT(3);
  result_inst_3 = ActivateTask(t3);
  SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_3);

  SCHEDULING_CHECK_INIT(7);
  result_inst_4 = ActivateTask(t2);
  SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_4);

  SCHEDULING_CHECK_STEP(11);

}

#define APP_Task_t1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define TEST_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture(strTestFixtureNamet1,test_t1_instance)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,strTestCallerNamet1,NULL,NULL,fixtures);
#define TEST_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define APP_Task_t1_START_SEC_CODE
#include "tpl_memmap.h"

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq5_t1_instance(void)
{
/*
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture(strTestFixtureNamet1,test_t1_instance)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,strTestCallerNamet1,NULL,NULL,fixtures);
*/
  return (TestRef)&TaskManagementTest;
}

#define APP_Task_t1_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file ioc_s4/task1_instance.c */
