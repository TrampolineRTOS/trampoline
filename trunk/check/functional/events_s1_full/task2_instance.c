/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Event1);
DeclareResource(Resource1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_1 = GetResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_2 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OS_RESOURCE, result_inst_2);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_3 = ReleaseResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_3);
	
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq1_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
