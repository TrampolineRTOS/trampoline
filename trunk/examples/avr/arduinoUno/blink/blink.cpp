// see blink.oil head of file for information about the compilation process.

#include "tpl_os.h"
#include <avr/io.h>

DeclareAlarm(periodicAl);

unsigned int period = 2000;

ISR(ISRButton)
{
	//slow alarm related to task periodicTask
	period *= 2;
	CancelAlarm(periodicAl);
	SetRelAlarm(periodicAl,period,period);
}

ISR(ISRButton2)
{
	period /= 2;
	CancelAlarm(periodicAl);
	SetRelAlarm(periodicAl,period,period);
}

#include "Arduino.h"

DeclareTask(periodicTask);
DeclareTask(periodicTask2);

void setup()
{
	// initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(11, OUTPUT);

	//init button for ISR
	DDRD  &= ~(1<<2);	// bit 2 (port D)  is an input
	PORTD |= (1<<2);	// pullup port D.2
	EICRA |=  0x03;     // rising edge detection on D.2 (INT0)
	EIMSK |= (1<<0);    // config interrupt port D.2 => INT0

	DDRD  &= ~(1<<3);	// bit 3 (port D)  is an input
	PORTD |= (1<<3);	// pullup port D.3
	EICRA |=  0x0C;     // rising edge detection on D.3 (INT1)
	EIMSK |= (1<<1);    // config interrupt port D.3 => INT0
}


//The TASK is activated by the alarm "periodicAl":
//* The alarm "periodicAl" is configured in the .oil file to activate task 
//"periodicTask" each 1000 pulses of counter SystemCounter.
//* The SystemCounter is the same as the systick used in Arduino, a tick each 1024us on a 16MHz arduino.
//* This task is periodic, with a period of 1024ms.
TASK(periodicTask)
{
	static unsigned int nb = 0;
	nb++;
	if(nb & 1) digitalWrite(13, HIGH); //odd
	else digitalWrite(13, LOW);        //even
}


//TASK(periodicTask)
//{
//	digitalWrite(11, HIGH);
//	ActivateTask(periodicTask2);
//	digitalWrite(11, LOW);
//}
//
//TASK(periodicTask2)
//{
//	volatile int i;
//	digitalWrite(12, HIGH);
//	//for(i=0;i<10000;i++);
//	digitalWrite(12, LOW);
//}

