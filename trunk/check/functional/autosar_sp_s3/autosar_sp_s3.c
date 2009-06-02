#include "Os.h"
#include "embUnit.h"

TestRef AutosarSPTest_seq3_t1_instance(void);
TestRef AutosarSPTest_seq3_isr1_instance(void);
TestRef AutosarSPTest_seq3_isr2_instance(void);
TestRef AutosarSPTest_seq3_error_instance(void);

StatusType error_status;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ErrorHook(StatusType error)
{
	error_status = error;
	TestRunner_runTest(AutosarSPTest_seq3_error_instance());
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(AutosarSPTest_seq3_t1_instance());
	ShutdownOS(E_OK);
}

ISR(isr1)
{
	TestRunner_runTest(AutosarSPTest_seq3_isr1_instance());
}


ISR(isr2)
{
	TestRunner_runTest(AutosarSPTest_seq3_isr2_instance());
}

