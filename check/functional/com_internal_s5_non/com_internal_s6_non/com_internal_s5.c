#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"


TestRef COMInternalTest_seq5_t1_instance(void);
TestRef COMInternalTest_seq5_t2_instance(void);
TestRef COMInternalTest_seq5_t3_instance(void);

TestRef COMInternalTest_seq5_t4_instance1(void);
TestRef COMInternalTest_seq5_t4_instance2(void);

TestRef COMInternalTest_seq5_t5_instance1(void);
TestRef COMInternalTest_seq5_t5_instance2(void);
TestRef COMInternalTest_seq5_t5_instance3(void);

TestRef COMInternalTest_seq5_t6_instance1(void);
TestRef COMInternalTest_seq5_t6_instance2(void);

TestRef COMInternalTest_seq5_t7_instance1(void);
TestRef COMInternalTest_seq5_t7_instance2(void);
TestRef COMInternalTest_seq5_t7_instance3(void);

TestRef COMInternalTest_seq5_t8_instance1(void);
TestRef COMInternalTest_seq5_t8_instance2(void);
TestRef COMInternalTest_seq5_t8_instance3(void);

int t4_instance = 0;
int t5_instance = 0;
int t6_instance = 0;
int t7_instance = 0;
int t8_instance = 0;

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
	TestRunner_runTest(COMInternalTest_seq5_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(COMInternalTest_seq5_t2_instance());
}

TASK(t3)
{
	stdimpl_print("instance error");
	TestRunner_runTest(COMInternalTest_seq5_t3_instance());	
}

TASK(t4)
{	
	t4_instance++;
	switch (t4_instance)
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq5_t4_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq5_t4_instance2());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
}

TASK(t5)
{	
	t5_instance++;
	switch (t5_instance) 
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq5_t5_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq5_t5_instance2());
			break;
		case 3:
			TestRunner_runTest(COMInternalTest_seq5_t5_instance3());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
	
}

TASK(t6)
{
	t6_instance++;
	switch (t6_instance)
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq5_t6_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq5_t6_instance2());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
	
}

TASK(t7)
{
	t7_instance++;
	switch (t7_instance) 
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq5_t7_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq5_t7_instance2());
			break;
		case 3:
			TestRunner_runTest(COMInternalTest_seq5_t7_instance3());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
}

TASK(t8)
{
	t8_instance++;
	switch (t8_instance)
	{
		case 1:
			TestRunner_runTest(COMInternalTest_seq5_t8_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq5_t8_instance2());
			break;
		case 3:
			TestRunner_runTest(COMInternalTest_seq5_t8_instance3());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
}
