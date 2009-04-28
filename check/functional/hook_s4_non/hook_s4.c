#include "tpl_os.h"
#include "embUnit.h"
#include "config.h" /*for stdimpl_print */

TestRef HookTest_seq4_t1_instance(void);
TestRef HookTest_seq4_t2_instance(void);
TestRef HookTest_seq4_isr1_instance1(void);
TestRef HookTest_seq4_isr1_instance2(void);
TestRef HookTest_seq4_isr2_instance1(void);
TestRef HookTest_seq4_isr2_instance2(void);
TestRef HookTest_seq4_pretask_instance2(void);
TestRef HookTest_seq4_pretask_instance3(void);
TestRef HookTest_seq4_pretask_instance6(void);
TestRef HookTest_seq4_pretask_instance7(void);
TestRef HookTest_seq4_posttask_instance3(void);
TestRef HookTest_seq4_posttask_instance6(void);

unsigned char instance_pre = 0;
unsigned char instance_post = 0;
unsigned char instance_isr2 = 0;
unsigned char instance_isr1 = 0;

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
		case 2:
		{
			TestRunner_runTest(HookTest_seq4_pretask_instance2());
			break;
		}
		case 3:
		{
			TestRunner_runTest(HookTest_seq4_pretask_instance3());
			break;
		}
		case 6: 
		{
			TestRunner_runTest(HookTest_seq4_pretask_instance6());
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
		case 3:
		{
			TestRunner_runTest(HookTest_seq4_posttask_instance3());
			break;
		}
		case 6:
		{
			TestRunner_runTest(HookTest_seq4_posttask_instance6());
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
	TestRunner_runTest(HookTest_seq4_t1_instance());
}


TASK(t2)
{
	TestRunner_runTest(HookTest_seq4_t2_instance());
	ShutdownOS(E_OK);
}


ISR(isr1)
{
	instance_isr1++;
	switch (instance_isr1)
	{
		case 1:
		{
			TestRunner_runTest(HookTest_seq4_isr1_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(HookTest_seq4_isr1_instance2());
			break;
		}
		default: 
		{
			stdimpl_print("instance error");
			break;
		}
	}
	
}

ISR(isr2)
{
	instance_isr2++;
	switch (instance_isr2)
	{
		case 1:
		{
			TestRunner_runTest(HookTest_seq4_isr2_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(HookTest_seq4_isr2_instance2());
			break;
		}
		default: 
		{
			stdimpl_print("instance error");
			break;
		}
	}
}
