#include "tpl_os.h"
#include "tpl_app_config.h"
#include <avr/io.h>

DeclareAlarm(periodicAl);
//ISR2 associated to an external interrupt source (Int5 on portE.5)
//Note: The 'ISR' keyword is ALSO used by gcc to set interrupt handlers.
//      Be careful to use either:
//        * the one of 'tpl_os.h' (OSEK-ISR2) or 
//        * the one of 'avr/interrupt.h' (interrupt handler -> OSEK-ISR1)

//ATMega328p has 2 external interrupts on PD.2 (pin 2) and PD.3 (pin 3).
//other I/O can also be configure to have an interrupt on pin change.
//We use the the PD.2 (pin 2) on Arduino Uno in this example.
//
// each time the button on pin2 is pressed (rising edge on pin2)
// The ISR is activated -> periodic task gets slower.
ISR(ISRButton)
{
	static unsigned int period = 1;
	//slow alarm related to task periodicTask
	period++;
	CancelAlarm(periodicAl);
	SetRelAlarm(periodicAl,period,period);
	//
    tpl_terminate_isr2_service();
}

//remove trampoline definition of ISR..
#undef ISR
//and add GCC def of ISR :-/
#include <avr/interrupt.h> //sei,cli

int main(void)
{
	//portB.5 => pin 13 on Arduino Uno
	DDRB  |= (1<<5);

	//timer2 => base for SystemCounter.
	TCCR2B = 7; //start timer, prescaler 1024
	TIMSK2 = 1; //interrupt on timer2 overflow

	//init button for ISR
	DDRD  &= ~(1<<2);	// bit 2 (port D)  is an input
	PORTD |= (1<<2);	// pullup port D.2
	EICRA |=  0x03;     // rising edge detection on D.2 (INT0)
	EIMSK |= (1<<0);    // config interrupt port D.2 => INT0

    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

TASK(periodicTask)
{
	PORTB ^= (1<<5); //blink Led 13.
	TerminateTask();
}

