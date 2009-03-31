#include "tpl_os.h"
#include "embUnit.h";

TestRef HookTest_seq5_t1_instance(void);
TestRef HookTest_seq5_t2_instance(void);
TestRef HookTest_seq5_isr1_instance(void);
TestRef HookTest_seq5_pretask_instance8(void);
TestRef HookTest_seq5_pretask_instance11(void);
TestRef HookTest_seq5_posttask_instance2(void);
TestRef HookTest_seq5_posttask_instance5(void);

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
	posttask_instance++;
	switch (posttask_instance) {
		case 2: {
			TestRunner_runTest(HookTest_seq5_posttask_instance2());
			break;
		}
		case 5: {
			TestRunner_runTest(HookTest_seq5_posttask_instance5());
			break;
		}
		default: {

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
	TestRunner_runTest(HookTest_seq5_t2_instance());
}

ISR(isr1)
{
	TestRunner_runTest(HookTest_seq5_isr1_instance());
}