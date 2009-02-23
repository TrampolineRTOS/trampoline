#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"
//#include "tests_tasksManagement_sequence1.h"
//#define _XOPEN_SOURCE 500
//include <unistd.h>

TestRef InterruptProcessingTest_seq3_t1_instance(void);
TestRef InterruptProcessingTest_seq3_t2_instance(void);
TestRef InterruptProcessingTest_seq3_isr1_instance(void);
TestRef InterruptProcessingTest_seq3_isr2_instance(void);

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
	TestRunner_runTest(InterruptProcessingTest_seq3_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(InterruptProcessingTest_seq3_t2_instance());
}

ISR(isr1)
{
	TestRunner_runTest(InterruptProcessingTest_seq3_isr1_instance());
}

ISR(isr2)
{
	TestRunner_runTest(InterruptProcessingTest_seq3_isr2_instance());
}