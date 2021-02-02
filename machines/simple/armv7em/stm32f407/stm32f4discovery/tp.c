#include "tp.h"

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
extern volatile VAR(uint32, OS_VAR) tpl_time_counter;
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Initialise la carte avec les ports d'E/S configurés pour allumer les LED
 * et lire le poussoir en mode GPIO ou IT
 */
FUNC(void, OS_CODE) initBoard(void)
{
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);
  STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);
}

/*
 * Allume une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED3, LED4, LED5 et LED6
 */
FUNC(void, OS_CODE) ledOn(Led_TypeDef led)
{
  if (led >= 0 && led <= 3) {
    STM_EVAL_LEDOn(led);
  }
}

/*
 * Eteint une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED3, LED4, LED5 et LED6
 */
FUNC(void, OS_CODE) ledOff(Led_TypeDef led)
{
  if (led >= 0 && led <= 3) {
    STM_EVAL_LEDOff(led);
  }
}

/*
 * Change l'état d'une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED3, LED4, LED5 et LED6
 */
FUNC(void, OS_CODE) ledToggle(Led_TypeDef led)
{
  if (led >= 0 && led <= 3) {
    STM_EVAL_LEDToggle(led);
  }
}

/*
 * Lit le bouton
 */
FUNC(ButtonState, OS_CODE) readButton()
{
  static ButtonState previousState = BUTTON_OFF;
  ButtonState newState;
  ButtonState outState;

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

  return outState;
}

/*
 * delay comme sur l'arduino
 */
FUNC(void, OS_CODE) delay(CONST(uint32, AUTOMATIC) howMuch)
{
  CONST(uint32, AUTOMATIC) start = tpl_time_counter;
  while (tpl_time_counter - start < howMuch);
}

#ifdef __cplusplus
}
#endif // __cplusplus

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
