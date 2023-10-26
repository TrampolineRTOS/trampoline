#include "pinAccess.h"
#include "sam.h"

void pinMode(unsigned char port, 
             unsigned char numBit,
             unsigned char mode)
{
	//check args
	if(port > 1) return;
	if(numBit > 31) return;
	//done
	switch(mode)
	{
		case DISABLE: //pullen = 0 - inen = 0 - dir = 0
			PORT->Group[port].DIRCLR.reg = 1 << numBit;
			PORT->Group[port].PINCFG[numBit].reg = 0;
			break;
		case OUTPUT: //pullen = 0 - inen = 0 - dir = 1
			PORT->Group[port].DIRSET.reg = 1 << numBit;
			PORT->Group[port].OUTCLR.reg = 1 << numBit;
			PORT->Group[port].PINCFG[numBit].reg = 0;
			break;
		case INPUT: //pullen = 0 - inen = 1 - dir = 0
			PORT->Group[port].DIRCLR.reg = 1 << numBit;
			PORT->Group[port].PINCFG[numBit].reg = 0x2;
			break;
		case INPUT_PULLUP: //pullen = 1 - inen = 1 - dir = 0
			PORT->Group[port].DIRCLR.reg = 1 << numBit;
			PORT->Group[port].OUTSET.reg = 1 << numBit;
			PORT->Group[port].PINCFG[numBit].reg = 0x6;
			break;
		case INPUT_PULLDOWN: //pullen = 1 - inen = 1 - dir = 0
			PORT->Group[port].DIRCLR.reg = 1 << numBit;
			PORT->Group[port].OUTCLR.reg = 1 << numBit;
			PORT->Group[port].PINCFG[numBit].reg = 0x6;
			break;
		default:
			break;
	}
}

void digitalWrite(unsigned char port, 
                  unsigned char numBit,
                  unsigned int value)
{
	if(port > 1) return;
	if(numBit > 31) return;
	
	if(value)
		PORT->Group[port].OUTSET.reg = 1 << numBit;
	else
		PORT->Group[port].OUTCLR.reg = 1 << numBit;
}

void digitalToggle(unsigned char port, 
                  unsigned char numBit)
{
	if(port > 1) return;
	if(numBit > 31) return;
	PORT->Group[port].OUTTGL.reg = 1 << numBit;
}


unsigned char digitalRead(unsigned char port,
                          unsigned char numBit)
{
	if(port > 1) return 0xFF;
	if(numBit > 31) return 0xFF;
	if (PORT->Group[port].IN.reg & (1 << numBit))
		return 1;
	return 0;
}

