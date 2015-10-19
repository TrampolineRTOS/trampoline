/**
 * setup pour les TP
 */

#ifndef __tp_h__
#define __tp_h__

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "gpio.h"

// typedef enum {
//   BUTTON_RELEASED,
//   BUTTON_PRESSED,
//   BUTTON_ON,
//   BUTTON_OFF
// } ButtonState;

typedef enum {
  BUTTON_IT,
  BUTTON_NOIT
} ButtonMode;

typedef uint8 Led_TypeDef;

#define LED0     (3)
#define LED1     (4)
#define LED2     (5)
#define LED3     (6)
#define LED4     (7)
#define LEDBOARD (13)

// #define HIGH (1)
// #define LOW  (0)
//
// #define INPUT		 (0)
// #define OUTPUT		 (1)
// #define INPUT_PULLUP (2)

/*
 *
 */
FUNC(void, OS_CODE) initBoard(void);

/*
 * Allume une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED0, LED1, LED2, LED3, LED4
 */
FUNC(void, OS_CODE) ledOn(Led_TypeDef led);

/*
 * Eteint une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED0, LED1, LED2, LED3, LED4
 */
FUNC(void, OS_CODE) ledOff(Led_TypeDef led);

/*
 * Change l'état d'une LED
 *
 * l'argument est le nom de la LED. Les noms possibles sont :
 * LED0, LED1, LED2, LED3, LED4
 */
FUNC(void, OS_CODE) ledToggle(Led_TypeDef led);

/*
 * Lit le bouton
 *
 * retourne BUTTON_ON ou BUTTON_OFF
 */
//FUNC(ButtonState, OS_CODE) readButton();

/*
 * delay comme sur l'arduino
 */
FUNC(void, OS_CODE) delay(CONST(uint32, AUTOMATIC) howMuch);


/* End of file tp.h */
#endif
