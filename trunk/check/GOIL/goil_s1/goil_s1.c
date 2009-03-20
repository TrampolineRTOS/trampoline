#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "embUnit.h"
#include "tpl_os.h"

TestRef GoilTest_seq1_t1_instance(void);
//TestRef GoilTest_seq1_t2_instance(void);

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
	TestRunner_runTest(GoilTest_seq1_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	//TestRunner_runTest(TaskManagementTest_seq14_t2_instance());
}
