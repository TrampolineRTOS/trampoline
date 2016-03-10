/**
 * @file isr2onPIT.c
 *
 * @section desc File description
 *
 * Simple isr example.
 *
 * A periodic task toggles the built in led of the teensy the board every
 * 500ms by using an alarm. In addition the task gets the current value
 * of the PIT0 timer and print it on the LCD. This runs at start.
 *
 * PIT0 timer is programmed to count down from 100000000 (100 millions).
 * With the 48MHz clock, this corresponds to a 2,0833333 seconds period
 * An IRQ (PIT0_IRQ) is programmed and, when the timer reaches 0, it
 * leads to the execution of ISR category 2 timer.
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

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * A LiquidCrystalFast object is instantiated.
 * Pin numbers are per Teensyduino specification
 */
LiquidCrystalFast lcd(18,17,16,15,14,19);

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  /* For LCD 20 columns, 4 rows */
  lcd.begin(20,4);

  /* board LED as output */
  pinMode(13, OUTPUT);
  /* LED L0-3 as output */
  pinMode(3, OUTPUT);
  /* LED L1-4 as output */
  pinMode(4, OUTPUT);

  /* pin 8 as input for the button */
  pinMode(8, INPUT_PULLUP);

  /*
   * Priority of Systick and SVCCall are set to 128
   * So priority of PIT0 is set to 128 too. That way
   * an ISR2 IRQ cannot interrupt a Systick ISR or the Syscall
   * Should be done by generated code in the future.
   */
  NVIC_SET_PRIORITY(IRQ_PIT_CH0, 128);
  NVIC_ENABLE_IRQ(IRQ_PIT_CH0);

  /*
   * Enable access to the PIT module registers when in
   * unprivileged thread mode
   */
  PITEnableUserAccess();
  /* Enable the clock for the PIT module */
  PITEnableClock();
  /* Enable the module itself */
  PITEnableModule();
  /* Set the reload value of timer 0 */
  PITSetTimerLoad(0, 100000000);
  /* Enable interrupts for timer 0 */
  PITEnableTimerInterrupt(0);
  /* Start timer 0 */
  PITEnableTimer(0);

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

  digitalWrite(4, HIGH);

  digitalWrite(13, ledState);
  ledState = !ledState;

  lcd.setCursor(0,0);
  lcd.print(PITTimerValue(0));
  lcd.print("        ");
  lcd.setCursor(0,2);
  lcd.print(PIT_CHANNEL[0].PIT_TFLG);

  digitalWrite(4, LOW);

  TerminateTask();
}

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_timer_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * This ISR2 is triggered by the PIT Channel 0 interrupt
 */
ISR(timer)
{
  digitalWrite(3, !digitalRead(3));
}
#define APP_ISR_timer_STOP_SEC_CODE
#include "tpl_memmap.h"



