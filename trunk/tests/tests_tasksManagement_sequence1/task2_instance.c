/*Instance of task t2*/

#include "test_instances.h"
#include <embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "defaultAppWorkstation/tpl_os_generated_configuration.h"

DeclareTask(t1);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{

	int result_inst_1, result_inst_2, result_inst_3;
//	result_inst_1 = ;
//	result_inst_2 = ;
//	result_inst_3 = ;
	
	TEST_ASSERT_EQUAL_INT(E_OS_LIMIT, ActivateTask(t1));
	TEST_ASSERT_EQUAL_INT(E_OS_LIMIT, ActivateTask(t2));
	TEST_ASSERT_EQUAL_INT(E_OS_LIMIT, ChainTask(t1));
	
	UART_envoyer_chaine("t2 \n");
	
	TerminateTask();

}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq1_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence1",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
