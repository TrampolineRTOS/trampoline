/**
 * @file ioc_s3/ioc_s3.c
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

#include "ioc_types.h"
#include "Os.h"
/*#include "test_hal.h"*/



TestRef TaskManagementTest_seq3_t1_instance(void);
TestRef TaskManagementTest_seq3_t2_instance1(void);
TestRef TaskManagementTest_seq3_t2_instance2(void);
TestRef TaskManagementTest_seq3_t2_instance3(void);



#define TEST_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
u8 instance_t2=0;
#define TEST_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"



#define TEST_START_SEC_CODE
#include "tpl_memmap.h"

int main(void)
{

  /*test_hal_init();*/



  StartOS(OSDEFAULTAPPMODE);
  return 0;
}


FUNC(ProtectionReturnType, OS_CODE) ProtectionHook(StatusType error)
{

  return PRO_SHUTDOWN;

}


void ShutdownHook(StatusType error)
{

}

#define TEST_STOP_SEC_CODE
#include "tpl_memmap.h"



#define APP_Task_t1_START_SEC_CODE
#include "tpl_memmap.h"

TASK(t1)
{
  TestRunner_start();
  TestRunner_runTest(TaskManagementTest_seq3_t1_instance());
  TestRunner_end();

}

#define APP_Task_t1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_t2_START_SEC_CODE
#include "tpl_memmap.h"

TASK(t2)
{
  instance_t2 ++;
  switch(instance_t2)
  {
    case 1:
    {
      TestRunner_runTest(TaskManagementTest_seq3_t2_instance1());

      break;
    }
    case 2:
    {
      TestRunner_runTest(TaskManagementTest_seq3_t2_instance2());
      break;
    }
    case 3:
    {
      TestRunner_runTest(TaskManagementTest_seq3_t2_instance3());
      break;
    }
    default:
    {
      addFailure("Instance error \n", __LINE__, __FILE__);
      break;
    }
  }

  TerminateTask();
}

#define APP_Task_t2_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file ioc_s3/ioc_s3.c */
