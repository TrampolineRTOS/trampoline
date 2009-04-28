#include "tpl_os.h"
#include "embUnit.h"

TestRef HookTest_seq2_error_instance1(void);
TestRef HookTest_seq2_error_instance2(void);
TestRef HookTest_seq2_error_instance3(void);
TestRef HookTest_seq2_error_instance4(void);
TestRef HookTest_seq2_error_instance5(void);
TestRef HookTest_seq2_error_instance6(void);
TestRef HookTest_seq2_error_instance7(void);
TestRef HookTest_seq2_error_instance8(void);
TestRef HookTest_seq2_error_instance9(void);
TestRef HookTest_seq2_pretask_instance1(void);
TestRef HookTest_seq2_pretask_instance2(void);
TestRef HookTest_seq2_pretask_instance3(void);
TestRef HookTest_seq2_pretask_instance4(void);
TestRef HookTest_seq2_posttask_instance1(void);
TestRef HookTest_seq2_posttask_instance2(void);
TestRef HookTest_seq2_posttask_instance3(void);
TestRef HookTest_seq2_posttask_instance4(void);
TestRef HookTest_seq2_t1_instance(void);
TestRef HookTest_seq2_t2_instance(void);

unsigned char instance_post = 0;
unsigned char instance_pre = 0;
unsigned char instance_error = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

void ErrorHook(void)
{ 
	instance_error++;
	switch (instance_error)
	{
		case 1 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance2());
			break;
		}
		case 3 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance3());
			break;
		}
		case 4 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance4());
			break;
		}
		case 5 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance5());
			break;
		}
		case 6 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance6());
			break;
		}
		case 7 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance7());
			break;
		}
		case 8 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance8());
			break;
		}
		case 9 :
		{
			TestRunner_runTest(HookTest_seq2_error_instance9());
			break;
		}
		default:
		{
			stdimpl_print("Instance error");
			break;
		}
	}
	
}

void PreTaskHook(void)
{ 
	instance_pre++;
	switch (instance_pre)
	{
		case 1 :
		{
			TestRunner_runTest(HookTest_seq2_pretask_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(HookTest_seq2_pretask_instance2());
			break;
		}
		case 3 :
		{
			TestRunner_runTest(HookTest_seq2_pretask_instance3());
			break;
		}
		case 4 :
		{
			TestRunner_runTest(HookTest_seq2_pretask_instance4());
			break;
		}
		default:
		{
			stdimpl_print("Instance error");
			break;
		}
	}
}

void PostTaskHook(void)
{ 	
	instance_post++;
	switch (instance_post)
	{
		case 1 :
		{
			TestRunner_start();
			TestRunner_runTest(HookTest_seq2_posttask_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(HookTest_seq2_posttask_instance2());
			break;
		}
		case 3 :
		{
			TestRunner_runTest(HookTest_seq2_posttask_instance3());
			break;
		}
		case 4 :
		{
			TestRunner_runTest(HookTest_seq2_posttask_instance4());
			break;
		}
		default:
		{
			stdimpl_print("Instance error");
			break;
		}
	}

	
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
