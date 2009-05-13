/*Instance of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareCounter(Counter1);
DeclareTask(t1);
DeclareAlarm(Alarm1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	TickType TickType_inst_1, TickType_inst_2, TickType_inst_3, TickType_inst_4, TickType_inst_5;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetCounterValue(Counter1, &TickType_inst_1);	
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(1,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,0, TickType_inst_1);

	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = SetRelAlarm(Alarm1, 2, 0);	
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_2);	
		
	SCHEDULING_CHECK_INIT(3);
	result_inst_3 = IncrementCounter(Counter1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_3);

	SCHEDULING_CHECK_INIT(4);
	result_inst_4 = IncrementCounter(Counter1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_5 = GetCounterValue(Counter1, &TickType_inst_2);	
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(5,E_OK, result_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,1, TickType_inst_2);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_6 = IncrementCounter(Counter1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_6);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_7 = IncrementCounter(Counter1);
	/*alarm expires*/
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_7);
	
	/*force rescheduling*/
			
	SCHEDULING_CHECK_INIT(10);
	result_inst_8 = GetCounterValue(Counter1, &TickType_inst_3);	
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(10,E_OK, result_inst_8);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,2, TickType_inst_3);
		
	SCHEDULING_CHECK_INIT(11);
	TickType_inst_4 = 0;
	result_inst_9 = GetElapsedCounterValue(Counter1, &TickType_inst_4, &TickType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(11,E_OK , result_inst_9);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(11,2 , TickType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,2 , TickType_inst_5);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTest,"AutosarTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTest;
}
