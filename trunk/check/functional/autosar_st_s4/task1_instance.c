/*Instance of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareCounter(Software_Counter);
DeclareScheduleTable(sched);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1;

	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = StartScheduleTableRel(sched, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = IncrementCounter(Software_Counter);
	/*start schedule table (because StartScheduleTabelRel(x, 1))*/
	/*offset = 0+offset_sched -> t1 can't be launch because of activation=1 -> errorhook*/
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_2);
			
	SCHEDULING_CHECK_INIT(4);
	result_inst_3 = IncrementCounter(Software_Counter);
	/*offset = 1+offset_sched -> set an event to a basic task (t2) so errorhook*/
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_4 = GetScheduleTableStatus(sched, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(6, SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_4);
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq4_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}
