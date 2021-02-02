#include "tp.h"

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
extern volatile VAR(uint32, OS_VAR) tpl_time_counter;
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * 
 */
FUNC(void, OS_CODE) initBoard(void)
{
  pinMode(LED0, OUTPUT); /* Led L0 on daughter board */
  pinMode(LED1, OUTPUT); /* Led L1 on daughter board */
  pinMode(LED2, OUTPUT); /* Led L2 on daughter board */
  pinMode(LED3, OUTPUT); /* Led L3 on daughter board */
  pinMode(LED4, OUTPUT); /* Led L4 on daughter board */
  pinMode(LEDBOARD, OUTPUT); /* Led on Teensy board */
}

/*
 * Allume une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED3, LED4, LED5 et LED6
 */
FUNC(void, OS_CODE) ledOn(Led_TypeDef led)
{
//  if ((led >= 0 && led <= 4) || led == 13) {
    digitalWrite(led, HIGH);
//  }
}

/*
 * Eteint une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED3, LED4, LED5 et LED6
 */
FUNC(void, OS_CODE) ledOff(Led_TypeDef led)
{
//  if ((led >= 0 && led <= 4) || led == 13) {
    digitalWrite(led, LOW);
//  }
}

/*
 * Change l'état d'une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED3, LED4, LED5 et LED6
 */
FUNC(void, OS_CODE) ledToggle(Led_TypeDef led)
{
//  if ((led >= 0 && led <= 4) || led == 13) {
    if (digitalRead(led) == 1) {
      digitalWrite(led, LOW);
    } else {
      digitalWrite(led, HIGH);
    }
//  }
}

/*
 * Lit le bouton
 */
FUNC(ButtonState, OS_CODE) readButton()
{
  static ButtonState previousState = BUTTON_OFF;
//  ButtonState newState;
  ButtonState outState;

  outState = previousState;
  
/*
  if (STM_EVAL_PBGetState(BUTTON_USER) == Bit_SET) {
    newState = BUTTON_ON;
  }
  else {
    newState = BUTTON_OFF;
  }

  if (newState == previousState) {
    outState = newState;
  }
  else {
    if (newState == BUTTON_ON) {
      outState = BUTTON_PRESSED;
    }
    else {
      outState = BUTTON_RELEASED;
    }
  }

  previousState = newState;
*/
  return outState;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
