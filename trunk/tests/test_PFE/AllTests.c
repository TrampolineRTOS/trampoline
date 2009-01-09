 /**
  * @file AllTests.c
  * 
  * $Date: 2008/05/20 12:09:34 $
 * $Rev$
 * $Author: GuillaumeNuth $
 * $URL$
 */


#include "embUnit.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "AllTests.h"

/*reference to the suite of test created*/
TestRef TaskManagementTest_tests(void);

int main_test ()
{
	TestRunner_start();
		/*run the test suite given in reference*/
		TestRunner_runTest(TaskManagementTest_tests());
	TestRunner_end();
	return 0;
}

void stdimpl_print(const char* string){
	UART_envoyer_chaine((const char*)(string));
}
