/**
 * @file autosar_tp_s6/autosar_tp_s6.c
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
#include "embUnit.h"
#include "config.h" /*for stdimpl_print*/

TestRef AutosarTPTest_seq6_t1_instance(void);
TestRef AutosarTPTest_seq6_protection_instance1(void);
TestRef AutosarTPTest_seq6_protection_instance2(void);

StatusType errorstatus;
StatusType Fatalerrorstatus;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

ProtectionReturnType ProtectionHook(StatusType Fatalerror)
{

  Fatalerrorstatus = Fatalerror;
  switch(Fatalerrorstatus)
  {
      case E_OS_PROTECTION_ARRIVAL:
          /*printf("ProtectionHook1:E_OS_PROTECTIONARRIVAL:@%d\n", tpl_get_local_current_date());*/
          TestRunner_runTest(AutosarTPTest_seq6_protection_instance1());
          return PRO_IGNORE;
      case E_OS_PROTECTION_TIME:
          /*printf("ProtectionHook2:E_OS_TIME:@%d\n", tpl_get_local_current_date());*/
          TestRunner_runTest(AutosarTPTest_seq6_protection_instance2());
          return PRO_SHUTDOWN;
  }
  return PRO_SHUTDOWN;
}

TASK(t1)
{
  TestRunner_start();
  TestRunner_runTest(AutosarTPTest_seq6_t1_instance());
}

/* End of file autosar_tp_s6/autosar_tp_s6.c */
