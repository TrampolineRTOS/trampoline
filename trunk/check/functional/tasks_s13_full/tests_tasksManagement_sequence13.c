#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "embUnit.h"
#include "tpl_os.h"

TestRef TaskManagementTest_seq13_t1_instance(void);
TestRef TaskManagementTest_seq13_t2_instance(void);
TestRef TaskManagementTest_seq13_t3_instance(void);
TestRef TaskManagementTest_seq13_t4_instance(void);
TestRef TaskManagementTest_seq13_t5_instance(void);
TestRef TaskManagementTest_seq13_t6_instance(void);
TestRef TaskManagementTest_seq13_t7_instance(void);
TestRef TaskManagementTest_seq13_t8_instance(void);

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
	TestRunner_runTest(TaskManagementTest_seq13_t1_instance());
}

TASK(t2)
{
	TestRunner_runTest(TaskManagementTest_seq13_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(TaskManagementTest_seq13_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(TaskManagementTest_seq13_t4_instance());
}

TASK(t5)
{
	TestRunner_runTest(TaskManagementTest_seq13_t5_instance());
}

TASK(t6)
{
	TestRunner_runTest(TaskManagementTest_seq13_t6_instance());
}

TASK(t7)
{
	TestRunner_runTest(TaskManagementTest_seq13_t7_instance());
}

TASK(t8)
{
	TestRunner_runTest(TaskManagementTest_seq13_t8_instance());
	ShutdownOS(E_OK);
}
