// see blink.oil head of file for information about the compilation process.

#include "tpl_os.h"
#include "Arduino.h"

void setup()
{
	Serial.begin(115200); //115200 bps 8N1
	// initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);
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

	Serial.print(nb);
	Serial.println(" done");
	TerminateTask();
}
