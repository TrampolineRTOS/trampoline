#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"

TestRef HookTest_seq1_startup_instance(void);
TestRef HookTest_seq1_shutdown_instance(void);

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void StartupHook(void)
{ 
	TestRunner_start();
	TestRunner_runTest(HookTest_seq1_startup_instance());
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_runTest(HookTest_seq1_shutdown_instance());
	TestRunner_end();
}

TASK(t1)
{
	stdimpl_print("instance error");
}
