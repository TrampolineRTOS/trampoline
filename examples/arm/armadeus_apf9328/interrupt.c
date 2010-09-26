#include "interrupt.h"

void initIT()
{
	//default priority level to -1... contradiction in ref manual!
	(*NIMASK) = 0;
}

void initNormalInterrupt(const unsigned int sourceId,const unsigned int priority)
{
	if((sourceId < 64) && (priority < 16))
	{
		(*INTENNUM) = sourceId; //local interrupt mask.
		//set normal interrupt (set bit associated to interrupt source to 0)
		if(sourceId > 32) (*INTTYPEH) &= ~(1 << (sourceId-32));
		else (*INTTYPEL) &= ~(1 << sourceId);
		//set priority
		const unsigned int regPriorityId = sourceId >> 3;
		unsigned int *regPriorityAddr = (unsigned int *)((unsigned int)(NIPRIORITY0)-(regPriorityId<<2));
		//first reset priority
		(*regPriorityAddr) &= ~(0xF << ((sourceId &7) << 2));
		//then set new priority.
		(*regPriorityAddr) |= priority << ((sourceId & 7) << 2);
	}
}

void forceInterrupt(const unsigned int sourceId)
{
	if(sourceId > 32) (*INTFRCH) |= (1 << (sourceId-32));
	else (*INTFRCH) |= ~(1 << sourceId);
}
