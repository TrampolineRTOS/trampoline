#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"

TestRef InterruptsTest_seq4_t1_instance(void);
TestRef InterruptsTest_seq4_isr1_instance(void);
TestRef InterruptsTest_seq4_callback_instance(void);

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
	TestRunner_runTest(InterruptsTest_seq4_t1_instance());
	ShutdownOS(E_OK);
}

ISR(isr1)
{
	TestRunner_runTest(InterruptsTest_seq4_isr1_instance());
}

void CallBackC_callback(void){
	TestRunner_runTest(InterruptsTest_seq4_callback_instance());
}