/**
 * @file tasks_s2/isr_instance.c
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

DeclareSpinlock(already_taken);
DeclareSpinlock(lock_isr);
DeclareSpinlock(sync);

static void test_isr_instance(void)
{
  StatusType r1, r2, r3, r4, r5;
  TryToGetSpinlockType success;

  /* Get two times the same spinlock */
  SCHEDULING_CHECK_INIT(14);
  r1 = GetSpinlock(already_taken);
  SCHEDULING_CHECK_AND_EQUAL_INT(14, E_OK, r1);
  SCHEDULING_CHECK_INIT(15);
  r2 = GetSpinlock(already_taken);
  SCHEDULING_CHECK_AND_EQUAL_INT(15, E_OS_INTERFERENCE_DEADLOCK, r2);

  /* Release already_taken */
  SCHEDULING_CHECK_INIT(16);
  r3 = ReleaseSpinlock(already_taken);
  SCHEDULING_CHECK_AND_EQUAL_INT(16, E_OK, r3);

  /* Core 0 has the spinlock lock_isr */
  SCHEDULING_CHECK_INIT(17);
  r4 = TryToGetSpinlock(already_taken, &success);
  SCHEDULING_CHECK_AND_EQUAL_INT(17, E_OK, r4);
  SCHEDULING_CHECK_INIT(18);
  SCHEDULING_CHECK_AND_EQUAL_INT(18, TRYTOGETSPINLOCK_SUCCESS, success);

  /* Release already_taken */
  ReleaseSpinlock(already_taken);

  /* Core 0 has the spinlock lock_isr */
  SCHEDULING_CHECK_INIT(19);
  r5 = TryToGetSpinlock(lock_isr, &success);
  SCHEDULING_CHECK_AND_EQUAL_INT(19, E_OK, r5);
  SCHEDULING_CHECK_INIT(20);
  SCHEDULING_CHECK_AND_EQUAL_INT(20, TRYTOGETSPINLOCK_NOSUCCESS, success);

  /* Release the core0 so he goes to ShutdownOs*/
  SyncAllCores(sync);
}

TestRef isr_instance(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_isr_instance",test_isr_instance)
  };
  EMB_UNIT_TESTCALLER(caller,"mc_spinlocks_s1",NULL,NULL,fixtures);
  return (TestRef)&caller;
}

/* End of file tasks_s2/task1_instance.c */

