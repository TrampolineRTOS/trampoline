/**
 * @file ioc_s4/ioc_s4.c
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


TestRef TaskManagementTest_seq4_t1_instance(void);
TestRef TaskManagementTest_seq4_t2_instance(void);



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
  TestRunner_end();
}

#define TEST_STOP_SEC_CODE
#include "tpl_memmap.h"



#define APP_Task_t1_START_SEC_CODE
#include "tpl_memmap.h"

TASK(t1)
{
  TestRunner_start();
  TestRunner_runTest(TaskManagementTest_seq4_t1_instance());
  TestRunner_end();
}

#define APP_Task_t1_STOP_SEC_CODE
#include "tpl_memmap.h"




#define APP_Task_t2_START_SEC_CODE
#include "tpl_memmap.h"

TASK(t2)
{

  TestRunner_runTest(TaskManagementTest_seq4_t2_instance());

}

#define APP_Task_t2_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file ioc_s3/ioc_s3.c */
