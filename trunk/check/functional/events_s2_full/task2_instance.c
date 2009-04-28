/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t1);
DeclareEvent(Event2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_3, result_inst_4, result_inst_5;
	EventMaskType result_inst_2;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = ActivateTask(t1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_3 = GetEvent(t1,&result_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(2,E_OK, result_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_4 = WaitEvent(Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_5 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_5);

}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq2_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
