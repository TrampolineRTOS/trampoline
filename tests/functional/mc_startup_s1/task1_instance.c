/**
 * @file mc_startup_s1/task1_instance.c
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

DeclareSpinlock(sync);
DeclareSpinlock(end_of_tests);

extern uint32 coresInStartupHook[NUMBER_OF_CORES];

static void test_t1_instance(void)
{
  StatusType r1;
  int i;
  int testNumber = 3;
  int totalCores = GetNumberOfActivatedCores();

  /* Be sure the other cores have finished executing the StartupHook */
  SyncAllCores(sync);

  /* For each activated core, check if it has successfully executed the
   * StartupHook.
   */
  for(i = 0; i < totalCores; i++, testNumber++)
  {
    SCHEDULING_CHECK_INIT(testNumber);
    SCHEDULING_CHECK_AND_EQUAL_INT(testNumber, 1, coresInStartupHook[i]);
  }

  /* Notify end of tests */
  SyncAllCores(end_of_tests);
}

/*create the test suite with all the test cases*/
TestRef t1_instance(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t1_instance", test_t1_instance)
  };
  EMB_UNIT_TESTCALLER(caller,"mc_startup_s1",NULL,NULL,fixtures);
  return (TestRef)&caller;
}

/* End of file mc_startup_s1/task1_instance.c */
