#include "tpl_os.h"
#include "embUnit.h"
#include "config.h" /*for stdimpl_print */

TestRef HookTest_seq5_t1_instance(void);
TestRef HookTest_seq5_t2_instance1(void);
TestRef HookTest_seq5_t2_instance2(void);
TestRef HookTest_seq5_isr1_instance1(void);
TestRef HookTest_seq5_isr1_instance2(void);
TestRef HookTest_seq5_isr1_instance3(void);
TestRef HookTest_seq5_isr1_instance4(void);
TestRef HookTest_seq5_pretask_instance8(void);
TestRef HookTest_seq5_pretask_instance11(void);
TestRef HookTest_seq5_posttask_instance2(void);
TestRef HookTest_seq5_posttask_instance5(void);

unsigned char instance_post = 0;
unsigned char instance_pre = 0;
unsigned char instance_isr1 = 0;
unsigned char instance_t2 = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void StartupHook(void)
{ 
	TestRunner_start();
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

void PreTaskHook(void)
{ 
	instance_pre++;
	switch (instance_pre)
	{
		case 8:
		{
			TestRunner_runTest(HookTest_seq5_pretask_instance8());
			break;
		}
		case 11:
		{
			TestRunner_runTest(HookTest_seq5_pretask_instance11());
			break;
		}
		default:
		{
			
			break;
		}
	}
	
}

void PostTaskHook(void)
{ 
	instance_post++;
	switch (instance_post)
	{
		case 2:
		{
			TestRunner_runTest(HookTest_seq5_posttask_instance2());
			break;
		}
		case 5:
		{
			TestRunner_runTest(HookTest_seq5_posttask_instance5());
			break;
		}
		default:
		{
			
			break;
		}
	}
}

TASK(t1)
{
	TestRunner_runTest(HookTest_seq5_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	instance_t2++;
	switch (instance_t2)
	{
		case 1:
		{
			TestRunner_runTest(HookTest_seq5_t2_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(HookTest_seq5_t2_instance2());
			break;
		}
		default:
		{
			stdimpl_print("instance errror");
			break;
		}
	}
	
}

ISR(isr1)
{
	instance_isr1++;
	switch (instance_isr1)
	{
		case 1:
		{
			TestRunner_runTest(HookTest_seq5_isr1_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(HookTest_seq5_isr1_instance2());
			break;
		}
		case 3:
		{
			TestRunner_runTest(HookTest_seq5_isr1_instance3());
			break;
		}
		case 4:
		{
			TestRunner_runTest(HookTest_seq5_isr1_instance4());
			break;
		}
		default:
		{
			stdimpl_print("instance error");
			break;
		}
	}
	
}
