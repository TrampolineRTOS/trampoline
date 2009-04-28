/*Instance of task t5*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Task5_Event1);
DeclareEvent(Task5_Event2);
DeclareEvent(Task5_Event3);
DeclareEvent(Task5_Event4);
DeclareEvent(Task5_Event5);
DeclareEvent(Task5_Event6);
DeclareEvent(Task5_Event7);
DeclareEvent(Task5_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t5_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	
	SCHEDULING_CHECK_INIT(52);
	result_inst_1 = ClearEvent(Task5_Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(52,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(53);
	result_inst_2 = ClearEvent(Task5_Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(53,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(54);
	result_inst_3 = ClearEvent(Task5_Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(54,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(55);
	result_inst_4 = ClearEvent(Task5_Event4);
	SCHEDULING_CHECK_AND_EQUAL_INT(55,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(56);
	result_inst_5 = ClearEvent(Task5_Event5);
	SCHEDULING_CHECK_AND_EQUAL_INT(56,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(57);
	result_inst_6 = ClearEvent(Task5_Event6);
	SCHEDULING_CHECK_AND_EQUAL_INT(57,E_OK , result_inst_6);
	
	SCHEDULING_CHECK_INIT(58);
	result_inst_7 = ClearEvent(Task5_Event7);
	SCHEDULING_CHECK_AND_EQUAL_INT(58,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(59);
	result_inst_8 = ClearEvent(Task5_Event8);
	SCHEDULING_CHECK_AND_EQUAL_INT(59,E_OK , result_inst_8);
	
	SCHEDULING_CHECK_INIT(60);
	result_inst_9 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(60,E_OK , result_inst_9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t5_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t5_instance",test_t5_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
