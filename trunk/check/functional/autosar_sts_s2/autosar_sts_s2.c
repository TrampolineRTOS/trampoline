#include "Os.h"
#include "embUnit.h"
#include "config.h"

TestRef AutosarSTSTest_seq2_t1_instance(void);
TestRef AutosarSTSTest_seq2_error_instance1(void);
TestRef AutosarSTSTest_seq2_error_instance2(void);
TestRef AutosarSTSTest_seq2_error_instance3(void);
TestRef AutosarSTSTest_seq2_error_instance4(void);
TestRef AutosarSTSTest_seq2_error_instance5(void);
TestRef AutosarSTSTest_seq2_error_instance6(void);
TestRef AutosarSTSTest_seq2_error_instance7(void);
TestRef AutosarSTSTest_seq2_error_instance8(void);
TestRef AutosarSTSTest_seq2_error_instance9(void);
TestRef AutosarSTSTest_seq2_error_instance10(void);
TestRef AutosarSTSTest_seq2_error_instance11(void);
TestRef AutosarSTSTest_seq2_error_instance12(void);
TestRef AutosarSTSTest_seq2_error_instance13(void);
TestRef AutosarSTSTest_seq2_error_instance14(void);
TestRef AutosarSTSTest_seq2_error_instance15(void);
TestRef AutosarSTSTest_seq2_error_instance16(void);
TestRef AutosarSTSTest_seq2_error_instance17(void);

StatusType instance_error = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

void ErrorHook(StatusType error)
{
	instance_error++;
	switch (instance_error) {
		case 1:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance1());	
			break;
		}
		case 2:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance2());	
			break;
		}
		case 3:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance3());	
			break;
		}
		case 4:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance4());	
			break;
		}
		case 5:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance5());	
			break;
		}
		case 6:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance6());	
			break;
		}
		case 7:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance7());	
			break;
		}
		case 8:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance8());	
			break;
		}
		case 9:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance9());	
			break;
		}
		case 10:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance10());	
			break;
		}
		case 11:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance11());	
			break;
		}
		case 12:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance12());	
			break;
		}
		case 13:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance13());	
			break;
		}
		case 14:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance14());	
			break;
		}
		case 15:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance15());	
			break;
		}
		case 16:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance16());	
			break;
		}
		case 17:
		{
			TestRunner_runTest(AutosarSTSTest_seq2_error_instance17());	
			break;
		}
		default:
		{
			stdimpl_print("instance error\n");
			break;
		}
	}
	
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(AutosarSTSTest_seq2_t1_instance());
	ShutdownOS(E_OK);
}
