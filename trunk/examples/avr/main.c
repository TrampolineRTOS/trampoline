#include "tpl_os.h"
#include "tpl_app_config.h"
#include <avr/io.h>

ISR(boutonISR)
{
	PORTA ^= 0x20;
}

//remove trampoline def of ISR..
#undef ISR
#include <avr/interrupt.h>
//and add GCC def of ISR :-/
//
int main(void)
{
	//portA => LEDs
	PORTA = 0;
	DDRA  = 0xFF;
	//timer2 => base pour SystemCounter.
	TCCR2A = 7; //timer lance, prediviseur 1024
	TIMSK2 = 1; //interruption locale en overflow
	//init bouton S
	DDRE  &= 0x7F;	// bit 7 du port E en entree
	PORTE |= 0x80;	// active la resistance de pullup port E.7
	EICRB =  0x80;  // detection de front descendant sur E.7 (INT7)
	EIMSK |= 0x80;  //port E.7 => int7

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

