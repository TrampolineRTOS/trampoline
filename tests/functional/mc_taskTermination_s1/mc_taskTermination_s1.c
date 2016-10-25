/**
 * @file tasks_s2/tasks_s2.c
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
/* ----------------------------------------------------------------------------
 * Verification tags
 * ----------------------------------------------------------------------------
 * {...}      : Verified by tests numbers (...)
 * NoTimeout  : Verified if the execution did not timeout
 * NoErr      : If a failure has not been reached
 * Internal   : Cannot be tested here. Need to look at the code directly
 * Trivial    : No need to be tested
 * Goil       : Tested by Goil's Checks section
 * TODO       : Test not written
 */
/* --------------------------------------------------------------------------
 *  Requirement  | Short description                  | Verified
 * --------------------------------------------------------------------------
 * SWS_Os_00612  | TerminateTask / ChainTask returns  | {1,2,3}
 *               | with E_OS_SPINLOCK if has spinlock
 * SWS_Os_00613  | Spinlocks released after tp hook   | {4}, NoTimeout
 */

#include "tpl_os.h"

TestRef t1_instance(void);
TestRef t2_instance(void);

int main(void)
{
#if NUMBER_OF_CORES > 1
  StatusType rv;

  switch(GetCoreID())
  {
    case OS_CORE_ID_MASTER :
      TestRunner_start();
      SyncAllCores_Init();
      StartCore(OS_CORE_ID_1, &rv);
      if(rv == E_OK)
        StartOS(OSDEFAULTAPPMODE);
      break;
    case OS_CORE_ID_1 :
      StartOS(OSDEFAULTAPPMODE);
      break;
    default :
      /* Should not happen */
      break;
  }
#else
# error "This is a multicore example. NUMBER_OF_CORES should be > 1"
#endif
  return 0;
}

void ShutdownHook(StatusType error)
{
  switch(GetCoreID())
  {
    case OS_CORE_ID_MASTER :
      TestRunner_end();
      break;
    default :
      while(1); /* Slave cores wait here */
      break;
  }
}

FUNC(ProtectionReturnType, OS_CODE) ProtectionHook(
  VAR(StatusType, AUTOMATIC) FatalError)
{
  return PRO_TERMINATETASKISR; /* => Send this core to Idle function */
}

TASK(t1)
{
  ActivateTask(t2);
  TestRunner_runTest(t1_instance());
  ShutdownOS(E_OK);
}

TASK(t2)
{
  TestRunner_runTest(t2_instance());
  ShutdownOS(E_OK);
}

TASK(chain)
{
  addFailure("Chain task has been called...\n", __LINE__, __FILE__);
  /* Should not happen */
  while(1);
}

/* End of file tasks_s2/tasks_s2.c */
