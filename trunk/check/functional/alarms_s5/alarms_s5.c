#include "tpl_os.h"
#include "embUnit.h"

TestRef AlarmsTest_seq5_t1_instance(void);
TestRef AlarmsTest_seq5_t2_instance(void);

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
	TestRunner_runTest(AlarmsTest_seq5_t1_instance());
	
}

TASK(t2)
{
	TestRunner_runTest(AlarmsTest_seq5_t2_instance());
	ShutdownOS(E_OK);
}
