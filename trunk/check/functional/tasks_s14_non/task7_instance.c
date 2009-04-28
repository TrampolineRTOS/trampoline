/*Instance of task t7*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Task7_Event1);
DeclareEvent(Task7_Event2);
DeclareEvent(Task7_Event3);
DeclareEvent(Task7_Event4);
DeclareEvent(Task7_Event5);
DeclareEvent(Task7_Event6);
DeclareEvent(Task7_Event7);
DeclareEvent(Task7_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t7_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	
	SCHEDULING_CHECK_INIT(70);
	result_inst_1 = ClearEvent(Task7_Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(70,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(71);
	result_inst_2 = ClearEvent(Task7_Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(71,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(72);
	result_inst_3 = ClearEvent(Task7_Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(72,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(73);
	result_inst_4 = ClearEvent(Task7_Event4);
	SCHEDULING_CHECK_AND_EQUAL_INT(73,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(74);
	result_inst_5 = ClearEvent(Task7_Event5);
	SCHEDULING_CHECK_AND_EQUAL_INT(74,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(75);
	result_inst_6 = ClearEvent(Task7_Event6);
	SCHEDULING_CHECK_AND_EQUAL_INT(75,E_OK , result_inst_6);
	
	SCHEDULING_CHECK_INIT(76);
	result_inst_7 = ClearEvent(Task7_Event7);
	SCHEDULING_CHECK_AND_EQUAL_INT(76,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(77);
	result_inst_8 = ClearEvent(Task7_Event8);
	SCHEDULING_CHECK_AND_EQUAL_INT(77,E_OK , result_inst_8);
	
	SCHEDULING_CHECK_INIT(78);
	result_inst_9 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(78,E_OK , result_inst_9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t7_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t7_instance",test_t7_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
