#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"


TestRef COMInternalTest_seq4_t1_instance(void);

TestRef COMInternalTest_seq4_t2_instance1(void);
TestRef COMInternalTest_seq4_t2_instance2(void);
TestRef COMInternalTest_seq4_t2_instance3(void);

TestRef COMInternalTest_seq4_t3_instance1(void);
TestRef COMInternalTest_seq4_t3_instance2(void);

TestRef COMInternalTest_seq4_t4_instance(void);

TestRef COMInternalTest_seq4_t5_instance1(void);
TestRef COMInternalTest_seq4_t5_instance2(void);
TestRef COMInternalTest_seq4_t5_instance3(void);
TestRef COMInternalTest_seq4_t5_instance4(void);

TestRef COMInternalTest_seq4_t6_instance1(void);
TestRef COMInternalTest_seq4_t6_instance2(void);

TestRef COMInternalTest_seq4_t7_instance1(void);
TestRef COMInternalTest_seq4_t7_instance2(void);

TestRef COMInternalTest_seq4_t8_instance1(void);
TestRef COMInternalTest_seq4_t8_instance2(void);

TestRef COMInternalTest_seq4_t9_instance1(void);
TestRef COMInternalTest_seq4_t9_instance2(void);
TestRef COMInternalTest_seq4_t9_instance3(void);

int t2_instance = 0;
int t3_instance = 0;
int t5_instance = 0;
int t6_instance = 0;
int t7_instance = 0;
int t8_instance = 0;
int t9_instance = 0;

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
	TestRunner_runTest(COMInternalTest_seq4_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	t2_instance++;
	switch (t2_instance) {
		case 1:
			TestRunner_runTest(COMInternalTest_seq4_t2_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq4_t2_instance2());
			break;
		case 3:
			TestRunner_runTest(COMInternalTest_seq4_t2_instance3());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
}

TASK(t3)
{
	t3_instance++;
	switch (t3_instance) {
		case 1:
			TestRunner_runTest(COMInternalTest_seq4_t3_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq4_t3_instance2());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
}

TASK(t4)
{	
	TestRunner_runTest(COMInternalTest_seq4_t4_instance());
}

TASK(t5)
{	
	t5_instance++;
	switch (t5_instance) {
		case 1:
			TestRunner_runTest(COMInternalTest_seq4_t5_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq4_t5_instance2());
			break;
		case 3:
			TestRunner_runTest(COMInternalTest_seq4_t5_instance3());
			break;
		case 4:
			TestRunner_runTest(COMInternalTest_seq4_t5_instance4());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}	
	
}

TASK(t6)
{
	t6_instance++;
	switch (t6_instance) {
		case 1:
			TestRunner_runTest(COMInternalTest_seq4_t6_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq4_t6_instance2());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
	
}

TASK(t7)
{	
	t7_instance++;
	switch (t7_instance) {
		case 1:
			TestRunner_runTest(COMInternalTest_seq4_t7_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq4_t7_instance2());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
}

TASK(t8)
{
	t8_instance++;
	switch (t8_instance) {
		case 1:
			TestRunner_runTest(COMInternalTest_seq4_t8_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq4_t8_instance2());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
}

TASK(t9)
{
	t9_instance++;
	switch (t9_instance) {
		case 1:
			TestRunner_runTest(COMInternalTest_seq4_t9_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq4_t9_instance2());
			break;
		case 3:
			TestRunner_runTest(COMInternalTest_seq4_t9_instance3());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
}