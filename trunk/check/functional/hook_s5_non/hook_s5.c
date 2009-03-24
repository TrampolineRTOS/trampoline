#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h";

TestRef HookTest_seq5_t1_instance(void);
TestRef HookTest_seq5_t2_instance(void);
TestRef HookTest_seq5_isr1_instance(void);
TestRef HookTest_seq5_pretask_instance8(void);
TestRef HookTest_seq5_pretask_instance11(void);
TestRef HookTest_seq5_posttask_instance2(void);
TestRef HookTest_seq5_posttask_instance5(void);

void tpl_send_it1(void);
void tpl_send_it2(void);

int posttask_instance = 0;
int pretask_instance = 0;

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

void PreTaskHook(void)
{ 
	pretask_instance++;
	//stdimpl_print("PreTask : case %d\n",pretask_instance);
	switch (pretask_instance) {
		case 8: {
			TestRunner_runTest(HookTest_seq5_pretask_instance8());
			break;
		}
		case 11: {
			TestRunner_runTest(HookTest_seq5_pretask_instance11());
			break;
		}
		default: {
			
			break;
		}
	}
	
}

void PostTaskHook(void)
{ 
	posttask_instance++;
	//stdimpl_print("PostTask : case %d\n",posttask_instance);
	switch (posttask_instance) {
		case 2: {
			TestRunner_runTest(HookTest_seq5_posttask_instance2());
			break;
		}
		case 5: {
			TestRunner_runTest(HookTest_seq5_posttask_instance5());
			break;
		}
		default: {

			break;
		}
	}
}

TASK(t1)
{
	//stdimpl_print("## t1 ##\n");
	TestRunner_runTest(HookTest_seq5_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	//stdimpl_print("## t2 ##\n");
	TestRunner_runTest(HookTest_seq5_t2_instance());
}

ISR(isr1)
{
	//stdimpl_print("ISR1 \n");
	TestRunner_runTest(HookTest_seq5_isr1_instance());
}