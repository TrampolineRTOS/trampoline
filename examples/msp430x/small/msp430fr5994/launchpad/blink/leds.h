#ifndef __LED_H__
#define __LED_H__

#define LED1 (1<<0) //P1.0
#define LED2 (1<<1) //P1.1

/** init GPIO to use leds. 
 * Should be called first
 */
void ledInit();

/** ledId is a mask: 
 * may be LED1, LED2 or LED1|LED2
 */ 
void ledToggle(int ledId);

/** ledId is a mask: 
 * may be LED1, LED2 or LED1|LED2
 */ 
void ledSet(int ledId);

/** ledId is a mask: 
 * may be LED1, LED2 or LED1|LED2
 */ 
void ledclear(int ledId);

#endif