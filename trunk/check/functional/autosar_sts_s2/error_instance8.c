/*Instance 8 of error*/

#include "embUnit.h"
#include "Os.h"

DeclareScheduleTable(sched_explicit);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance8(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(17,sched_explicit, OSServiceId_StartScheduleTableAbs_ScheduleTableID());
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(17,1 , OSServiceId_StartScheduleTableAbs_value());
	SCHEDULING_CHECK_AND_EQUAL_INT(17,OSServiceId_StartScheduleTableAbs, result_inst_1);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTSTest_seq2_error_instance8(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance8",test_error_instance8)
	};
	EMB_UNIT_TESTCALLER(AutosarSTSTest,"AutosarSTSTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTSTest;
}
