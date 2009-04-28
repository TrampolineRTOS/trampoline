/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareAlarm(Alarm1);
DeclareEvent(Event1);
DeclareTask(t1);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4;
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_1 = SetAbsAlarm(Alarm1, 16, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK , result_inst_1); 

	SCHEDULING_CHECK_INIT(18);
	result_inst_2 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(39,E_OK , result_inst_2); 

	SCHEDULING_CHECK_INIT(40);
	result_inst_3 = SetEvent(t1, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(40,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(41);
	result_inst_4 = ChainTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(41,E_OK , result_inst_4); 
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
