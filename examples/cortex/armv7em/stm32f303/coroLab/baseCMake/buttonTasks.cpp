#include "tpl_os.h"
#include "mcp23s17.h"

//ISR2 interrupt that activates tasks when a button is pressed
ISR(mcp23s17) {
	//detect the button pushed, 
	//and activate the associated task
	volatile char result = ioExt.getInterrupt();
	if(result & (1<<4)) ActivateTask(TaskB4);
	if(result & (1<<5)) ActivateTask(TaskB5);
	if(result & (1<<6)) ActivateTask(TaskB6);
	if(result & (1<<7)) ActivateTask(TaskB7);
}

volatile uint32_t nbLeds = 0;
void updateIOExtLeds()
{
	ioExt.clearBits(mcp23s17::PORTA,0xff);
	ioExt.setBits(mcp23s17::PORTA,(1<<nbLeds)-1);
}

TASK(TaskB4)
{
	if(nbLeds < 8) nbLeds++;
	updateIOExtLeds();
	TerminateTask();
}

TASK(TaskB5)
{
	if(nbLeds < 8) nbLeds++;
	updateIOExtLeds();
	TerminateTask();
}

TASK(TaskB6)
{
	if(nbLeds > 0) nbLeds--;
	updateIOExtLeds();
	TerminateTask();
}

TASK(TaskB7)
{
	if(nbLeds > 0) nbLeds--;
	updateIOExtLeds();
	TerminateTask();
}

