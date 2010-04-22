
/*Instance 3 of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareEvent(Event1);
DeclareTask(t1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance3(void)
{
	StatusType result_inst_1;
  
  SCHEDULING_CHECK_INIT(3);
	result_inst_1 = SetEvent(t1, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_1);
	
  while(1); /* --> Protection Hook */
	
}

/*create the test suite with all the test cases*/
TestRef AutosarTPTest_seq3_t1_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance3",test_t1_instance3)
	};
	EMB_UNIT_TESTCALLER(AutosarTPTest,"AutosarTPTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTPTest;
}

