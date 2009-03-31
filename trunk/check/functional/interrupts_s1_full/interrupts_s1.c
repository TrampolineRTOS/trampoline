#include "tpl_os.h"
#include "embUnit.h"

TestRef InterruptProcessingTest_seq1_t1_instance(void);
TestRef InterruptProcessingTest_seq1_isr1_instance(void);
TestRef InterruptProcessingTest_seq1_isr2_instance(void);
TestRef InterruptProcessingTest_seq1_isr3_instance(void);

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
	TestRunner_runTest(InterruptProcessingTest_seq1_t1_instance());
	ShutdownOS(E_OK);
}

ISR(isr1)
{
	TestRunner_runTest(InterruptProcessingTest_seq1_isr1_instance());
}

ISR(isr2)
{
	TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance());
}

ISR(isr3)
{
	TestRunner_runTest(InterruptProcessingTest_seq1_isr3_instance());
}