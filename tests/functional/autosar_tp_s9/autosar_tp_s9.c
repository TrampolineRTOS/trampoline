/**
 * @file autosar_tp_s9/autosar_tp_s9.c
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

TestRef AutosarTPTest_seq9_t1_instance(void);
TestRef AutosarTPTest_seq9_isr1_instance1(void);
TestRef AutosarTPTest_seq9_isr1_instance2(void);
TestRef AutosarTPTest_seq9_isr1_instance3(void);
TestRef AutosarTPTest_seq9_isr2_instance1(void);
TestRef AutosarTPTest_seq9_isr2_instance2(void);
TestRef AutosarTPTest_seq9_protection_instance(void);

StatusType instance_protection = 0;
StatusType instance_isr1=0;
StatusType instance_isr2=0;
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

void ErrorHook(StatusType error)
{
  addFailure("ErrorHook : Instance error\n", __LINE__, __FILE__);	
}


ProtectionReturnType ProtectionHook(StatusType Fatalerror)
{
  Fatalerrorstatus = Fatalerror;
	TestRunner_runTest(AutosarTPTest_seq9_protection_instance());
	return PRO_TERMINATETASKISR;
}

TASK(t1)
{
  TestRunner_start();
  TestRunner_runTest(AutosarTPTest_seq9_t1_instance());
  ShutdownOS(E_OK);
}

ISR(softwareInterruptHandler0)
{
  instance_isr1++;
	switch (instance_isr1)
	{
		case 1 :
		{
      TestRunner_runTest(AutosarTPTest_seq9_isr1_instance1());
			break;
		}
		case 2 :
		{
      TestRunner_runTest(AutosarTPTest_seq9_isr1_instance2());
      break;
		}
		case 3 :
		{
      TestRunner_runTest(AutosarTPTest_seq9_isr1_instance3());
      break;
		}
		default:
		{
			addFailure("isr1 : Instance error\n", __LINE__, __FILE__);
			break;
		}
	}
}

ISR(softwareInterruptHandler1)
{ 
  instance_isr2++;
	switch (instance_isr2)
	{
		case 1 :
		{
      TestRunner_runTest(AutosarTPTest_seq9_isr2_instance1());
			break;
		}
		case 2 :
		{
      TestRunner_runTest(AutosarTPTest_seq9_isr2_instance2());
      break;
		}
		default:
		{
			addFailure("isr2 : Instance error\n", __LINE__, __FILE__);
			break;
		}
	}
}

/* End of file autosar_tp_s9/autosar_tp_s9.c */
