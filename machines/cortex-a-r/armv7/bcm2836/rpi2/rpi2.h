#include "bcm2836.h"

/*****************************************************************************
 *                        GPIO
 *
 * Cf BCM2835 documentation, chapter 13, page 175.
 *
 *****************************************************************************/

/* ----- Onboard LED ------- */
#define ONBOARD_LED_PORT        GPIO16_PORT
#define ONBOARD_LED_PAD         GPIO16_PAD
