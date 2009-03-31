#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"

TestRef EventMechanismTest_seq6_t1_instance(void);
TestRef EventMechanismTest_seq6_t2_instance(void);
TestRef EventMechanismTest_seq6_t3_instance(void);
TestRef EventMechanismTest_seq6_t5_instance(void);
TestRef EventMechanismTest_seq6_isr1_instance(void);

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
	TestRunner_runTest(EventMechanismTest_seq6_t1_instance());
}

TASK(t2)
{
	TestRunner_runTest(EventMechanismTest_seq6_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(EventMechanismTest_seq6_t3_instance());
}

TASK(t4)
{
	stdimpl_print("instance error");
}

TASK(t5)
{
	TestRunner_runTest(EventMechanismTest_seq6_t5_instance());
	ShutdownOS(E_OK);
}

ISR(isr1)
{
	TestRunner_runTest(EventMechanismTest_seq6_isr1_instance());
}