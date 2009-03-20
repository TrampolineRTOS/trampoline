#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "embUnit.h"
#include "tpl_os.h"

TestRef TaskManagementTest_seq14_t1_instance(void);
TestRef TaskManagementTest_seq14_t2_instance(void);
TestRef TaskManagementTest_seq14_t3_instance(void);
TestRef TaskManagementTest_seq14_t4_instance(void);
TestRef TaskManagementTest_seq14_t5_instance(void);
TestRef TaskManagementTest_seq14_t6_instance(void);
TestRef TaskManagementTest_seq14_t7_instance(void);
TestRef TaskManagementTest_seq14_t8_instance(void);
TestRef TaskManagementTest_seq14_t9_instance(void);
TestRef TaskManagementTest_seq14_t10_instance(void);
TestRef TaskManagementTest_seq14_t11_instance(void);
TestRef TaskManagementTest_seq14_t12_instance(void);
TestRef TaskManagementTest_seq14_t13_instance(void);
TestRef TaskManagementTest_seq14_t14_instance(void);
TestRef TaskManagementTest_seq14_t15_instance(void);
TestRef TaskManagementTest_seq14_t16_instance(void);

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
	TestRunner_runTest(TaskManagementTest_seq14_t1_instance());
}

TASK(t2)
{
	TestRunner_runTest(TaskManagementTest_seq14_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(TaskManagementTest_seq14_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(TaskManagementTest_seq14_t4_instance());
}

TASK(t5)
{
	TestRunner_runTest(TaskManagementTest_seq14_t5_instance());
}

TASK(t6)
{
	TestRunner_runTest(TaskManagementTest_seq14_t6_instance());
}

TASK(t7)
{
	TestRunner_runTest(TaskManagementTest_seq14_t7_instance());
}

TASK(t8)
{
	TestRunner_runTest(TaskManagementTest_seq14_t8_instance());
}

TASK(t9)
{
	TestRunner_runTest(TaskManagementTest_seq14_t9_instance());
}

TASK(t10)
{
	TestRunner_runTest(TaskManagementTest_seq14_t10_instance());
}

TASK(t11)
{
	TestRunner_runTest(TaskManagementTest_seq14_t11_instance());
}

TASK(t12)
{
	TestRunner_runTest(TaskManagementTest_seq14_t12_instance());
}

TASK(t13)
{
	TestRunner_runTest(TaskManagementTest_seq14_t13_instance());
}

TASK(t14)
{
	TestRunner_runTest(TaskManagementTest_seq14_t14_instance());
}

TASK(t15)
{
	TestRunner_runTest(TaskManagementTest_seq14_t15_instance());
}

TASK(t16)
{
	TestRunner_runTest(TaskManagementTest_seq14_t16_instance());
	ShutdownOS(E_OK);
}
