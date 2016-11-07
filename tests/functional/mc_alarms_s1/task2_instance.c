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

DeclareAlarm(should_not_expire);
DeclareEvent(t2_event);
DeclareSpinlock(sync);

static void test_t2_instance(void)
{
  StatusType r1, r2, r3, r4, r5, r6, r7;
  TickRefType tickRef = NULL_PTR;
  AlarmBaseRefType alarmRef = NULL_PTR;

  /* Start an alarm in another core (Absolute) */
  SCHEDULING_CHECK_INIT(3);
  r1 = SetAbsAlarm(should_not_expire, 15, 0);
  SCHEDULING_CHECK_AND_EQUAL_INT(3, E_OK, r1);

  /* Stop it */
  SCHEDULING_CHECK_INIT(4);
  r2 = CancelAlarm(should_not_expire);
  SCHEDULING_CHECK_AND_EQUAL_INT(4, E_OK, r2);

  /* Start an alarm in another core (Relative) */
  SCHEDULING_CHECK_INIT(5);
  r3 = SetRelAlarm(should_not_expire, 5, 0);
  SCHEDULING_CHECK_AND_EQUAL_INT(5, E_OK, r3);

  /* Stop it */
  SCHEDULING_CHECK_INIT(6);
  r4 = CancelAlarm(should_not_expire);
  SCHEDULING_CHECK_AND_EQUAL_INT(6, E_OK, r4);

  /* Get alarm tests */
  SetRelAlarm(should_not_expire, 5, 0);

  SCHEDULING_CHECK_INIT(7);
  r5 = GetAlarmBase(should_not_expire, alarmRef);
  SCHEDULING_CHECK_AND_EQUAL_INT(7, E_OK, r5);

  SCHEDULING_CHECK_INIT(8);
  r6 = GetAlarm(should_not_expire, tickRef);
  SCHEDULING_CHECK_AND_EQUAL_INT(8, E_OK, r6);

  CancelAlarm(should_not_expire);

  /* Wait for t1's alarm to set the event */
  SCHEDULING_CHECK_INIT(9);
  r7 = WaitEvent(t2_event);
  SCHEDULING_CHECK_AND_EQUAL_INT(9, E_OK, r7);

  SyncAllCores(sync);
}

TestRef t2_instance(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t2_instance",test_t2_instance)
  };
  EMB_UNIT_TESTCALLER(caller,"mc_alarms_s1",NULL,NULL,fixtures);
  return (TestRef)&caller;
}

/* End of file tasks_s2/task1_instance.c */
