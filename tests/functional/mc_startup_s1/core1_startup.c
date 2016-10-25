/**
 * @file mc_startup_s1/core1_startup.c
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

static void test_c1_startup(void)
{
  SCHEDULING_CHECK_STEP(2);
}

TestRef c1_startup(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_c1_startup", test_c1_startup)
  };
  EMB_UNIT_TESTCALLER(caller,"mc_startup_s1",NULL,NULL,fixtures);
  return (TestRef)&caller;
}

/* End of file mc_startup_s1/core1_startup.c */
