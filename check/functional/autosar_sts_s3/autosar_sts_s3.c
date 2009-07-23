#include "Os.h"
#include "embUnit.h"
#include "config.h"

TestRef AutosarSTSTest_seq3_t1_instance(void);
TestRef AutosarSTSTest_seq3_t2_instance(void);

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
	TestRunner_runTest(AutosarSTSTest_seq3_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(AutosarSTSTest_seq3_t2_instance());
}
