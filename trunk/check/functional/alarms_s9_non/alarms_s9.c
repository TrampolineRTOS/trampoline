#include "tpl_os.h"
#include "embUnit.h"

TestRef AlarmsTest_seq11_t1_instance(void);
TestRef AlarmsTest_seq11_t2_instance(void);
TestRef AlarmsTest_seq11_t3_instance(void);
TestRef AlarmsTest_seq11_t4_instance(void);
TestRef AlarmsTest_seq11_t5_instance(void);
TestRef AlarmsTest_seq11_isr1_instance(void);
TestRef AlarmsTest_seq11_callback_instance1(void);
TestRef AlarmsTest_seq11_callback_instance2(void);

unsigned char instance_callback = 0;

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
	TestRunner_runTest(AlarmsTest_seq11_t1_instance());
}

TASK(t2)
{
	TestRunner_runTest(AlarmsTest_seq11_t2_instance());
	ShutdownOS(E_OK);
}

TASK(t3)
{
	TestRunner_runTest(AlarmsTest_seq11_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(AlarmsTest_seq11_t4_instance());
}

TASK(t5)
{
	TestRunner_start();
	TestRunner_runTest(AlarmsTest_seq11_t5_instance());
}

ISR(isr1)
{
	TestRunner_runTest(AlarmsTest_seq11_isr1_instance());	
}

void CallBackC_callback(void)
{
	instance_callback++;
	switch(instance_callback)
	{ 
		case 1:	
		{
			TestRunner_runTest(AlarmsTest_seq11_callback_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(AlarmsTest_seq11_callback_instance2());
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
}
