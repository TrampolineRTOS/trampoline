/*Instance of task t12*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Task12_Event1);
DeclareEvent(Task12_Event2);
DeclareEvent(Task12_Event3);
DeclareEvent(Task12_Event4);
DeclareEvent(Task12_Event5);
DeclareEvent(Task12_Event6);
DeclareEvent(Task12_Event7);
DeclareEvent(Task12_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t12_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	
	SCHEDULING_CHECK_INIT(115);
	result_inst_1 = ClearEvent(Task12_Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(115,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(116);
	result_inst_2 = ClearEvent(Task12_Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(116,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(117);
	result_inst_3 = ClearEvent(Task12_Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(117,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(118);
	result_inst_4 = ClearEvent(Task12_Event4);
	SCHEDULING_CHECK_AND_EQUAL_INT(118,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(119);
	result_inst_5 = ClearEvent(Task12_Event5);
	SCHEDULING_CHECK_AND_EQUAL_INT(119,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(120);
	result_inst_6 = ClearEvent(Task12_Event6);
	SCHEDULING_CHECK_AND_EQUAL_INT(120,E_OK , result_inst_6);
	
	SCHEDULING_CHECK_INIT(121);
	result_inst_7 = ClearEvent(Task12_Event7);
	SCHEDULING_CHECK_AND_EQUAL_INT(121,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(122);
	result_inst_8 = ClearEvent(Task12_Event8);
	SCHEDULING_CHECK_AND_EQUAL_INT(122,E_OK , result_inst_8);
	
	SCHEDULING_CHECK_INIT(123);
	result_inst_9 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(123,E_OK , result_inst_9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t12_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t12_instance",test_t12_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
