/**
 * @file mc_schedtables_s1/task2_instance.c
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
DeclareEvent(t2_event);

static void test_t2_instance(void)
{
  StatusType r1;

  SCHEDULING_CHECK_INIT(2);
  r1 = WaitEvent(t2_event);
  SCHEDULING_CHECK_AND_EQUAL_INT(2, E_OK, r1);

  SyncAllCores(sync0);

  /* Wait for the core0 to reach the end of its tests */
  SyncAllCores(sync1);
}

TestRef t2_instance(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t2_instance",test_t2_instance)
  };
  EMB_UNIT_TESTCALLER(caller,"mc_schedtables_s1",NULL,NULL,fixtures);
  return (TestRef)&caller;
}

/* End of file mc_schedtables_s1/task2_instance.c */
