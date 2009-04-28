#include "tpl_os.h"
#include "embUnit.h";

TestRef HookTest_seq6_t1_instance(void);
TestRef HookTest_seq6_isr1_instance(void);
TestRef HookTest_seq6_isr2_instance(void);
TestRef HookTest_seq6_error_instance(void);
TestRef HookTest_seq6_posttask_instance4(void);

int posttask_instance = 0;

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

void ErrorHook(void)
{
	TestRunner_runTest(HookTest_seq6_error_instance());
}


void PostTaskHook(void)
{ 
	posttask_instance++;
	switch (posttask_instance)
	{
		case 4:
		{
			TestRunner_runTest(HookTest_seq6_posttask_instance4());
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
	TestRunner_runTest(HookTest_seq6_t1_instance());
}

ISR(isr1)
{
	TestRunner_runTest(HookTest_seq6_isr1_instance());
}

ISR(isr2)
{
	TestRunner_runTest(HookTest_seq6_isr2_instance());
	ShutdownOS(E_OK);
}
