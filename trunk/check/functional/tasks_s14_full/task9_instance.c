/*Instance of task t9*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Task9_Event1);
DeclareEvent(Task9_Event2);
DeclareEvent(Task9_Event3);
DeclareEvent(Task9_Event4);
DeclareEvent(Task9_Event5);
DeclareEvent(Task9_Event6);
DeclareEvent(Task9_Event7);
DeclareEvent(Task9_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t9_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	
	SCHEDULING_CHECK_INIT(88);
	result_inst_1 = ClearEvent(Task9_Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(88,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(89);
	result_inst_2 = ClearEvent(Task9_Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(89,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(90);
	result_inst_3 = ClearEvent(Task9_Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(90,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(91);
	result_inst_4 = ClearEvent(Task9_Event4);
	SCHEDULING_CHECK_AND_EQUAL_INT(91,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(92);
	result_inst_5 = ClearEvent(Task9_Event5);
	SCHEDULING_CHECK_AND_EQUAL_INT(92,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(93);
	result_inst_6 = ClearEvent(Task9_Event6);
	SCHEDULING_CHECK_AND_EQUAL_INT(93,E_OK , result_inst_6);
	
	SCHEDULING_CHECK_INIT(94);
	result_inst_7 = ClearEvent(Task9_Event7);
	SCHEDULING_CHECK_AND_EQUAL_INT(94,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(95);
	result_inst_8 = ClearEvent(Task9_Event8);
	SCHEDULING_CHECK_AND_EQUAL_INT(95,E_OK , result_inst_8);
	
	SCHEDULING_CHECK_INIT(96);
	result_inst_9 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(96,E_OK , result_inst_9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t9_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t9_instance",test_t9_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
