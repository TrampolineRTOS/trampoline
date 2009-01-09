#include "../embUnit/embUnit.h"
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "../../os/tpl_os_kernel.h"
#include "tests_tasksManagement_sequence9.h"

unsigned char instance_t3=0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{
	TestRunner_end();
	UART_envoyer_chaine("Fin des 2 tests \n");
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(TaskManagementTest_seq9_t1_instance());
}

TASK(t2)
{
	TestRunner_runTest(TaskManagementTest_seq9_t2_instance());
}

TASK(t3)
{
	instance_t3 ++;
	switch(instance_t3)
	{ 
		case 1:	
		{
			ChainTask(t3);
			break;
		}
		case 2:
		{
			ShutdownOS(E_OK);
			break;
		}
		default:
		{
			UART_envoyer_chaine("Instance error \n");
			break;
		}
	}
}
