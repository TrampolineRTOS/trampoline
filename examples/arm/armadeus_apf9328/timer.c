#include "timer.h"

unsigned long *timerGetRegisterAddress(unsigned int timerId, unsigned int regId)
{
	return (unsigned long *)(timerId == 1 ? (T1_BASE+regId) : (T2_BASE+regId));
}

void timerInit(unsigned int timerId, unsigned int source)
{
	unsigned long *tctl = timerGetRegisterAddress(timerId, TCTL);
	*tctl=source | 1; // Timer enable - source PERCLK1 - restart after compare.
}

void timerSetPrescaler(unsigned int timerId, unsigned char prescaler)
{
	unsigned long *tprer = timerGetRegisterAddress(timerId, TPRER);
	*tprer = prescaler;
}

unsigned int timerGetValue(unsigned int timerId)
{
	unsigned long *tcn = timerGetRegisterAddress(timerId, TCN);
	volatile unsigned long val = *tcn;
	return val;
}

void timerInitWithPeriodicUS(unsigned int timerId, unsigned int period)
{
	unsigned long *tcmp=timerGetRegisterAddress(timerId, TCMP);
	unsigned long *tctl = timerGetRegisterAddress(timerId, TCTL);
	unsigned long *tprer = timerGetRegisterAddress(timerId, TPRER);
	*tprer = 0;	
	//timer disable (reset value).
	*tctl=0x0;
	*tcmp=period; //compare value in us
	// source 1MHz -> period 1us
	// restart after compare
	// IRQ enable
	*tctl=CLK_1M | 0x10;
	// Timer enable
	*tctl|=0x1;
}

