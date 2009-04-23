#include "tpl_os.h"
#include "embUnit.h"

TestRef ResourceManagementTest_seq1_t1_instance(void);
TestRef ResourceManagementTest_seq1_t2_instance1(void);
TestRef ResourceManagementTest_seq1_t2_instance2(void);
TestRef ResourceManagementTest_seq1_isr1_instance(void);
TestRef ResourceManagementTest_seq1_isr2_instance1(void);
TestRef ResourceManagementTest_seq1_isr2_instance2(void);
TestRef ResourceManagementTest_seq1_isr3_instance1(void);
TestRef ResourceManagementTest_seq1_isr3_instance2(void);

StatusType instance_t2 = 0;
StatusType instance_isr2 = 0;
StatusType instance_isr3 = 0;

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
	TestRunner_runTest(ResourceManagementTest_seq1_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	instance_t2 ++;
	switch(instance_t2)
	{ 
		case 1:	
		{
			TestRunner_runTest(ResourceManagementTest_seq1_t2_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(ResourceManagementTest_seq1_t2_instance2());
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
	
}

ISR(isr1)
{
	TestRunner_runTest(ResourceManagementTest_seq1_isr1_instance());
}

ISR(isr2)
{
	instance_isr2 ++;
	switch(instance_isr2)
	{ 
		case 1:	
		{
			TestRunner_runTest(ResourceManagementTest_seq1_isr2_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(ResourceManagementTest_seq1_isr2_instance2());
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
}

ISR(isr3)
{
	instance_isr3 ++;
	switch(instance_isr3)
	{ 
		case 1:	
		{
			TestRunner_runTest(ResourceManagementTest_seq1_isr3_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(ResourceManagementTest_seq1_isr3_instance2());
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
}
