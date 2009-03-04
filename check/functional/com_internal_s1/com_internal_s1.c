#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"

TestRef COMInternalTest_seq1_t1_instance(void);
TestRef COMInternalTest_seq1_t2_instance(void);

DeclareMessage(sm);
DeclareMessage(rm);

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

void COMErrorHook(error){
	
	
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