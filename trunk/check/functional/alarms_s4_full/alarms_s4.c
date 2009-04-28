#include "tpl_os.h"
#include "embUnit.h"

TestRef AlarmsTest_seq4_t1_instance(void);
TestRef AlarmsTest_seq4_callback_instance1(void);
TestRef AlarmsTest_seq4_callback_instance2(void);
TestRef AlarmsTest_seq4_callback_instance3(void);

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
	TestRunner_start();
	TestRunner_runTest(AlarmsTest_seq4_t1_instance());
	ShutdownOS(E_OK);
}

void CallBackC_callback(void)
{
	instance_callback++;
	switch (instance_callback)
	{
		case 1 :
		{
			TestRunner_runTest(AlarmsTest_seq4_callback_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(AlarmsTest_seq4_callback_instance2());
			break;
		}
		case 3 :
		{
			TestRunner_runTest(AlarmsTest_seq4_callback_instance3());
			break;
		}
		default:
		{
			stdimpl_print("Instance error");
			break;
		}
	}

	
}
