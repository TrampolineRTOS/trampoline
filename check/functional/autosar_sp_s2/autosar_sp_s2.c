#include "Os.h"
#include "embUnit.h"

TestRef AutosarSPTest_seq2_t1_instance(void);
TestRef AutosarSPTest_seq2_t2_instance(void);
TestRef AutosarSPTest_seq2_t3_instance(void);
TestRef AutosarSPTest_seq2_isr1_instance(void);
TestRef AutosarSPTest_seq2_isr2_instance(void);

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
	TestRunner_runTest(AutosarSPTest_seq2_t1_instance());
}

TASK(t2)
{
	TestRunner_runTest(AutosarSPTest_seq2_t2_instance());
}

TASK(t3)
{
	TestRunner_start();
	TestRunner_runTest(AutosarSPTest_seq2_t3_instance());
	ShutdownOS(E_OK);
}

ISR(isr1)
{
	TestRunner_runTest(AutosarSPTest_seq2_isr1_instance());
}


ISR(isr2)
{
	TestRunner_runTest(AutosarSPTest_seq2_isr2_instance());
}

