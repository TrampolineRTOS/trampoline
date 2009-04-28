/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Task2_Event1);
DeclareEvent(Task2_Event2);
DeclareEvent(Task2_Event3);
DeclareEvent(Task2_Event4);
DeclareEvent(Task2_Event5);
DeclareEvent(Task2_Event6);
DeclareEvent(Task2_Event7);
DeclareEvent(Task2_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	
	SCHEDULING_CHECK_INIT(25);
	result_inst_1 = ClearEvent(Task2_Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(25,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_2 = ClearEvent(Task2_Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(26,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_3 = ClearEvent(Task2_Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(27,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(28);
	result_inst_4 = ClearEvent(Task2_Event4);
	SCHEDULING_CHECK_AND_EQUAL_INT(28,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(29);
	result_inst_5 = ClearEvent(Task2_Event5);
	SCHEDULING_CHECK_AND_EQUAL_INT(29,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(30);
	result_inst_6 = ClearEvent(Task2_Event6);
	SCHEDULING_CHECK_AND_EQUAL_INT(30,E_OK , result_inst_6);
	
	SCHEDULING_CHECK_INIT(31);
	result_inst_7 = ClearEvent(Task2_Event7);
	SCHEDULING_CHECK_AND_EQUAL_INT(31,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(32);
	result_inst_8 = ClearEvent(Task2_Event8);
	SCHEDULING_CHECK_AND_EQUAL_INT(32,E_OK , result_inst_8);
	
	SCHEDULING_CHECK_INIT(33);
	result_inst_9 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(33,E_OK , result_inst_9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
