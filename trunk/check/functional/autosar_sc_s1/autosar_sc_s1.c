#include "Os.h"
#include "embUnit.h"

TestRef AutosarTest_seq1_t1_instance(void);
TestRef AutosarTest_seq1_error_instance(void);

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ErrorHook(void)
{
	TestRunner_runTest(AutosarTest_seq1_error_instance());
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(AutosarTest_seq1_t1_instance());
	ShutdownOS(E_OK);
}
