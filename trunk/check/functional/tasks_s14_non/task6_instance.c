/*Instance of task t6*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Task6_Event1);
DeclareEvent(Task6_Event2);
DeclareEvent(Task6_Event3);
DeclareEvent(Task6_Event4);
DeclareEvent(Task6_Event5);
DeclareEvent(Task6_Event6);
DeclareEvent(Task6_Event7);
DeclareEvent(Task6_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t6_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	
	SCHEDULING_CHECK_INIT(61);
	result_inst_1 = ClearEvent(Task6_Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(61,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(62);
	result_inst_2 = ClearEvent(Task6_Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(62,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(63);
	result_inst_3 = ClearEvent(Task6_Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(63,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(64);
	result_inst_4 = ClearEvent(Task6_Event4);
	SCHEDULING_CHECK_AND_EQUAL_INT(64,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(65);
	result_inst_5 = ClearEvent(Task6_Event5);
	SCHEDULING_CHECK_AND_EQUAL_INT(65,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(66);
	result_inst_6 = ClearEvent(Task6_Event6);
	SCHEDULING_CHECK_AND_EQUAL_INT(66,E_OK , result_inst_6);
	
	SCHEDULING_CHECK_INIT(67);
	result_inst_7 = ClearEvent(Task6_Event7);
	SCHEDULING_CHECK_AND_EQUAL_INT(67,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(68);
	result_inst_8 = ClearEvent(Task6_Event8);
	SCHEDULING_CHECK_AND_EQUAL_INT(68,E_OK , result_inst_8);
	
	SCHEDULING_CHECK_INIT(69);
	result_inst_9 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(69,E_OK , result_inst_9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t6_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t6_instance",test_t6_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
