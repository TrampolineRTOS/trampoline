
//Note: The 'ISR' keyword is defined twice in avr targets:
//  * the one of 'tpl_os.h' (OSEK-ISR) or 
//  * the one of 'avr/interrupt.h' (interrupt handler), included by Arduino.h
// As Arduino.h includes 

#include "Arduino.h"
#undef ISR //remove the avr-gcc ISR version
extern "C" {
	#include "tpl_app_config.h"
	#include "tpl_os.h" //set the OSEK ISR version.
}

//This simple example uses one periodic task (periodicTask), activated by an alarm (periodicAl) and 2 external interrupts.
// -> The periodic task just blink the led (pin13)
// -< The 2 interrupts (rising edge) update the period of the alarm (slower/faster).

//the period of the alarm (non protected global var!)
volatile unsigned int period = 1000; 

ISR(ISRButtonSlow)
{
	//slow alarm related to task periodicTask
	period *= 1.1; //10% slower
	Serial.print("slower:");
	Serial.println(period);
	CancelAlarm(periodicAl);
	SetRelAlarm(periodicAl,period,period);
}

ISR(ISRButtonFast)
{
	period *= 0.9; //10% faster
	Serial.print("faster:");
	Serial.println(period);
	CancelAlarm(periodicAl);
	SetRelAlarm(periodicAl,period,period);
}

//basic Arduino setup(). Note that there is no loop!
void setup(void)
{
	pinMode(13, OUTPUT);
	Serial.begin(115200);
}

TASK(periodicTask)
{
	static unsigned int state = LOW;
	digitalWrite(13,state);
	state = !state;
	TerminateTask();
}
