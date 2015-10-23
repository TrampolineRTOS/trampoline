/**
 * @file blink.c
 *
 * @section desc File description
 *
 * Simple startStorpBlink example.
 *
 * The basis of this application is the same as the blink example.
 * A periodic task  toggles the built in led of the teensy the board.
 * This runs at start.
 *
 * A second alarm with a period of 20ms scans a button connected on pin 8.
 * When the button is pressed, the alarm is cancelled.
 * When the button is pressed again the alarm is started again.
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
  pinMode(3, OUTPUT);
  /* pin 8 as input for the button */
  pinMode(8, INPUT_PULLUP);

  StartOS(OSDEFAULTAPPMODE);
  return 0;
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

DeclareAlarm(blink_blink);

typedef enum { BUTTON_OFF, BUTTON_PUSH, BUTTON_ON, BUTTON_RELEASE } ButtonState;

#define APP_Task_button_scanner_START_SEC_CODE
#include "tpl_memmap.h"
ButtonState readButton()
{
  static ButtonState state = BUTTON_OFF;
  uint8 button = digitalRead(8);

  switch (state)
  {
    case BUTTON_OFF:     if (button == LOW) state = BUTTON_PUSH; break;
    case BUTTON_PUSH:    state = BUTTON_ON; break;
    case BUTTON_ON:      if (button == HIGH) state = BUTTON_RELEASE; break;
    case BUTTON_RELEASE: state = BUTTON_OFF; break;
  }

  return state;
}

TASK(button_scanner)
{
  static uint8 state = HIGH;
  ButtonState button = readButton();

  if (button == BUTTON_PUSH) {
    if (state == HIGH)
    {
      CancelAlarm(blink_blink);
      state = LOW;
    }
    else
    {
      SetRelAlarm(blink_blink, 500, 500);
      state = HIGH;
    }
  }

  /* update the LED according to the state */
  digitalWrite(3, state);

  TerminateTask();
}
#define APP_Task_button_scanner_STOP_SEC_CODE
#include "tpl_memmap.h"


