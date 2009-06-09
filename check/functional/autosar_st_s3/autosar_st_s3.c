#include "Os.h"
#include "embUnit.h"

TestRef AutosarSTTest_seq3_t1_instance(void);
TestRef AutosarSTTest_seq3_t2_instance(void);
TestRef AutosarSTTest_seq3_t3_instance(void);
TestRef AutosarSTTest_seq3_t4_instance(void);
TestRef AutosarSTTest_seq3_t5_instance(void);

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
	TestRunner_runTest(AutosarSTTest_seq3_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(AutosarSTTest_seq3_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(AutosarSTTest_seq3_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(AutosarSTTest_seq3_t4_instance());
}

TASK(t5)
{
	TestRunner_runTest(AutosarSTTest_seq3_t5_instance());
}
