/**
 * @file tasks_s2/task1_instance.c
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
DeclareSpinlock(lock_task);
DeclareSpinlock(lock_isr);
DeclareSpinlock(already_taken);
DeclareSpinlock(not_successor);
DeclareTask(t2);

static void test_t1_instance(void)
{
  StatusType r1, r2, r3, r4, r5, r6, r7, r8, r9;
  TryToGetSpinlockType success;

  /* Get two times the same spinlock */
  SCHEDULING_CHECK_INIT(1);
  r1 = GetSpinlock(already_taken);
  SCHEDULING_CHECK_AND_EQUAL_INT(1, E_OK, r1);
  SCHEDULING_CHECK_INIT(2);
  r2 = GetSpinlock(already_taken);
  SCHEDULING_CHECK_AND_EQUAL_INT(2, E_OS_INTERFERENCE_DEADLOCK, r2);

  /* Get a spinlock that is not the successor of "already_taken" */
  SCHEDULING_CHECK_INIT(3);
  r3 = GetSpinlock(not_successor);
  SCHEDULING_CHECK_AND_EQUAL_INT(3, E_OS_NESTING_DEADLOCK, r3);
  /* Release already_taken */
  SCHEDULING_CHECK_INIT(4);
  r4 = ReleaseSpinlock(already_taken);
  SCHEDULING_CHECK_AND_EQUAL_INT(4, E_OK, r4);

  /* Retry to get not_successor */
  SCHEDULING_CHECK_INIT(5);
  r5 = GetSpinlock(not_successor);
  SCHEDULING_CHECK_AND_EQUAL_INT(5, E_OK, r5);
  /* Release not_successor */
  SCHEDULING_CHECK_INIT(6);
  r6 = ReleaseSpinlock(not_successor);
  SCHEDULING_CHECK_AND_EQUAL_INT(6, E_OK, r6);

  /* TryToGetSpinlock test to get lock_task */
  SCHEDULING_CHECK_INIT(7);
  r7 = TryToGetSpinlock(lock_task, &success);
  SCHEDULING_CHECK_AND_EQUAL_INT(7, E_OK, r7);
  SCHEDULING_CHECK_INIT(8);
  SCHEDULING_CHECK_AND_EQUAL_INT(8, TRYTOGETSPINLOCK_SUCCESS, success);

  /* Get lock_isr that is successor of lock_task */
  SCHEDULING_CHECK_INIT(9);
  r8 = GetSpinlock(lock_isr);
  SCHEDULING_CHECK_AND_EQUAL_INT(9, E_OK, r8);

  /* Activate t2 */
  SCHEDULING_CHECK_INIT(10);
  r9 = ActivateTask(t2);
  SCHEDULING_CHECK_AND_EQUAL_INT(10, E_OK, r9);

  /* Wait for the core 1 to end its tests */
  SyncAllCores(sync);
}

TestRef t1_instance(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t1_instance",test_t1_instance)
  };
  EMB_UNIT_TESTCALLER(caller,"mc_spinlocks_s1",NULL,NULL,fixtures);
  return (TestRef)&caller;
}

/* End of file tasks_s2/task1_instance.c */
