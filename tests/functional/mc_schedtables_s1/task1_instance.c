/**
 * @file mc_schedtables_s1/task1_instance.c
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

#include "Os.h"

DeclareSpinlock(sync0);
DeclareSpinlock(sync1);
DeclareEvent(t1_event);
DeclareScheduleTable(core0_schedtable);
DeclareScheduleTable(core1_schedtable);
DeclareScheduleTable(should_not_expire);

static void test_t1_instance(void)
{
  StatusType r1, r2, r3, r4, r5, r6;
  ScheduleTableStatusType status;

  /* Start core0's sched table */
  SCHEDULING_CHECK_INIT(1);
  r1 = StartScheduleTableRel(core0_schedtable, 5);
  SCHEDULING_CHECK_AND_EQUAL_INT(1, E_OK, r1);

  /* Wait for t2 to sync */
  SyncAllCores(sync0);

  SCHEDULING_CHECK_INIT(3);
  r2 = StartScheduleTableRel(should_not_expire, 10);
  SCHEDULING_CHECK_AND_EQUAL_INT(3, E_OK, r2);

  SCHEDULING_CHECK_INIT(4);
  r3 = StartScheduleTableAbs(core1_schedtable, 50);
  SCHEDULING_CHECK_AND_EQUAL_INT(4, E_OK, r3);

  SCHEDULING_CHECK_INIT(5);
  r4 = GetScheduleTableStatus(should_not_expire, &status);
  SCHEDULING_CHECK_AND_EQUAL_INT(5, E_OK, r4);
  SCHEDULING_CHECK_INIT(6);
  SCHEDULING_CHECK_AND_EQUAL_INT(6, TIME_OBJ_ACTIVE, status);

  SCHEDULING_CHECK_INIT(7);
  r5 = StopScheduleTable(should_not_expire);
  SCHEDULING_CHECK_AND_EQUAL_INT(7, E_OK, r5);

  SCHEDULING_CHECK_INIT(8);
  r6 = WaitEvent(t1_event);
  SCHEDULING_CHECK_AND_EQUAL_INT(8, E_OK, r6);

  SyncAllCores(sync1);
}

TestRef t1_instance(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t1_instance",test_t1_instance)
  };
  EMB_UNIT_TESTCALLER(caller,"mc_schedtables_s1",NULL,NULL,fixtures);
  return (TestRef)&caller;
}

/* End of file mc_schedtables_s1/task1_instance.c */
