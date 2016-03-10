/**
 * setup pour les TP
 */

#ifndef __tp_h__
#define __tp_h__

#include "tpl_compiler.h"
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "tpl_os_std_types.h"

typedef enum {
  BUTTON_RELEASED,
  BUTTON_PRESSED,
  BUTTON_ON,
  BUTTON_OFF
} ButtonState;

typedef enum {
  BUTTON_IT,
  BUTTON_NOIT
} ButtonMode;

#define ORANGE LED3
#define GREEN  LED4
#define RED    LED5
#define BLUE   LED6

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/*
 * Initialise la carte avec les ports d'E/S configurer pour allumer les LED
 * et lire le poussoir
 */
FUNC(void, OS_CODE) initBoard(void);

/*
 * Allume une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED3, LED4, LED5 et LED6
 */
FUNC(void, OS_CODE) ledOn(Led_TypeDef led);

/*
 * Eteint une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED3, LED4, LED5 et LED6
 */
FUNC(void, OS_CODE) ledOff(Led_TypeDef led);

/*
 * Change l'état d'une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED3, LED4, LED5 et LED6
 */
FUNC(void, OS_CODE) ledToggle(Led_TypeDef led);

/*
 * Lit le bouton
 *
 * retourne BUTTON_ON ou BUTTON_OFF
 */
FUNC(ButtonState, OS_CODE) readButton();

/*
 * delay comme sur l'arduino
 */
FUNC(void, OS_CODE) delay(CONST(uint32, AUTOMATIC) howMuch);

#ifdef __cplusplus
}
#endif // __cplusplus


/* End of file tp.h */
#endif
