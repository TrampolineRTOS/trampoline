#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"
#include "tpl_app_objects.h"


TestRef COMInternalTest_seq3_t1_instance(void);
TestRef COMInternalTest_seq3_t2_instance(void);
TestRef COMInternalTest_seq3_t3_instance(void);
TestRef COMInternalTest_seq3_t4_instance(void);
TestRef COMInternalTest_seq3_comcallback_instance(void);

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
	
//
	
	
}


TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(COMInternalTest_seq3_t1_instance());
	ShutdownOS(E_OK);
	
}

TASK(t2)
{
	TestRunner_runTest(COMInternalTest_seq3_t2_instance());
	
}

TASK(t3)
{
	TestRunner_runTest(COMInternalTest_seq3_t3_instance());
	
}

TASK(t4)
{
	TestRunner_runTest(COMInternalTest_seq3_t4_instance());
	//ShutdownOS(E_OK);
}

extern void ComCallBack_callback(void){
	
	TestRunner_runTest(COMInternalTest_seq3_comcallback_instance());
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