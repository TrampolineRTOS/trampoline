#include "tpl_os.h"
#include "tpl_app_config.h"
#include <avr/io.h>


//This simple example uses one periodic task (periodicTask), activated by an alarm (periodicAl) and 2 external interrupts.
// -> The periodic task just blink the led (pin13)
// -< The 2 interrupts (rising edge) update the period of the alarm (slower/faster).

DeclareAlarm(periodicAl);

//the period of the alarm (non protected global var!)
unsigned int period = 1000; 

//Note: The 'ISR' keyword is ALSO used by gcc to set interrupt handlers.
//      Be careful to use either:
//        * the one of 'tpl_os.h' (OSEK-ISR2) or 
//        * the one of 'avr/interrupt.h' (interrupt handler -> OSEK-ISR1)

//ATMega328p has 2 external interrupts on PD.2 (pin 2) and PD.3 (pin 3).
//other I/O can also be configure to have an interrupt on pin change.
//We use the pin 2 and 3 on Arduino Uno in this example.
//
// each time the button on pin2 is pressed (rising edge on pin2)
// The ISR is activated -> periodic task gets slower.
// the name of the ISR is the one defined in the .oil file.
ISR(ISRButtonSlow)
{
	//slow alarm related to task periodicTask
	period *= 1.1; //10% slower
	CancelAlarm(periodicAl);
	SetRelAlarm(periodicAl,period,period);
}

// each time the button on pin3 is pressed (rising edge on pin3)
// The ISR is activated -> periodic task gets faster
ISR(ISRButtonFast)
{
	period *= 0.9; //10% faster
	CancelAlarm(periodicAl);
	SetRelAlarm(periodicAl,period,period);
}


//remove trampoline definition of ISR..
//#undef ISR
//and add GCC def of ISR :-/
//#include <avr/interrupt.h> //sei,cli
// => here, one could add ISR1 interrupts (i.e. fast interrupts
//    that are not managed by the OS... but should not interact 
//    with it (no service call allowed!)

//be careful: the 'Arduino.h' header file includes 'avr/interrupt.h' and
//redefine the ISR macro!!!
#include "Arduino.h"
void setup(void)
{
	// initialize digital pin 13 as an output.
	init();
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);
	Serial.begin(115200);
	Serial.print("Ceci est un test.\n");

	//init button for ISRButtonSlow
	DDRD  &= ~(1<<2);	// bit 2 (port D)  is an input
	PORTD |= (1<<2);	// pullup port D.2
	EICRA |=  0x03;     // rising edge detection on D.2 (INT0)
	EIMSK |= (1<<0);    // config interrupt port D.2 => INT0

	//init button for ISRButtonFast
	DDRD  &= ~(1<<3);	// bit 3 (port D)  is an input
	PORTD |= (1<<3);	// pullup port D.3
	EICRA |=  0x07;     // rising edge detection on D.3 (INT1)
	EIMSK |= (1<<1);    // config interrupt port D.3 => INT1

	Serial.begin(115200);

    StartOS(OSDEFAULTAPPMODE);
}

TASK(periodicTask)
{
	static unsigned int nb = 0;
	nb++;
	if(nb & 1) digitalWrite(13, HIGH); //impair
	else digitalWrite(13, LOW);        //pair

	Serial.print("***** ");
	Serial.print(nb);
	Serial.println(" done");
}
