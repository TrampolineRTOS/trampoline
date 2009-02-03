#include <embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "defaultAppWorkstation/tpl_os_generated_configuration.h"
#include "../../machines/ARM7/OKI/uart.h"
#include "../../os/tpl_os_kernel.h"
#include "tests_tasksManagement_sequence1.h"


int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{
	TestRunner_end();
	UART_envoyer_chaine("Fin du test \n");
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(TaskManagementTest_seq1_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(TaskManagementTest_seq1_t2_instance());
}

ISR(isr1)
{
	TestRunner_runTest(TaskManagementTest_seq1_isr1_instance());
}

ISR(isr2)
{
	TestRunner_runTest(TaskManagementTest_seq1_isr2_instance());
}
