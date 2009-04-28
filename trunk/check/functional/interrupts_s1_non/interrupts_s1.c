#include "tpl_os.h"
#include "embUnit.h"

TestRef InterruptProcessingTest_seq1_t1_instance(void);
TestRef InterruptProcessingTest_seq1_isr1_instance(void);
TestRef InterruptProcessingTest_seq1_isr2_instance1(void);
TestRef InterruptProcessingTest_seq1_isr2_instance2(void);
TestRef InterruptProcessingTest_seq1_isr2_instance3(void);
TestRef InterruptProcessingTest_seq1_isr2_instance4(void);
TestRef InterruptProcessingTest_seq1_isr2_instance5(void);
TestRef InterruptProcessingTest_seq1_isr2_instance6(void);
TestRef InterruptProcessingTest_seq1_isr2_instance7(void);
TestRef InterruptProcessingTest_seq1_isr2_instance8(void);
TestRef InterruptProcessingTest_seq1_isr2_instance9(void);
TestRef InterruptProcessingTest_seq1_isr2_instance10(void);
TestRef InterruptProcessingTest_seq1_isr2_instance11(void);
TestRef InterruptProcessingTest_seq1_isr3_instance(void);

unsigned char instance_isr2 = 0;

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
	TestRunner_runTest(InterruptProcessingTest_seq1_t1_instance());
	ShutdownOS(E_OK);
}

ISR(isr1)
{
	TestRunner_runTest(InterruptProcessingTest_seq1_isr1_instance());
}

ISR(isr2)
{
	
	instance_isr2 ++;
	switch(instance_isr2)
	{ 
		case 1:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance2());
			break;
		}
		case 3:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance3());
			break;
		}
		case 4:
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance4());
			break;
		}
		case 5:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance5());
			break;
		}
		case 6:
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance6());
			break;
		}
		case 7:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance7());
			break;
		}
		case 8:
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance8());
			break;
		}
		case 9:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance9());
			break;
		}
		case 10:
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance10());
			break;
		}
		case 11:	
		{
			TestRunner_runTest(InterruptProcessingTest_seq1_isr2_instance11());
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
	
	
	
}

ISR(isr3)
{
	TestRunner_runTest(InterruptProcessingTest_seq1_isr3_instance());
}
