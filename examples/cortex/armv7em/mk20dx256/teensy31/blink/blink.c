/**
 * @file blink.c
 *
 * @section desc File description
 *
 * Simple blink example.
 *
 * One alarm and one task are used for this simple example.
 * Alarm 'blink_blink' activates task 'blink' and make it a periodic task.
 * The alarm is AUTOSTART so it runs when the OS is started. Period is
 * set to 500 ticks (1 ms tick). See blink.oil
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  /* board LED as output */
  pinMode(13, OUTPUT);
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

FUNC(void, OS_CODE) PanicHook(VAR(uint8, AUTOMATIC) fault)
{
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
TASK(blink)
{
  static uint8 ledState = HIGH;

  digitalWrite(13, ledState);
  ledState = !ledState;

  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"


