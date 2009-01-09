#include "../embUnit/embUnit.h"
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "../../os/tpl_os_kernel.h"
#include "tests_tasksManagement_sequence11.h"

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{
	TestRunner_end();
	UART_envoyer_chaine("Fin des 4 tests \n");
}

TASK(t1)
{
	TestRunner_runTest(TaskManagementTest_seq11_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_start();
	TestRunner_runTest(TaskManagementTest_seq11_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(TaskManagementTest_seq11_t3_instance());
}

TASK(t4)
{
	TestRunner_runTest(TaskManagementTest_seq11_t4_instance());
}
