#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"
#include "tpl_app_objects.h"


TestRef COMInternalTest_seq1_t1_instance(void);
TestRef COMInternalTest_seq1_t2_instance(void);
TestRef COMInternalTest_seq1_comerror_instance1(void);
TestRef COMInternalTest_seq1_comerror_instance2(void);

DeclareMessage(sm);
DeclareMessage(rm);

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

void ErrorHook(error){

	
}

void COMErrorHook(error){
	
	com_error_instance++;
	switch (com_error_instance) {
		case 1:
			TestRunner_runTest(COMInternalTest_seq1_comerror_instance1());
			break;
		case 2:
			TestRunner_runTest(COMInternalTest_seq1_comerror_instance2());
			break;
		default:
			stdimpl_print("instance error\n");
			break;
	}
	
	
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(COMInternalTest_seq1_t1_instance());
	ShutdownOS(E_OK);
	
}

TASK(t2)
{
	TestRunner_runTest(COMInternalTest_seq1_t2_instance());
	
}

/*

 DOW = TRUE;
 UNITTEST = TRUE;
 
 CFLAGS  = "-g";
 CFLAGS  = "-Wall -pedantic -fasm-blocks";
 CFLAGS  = "-Wmissing-field-initializers";
 ASFLAGS = "";
 LDFLAGS = "-g";

*/