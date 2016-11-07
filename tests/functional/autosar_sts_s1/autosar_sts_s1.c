/**
 * @file autosar_sts_s1/autosar_sts_s1.c
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

TestRef AutosarSTSTest_seq1_t1_instance(void);
TestRef AutosarSTSTest_seq1_t2_instance(void);
TestRef AutosarSTSTest_seq1_error_instance1(void);
TestRef AutosarSTSTest_seq1_error_instance2(void);
TestRef AutosarSTSTest_seq1_error_instance3(void);

StatusType instance_error = 0;

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
	instance_error++;
	switch (instance_error) {
		case 1:
		{
			TestRunner_runTest(AutosarSTSTest_seq1_error_instance1());	
			break;
		}
		case 2:
		{
			TestRunner_runTest(AutosarSTSTest_seq1_error_instance2());	
			break;
		}
		case 3:
		{
			TestRunner_runTest(AutosarSTSTest_seq1_error_instance3());	
			break;
		}
		default:
		{
			addFailure("instance error\n", __LINE__, __FILE__);
			break;
		}
	}
	
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(AutosarSTSTest_seq1_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(AutosarSTSTest_seq1_t2_instance());
}

/* End of file autosar_sts_s1/autosar_sts_s1.c */
