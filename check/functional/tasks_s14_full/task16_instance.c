/*Instance of task t16*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Task16_Event1);
DeclareEvent(Task16_Event2);
DeclareEvent(Task16_Event3);
DeclareEvent(Task16_Event4);
DeclareEvent(Task16_Event5);
DeclareEvent(Task16_Event6);
DeclareEvent(Task16_Event7);
DeclareEvent(Task16_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t16_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8;
	
	SCHEDULING_CHECK_INIT(151);
	result_inst_1 = ClearEvent(Task16_Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(151,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(152);
	result_inst_2 = ClearEvent(Task16_Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(152,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(153);
	result_inst_3 = ClearEvent(Task16_Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(153,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(154);
	result_inst_4 = ClearEvent(Task16_Event4);
	SCHEDULING_CHECK_AND_EQUAL_INT(154,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(155);
	result_inst_5 = ClearEvent(Task16_Event5);
	SCHEDULING_CHECK_AND_EQUAL_INT(155,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(156);
	result_inst_6 = ClearEvent(Task16_Event6);
	SCHEDULING_CHECK_AND_EQUAL_INT(156,E_OK , result_inst_6);
	
	SCHEDULING_CHECK_INIT(157);
	result_inst_7 = ClearEvent(Task16_Event7);
	SCHEDULING_CHECK_AND_EQUAL_INT(157,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(158);
	result_inst_8 = ClearEvent(Task16_Event8);
	SCHEDULING_CHECK_AND_EQUAL_INT(158,E_OK , result_inst_8);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t16_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t16_instance",test_t16_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
