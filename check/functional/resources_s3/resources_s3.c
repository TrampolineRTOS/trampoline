#include "tpl_os.h"
#include "embUnit.h"

TestRef ResourceManagementTest_seq3_t1_instance(void);
TestRef ResourceManagementTest_seq3_t2_instance(void);
TestRef ResourceManagementTest_seq3_t3_instance(void);

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
	TestRunner_runTest(ResourceManagementTest_seq3_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(ResourceManagementTest_seq3_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(ResourceManagementTest_seq3_t3_instance());
}
