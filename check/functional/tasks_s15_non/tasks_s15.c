#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "embUnit.h"
#include "tpl_os.h"

TestRef TaskManagementTest_seq16_t1_instance(void);
TestRef TaskManagementTest_seq16_t2_instance1(void);
TestRef TaskManagementTest_seq16_t2_instance2(void);
TestRef TaskManagementTest_seq16_t3_instance1(void);
TestRef TaskManagementTest_seq16_t3_instance2(void);
TestRef TaskManagementTest_seq16_t4_instance1(void);
TestRef TaskManagementTest_seq16_t4_instance2(void);
TestRef TaskManagementTest_seq16_t5_instance(void);
TestRef TaskManagementTest_seq16_t6_instance(void);
TestRef TaskManagementTest_seq16_t7_instance(void);
TestRef TaskManagementTest_seq16_t8_instance(void);
TestRef TaskManagementTest_seq16_isr1_instance(void);

unsigned char instance_t2 = 0;
unsigned char instance_t3 = 0;
unsigned char instance_t4 = 0;

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
	instance_t2++;
	switch (instance_t2)
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
	instance_t3++;
	switch (instance_t3)
	{
		case 1 :
			TestRunner_runTest(TaskManagementTest_seq16_t3_instance1());
			break;
		case 2 :
			TestRunner_runTest(TaskManagementTest_seq16_t3_instance2());
			break;
		default:
			stdimpl_print("Instance error");
			break;
	}
}

TASK(t4)
{
	instance_t4++;
	switch (instance_t4)
	{
		case 1 :
			TestRunner_runTest(TaskManagementTest_seq16_t4_instance1());
			break;
		case 2 :
			TestRunner_runTest(TaskManagementTest_seq16_t4_instance2());
			break;
		default:
			stdimpl_print("Instance error");
			break;
	}
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
