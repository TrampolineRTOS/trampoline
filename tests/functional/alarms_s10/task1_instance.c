/**
 * @file alarms_s10/task1_instance.c
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

/*Instance of task t1*/

#include "tpl_os.h"

DeclareAlarm(Alarm1);

void WaitActivationOneShotAlarm(AlarmType Alarm);

/*test case:test the reaction of the system called with
an activation of a task*/
static void test_t1_instance(void)
{

  StatusType result_inst_1;

  SCHEDULING_CHECK_INIT(1);
  result_inst_1 = SetRelAlarm(Alarm1, 2, 0);
  SCHEDULING_CHECK_AND_EQUAL_INT(1, E_OK, result_inst_1);

  WaitActivationOneShotAlarm(Alarm1);

  SCHEDULING_CHECK_STEP(3);
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq10_t1_instance(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures){
      new_TestFixture("test_t1_instance", test_t1_instance)};
  EMB_UNIT_TESTCALLER(AlarmsTest, "AlarmsTest_sequence10", NULL, NULL,
                      fixtures);

  return (TestRef)&AlarmsTest;
}

/* End of file alarms_s10/task1_instance.c */
