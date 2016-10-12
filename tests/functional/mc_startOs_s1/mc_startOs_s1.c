/**
 * @file tasks_s2/tasks_s2.c
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
/* --------------------------------------------------------------------------
 *  Requirement  | Short description                  | Verified
 * --------------------------------------------------------------------------
 * SWS_Os_00606  | StartCore after StartOS returns    | Y : Test 1
 *               | E_OS_ACCESS
 * SWS_Os_00607  | StartOS starts OS on calling core  | Y : t2 not executed
 * SWS_Os_00608  | AppModes shall be the same         | Not Tested
 * SWS_Os_00609  | If AppMode = DONOTCARE, then th    | Not Tested
 *               | AppMode is = to other cores.
 * SWS_Os_00610  | At least one AppMode != DONOTCARE  | Not Tested
 * SWS_Os_00611  | StartOS initializes IOC if any     | Not Tested
 */

#include "tpl_os.h"
#include "embUnit.h"

TestRef TaskManagementTest_seq2_t1_instance(void);
TestRef TaskManagementTest_seq2_t2_instance(void);

int main(void)
{
#if NUMBER_OF_CORES > 1
    StatusType rv;

    switch(GetCoreID()){
      case OS_CORE_ID_MASTER :
        StartOS(OSDEFAULTAPPMODE);
        break;
      case OS_CORE_ID_1 :
        StartOS(OSDEFAULTAPPMODE);
        break;
      default :
        /* Should not happen */
        break;
    }
#else
# error "This is a multicore example. NUMBER_OF_CORES should be > 1"
#endif
  return 0;
}

void ShutdownHook(StatusType error)
{
  TestRunner_end();
}

TASK(t1)
{
  TestRunner_start();
  TestRunner_runTest(TaskManagementTest_seq2_t1_instance());
  ShutdownOS(E_OK);
}

TASK(t2)
{
  TestRunner_runTest(TaskManagementTest_seq2_t2_instance());
}

/* End of file tasks_s2/tasks_s2.c */
