/**
 * @file ioc_s5/task3_instance.c
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


#define TEST_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
char strTestFixtureNamet3[]="test_t3_instance";
char strTestCallerNamet3[]="TaskManagementTest_sequence5";
#define TEST_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define APP_Task_t3_START_SEC_CODE
#include "tpl_memmap.h"

static void test_t3_instance(void)
{
  Std_ReturnType result_inst_1;

  TestType1 data1 = 0xAA;
  TestType2 data2;
  data2.a=0xAA;
  data2.b=0xAA;


  SCHEDULING_CHECK_INIT(4);
  result_inst_1 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(4,IOC_E_NOT_OK, result_inst_1);

  SCHEDULING_CHECK_INIT(5);
  result_inst_1 = IocReceive_ioc1(&data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(5,IOC_E_NOT_OK, result_inst_1);

  SCHEDULING_CHECK_STEP(6);

  TerminateTask();


}

#define APP_Task_t3_STOP_SEC_CODE
#include "tpl_memmap.h"



#define TEST_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture(strTestFixtureNamet3,test_t3_instance)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,strTestCallerNamet3,NULL,NULL,fixtures);
#define TEST_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"



#define APP_Task_t3_START_SEC_CODE
#include "tpl_memmap.h"

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq5_t3_instance(void)
{
/*
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture(strTestFixtureNamet3,test_t3_instance)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,strTestCallerNamet3,NULL,NULL,fixtures);
*/
  return (TestRef)&TaskManagementTest;
}

#define APP_Task_t3_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file ioc_s5/task3_instance.c */
