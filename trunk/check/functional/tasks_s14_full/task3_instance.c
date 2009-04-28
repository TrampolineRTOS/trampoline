/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Task3_Event1);
DeclareEvent(Task3_Event2);
DeclareEvent(Task3_Event3);
DeclareEvent(Task3_Event4);
DeclareEvent(Task3_Event5);
DeclareEvent(Task3_Event6);
DeclareEvent(Task3_Event7);
DeclareEvent(Task3_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	
	SCHEDULING_CHECK_INIT(34);
	result_inst_1 = ClearEvent(Task3_Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(34,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(35);
	result_inst_2 = ClearEvent(Task3_Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(35,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(36);
	result_inst_3 = ClearEvent(Task3_Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(36,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(37);
	result_inst_4 = ClearEvent(Task3_Event4);
	SCHEDULING_CHECK_AND_EQUAL_INT(37,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(38);
	result_inst_5 = ClearEvent(Task3_Event5);
	SCHEDULING_CHECK_AND_EQUAL_INT(38,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(39);
	result_inst_6 = ClearEvent(Task3_Event6);
	SCHEDULING_CHECK_AND_EQUAL_INT(39,E_OK , result_inst_6);
	
	SCHEDULING_CHECK_INIT(40);
	result_inst_7 = ClearEvent(Task3_Event7);
	SCHEDULING_CHECK_AND_EQUAL_INT(40,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(41);
	result_inst_8 = ClearEvent(Task3_Event8);
	SCHEDULING_CHECK_AND_EQUAL_INT(41,E_OK , result_inst_8);
	
	SCHEDULING_CHECK_INIT(42);
	result_inst_9 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(42,E_OK , result_inst_9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
