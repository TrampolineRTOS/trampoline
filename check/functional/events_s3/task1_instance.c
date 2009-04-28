/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);
DeclareTask(t3);
DeclareEvent(Event1);
DeclareEvent(Event2);
DeclareEvent(Event3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_2, result_inst_4, result_inst_5, result_inst_7, result_inst_9, result_inst_10, result_inst_12, result_inst_14, result_inst_15, result_inst_17, result_inst_18, result_inst_19, result_inst_20;
	TaskStateType result_inst_1, result_inst_6, result_inst_11;
	EventMaskType result_inst_3, result_inst_8, result_inst_13, result_inst_16;
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = GetTaskState(t2, &result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(2,WAITING, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_4 = GetEvent(t2,&result_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(3,E_OK, result_inst_3); 
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_4);	
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_5 = SetEvent(t2,Event2);	
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK, result_inst_5);	
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_7 = GetTaskState(t2, &result_inst_6);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(5,WAITING, result_inst_6);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_7);	

	SCHEDULING_CHECK_INIT(6);
	result_inst_9 = GetEvent(t2,&result_inst_8);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(6,Event2, result_inst_8);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_10 = SetEvent(t2,Event1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_10);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_12 = GetTaskState(t2, &result_inst_11);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(8,READY, result_inst_11);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_12);						  
						  
	SCHEDULING_CHECK_INIT(9);
	result_inst_14 = GetEvent(t2,&result_inst_13);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(9,Event1|Event2, result_inst_13);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_14);						  
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_15 = SetEvent(t2,Event3);	
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_15);
						  
	SCHEDULING_CHECK_INIT(11);
	result_inst_17 = GetEvent(t2,&result_inst_16);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(11,Event1|Event2|Event3, result_inst_16);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_17);						  
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_18 = ActivateTask(t3);	
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_18);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_19 = SetEvent(t3,Event3);	
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OK, result_inst_19);
		
	SCHEDULING_CHECK_INIT(14);
	result_inst_20 = TerminateTask();	
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_20);

}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
