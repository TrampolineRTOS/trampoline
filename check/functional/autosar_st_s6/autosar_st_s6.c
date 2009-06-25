#include "Os.h"
#include "embUnit.h"
#include "config.h"

TestRef AutosarSTTest_seq6_t1_instance(void);
TestRef AutosarSTTest_seq6_t2_instance(void);
TestRef AutosarSTTest_seq6_t3_instance(void);
TestRef AutosarSTTest_seq6_t4_instance(void);
TestRef AutosarSTTest_seq6_t5_instance(void);
TestRef AutosarSTTest_seq6_t6_instance(void);
TestRef AutosarSTTest_seq6_t7_instance(void);
TestRef AutosarSTTest_seq6_t8_instance(void);
TestRef AutosarSTTest_seq6_t9_instance(void);
TestRef AutosarSTTest_seq6_t10_instance(void);
TestRef AutosarSTTest_seq6_t11_instance(void);

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
	TestRunner_runTest(AutosarSTTest_seq6_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(AutosarSTTest_seq6_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(AutosarSTTest_seq6_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(AutosarSTTest_seq6_t4_instance());
}

TASK(t5)
{
	TestRunner_runTest(AutosarSTTest_seq6_t5_instance());
}

TASK(t6)
{
	TestRunner_runTest(AutosarSTTest_seq6_t6_instance());
}

TASK(t7)
{
	TestRunner_runTest(AutosarSTTest_seq6_t7_instance());
}

TASK(t8)
{
	TestRunner_runTest(AutosarSTTest_seq6_t8_instance());
}

TASK(t9)
{
	TestRunner_runTest(AutosarSTTest_seq6_t9_instance());
}

TASK(t10)
{
	TestRunner_runTest(AutosarSTTest_seq6_t10_instance());
}

TASK(t11)
{
	TestRunner_runTest(AutosarSTTest_seq6_t11_instance());
}

