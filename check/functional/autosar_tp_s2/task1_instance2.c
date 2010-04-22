
/*Instance 2 of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance2(void)
{
	StatusType result_inst_1;
	
  SCHEDULING_CHECK_INIT(2);
	result_inst_1 = ActivateTask(t2);
  SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_1);
  
  SCHEDULING_CHECK_STEP(4);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarTPTest_seq2_t1_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance2",test_t1_instance2)
	};
	EMB_UNIT_TESTCALLER(AutosarTPTest,"AutosarTPTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTPTest;
}

