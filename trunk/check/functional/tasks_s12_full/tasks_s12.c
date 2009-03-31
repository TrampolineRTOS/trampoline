#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "embUnit.h"
#include "tpl_os.h"

TestRef TaskManagementTest_seq12_t1_instance(void);
TestRef TaskManagementTest_seq12_t2_instance(void);
TestRef TaskManagementTest_seq12_t3_instances(void);
TestRef TaskManagementTest_seq12_t3_instance3(void);

unsigned char instance_t3 = 0;

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
	TestRunner_runTest(TaskManagementTest_seq12_t1_instance());
}

TASK(t2)
{
	TestRunner_runTest(TaskManagementTest_seq12_t2_instance());
}

TASK(t3)
{
	instance_t3 ++;
	switch(instance_t3)
	{ 
		case 1:	
		{
			TestRunner_runTest(TaskManagementTest_seq12_t3_instances());
			break;
		}
		case 2:
		{
			TestRunner_runTest(TaskManagementTest_seq12_t3_instances());
			break;
		}
		case 3:
		{
			TestRunner_runTest(TaskManagementTest_seq12_t3_instance3());
			ShutdownOS(E_OK);
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
}
