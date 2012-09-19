#include "tpl_os.h"
#include "tpl_app_config.h"
#include <avr/io.h>

//ISR2 associated to an external interrupt source (Int7 on portE.7)
//Note: The 'ISR' keyword is ALSO used by gcc to set interrupt handlers.
//      Be careful to use either:
//        * the one of 'tpl_os.h' (OSEK-ISR2) or 
//        * the one of 'avr/interrupt.h' (interrupt handler -> OSEK-ISR1)
//
ISR(ISRButton) 
{
	PORTA ^= 0x20;
}

//remove trampoline definition of ISR..
#undef ISR
//and add GCC def of ISR :-/
#include <avr/interrupt.h> //sei,cli

int main(void)
{
	//portA => LEDs
	PORTA = 0;
	DDRA  = 0xFF;

	//timer2 => base for SystemCounter.
	TCCR2A = 7; //start timer, prescaler 1024
	TIMSK2 = 1; //interrupt on timer2 overflow

	//init button for ISR
	DDRE  &= 0x7F;	// bit 7 (port E)  is an input
	PORTE |= 0x80;	// pullup port E.7
	EICRB =  0x80;  // rising edge detection on E.7 (INT7)
	EIMSK |= 0x80;  // config interrupt port E.7 => int7

	sei();
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
TASK(secondTask)
{
	PORTA |=2;
	TerminateTask();
}

TASK(startTask)
{
	PORTA |= 1;
	ChainTask(secondTask);
}

TASK(periodicTask)
{
	PORTA ^= 0x80;
	TerminateTask();
}

