/**
 * @file mc_taskActivation_s1/task2_instance.c
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

DeclareSpinlock(end_of_tests);

static void test_t2_instance(void)
{
  /* Wait end of tests */
  SyncAllCores(end_of_tests);
}

TestRef t2_instance(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t2_instance", test_t2_instance)
  };
  EMB_UNIT_TESTCALLER(caller,"mc_taskActivation_s1",NULL,NULL,fixtures);
  return (TestRef)&caller;
}

/* End of file mc_taskActivation_s1/task2_instance.c */
