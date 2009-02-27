#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"

TestRef EventMechanismTest_seq4_t1_instance(void);
TestRef EventMechanismTest_seq4_t2_instance(void);
TestRef EventMechanismTest_seq4_t3_instance(void);
TestRef EventMechanismTest_seq4_t4_instance(void);

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
	TestRunner_runTest(EventMechanismTest_seq4_t1_instance());
}

TASK(t2)
{
	TestRunner_start();
	TestRunner_runTest(EventMechanismTest_seq4_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(EventMechanismTest_seq4_t3_instance());
	ShutdownOS(E_OK);
}

TASK(t4)
{
	TestRunner_runTest(EventMechanismTest_seq4_t4_instance());
}