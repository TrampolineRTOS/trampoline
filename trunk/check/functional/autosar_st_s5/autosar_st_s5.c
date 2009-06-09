#include "Os.h"
#include "embUnit.h"

TestRef AutosarSTTest_seq5_t1_instance(void);
TestRef AutosarSTTest_seq5_t2_instance(void);
TestRef AutosarSTTest_seq5_error_instance(void);

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
	TestRunner_runTest(AutosarSTTest_seq5_error_instance());	
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(AutosarSTTest_seq5_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(AutosarSTTest_seq5_t2_instance());
}