#include "leds.h"
#include "msp430.h"


void ledInit()
{
	// Disable the GPIO power-on default high-impedance mode
	// to activate previously configured port settings
	PM5CTL0 &= ~LOCKLPM5;
	//set both GPIO P1.0 (LED1) and GPIO P1.1 (LED2) as an output
	P1DIR |= (LED1 | LED2);
	//leds off
	P1OUT &= ~(LED1 | LED2);
}

void ledToggle(int ledId)
{
	if(ledId > (LED1|LED2)) return;
	P1OUT ^= ledId;
}

void ledSet(int ledId)
{
	if(ledId > (LED1|LED2)) return;
	P1OUT |= ledId;
}

void ledclear(int ledId)
{
	if(ledId > (LED1|LED2)) return;
	P1OUT &= ~ledId;
}
