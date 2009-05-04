#include "Os.h"
#include "embUnit.h"
#include "config.h" /*for stdimpl_print*/

TestRef AutosarTest_seq1_t1_instance(void);
TestRef AutosarTest_seq1_t2_instance(void);
TestRef AutosarTest_seq1_isr1_instance(void);
TestRef AutosarTest_seq1_isr2_instance(void);

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
	TestRunner_runTest(AutosarTest_seq1_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(AutosarTest_seq1_t2_instance());
}

ISR(isr1)
{
	TestRunner_runTest(AutosarTest_seq1_isr1_instance());
}

ISR(isr2)
{
	stdimpl_print("instance error\n");
}