#include "tpl_os.h"
#include "embUnit.h"

TestRef AlarmsTest_seq2_t1_instance(void);
TestRef AlarmsTest_seq2_t2_instance1(void);
TestRef AlarmsTest_seq2_t2_instance2(void);
TestRef AlarmsTest_seq2_t2_instance3(void);

unsigned char instance_t2 = 0;

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
	TestRunner_runTest(AlarmsTest_seq2_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	instance_t2++;
	switch (instance_t2)
	{
		case 1 :
		{
			TestRunner_runTest(AlarmsTest_seq2_t2_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(AlarmsTest_seq2_t2_instance2());
			break;
		}
		case 3 :
		{
			TestRunner_runTest(AlarmsTest_seq2_t2_instance3());
			break;
		}
		default:
		{
			stdimpl_print("Instance error");
			break;
		}
	}
}
