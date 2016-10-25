/**
 * @file com_internal_s4/com_internal_s4.c
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

#include "tpl_os.h"

TestRef COMInternalTest_seq4_t1_instance(void);
TestRef COMInternalTest_seq4_t2_instance(void);
TestRef COMInternalTest_seq4_t3_instance(void);
TestRef COMInternalTest_seq4_t4_instance(void);
TestRef COMInternalTest_seq4_comcallback_instance(void);

int com_error_instance = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(COMInternalTest_seq4_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(COMInternalTest_seq4_t2_instance());
	ShutdownOS(E_OK);
}

TASK(t3)
{
	TestRunner_runTest(COMInternalTest_seq4_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(COMInternalTest_seq4_t4_instance());
}

extern void ComCallBack_callback(void)
{	
	TestRunner_runTest(COMInternalTest_seq4_comcallback_instance());
}

/* End of file com_internal_s4/com_internal_s4.c */
