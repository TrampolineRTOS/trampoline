#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h";

TestRef HookTest_seq6_t1_instance(void);
TestRef HookTest_seq6_isr1_instance(void);
TestRef HookTest_seq6_isr2_instance(void);
TestRef HookTest_seq6_error_instance(void);
TestRef HookTest_seq6_posttask_instance4(void);

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

void ErrorHook(void)
{
	//stdimpl_print("ErrorHook\n");
	TestRunner_runTest(HookTest_seq6_error_instance());
	
}


void PostTaskHook(void)
{ 
	posttask_instance++;
	//stdimpl_print("PostTask : case %d\n",posttask_instance);
	switch (posttask_instance) {
		case 4: {
			TestRunner_runTest(HookTest_seq6_posttask_instance4());
			break;
		}
		default: {

			break;
		}
	}
}

TASK(t1)
{
	TestRunner_runTest(HookTest_seq6_t1_instance());
}

ISR(isr1)
{
	//stdimpl_print("ISR1 \n");
	TestRunner_runTest(HookTest_seq6_isr1_instance());
}

ISR(isr2)
{
	//stdimpl_print("ISR2 \n");
	TestRunner_runTest(HookTest_seq6_isr2_instance());
	ShutdownOS(E_OK);
}