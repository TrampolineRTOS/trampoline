/**
 * @file tasks_s2/task2_instance.c
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

DeclareSpinlock(lock_task);
DeclareSpinlock(sync);

static void test_t2_instance(void)
{
  StatusType r1, r2;
  TryToGetSpinlockType success;

  /* Core 0 has the spinlock lock_task */
  SCHEDULING_CHECK_INIT(11);
  r1 = TryToGetSpinlock(lock_task, &success);
  SCHEDULING_CHECK_AND_EQUAL_INT(11, E_OK, r1);
  SCHEDULING_CHECK_INIT(12);
  SCHEDULING_CHECK_AND_EQUAL_INT(12, TRYTOGETSPINLOCK_NOSUCCESS, success);

  /* Blocking call. We're waiting for the timing protection watchdog to kill us
   * dramatically. We're using GetSpinlock_IE instead of GetSpinlock to allow
   * the interruptions during the call.
   */
  SCHEDULING_CHECK_INIT(13);
  r2 = GetSpinlock_IE(lock_task);
  SCHEDULING_CHECK_AND_EQUAL_INT(13, E_OK, r2);

  while(1);

  SyncAllCores(sync);
}

TestRef t2_instance(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t2_instance",test_t2_instance)
  };
  EMB_UNIT_TESTCALLER(caller,"mc_spinlocks_s1",NULL,NULL,fixtures);
  return (TestRef)&caller;
}

/* End of file tasks_s2/task1_instance.c */
