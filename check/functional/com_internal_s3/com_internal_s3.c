#include "tpl_os.h"
#include "embUnit.h"

TestRef COMInternalTest_seq3_t1_instance(void);
TestRef COMInternalTest_seq3_t2_instance(void);
TestRef COMInternalTest_seq3_t3_instance(void);
TestRef COMInternalTest_seq3_t4_instance(void);
TestRef COMInternalTest_seq3_comcallback_instance(void);

int com_error_instance = 0;

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
	TestRunner_runTest(COMInternalTest_seq3_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(COMInternalTest_seq3_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(COMInternalTest_seq3_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(COMInternalTest_seq3_t4_instance());
}

extern void ComCallBack_callback(void)
{	
	TestRunner_runTest(COMInternalTest_seq3_comcallback_instance());
}