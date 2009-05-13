#include "Os.h"
#include "embUnit.h"

TestRef AutosarTest_seq2_t1_instance(void);

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
	TestRunner_runTest(AutosarTest_seq2_t1_instance());
	ShutdownOS(E_OK);
}
