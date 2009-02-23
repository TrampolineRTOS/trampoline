#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"

int instance_t1 = 0;

TestRef AlarmsTest_seq10_t1_instance(void);
TestRef AlarmsTest_seq10_t2_instance1(void);
TestRef AlarmsTest_seq10_t2_instance2(void);
TestRef AlarmsTest_seq10_t3_instance(void);
TestRef AlarmsTest_seq10_callback_instance(void);

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
	TestRunner_runTest(AlarmsTest_seq10_t1_instance());
}

TASK(t2)
{
	/*Switch to finish by Shutdown(OS)*/
	instance_t1 ++;
	switch(instance_t1)
	{ 
		case 1:	
		{
			TestRunner_runTest(AlarmsTest_seq10_t2_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(AlarmsTest_seq10_t2_instance2());
			ShutdownOS(E_OK);
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
}

TASK(t3)
{
	TestRunner_runTest(AlarmsTest_seq10_t3_instance());
}

void CallBackC_callback(void){
	TestRunner_runTest(AlarmsTest_seq10_callback_instance());
}