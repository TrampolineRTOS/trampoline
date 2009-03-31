#include "tpl_os.h"
#include "embUnit.h";

TestRef HookTest_seq4_t1_instance(void);
TestRef HookTest_seq4_t2_instance(void);
TestRef HookTest_seq4_isr1_instance(void);
TestRef HookTest_seq4_isr2_instance(void);
TestRef HookTest_seq4_pretask_instance2(void);
TestRef HookTest_seq4_pretask_instance3(void);
TestRef HookTest_seq4_pretask_instance6(void);
TestRef HookTest_seq4_posttask_instance3(void);
TestRef HookTest_seq4_posttask_instance6(void);

int posttask_instance = 0;
int pretask_instance = 0;

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
	pretask_instance++;
	switch (pretask_instance)
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
	posttask_instance++;
	switch (posttask_instance)
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
	TestRunner_runTest(HookTest_seq4_isr1_instance());
}

ISR(isr2)
{
	TestRunner_runTest(HookTest_seq4_isr2_instance());
}