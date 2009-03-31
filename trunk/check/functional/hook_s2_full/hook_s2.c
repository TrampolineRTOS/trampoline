#include "tpl_os.h"
#include "embUnit.h"

TestRef HookTest_seq2_error_instance(void);
TestRef HookTest_seq2_pretask_instance(void);
TestRef HookTest_seq2_posttask_instance(void);
TestRef HookTest_seq2_t1_instance(void);
TestRef HookTest_seq2_t2_instance(void);

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
	TestRunner_runTest(HookTest_seq2_error_instance());
}

void PreTaskHook(void)
{ 
	TestRunner_runTest(HookTest_seq2_pretask_instance());
}

void PostTaskHook(void)
{ 	
	TestRunner_runTest(HookTest_seq2_posttask_instance());
}

TASK(t1)
{
	TestRunner_runTest(HookTest_seq2_t1_instance());
}

TASK(t2)
{		
	TestRunner_runTest(HookTest_seq2_t2_instance());
	ShutdownOS(E_OK);
}
