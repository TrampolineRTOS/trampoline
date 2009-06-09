#include "Os.h"
#include "embUnit.h"

TestRef AutosarSTTest_seq4_t1_instance(void);
TestRef AutosarSTTest_seq4_error_instance1(void);
TestRef AutosarSTTest_seq4_error_instance2(void);
TestRef AutosarSTTest_seq4_error_instance3(void);

StatusType instance_error = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

void ErrorHook(StatusType error)
{
	instance_error++;
	switch (instance_error)
	{
		case 1 :
		{
			TestRunner_runTest(AutosarSTTest_seq4_error_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(AutosarSTTest_seq4_error_instance2());
			break;
		}
		case 3 :
		{
			TestRunner_runTest(AutosarSTTest_seq4_error_instance3());
			break;
		}
		default:
		{
			stdimpl_print("Instance error");
			break;
		}
	}
	
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(AutosarSTTest_seq4_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	stdimpl_print("instance error\n");
}

TASK(t3)
{
	stdimpl_print("instance error\n");
}