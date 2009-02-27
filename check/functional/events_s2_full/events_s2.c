#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"

TestRef EventMechanismTest_seq2_t1_instance(void);
TestRef EventMechanismTest_seq2_t2_instance(void);

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
	TestRunner_runTest(EventMechanismTest_seq2_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_start();
	TestRunner_runTest(EventMechanismTest_seq2_t2_instance());
}
