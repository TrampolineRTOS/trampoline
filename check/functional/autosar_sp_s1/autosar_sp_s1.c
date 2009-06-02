#include "Os.h"
#include "embUnit.h"
#include "config.h" /*for stdimpl_print*/

TestRef AutosarSPTest_seq1_t1_instance(void);
TestRef AutosarSPTest_seq1_t2_instance(void);
TestRef AutosarSPTest_seq1_isr1_instance(void);
TestRef AutosarSPTest_seq1_isr2_instance(void);
TestRef AutosarSPTest_seq1_error_instance1(void);
TestRef AutosarSPTest_seq1_error_instance2(void);
TestRef AutosarSPTest_seq1_error_instance3(void);

StatusType instance_error = 0;
StatusType error_status;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ErrorHook(StatusType error)
{
	instance_error++;
	switch (instance_error)
	{
		case 1 :
		{
			TestRunner_runTest(AutosarSPTest_seq1_error_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(AutosarSPTest_seq1_error_instance2());
			break;
		}
		case 3 :
		{
			error_status = error;
			TestRunner_runTest(AutosarSPTest_seq1_error_instance3());
			break;
		}
		case 4 :
		{
			break;
		}
		default:
		{
			stdimpl_print("Instance error");
			break;
		}
	}
	
	
	
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(AutosarSPTest_seq1_t1_instance());
}

TASK(t2)
{
	TestRunner_runTest(AutosarSPTest_seq1_t2_instance());
	ShutdownOS(E_OK);
}

ISR(isr1)
{
	TestRunner_runTest(AutosarSPTest_seq1_isr1_instance());
}


ISR(isr2)
{
	TestRunner_runTest(AutosarSPTest_seq1_isr2_instance());
}
