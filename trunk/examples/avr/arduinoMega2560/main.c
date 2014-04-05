#include "tpl_os.h"
#include "tpl_app_config.h"
#include <avr/io.h>

DeclareAlarm(periodicAl);
//ISR2 associated to an external interrupt source (Int5 on portE.5)
//Note: The 'ISR' keyword is ALSO used by gcc to set interrupt handlers.
//      Be careful to use either:
//        * the one of 'tpl_os.h' (OSEK-ISR2) or 
//        * the one of 'avr/interrupt.h' (interrupt handler -> OSEK-ISR1)

//on Arduino Mega, INT5 is PE.5 -> pin number 3 on Arduino.
ISR(ISRButton)
{
	static unsigned int period = 1;
	//slow alarm related to task periodicTask
	period++;
	CancelAlarm(periodicAl);
	SetRelAlarm(periodicAl,period,period);
	//
	PORTB ^= (1<<7); //blink Led on PIN 13
    tpl_terminate_isr2_service();
}

//remove trampoline definition of ISR..
#undef ISR
//and add GCC def of ISR :-/
#include <avr/interrupt.h> //sei,cli

int main(void)
{
	//portA.7 => pin 29 on Arduino Mega.
	DDRA  |= (1<<7);

	//portB.7 => pin 13 on Arduino Mega (with Yellow Led)
	DDRB  |= (1<<7);

	//timer2 => base for SystemCounter.
	TCCR2B = 7; //start timer, prescaler 1024
	TIMSK2 = 1; //interrupt on timer2 overflow

	//init button for ISR
	DDRE  &= ~(1<<5);	// bit 5 (port E)  is an input
	PORTE |= (1<<5);	// pullup port E.7
	EICRB |=  0x0C;     // rising edge detection on E.5 (INT5)
	EIMSK |= (1<<5);    // config interrupt port E.5 => int5

    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

TASK(secondTask)
{
	PORTB |=(1<<7);
	TerminateTask();
}

TASK(startTask)
{
	PORTA |= (1<<7);
	ChainTask(secondTask);
}

TASK(periodicTask)
{
	PORTA ^= (1<<7);
	TerminateTask();
}

