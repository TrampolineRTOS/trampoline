#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "embUnit.h"
#include "tpl_os.h"

TestRef TaskManagementTest_seq16_t1_instance(void);
TestRef TaskManagementTest_seq16_t2_instance1(void);
TestRef TaskManagementTest_seq16_t2_instance2(void);
TestRef TaskManagementTest_seq16_t3_instance(void);
TestRef TaskManagementTest_seq16_t4_instance(void);
TestRef TaskManagementTest_seq16_t5_instance(void);
TestRef TaskManagementTest_seq16_t6_instance(void);
TestRef TaskManagementTest_seq16_t7_instance(void);
TestRef TaskManagementTest_seq16_t8_instance(void);
TestRef TaskManagementTest_seq16_isr1_instance(void);

int instance = 0;

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
	TestRunner_runTest(TaskManagementTest_seq16_t1_instance());
	
}

TASK(t2)
{
	instance++;
	switch (instance)
	{
		case 1 :
			TestRunner_runTest(TaskManagementTest_seq16_t2_instance1());
			break;
		case 2 :
			TestRunner_runTest(TaskManagementTest_seq16_t2_instance2());
			ShutdownOS(E_OK);
			break;
		default:
			stdimpl_print("Instance error");
			break;
	}
}

TASK(t3)
{
	TestRunner_runTest(TaskManagementTest_seq16_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(TaskManagementTest_seq16_t4_instance());
}

TASK(t5)
{
	TestRunner_runTest(TaskManagementTest_seq16_t5_instance());
}

TASK(t6)
{
	TestRunner_runTest(TaskManagementTest_seq16_t6_instance());
}

TASK(t7)
{
	TestRunner_runTest(TaskManagementTest_seq16_t7_instance());
}

TASK(t8)
{
	TestRunner_start();
	TestRunner_runTest(TaskManagementTest_seq16_t8_instance());
}

ISR(isr1)
{
	TestRunner_runTest(TaskManagementTest_seq16_isr1_instance());	
}
