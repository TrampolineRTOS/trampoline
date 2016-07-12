/**
 * @file multicore_s1/multicore_s1.c
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
#include "tpl_os.h"

#define MAX_SHARED_1 3
#define MAX_SHARED_2 5

DeclareSpinlock(spin0);
DeclareSpinlock(spin1);

DeclareTask(producer);
DeclareTask(consumer_1);
DeclareTask(consumer_2);

VAR(boolean, AUTOMATIC) restock = FALSE;
VAR(uint32, AUTOMATIC) shared_1 = 0;
VAR(uint32, AUTOMATIC) shared_2 = 0;

#define APP_COMMON_START_SEC_CODE
#include "tpl_memmap.h"

int main(void)
{
  StatusType rv;

  switch(GetCoreID()){
    case OS_CORE_ID_MASTER :
      initLed();
      setLed(0, 0);
      setLed(1, 0);
      setLed(2, 0);
      setLed(3, 0);
      /* Wakeup core 1 */
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
  return 0;
}

void update_leds()
{
  setLed(0, (shared_1/MAX_SHARED_1) & 0x1);
  setLed(1, (shared_2/MAX_SHARED_2) & 0x1);
}

#define APP_COMMON_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_producer_START_SEC_CODE
#include "tpl_memmap.h"
TASK(producer)
{
  restock = FALSE;
  GetSpinlock(spin0);
  GetSpinlock(spin1);

  if (shared_1 < MAX_SHARED_1)
    shared_1++;
  else if(shared_2 < MAX_SHARED_2)
    shared_2++;
  update_leds();

  ReleaseSpinlock(spin1);
  ReleaseSpinlock(spin0);
  TerminateTask();
}
#define APP_Task_producer_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_consumer_1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(consumer_1)
{
  GetSpinlock(spin0);
  shared_1 = 0;
  ReleaseSpinlock(spin0);
  TerminateTask();
}
#define APP_Task_consumer_1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_consumer_2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(consumer_2)
{
  GetSpinlock(spin1);
  shared_2 = 0;
  ReleaseSpinlock(spin1);
  TerminateTask();
}
#define APP_Task_consumer_2_STOP_SEC_CODE
#include "tpl_memmap.h"


