#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "../../os/tpl_os_kernel.h"
#include "tests_InterruptProcessing_sequence3.h"

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{
	TestRunner_end();
	UART_envoyer_chaine("Fin des 3 tests \n");
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(InterruptProcessingTest_seq3_t1_instance());
}

TASK(t2)
{
/*	...*/
	TerminateTask();
}

TASK(t3)
{
	ShutdownOS(E_OK);
}

ISR2(isr2)
{
	TestRunner_runTest(InterruptProcessingTest_seq3_isr2_instance());
}

ISR2(isr3)
{
	TestRunner_runTest(InterruptProcessingTest_seq3_isr3_instance());
}
