#include <embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "defaultAppWorkstation/tpl_os_generated_configuration.h"
#include "../../machines/ARM7/OKI/uart.h"
#include "../../os/tpl_os_kernel.h"
#include "tests_tasksManagement_sequence10.h"
#include "test_instances.h"

TestRef TaskManagementTest_seq10_t1_instance();
TestRef TaskManagementTest_seq10_t2_instance();
TestRef TaskManagementTest_seq10_t3_instance();

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
	TestRunner_runTest(TaskManagementTest_seq10_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(TaskManagementTest_seq10_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(TaskManagementTest_seq10_t3_instance());
}
