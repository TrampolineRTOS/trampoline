/**
 * @file ioc_s1/task1_instance.c
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
#include "Std_Types.h"
/*#include "Rte.h"
#include "Rte_Type.h"*/

DeclareTask(t1);
DeclareTask(t2);
DeclareTask(t3);
DeclareTask(INVALID_TASK);

#define APP_Task_t1_START_SEC_CODE
#include "tpl_memmap.h"

static void test_t1_instance(void)
{
  Std_ReturnType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_8, result_inst_9,
              result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15;
  StatusType result_inst_7, result_inst_16;

  TestType1 data1 = 0x01;
  TestType2 data2;
  data2.a=0x01;
  data2.b=0x02;

  /* test send on simple data type */
  SCHEDULING_CHECK_INIT(1);
  result_inst_1 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(1,IOC_E_OK, result_inst_1);

  /* test send on complex data type */
  SCHEDULING_CHECK_INIT(2);
  result_inst_2 = IocSend_ioc2(&data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(2,IOC_E_OK, result_inst_2);

  /* test send with several senders */
  SCHEDULING_CHECK_INIT(3);
  result_inst_3 = IocSend_ioc3_sender1(&data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(3,IOC_E_OK, result_inst_3);

  /* test queue */
  SCHEDULING_CHECK_INIT(4);
  data1=0x02;
  result_inst_4 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(4,IOC_E_OK, result_inst_4);

  SCHEDULING_CHECK_INIT(5);
  data1=0x03;
  result_inst_5 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(5,IOC_E_OK, result_inst_5);

  SCHEDULING_CHECK_INIT(6);
  data1=0x04;
  result_inst_6 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(6,IOC_E_OK, result_inst_6);

  SCHEDULING_CHECK_INIT(7);
  result_inst_7 = ActivateTask(t2);
  SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OK, result_inst_7);
	
  /* test overflow on simple data type */
  SCHEDULING_CHECK_INIT(14);
  data1=0x01;
  result_inst_8 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(14,IOC_E_OK, result_inst_8);

  SCHEDULING_CHECK_INIT(15);
  data1=0x02;
  result_inst_9 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(15,IOC_E_OK, result_inst_9);

  SCHEDULING_CHECK_INIT(16);
  data1=0x03;
  result_inst_10 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(16,IOC_E_OK, result_inst_10);

  SCHEDULING_CHECK_INIT(17);
  data1=0x04;
  result_inst_11 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(17,IOC_E_OK, result_inst_11);

  SCHEDULING_CHECK_INIT(18);
  data1=0x05;
  result_inst_12 = IocSend_ioc1(data1);
  SCHEDULING_CHECK_AND_EQUAL_INT(18,IOC_E_LIMIT, result_inst_12);

  /* test overflow on multiple senders */
  SCHEDULING_CHECK_INIT(19);
  result_inst_13 = IocSend_ioc3_sender1(&data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(19,IOC_E_OK, result_inst_13);

  SCHEDULING_CHECK_INIT(20);
  result_inst_14 = IocSend_ioc3_sender1(&data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(20,IOC_E_OK, result_inst_14);

  SCHEDULING_CHECK_INIT(21);
  result_inst_15 = IocSend_ioc3_sender1(&data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(21,IOC_E_LIMIT, result_inst_15);

  SCHEDULING_CHECK_INIT(22);
  result_inst_16 = ActivateTask(t2);
  SCHEDULING_CHECK_AND_EQUAL_INT(29,E_OK, result_inst_16);


  SCHEDULING_CHECK_STEP(30);

}

#define APP_Task_t1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define TEST_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture(NULL,test_t1_instance)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,NULL,NULL,NULL,fixtures);
#define TEST_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define APP_Task_t1_START_SEC_CODE
#include "tpl_memmap.h"

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq1_t1_instance(void)
{
/*
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t1_instance",test_t1_instance)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence1",NULL,NULL,fixtures);
*/
  return (TestRef)&TaskManagementTest;
}

#define APP_Task_t1_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file ioc_s1/task1_instance.c */
