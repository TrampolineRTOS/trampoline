#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"

TestRef HookTest_seq3_error_instance(void);
TestRef HookTest_seq3_t1_instance(void);

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
	TestRunner_runTest(HookTest_seq3_error_instance());
}

TASK(t1)
{
	TestRunner_runTest(HookTest_seq3_t1_instance());
	ShutdownOS(E_OK);
}

