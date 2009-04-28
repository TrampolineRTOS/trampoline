#include "tpl_os.h"
#include "embUnit.h"

TestRef InterruptsTest_seq4_t1_instance(void);
TestRef InterruptsTest_seq4_isr1_instance1(void);
TestRef InterruptsTest_seq4_isr1_instance2(void);
TestRef InterruptsTest_seq4_callback1_instance(void);
TestRef InterruptsTest_seq4_callback2_instance(void);

unsigned char instance_isr1 = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(InterruptsTest_seq4_t1_instance());
	ShutdownOS(E_OK);
}

ISR(isr1)
{
	instance_isr1 ++;
	switch(instance_isr1)
	{ 
		case 1:	
		{
			TestRunner_runTest(InterruptsTest_seq4_isr1_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(InterruptsTest_seq4_isr1_instance2());
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
	
}

void CallBack1_callback(void)
{
	TestRunner_runTest(InterruptsTest_seq4_callback1_instance());
}

void CallBack2_callback(void)
{
	TestRunner_runTest(InterruptsTest_seq4_callback2_instance());
}
