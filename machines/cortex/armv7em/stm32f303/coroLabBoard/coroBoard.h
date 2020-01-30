#ifndef __COROLAB_H__
#define __COROLAB_H__
#include "Adafruit_ST7735.h"

/* set of basic functions for the ECN Coro Lab board 
 * It initializes display, IO Expander, leds.
 **/

/** initialize most of coro lab hardware stuff:
 * - tft
 * - IO Expander
 * - green LED PB0
 * # charlieplexing leds
 */   
void initCoroBoard();

/* tft driver instance. */
extern Adafruit_ST7735 tft;

/* Initialisze the TFT display (chip ST7735).
 * based on the Adafruit libraries for Arduino.
 */
void setupDisplay();

/* init IO Expander for the Coro lab coard:
 * - 8 leds on PORTA
 * - 4 DIP switches on PORTB
 * - 4 push buttons on interrupt on PORT B
 */
void setupIOExtender();

/** initialize TIM6 as a stopwatch timer
 *  precision 1us
 */
void setupTimer();

/* reset the stopwatch timer TIM6 */
void resetTimer();

/* get the stopwatch timer value. 1 tick each 1us. No overflow protection */
uint32_t getTimerValue();

#endif //__COROLAB_H__
