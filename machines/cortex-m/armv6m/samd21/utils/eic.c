#include "eic.h"
#include "sam.h"
#include "pinMux.h"

int EICConfig(unsigned char eicNum,
              unsigned char withFilter,
              unsigned char edgeType)
{
	int result = 0;
	if((eicNum>15) || (edgeType>3)) result = 1;
	else {
		//arguments vérifiés
		const int configIndex = eicNum >> 3; // <=> div par 8
		const int offset = (eicNum & 0x7) << 2;
		//RAZ config precedente
		const int mask = 0xF << offset; //4 bits
		EIC->CONFIG[configIndex].reg &= ~mask;
		//choix nouvelle config
		int config = 0;
		if(withFilter) config |= 8;
		config |= edgeType;
		EIC->CONFIG[configIndex].reg |= config << offset;
		//validation de l'entrée externe
		EIC->INTENSET.reg = 1<<eicNum;
		//démarrage du module
		EIC->CTRL.reg = 2;
	}
	return result;
}

int EICInitClock(int source)
{
	int result = 0;
	if(source > 4) result = 1;
	else {
		//pas de power management (PM), car validé par défaut.
		//clock control
		GCLK->CLKCTRL.reg = 1 <<14 | //enable
							source << 8 | //generator
							5; //peripheral associated -> EIC
	}
	return result;
}


