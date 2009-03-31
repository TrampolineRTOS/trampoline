#include "embUnit.h"
#include "tpl_os.h"

TestRef TaskManagementTest_seq11_t1_instance(void);
TestRef TaskManagementTest_seq11_t2_instance(void);
TestRef TaskManagementTest_seq11_t3_instance(void);
TestRef TaskManagementTest_seq11_t4_instance(void);

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
	TestRunner_runTest(TaskManagementTest_seq11_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_start();
	TestRunner_runTest(TaskManagementTest_seq11_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(TaskManagementTest_seq11_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(TaskManagementTest_seq11_t4_instance());
}
