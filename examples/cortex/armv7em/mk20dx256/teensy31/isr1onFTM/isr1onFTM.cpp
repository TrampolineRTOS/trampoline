/**
 * @file isr1onFTM.cpp
 *
 * @section desc File description
 *
 * ISR 1 example.
 *
 * Periodic task "pulse" runs every 20ms (ALARMTIME and CYCLETIME = 20).
 * I sets output 3 to HIGH and programs the FTM0 to generate an interrupt
 * after a time between 66,67µs and 13,33ms. The time is updated according
 * to the speed variable. This runs at start.
 *
 * ISR 1 "fmt_timer" sets output 3 to LOW and stops FTM0.
 *
 * As a result a pulse with a width between 66,67µs and 13,33ms is generated
 * on output 3.
 *
 * A periodic task toggles the built in led of the teensy the board every
 * 500ms by using an alarm. In addition the task gets the pulse width and
 * the speed variable and print it on the LCD. This runs at start.
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
   * Priority of FTM0 is set to 112 (priority higher than 128).
   * That way the ISR1 IRQ can interrupt a Systick ISR or the Syscall
   * Should be done by generated code in the future.
   */
  NVIC_SET_PRIORITY(IRQ_FTM0, 112);
  NVIC_ENABLE_IRQ(IRQ_FTM0);

  /*
   * Enable access to the FTM0 module registers when in
   * unprivileged thread mode
   */
  FTMEnableUserAccess(0);
  /* Enable the clock gating for the FTM0 module */
  FTMEnableClock(0);
  /* Set the min value to 0x0000 and the max value to 0xFFFF */
  FTMSetMinCounterValue(0, 0x0000);
  FTMSetMaxCounterValue(0, 0xFFFF);
  /* Up Counting */
  FTMSetUpCounting(0);
  /*
   * Set the prescaler to 16
   * That way the counter increments every 16 x 1/48e6 = 0,333333... us
   * A 1ms pulse witdh corresponds to 3000
   * A 1,5ms pulse witdh corresponds to 4500
   * A 2ms pulse width corresponds to 6000
   */
  FTMSetPrescaler(0, FTM_PS_16);
  /* Enable Interrupts */
  FTMEnableTimerInterrupt(0);
  /* Start FTM 0 */
//  FTMSetClockSource(0, FTM_SystemClock);


  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_blink_START_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"
static VAR(uint32, AUTOMATIC) pulseWidth = 200;
static VAR(sint32, AUTOMATIC) speed = 100;
#define APP_Task_blink_STOP_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
TASK(blink)
{
  static uint8 ledState = HIGH;

  /* Beginning of pulse on output 4 to see the execution of the task */
  digitalWrite(4, HIGH);

  /* Blink the Teensy built-in LED */
  digitalWrite(13, ledState);
  ledState = !ledState;

  /* Print the current pulse width */
  lcd.setCursor(0,0);
  lcd.print(pulseWidth / 3);
  lcd.print("    ");
  /* And the current speed */
  lcd.setCursor(0,1);
  lcd.print(speed);
  lcd.print(' ');

  /* End of pulse on output 4 to see the execution of the task */
  digitalWrite(4, LOW);

  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_pulse_START_SEC_CODE
#include "tpl_memmap.h"
TASK (pulse)
{
  /* Start the pulse */
  digitalWrite(3, HIGH);
  /* Reset the counter to its initial value */
  FTMResetCounterValue(0);
  /* Set the width of the pulse */
  FTMSetMaxCounterValue(0, pulseWidth);
  /* Start the counter */
  FTMSetClockSource(0, FTM_SystemClock);

  /* Update the pulse width */
  pulseWidth += speed;

  if (pulseWidth > 40000) speed = -100;
  if (pulseWidth < 200) speed = 100;

  TerminateTask();
}
#define APP_Task_pulse_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_ftm_timer_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * This ISR1 is triggered by the FTM0 interrupt
 */
ISR(ftm_timer)
{
  /* stop the pulse */
  digitalWrite(3, LOW);

  /* stop the counter */
  FTMStopCounter(0);

  /* Acknowledge the timer interrupt */
  FTMAcknowledgeTimerInterrupt(0);
}
#define APP_ISR_ftm_timer_STOP_SEC_CODE
#include "tpl_memmap.h"
