#include "pinMux.h"
#include "sam.h"

void pinMux(unsigned char port,unsigned char numBit, unsigned char config)
{
	//check args
	if(port > 1) return;
	if(numBit > 31) return;
	if(config > 7) return;

	const unsigned char numReg = numBit >> 1;
	//get configuration of both odd and even pins
	int reg = PORT->Group[port].PMUX[numReg].reg;
	//is pin number odd?
	if(numBit & 1)
	{
		//update odd config
		reg &= 0xF;
		reg |= (config) << 4;
	} else {
		//update even config
		reg &= 0xF0;
		reg |= (config);
	}
	//update reg
	PORT->Group[port].PMUX[numReg].reg = reg;
	//enable pin mux.
    PORT->Group[port].PINCFG[numBit].reg |= 0x01 ;
}

