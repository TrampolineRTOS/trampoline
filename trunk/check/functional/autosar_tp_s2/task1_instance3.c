
/*Instance 3 of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareEvent(Event2);
DeclareScheduleTable(sched1);
DeclareTask(t3);
DeclareTask(t4);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance3(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
	
  SCHEDULING_CHECK_INIT(5);
	result_inst_1 = StopScheduleTable(sched1);
  SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_1);
	
  SCHEDULING_CHECK_INIT(6);
	result_inst_2 = SetEvent(t3, Event2);
  SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_2);
	
  SCHEDULING_CHECK_INIT(9);
	result_inst_3 = ActivateTask(t4);
  SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_3);
	
  while(1); /* --> Protection Hook */
  
}

/*create the test suite with all the test cases*/
TestRef AutosarTPTest_seq2_t1_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance3",test_t1_instance3)
	};
	EMB_UNIT_TESTCALLER(AutosarTPTest,"AutosarTPTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTPTest;
}

